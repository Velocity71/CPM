# Compile java file and create header
javac GetMetrics/GetMetrics.java

# If the compilation was successful compile the c file to to excecuable object with dependencies (GetMetrics.h and and GetMetrics_md.h)
if [ $? -eq 0 ]; then
    mv GetMetrics/GetMetrics.class .
    cc -c -fPIC -I${JAVA_INCLUDE} -I${JAVA_INCLUDE}/darwin GetMetrics/GetMetrics.c -o GetMetrics.o
else
    rm GetMetrics/GetMetrics.class
    exit 1
fi

# If c file compilation was successful compile C file dependency
if [ $? -eq 0 ]; then
    cc -c -fPIC -I${JAVA_INCLUDE} -I${JAVA_INCLUDE}/darwin Metrics/src/CPUMetrics.c -o CPUMetrics.o
else
    rm GetMetrics.class
    rm GetMetrics.o
    exit 1
fi

# If c file compilation was successful compile C file dependency
if [ $? -eq 0 ]; then
    cc -c -fPIC -I${JAVA_INCLUDE} -I${JAVA_INCLUDE}/darwin Metrics/src/DiskMetrics.c -o DiskMetrics.o
else
    rm GetMetrics.class
    rm GetMetrics.o
    rm CPUMetrics.o
    exit 1
fi

# If c file compilation was successful compile C file dependency
if [ $? -eq 0 ]; then
    cc -c -fPIC -I${JAVA_INCLUDE} -I${JAVA_INCLUDE}/darwin Metrics/src/MemMetrics.c -o MemMetrics.o
else
    rm GetMetrics.class
    rm GetMetrics.o
    rm CPUMetrics.o
    rm DiskMetrics.o
    exit 1
fi

# If c dependency compilation was successful compile files into library
if [ $? -eq 0 ]; then
    cc -dynamiclib -o libMetrics.dylib GetMetrics.o CPUMetrics.o DiskMetrics.o MemMetrics.o -lc
else
    rm GetMetrics.class
    rm GetMetrics.o
    rm CPUMetrics.o
    rm DiskMetrics.o
    rm MemMetrics.o
    exit 1
fi

# if library compilation was successful run program
if [ $? -eq 0 ]; then
    java GetMetrics
else
    rm GetMetrics.class
    rm GetMetrics.o
    rm CPUMetrics.o
    rm DiskMetrics.o
    rm MemMetrics.o
    rm libMetrics.dylib
    exit 1
fi

rm GetMetrics.class
rm GetMetrics.o
rm CPUMetrics.o
rm DiskMetrics.o
rm MemMetrics.o
rm libMetrics.dylib
exit 0