cls
@echo off
echo "   ______                      _ __         "
echo "  / ____/___  ____ ___  ____  (_) /__  _____"
echo " / /   / __ \/ __  __ \/ __ \/ / / _ \/ ___/"
echo "/ /___/ /_/ / / / / / / /_/ / / /  __/ /    "
echo "\____/\____/_/ /_/ /_/ .___/_/_/\___/_/     "
echo "                    /_/                     "
gcc -o release/GOAN.exe ../*.c exeConfig.res libgdi32.a -lmsimg32  -lwinmm