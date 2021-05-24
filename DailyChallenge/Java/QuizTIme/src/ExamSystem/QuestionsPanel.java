package ExamSystem;

import javax.swing.*;
import javax.xml.xpath.XPath;
import java.awt.event.*;
import java.awt.*;
import java.util.ArrayList;

public class QuestionsPanel extends JPanel{
    ArrayList<Question> ques;
    ArrayList<String[]> ans;
    ArrayList<String> correctAns;

    JRadioButton[] options;
    JLabel quesDes;
    JButton submit;
    ButtonGroup bg;
    int quesNo;
    int marks = 0;
    JFrame parentFrame;
    QuestionsPanel(JFrame parent) {
        marks = 0;
        parentFrame = parent;
        defineQuesAns();
        // define the components to be used
        options = new JRadioButton[4];
        submit = new JButton("Submit");
        bg = new ButtonGroup();
        quesDes = new JLabel();
        this.add(quesDes);
        for (int i = 0; i < 4; i++){
            options[i] = new JRadioButton();
            bg.add(options[i]);
            this.add(options[i]);
        }
        this.add(submit);
        // When the user submits
        submit.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                boolean marksGiven = false;
                for (int i = 0; i < 4; i++) {
                    // get the button Selected and then compare the answer
                    System.out.println("" + options[i].isSelected() + " " +
                            correctAns.get(quesNo) + " " +  options[i].getText());
                    if (options[i].isSelected() &&
                            options[i].getText().equals(correctAns.get(quesNo))){
                        marksGiven = true;
                        marks++;
                    }
                }
                bg.clearSelection();
                // Show Dialog to User
                if (marksGiven) {
                    if (quesNo == 3){
                        JOptionPane.showMessageDialog(parentFrame,
                                "<html>Correct Answer<br />Press OK to restart</html>");
                        quesNo = 0;
                        marks = 0;
                    }
                    else {
                        JOptionPane.showMessageDialog(parentFrame, "Correct Answer");
                        quesNo++;
                    }

                }
                else {
                    if (quesNo == 3){
                        JOptionPane.showMessageDialog(parentFrame,
                                "<html>Incorrect Answer<br />Press OK to restart</html>");
                        quesNo = 0;
                        marks = 0;
                    }
                    else {
                        JOptionPane.showMessageDialog(parentFrame, "Wrong Answer");
                        quesNo++;

                    }
                }
                renderQues();


            }
        });
        defineQuesAns();
        beginQuiz();
        this.setSize(400, 400);
        this.setLayout(null);
        this.setVisible(true);
    }

    void defineQuesAns() {
        // Make the ques and answer objects and use them
        ques = new ArrayList<>();
        ans = new ArrayList<>();
        correctAns = new ArrayList<>();
        String[] tempQues = {
                "Who is the father of Java",
                "Which item is used to construct object",
                "Which of the following is not a datatype",
                "Which item is used to construct object",
                "Which of the following is not a datatype",
        };
        String[][] tempAns = {
                {"Tim Cook", "Charles Babbage", "Elon Musk", "James Gosling"},
                {"Method", "Operator", "Constructor", "Variable"},
                {"int", "boolean", "decimal", "float"},
                {"Method", "Operator", "Constructor", "Variable"},
                {"int", "boolean", "decimal", "float"}
        };
        String[] corAns = {
                "James Gosling", "Constructor", "decimal", "Constructor", "decimal"
        };
        for (int i = 0; i < 5; i++){

            Question q = new Question(Question.SINGLE_CORRECT, tempQues[i]);
            ques.add(q);
            ans.add(tempAns[i]);
            correctAns.add(corAns[i]);
        }
    }

    void beginQuiz() {
        // To keep track of positions
        int yPos = 50, xPos = 50, xWidth = 100, yWidth = 30;
        quesDes.setBounds(xPos, yPos, xWidth + 200, yWidth);
        yPos += 35;
        int quesNo = 0; // to keep track of questions
        for (int i = 0; i < 4; i++) {
            options[i].setBounds(xPos, yPos, xWidth + 200, yWidth);
            yPos += 35;
        }
        submit.setBounds(xPos, yPos + 20, xWidth, yWidth);
        // Begin from the first ques
        quesNo = 0;
        renderQues();
    }

    void renderQues() {
        quesDes.setText(ques.get(quesNo).ques);
        for (int i = 0; i < 4; i++) {
            options[i].setText(ans.get(quesNo)[i]);
        }

    }

    void setQuestions() {

    }

    class Question {
        static final int SINGLE_CORRECT = 1;
        static final int MULTI_CORRECT = 2;
        public int type;
        public String ques;
        Question(int type, String ques) {
            this.type = type;
            this.ques = ques;
        }
    }
}
