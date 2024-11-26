cc -c -fPIC src/c/jni/jni.c -o bin/native/jni.o
cc -c -fPIC src/c/metrics/cpu_metrics.c -o bin/native/cpu_metrics.o
cc -c -fPIC src/c/metrics/disk_metrics.c -o bin/native/disk_metrics.o
cc -c -fPIC src/c/metrics/memory_metrics.c -o bin/native/memory_metrics.o
cc -shared -o bin/java/libmetrics.dylib bin/native/*.o -lc

cd src/java
javac -d ../../bin/java -cp ../../bin/java gui/MainFrame.java JNI.java

cd ../..
javac -d bin/java -cp bin/java Main.java

cd bin/java
java Main

cd ..
rm -f -r java
rm -f -r native