#include "CPUMetrics.h"
#include <unistd.h>

int main() {
    float *ptr = get_cpu_load();
    for (int i = 0; i < 4; i++) {
        printf("%f%%\n", *ptr);
        ptr++;
    }
    return 0;
}