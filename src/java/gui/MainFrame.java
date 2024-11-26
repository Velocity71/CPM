// MainFrame.java

// Frame used to display metrics values

package src.java.gui;

import src.java.JNI;

import java.awt.Frame;
import java.awt.Graphics;
import java.awt.Color;

// used to graph lines more precisely
import java.awt.Graphics2D;
import java.awt.geom.Line2D;

public class MainFrame extends Frame {
    private static int xSize = 300;
    private static int ySize = 300;

    // Scale used for x and y values
    private static int xScale = xSize/10;
    private static int yScale = ySize/100;

    public MainFrame() {
        setSize(xSize, ySize);
        setUndecorated(true);
        setVisible(true);
    }

    @Override
    public void paint(Graphics g) {
        // Update the metrics every time the frame is painted
        JNI.updateData();
        Graphics2D g2d = (Graphics2D) g;

        // paint y lines
        g.setColor(Color.lightGray);
        for (int y = 0; y < ySize; y += ySize/10) {g.drawLine(0, y, xSize, y);}

        // paint User values
        g.setColor(Color.red);
        drawMetric(g2d, JNI.getCpuUserVals());

        // paint System values
        g.setColor(Color.blue);
        drawMetric(g2d, JNI.getCpuSystemVals());

        // paint Idle values
        g.setColor(Color.orange);
        drawMetric(g2d, JNI.getCpuIdleVals());
    }

    // prints a line of each values from a metric
    private void drawMetric(Graphics2D g2d, float metric[]) {
        for (int i = 1; i <= 10; i++) {
            g2d.draw(new Line2D.Float((i-1)*xScale, transformY(metric[i-1]*yScale), i*xScale, transformY(metric[i]*yScale)));
        }
    }

    // transform the y values from a normal coordinate plane to Java's coordinate plane
    private static float transformY(float y) {return (y - ySize) * -1;}
}