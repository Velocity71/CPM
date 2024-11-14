#include <stdio.h> // standard input/output functions
#include <mach/mach.h> // Mach-specific APIs, used to get parameters like CPU load


// Print CPU usage
void print_cpu_load() {

    host_cpu_load_info_data_t cpu_load; // struct for CPU load information, populated later by host_statistics()
    mach_msg_type_number_t cpu_load_count = HOST_CPU_LOAD_INFO_COUNT; // specifies number of elements in the cpu_load struct

    // Retrieves CPU load information, return_status indicates errors, information populates to the cpu_load struct
    kern_return_t return_status = host_statistics(mach_host_self(), HOST_CPU_LOAD_INFO, (host_info_t)&cpu_load, &cpu_load_count);

    // Checks if host_statistics() was executed successfully
    if (return_status != KERN_SUCCESS) {
        fprintf(stderr, "Failed to get CPU info: %s\n", mach_error_string(return_status)); // if error, converts into readable message and prints to stderr
        return; // exit print_cpu_load() early
    }

    // Calculate CPU load as a percentage for user, system, idle, and nice
    uint64_t total_ticks = 0; // sum of ticks across all CPU states
    for (int i = 0; i < CPU_STATE_MAX; i++) {
        total_ticks += cpu_load.cpu_ticks[i]; // add number of ticks for each state
    }

    // Print CPU load statistics
    printf("---CPU USAGE---\n");
    printf("User: %f%%\n", (float) cpu_load.cpu_ticks[CPU_STATE_USER] / total_ticks * 100); // cpu percentage by user processes
    printf("System: %f%%\n", (float)cpu_load.cpu_ticks[CPU_STATE_SYSTEM] / total_ticks * 100); // cpu percentage by system processes
    printf("Idle: %f%%\n", (float)cpu_load.cpu_ticks[CPU_STATE_IDLE] / total_ticks * 100); // cpu percentage idle
    printf("Nice: %f%%\n", (float)cpu_load.cpu_ticks[CPU_STATE_NICE] / total_ticks * 100); // cpu percentage by processes with nice priority
}


int main() {
    print_cpu_load();
    return 0;
}