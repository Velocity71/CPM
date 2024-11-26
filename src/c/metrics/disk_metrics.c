// disk_metrics.c

// Functions for disk metrics

#include <stdio.h> // used for error printing
#include <stdlib.h> // used for the exit() function
#include <sys/statvfs.h> // functions related to (virtual)filesystem information

// Returns a pointer pointing to the array holding the disk usage statistics
long unsigned *get_disk_usage() {
    struct statvfs disk_usage; // struct for filesystem info (like space on a drive). populated later by statvfs()

    // Retrieves information about the root filesystem '/', return error if failed, information populates to disk_usage
    if (statvfs("/", &disk_usage) == -1) {
        perror("statvfs");
        exit(1); // exit get_disk_usage() early
    }

    // Save disk usage statistics to an array and return pointer for array
    // f_blocks is total space, f_bfree is free space, f_bsize is size of filesystem in f_frsize units
    long unsigned *bytes = (long unsigned *)malloc(2 * sizeof(long unsigned));
    bytes[0] = disk_usage.f_blocks * disk_usage.f_bsize;
    bytes[1] = disk_usage.f_bfree * disk_usage.f_bsize;
    long unsigned *ptr = bytes;
    return ptr;
}