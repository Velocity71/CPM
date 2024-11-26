// JNI.java

// Interface with and obtain values from C code

package src.java;

public class JNI {
    // Value Arrays hold last 10 seconds of readings (by 1 second)
    private static float[] CpuUserVals = new float[11];
    private static float[] CpuSystemVals = new float[11];
    private static float[] CpuIdleVals = new float[11];
    private static float[] CpuNiceVals = new float[11];

    private static long[] MemResidentVals = new long[11];
    private static long[] MemVirtualVals = new long[11];

    private static long[] DiskTotalVals = new long[11];
    private static long[] DiskUsedVals = new long[11];

    // Native methods used for C interfacing
    private static native float getCpuUser();
    private static native float getCpuSystem();
    private static native float getCpuIdle();
    private static native float getCpuNice();

    private static native long getMemResident();
    private static native long getMemVirtual();

    private static native long getDiskTotal();
    private static native long getDiskUsed();

    // Library Metrics has C methods
    static {
        System.loadLibrary("metrics");
    }

    // Update value arrays
    public static void updateData() {

        // update CPU User% values
        for (int i = 9; i >= 0; i--) {CpuUserVals[i+1] = CpuUserVals[i];}
        CpuUserVals[0] = getCpuUser();

        // update CPU System% values
        for (int i = 9; i >= 0; i--) {CpuSystemVals[i+1] = CpuSystemVals[i];}
        CpuSystemVals[0] = getCpuSystem();

        // update CPU Idle% values
        for (int i = 9; i >= 0; i--) {CpuIdleVals[i+1] = CpuIdleVals[i];}
        CpuIdleVals[0] = getCpuIdle();

        // update CPU Nice% values
        for (int i = 9; i >= 0; i--) {CpuNiceVals[i+1] = CpuNiceVals[i];}
        CpuNiceVals[0] = getCpuNice();

        // update memory resident bytes values
        for (int i = 9; i >= 0; i--) {MemResidentVals[i+1] = MemResidentVals[i];}
        MemResidentVals[0] = getMemResident();

        // update memory virtual bytes values
        for (int i = 9; i >= 0; i--) {MemVirtualVals[i+1] = MemVirtualVals[i];}
        MemVirtualVals[0] = getMemVirtual();

        // update Disk total bytes values
        for (int i = 9; i >= 0; i--) {DiskTotalVals[i+1] = DiskTotalVals[i];}
        DiskTotalVals[0] = getDiskTotal();

        // update Disk used bytes values
        for (int i = 9; i >= 0; i--) {DiskUsedVals[i+1] = DiskUsedVals[i];}
        DiskUsedVals[0] = getDiskUsed();
    }

    // Getter methods
    public static float[] getCpuUserVals() {return CpuUserVals;}
    public static float[] getCpuSystemVals() {return CpuSystemVals;}
    public static float[] getCpuIdleVals() {return CpuIdleVals;}
    public static float[] getCpuNiceVals() {return CpuNiceVals;}
    public static long[] getMemResidentVals() {return MemResidentVals;}
    public static long[] getMemVirtualVals() {return MemVirtualVals;}
    public static long[] getDiskTotalVals() {return DiskTotalVals;}
    public static long[] getDiskUsedVals() {return DiskUsedVals;}
}