package ExamSystem;

import javax.swing.JFrame;

class ExamFrame extends JFrame{
    ExamFrame() {
        // display title on title bar
        this.setTitle("Exam System");
        // to prevent components from breaking
        this.setResizable(false);
        // to conveniently exit the application
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.add(new ValidationPanel(this));

        this.setSize(400, 400);
        // to adapt the window size according to the subcomponents
        // this.pack();
        this.setLayout(null);
        this.setVisible(true);
        this.setLocationRelativeTo(null);

    }

}
