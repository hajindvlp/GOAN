cls
@echo off
echo "              _ _           ___                      _ _           " 
echo "  /\  /\__ _ (_|_)_ __     / __\___  _ __ ___  _ __ (_) | ___ _ __ "
echo " / /_/ / _` || | | '_ \   / /  / _ \| '_ ` _ \| '_ \| | |/ _ \ '__|"
echo "/ __  / (_| || | | | | | / /__| (_) | | | | | | |_) | | |  __/ |   "
echo "\/ /_/ \__,_|/ |_|_| |_| \____/\___/|_| |_| |_| .__/|_|_|\___|_|   "
echo "           |__/                               |_|                  "
gcc ./*.c libgdi32.a -lmsimg32  -lwinmm