package ExamSystem;

import javax.swing.*;
import java.awt.event.*;
import java.awt.*;
import java.util.ArrayList;


class ValidationPanel extends JPanel{
    String Username = "1";
    String Password = "1";
    static final int SCREEN_WIDTH = 600;
    static final int SCREEN_HEIGHT = 600;
    JPanel acronym;
    JFrame parentFrame;

    ValidationPanel(JFrame parentFrame) {
        // define the label and the text box for the username
        acronym = this;
        this.parentFrame = parentFrame;
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
                    // Procees to the next Panel
                    acronym.setVisible(false);
                    parentFrame.add(new QuestionsPanel());
                }
                else {
                    labelWrongInfo.setText("Invalid Username or Password!");
                    System.out.println("Username: " + Username + " " + textUsername.getText());
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



// class QuestionsPanel extends JPanel{
//     ArrayList<Question> ques;
//     ArrayList<String[]> ans;
//     ArrayList<String> correctAns;

//     QuestionsPanel() {

//         JLabel l1 = new JLabel("HELLO THERE");
//         this.add(l1);
//         this.setBackground(Color.red);
//         this.setSize(400, 400);
//         this.setLayout(null);
//         this.setVisible(true);
//     }

//     void defineQuesAns() {
//         // Make the ques and answer objects and use them
//         ques = new ArrayList<>();
//         ans = new ArrayList<>();
//         correctAns = new ArrayList<>();
//         for (int i = 0; i < 5; i++){
//             String tempQues = "What is your name?";
//             Question q = new Question(Question.SINGLE_CORRECT, tempQues);
//             String[] tempAns = {"M1", "M2", "M3", "M4"};
//             String corAns = M2;
//             ques.add(q);
//             ans.add(tempAns);
//             correctAns.add(corAns);
//         }
//     }

//     class Question {
//         static final int SINGLE_CORRECT = 1;
//         static final int MULTI_CORRECT = 2;
//         public int type;
//         public String ques;
//         Question(int type, String ques) {
//             this.type = type;
//             this.ques = ques;
//         }
//     }
// }
