import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPasswordField;
import javax.swing.JTextField;

public class Authorize 
{
	int wrong_counter;
	JFrame f;
	JTextField username;
	JPasswordField password;
	JButton submit;
	JLabel wrong_input_label, counter_label, ending_label;
	String path, user;

	public Authorize(JFrame f, JButton cont, String path)
	{
		this.f = f;
		this.path = path;
		
		cont.addActionListener(new ActionListener()
		{
			@Override
			public void actionPerformed(ActionEvent e) 
			{
				login_page();
				login();
			}
			
		});
	}
	
	public void clearFrame()	// clear all components on frame
	{
		f.getContentPane().removeAll();
		f.validate();
        f.repaint();
	}
	
	public void login_page()	// constructor
	{
		clearFrame();
		wrong_counter = 0;		// set wrong trials counter to zero at start

		username=new JTextField("Username");  // username text field
    	username.setBounds(125,100, 200, 30);  
    	f.add(username); 
    	
    	password = new JPasswordField("123456");  // password field
    	password.setBounds(125, 150, 200, 30);  
    	f.add(password); 
    	
    	submit = new JButton("Submit");		// submit button
        submit.setBounds(125,200,95,30);  
        f.add(submit);  
        
        wrong_input_label = new JLabel("Invalid username or password. Please try again."); 		// in case of wrong input
		wrong_input_label.setBounds(125, 250, 300, 30); 
		f.add(wrong_input_label);
		wrong_input_label.setVisible(false);
		
		counter_label = new JLabel("Remaining trials: " + (3 - wrong_counter)); 
		counter_label.setBounds(125, 275, 300, 30); 
		f.add(counter_label);
		counter_label.setVisible(false);
	}
	
	void login()
	{
		submit.addActionListener(new ActionListener()
		{
			@Override
			public void actionPerformed(ActionEvent e) 
			{
				if (wrong_counter < 3)		// if login trials not 3
        		{
        			user = username.getText();
	        		String pass = password.getText();
	        		
	        		if (authenticate(user, pass))
	        		{
	        			String t1 = "Admin";
	        			String t2 = "Worker";
	        			if (getRole(user).equals(t1))
	    				{
	        				clearFrame();
	    					Admin admin = new Admin(f);
	    				}
	    				else if (getRole(user).equals(t2))
	    				{
	    					clearFrame();
	    					Worker worker = new Worker(f);
	    				}
	        		}
	        		else 	// wrong login attempt
	        		{
	        			wrong_input_label.setVisible(true);
	        			wrong_counter++;
	        			counter_label.setVisible(true);
	        			counter_label.setText("Remaining trials: " + (3 - wrong_counter));
	        		}
	        		
	        		
        		}
				else		// if 3 wrong login attempts
        		{
        			clearFrame();
        			display_notrials();
        			System.exit(0);
        			
        		}
				
			}
			
		});
	}
	
	boolean authenticate(String username, String password)
	{
		String line = "";  
		String splitBy = ",";  
		try   
		{   
			BufferedReader br = new BufferedReader(new FileReader(path));  
			while ((line = br.readLine()) != null)
			{  
				String[] AccountInfo = line.split(splitBy);
				
				if (username.equals(AccountInfo[1]) && password.equals(AccountInfo[2]))		// if username and password match
				{
					return true;
				}
			}
			return false;
		}   
		catch (IOException e)   
		{  
			e.printStackTrace();
			return false;
		}
		
	}
	
	public void display_notrials()		// display message for wrong trials
	{
		ending_label = new JLabel("Sorry. You do not have any more trials.");
        ending_label.setBounds(125, 150, 300, 30); 
		f.add(ending_label);
		ending_label.setVisible(true);
	}
	
	public String getRole(String username)
	{
		String line = "";  
		String splitBy = ",";  
		try   
		{   
			BufferedReader br = new BufferedReader(new FileReader(path));  
			while ((line = br.readLine()) != null)
			{  
				String[] AccountInfo = line.split(splitBy);
				
				if (username.equals(AccountInfo[1]))
				{
					return AccountInfo[4];
				}
			}
		}   
		catch (IOException e)   
		{  
			e.printStackTrace();
		}
		
		return "";
	}
	
	

}
