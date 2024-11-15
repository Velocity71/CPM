#include "CPUMetrics.h"
#include <unistd.h>

int main() {
    float *ptr = get_cpu_load();

    printf("---CPU LOAD---\n");
    printf("User: %f%%\n", *ptr); ptr++;
    printf("System: %f%%\n", *ptr); ptr++;
    printf("Idle: %f%%\n", *ptr); ptr++;
    printf("Nice: %f%%\n", *ptr);
    return 0;
}