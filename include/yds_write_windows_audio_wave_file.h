#pragma once
#include <cstdint>
#include <string>
#include <vector>

void ysWriteWindowsAudioWaveFile(const std::string& filename, const std::vector<int16_t>& data);
