#include "CPUMetrics.h"
#include <unistd.h>

int main() {
    float *ptr = get_cpu_load();

    float cpu_user = *ptr; ptr++;
    float cpu_system = *ptr; ptr++;
    float cpu_idle = *ptr; ptr++;
    float cpu_nice = *ptr;

    printf("---CPU Load---\n");
    printf("Active: %f%%\n", cpu_user + cpu_system);
    printf("Idle: %f%%\n", cpu_idle);
    printf("---CPU Utilization---\n");
    printf("User: %f%%\n", cpu_user);
    printf("System: %f%%\n", cpu_system);
    printf("Nice: %f%%\n", cpu_nice);
    return 0;
}