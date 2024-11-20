# Compile C file to excecuable object with all the source files as dependencies
cc PrintMetrics.c Metrics/src/* -o PrintMetrics.o

# If the compilation was successful run the generated object (and delete it afterwards)
if [ $? -eq 0 ]; then
    ./PrintMetrics.o
# else exit with error status
else
    exit 1
fi

# delete excecutable object and exit with success
rm PrintMetrics.o
exit 0