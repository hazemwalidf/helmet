import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;

public class App
{
	JLabel startup1_label, startup2_label;
	JFrame f;
	JButton cont;
	JButton camera, location, health, feedback;
	
	String path = "/Users/hazemwalidf/Desktop/users.csv";

	public App()
	{
		startup();
		Authorize a = new Authorize(f, cont, path);
		
	}
	
	public void startup()
	{
		f = new JFrame("HELMET APP");
		f.setSize(500, 800);  
        f.setLocationRelativeTo(null);  
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);  
        f.setVisible(true);  
		
		startup1_label = new JLabel("Welcome, to the Smart Helmet App");
		startup1_label.setBounds(125, 100, 300, 30);
		f.add(startup1_label);
		startup1_label.setVisible(true);
		
		startup2_label = new JLabel("Press Next to Continue");
		startup2_label.setBounds(125, 150, 300, 30);
		f.add(startup2_label);
		startup2_label.setVisible(true);
		
		cont = new JButton("Next");
		cont.setBounds(125,200,95,30);  
		f.setLayout(null);
        f.add(cont);
	}
}

