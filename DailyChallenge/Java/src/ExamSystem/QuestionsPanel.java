package ExamSystem;

import javax.swing.*;
import java.awt.event.*;
import java.awt.*;
import java.util.ArrayList;

public class QuestionsPanel extends JPanel{
    ArrayList<Question> ques;
    ArrayList<String[]> ans;
    ArrayList<String> correctAns;

    QuestionsPanel() {
        defineQuesAns();
        int i = 0;
        // define the components to be used
        JRadioButton[] options = new JRadioButton[4];
        JButton submit = new JButton("Submit");


        this.setSize(400, 400);
        this.setLayout(null);
        this.setVisible(true);
    }

    void defineQuesAns() {
        // Make the ques and answer objects and use them
        ques = new ArrayList<>();
        ans = new ArrayList<>();
        correctAns = new ArrayList<>();
        for (int i = 0; i < 5; i++){
            String tempQues = "What is your name?";
            Question q = new Question(Question.SINGLE_CORRECT, tempQues);
            String[] tempAns = {"M1", "M2", "M3", "M4"};
            String corAns = "M2";
            ques.add(q);
            ans.add(tempAns);
            correctAns.add(corAns);
        }
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
