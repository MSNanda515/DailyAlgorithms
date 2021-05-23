import java.awt.*;
import java.awt.event.*;

// import jdk.internal.org.objectweb.asm.Label;


class SimpleAwt{

    SimpleAwt() {
        Frame f = new Frame("Checkbox Group");
        Label lang = new Label();
        lang.setAlignment(Label.CENTER);
        lang.setSize(300, 100);
        CheckboxGroup gp = new CheckboxGroup();
        Checkbox c1 = new Checkbox("Java", gp, false);
        c1.setBounds(150, 150, 50, 50);
        Checkbox c2 = new Checkbox("C++", gp, false);
        c2.setBounds(150, 250, 50, 50);

        c1.addItemListener(new ItemListener() {
            public void itemStateChanged(ItemEvent e) {
                lang.setText("Java Selected");
            }
        });
        c2.addItemListener(new ItemListener() {
            public void itemStateChanged(ItemEvent e) {
                lang.setText("C++ Selected");
            }
        });

        f.add(lang);
        f.add(c1);
        f.add(c2);
        f.setSize(400, 400);
        f.setLayout(null);
        f.setVisible(true);

    }
    public static void main(String[] args) {
        new SimpleAwt();
        // SimpleAwt f = new SimpleAwt();
        // TextField t1,t2;  
        // t1=new TextField("Welcome to Javatpoint.");  
        // t1.setBounds(50,100, 200,30);  
        // t2=new TextField("AWT Tutorial");  
        // t2.setBounds(50,150, 200,30);  
        // f.add(t1); f.add(t2);  
        // f.setSize(400,400);  
        // f.setLayout(null);  
        // f.setVisible(true);  
    }
}