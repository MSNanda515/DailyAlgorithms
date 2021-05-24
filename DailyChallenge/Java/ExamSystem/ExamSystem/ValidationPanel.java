package ExamSystem;
import javax.swing.*;
import java.awt.event.*;
import java.awt.*;

class ValidationPanel extends JPanel{
    String Username = "msnanda";
    String Password = "12345";
    static final int SCREEN_WIDTH = 600;
    static final int SCREEN_HEIGHT = 600;
    ValidationPanel() {
        // define the label and the text box for the username
        JLabel labelUsername = new JLabel("Username");
        labelUsername.setBounds(20, 90, 80, 30);
        JTextField textUsername = new JTextField("");
        textUsername.setBounds(100, 90, 200, 30);
        this.add(labelUsername);
        this.add(textUsername);
        
        // Define the label and text box for the password
        JLabel labelPass = new JLabel("Password");
        labelPass.setBounds(20, 130, 80, 30);
        JPasswordField textPass = new JPasswordField();
        textPass.setBounds(100, 130, 200, 30);
        this.add(labelPass);
        this.add(textPass);

        // Define the label for incorrect password
        JLabel labelWrongInfo = new JLabel();
        labelWrongInfo.setBounds(80, 180, 200, 30);
        this.add(labelWrongInfo);
        labelWrongInfo.setForeground(Color.red);

        // Define the buttons to validate password
        JButton signin = new JButton("Sign In");
        signin.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                if (textUsername.getText().equals(Username) && new String(textPass.getPassword()).equals(Password)){
                    System.out.println("Bye");
                    // Procees to the next Panel
                }
                else {
                    labelWrongInfo.setText("Invalid Username or Password!");
                    System.out.println("Username: " + Username + " " + textUsername.getText());
                    System.out.println("Password: " + Password + " " + new String(textPass.getPassword()));
                }
            }
        });
        signin.setBounds(80, 220, 80, 30);
        this.add(signin);

        this.setBounds(10, 10, 300, 300);
        this.setLayout(null);
        // this.setBounds(100, 100, 100, 100);

    }
}
