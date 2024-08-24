cd /D "%~dp0" || exit /b

cd build

set PERIODS_CONSTANT=200
set WAVE_FILE=..\recording.wav
set WAVE_FILE_MAX_MINUTES=20
set LABELS_FILE=..\recording_labels.txt

Release\engine-sim-app.exe
