public class GetMetrics {
    public native float getCpuUser();
    public native float getCpuSystem();
    public native float getCpuIdle();
    public native float getCpuNice();
    public native long getMemResident();
    public native long getMemVirtual();
    public native long getDiskTotal();
    public native long getDiskUsed();

    static {System.loadLibrary("Metrics");}

    public static void main(String[] args) {
        GetMetrics metrics = new GetMetrics();
        System.out.println("---CPU LOAD---");
        System.out.println(String.format("User:   %f%%", metrics.getCpuUser()));
        System.out.println(String.format("System: %f%%", metrics.getCpuSystem()));
        System.out.println(String.format("Idle:   %f%%", metrics.getCpuIdle()));
        System.out.println(String.format("Nice:   %f%%", metrics.getCpuNice()));

        System.out.println("---MEMORY USAGE---");
        System.out.println(String.format("Resident (Physical RAM) size: %d bytes", metrics.getMemResident()));
        System.out.println(String.format("Virtual (Virtual RAM) size: %d bytes", metrics.getMemVirtual()));

        System.out.println("---DISK USAGE---");
        System.out.println(String.format("Total Space: %d bytes", metrics.getDiskTotal()));
        System.out.println(String.format("Used Space: %d bytes", metrics.getDiskUsed()));
    }
}