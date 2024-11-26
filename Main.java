// Main.java

import src.java.gui.MainFrame;

import java.util.concurrent.TimeUnit;
import java.lang.InterruptedException;

public class Main {

    public static void main(String[] args) {
    // frame used to display metrics values
    MainFrame mf = new MainFrame();

    // every second repaint the frame;
    for (int i = 1; i <= 10; i++) {
        try {TimeUnit.SECONDS.sleep(1);}
        catch (InterruptedException e) {System.out.println(e);}
        mf.repaint();
    }
}
}