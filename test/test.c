#include <stdio.h>
#include <windows.h>

int main() {
   char a[101] = "open cannon.mp3 type mpegvideo";
   int error = 99;
   error = mciSendString(a, NULL,0,0);
   int error2;
   char b[101] = "play cannon.mp3";
   error2 = mciSendString(b, NULL, 0, 0);

   printf("%d %d\n", error, error2);
   while(1);

   //cannon.mp3 is stored in my resource file
   //error is just for debugging
}