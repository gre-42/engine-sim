#include "../include/yds_write_windows_audio_wave_file.h"
#include <fstream>

// From: https://gist.github.com/csukuangfj/c1d1d769606260d436f8674c30662450
struct WavHeader {
    /* RIFF Chunk Descriptor */
    uint8_t RIFF[4] = { 'R', 'I', 'F', 'F' };   // RIFF Header Magic header
    uint32_t ChunkSize;                         // RIFF Chunk Size
    uint8_t WAVE[4] = { 'W', 'A', 'V', 'E' };   // WAVE Header
    /* "fmt" sub-chunk */
    uint8_t fmt[4] = { 'f', 'm', 't', ' ' };    // FMT header
    uint32_t Subchunk1Size = 16;                // Size of the fmt chunk
    uint16_t AudioFormat = 1;                   // Audio format 1=PCM,6=mulaw,7=alaw, 257=IBM
                                                // Mu-Law, 258=IBM A-Law, 259=ADPCM
    uint16_t NumOfChan = 1;                     // Number of channels 1=Mono 2=Sterio
    uint32_t SamplesPerSec = 44100;             // Sampling Frequency in Hz
    uint32_t bytesPerSec = 44100 * 2;           // bytes per second
    uint16_t blockAlign = 2;                    // 2=16-bit mono, 4=16-bit stereo
    uint16_t bitsPerSample = 16;                // Number of bits per sample
    /* "data" sub-chunk */
    uint8_t Subchunk2ID[4] = { 'd', 'a', 't', 'a' };    // "data"  string
    uint32_t Subchunk2Size;                             // Sampled data length
};

static_assert(sizeof(WavHeader) == 44, "");

void ysWriteWindowsAudioWaveFile(const std::string& filename, const std::vector<int16_t>& data)
{
    std::ofstream waveFile{ filename, std::ios::binary };
    if (waveFile.fail()) {
        throw std::runtime_error("Could not open file for writing: \"" + filename + '"');
    }

    size_t fsize = data.size() * sizeof(data[0]);

    WavHeader header;
    header.ChunkSize = fsize + sizeof(header) - 8;
    header.Subchunk2Size = fsize + sizeof(header) - 44;

    waveFile.write((const char*)&header, sizeof(header));

    for (uint16_t v : data) {
        waveFile << char(v & 0xFF) << char(v >> 8);
    }

    waveFile.flush();
    if (waveFile.fail()) {
        throw std::runtime_error("Could not write to wave file \"" + filename + '"');
    }

    waveFile.close();
    if (waveFile.fail()) {
        throw std::runtime_error("Could not write to wave file \"" + filename + '"');
    }
}
