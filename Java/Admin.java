import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;

public class Admin implements User
{
	JFrame f;
	JButton projects, helmet, reports;
	
	public Admin(JFrame f)
	{
		this.f = f;
		
		options();
	}

	@Override
	public void options() 
	{
		displayOptions();
		
		projects.addActionListener(new ActionListener(){		// if user chooses projects button
        	public void actionPerformed(ActionEvent event)
        	{
    			
    			// call projects constructor
                
        	}
        });
		
		helmet.addActionListener(new ActionListener(){		// if user chooses helmet button
        	public void actionPerformed(ActionEvent event)
        	{
    			
    			Helmet helmet = new Helmet(f, true);
                
        	}
        });
		
		reports.addActionListener(new ActionListener(){		// if user chooses reports button
        	public void actionPerformed(ActionEvent event)
        	{
    			
    			// call reports constructor
                
        	}
        });
		
	}
	
	public void displayOptions()
	{
		// buttons for options
		projects = new JButton("1. Projects");
		projects.setBounds(125,100,200,30);  
        f.add(projects);
        
        helmet = new JButton("2. Smart Helmet");
        helmet.setBounds(125,150,200,30);  
        f.add(helmet);
        
        reports = new JButton("3. Reports");
        reports.setBounds(125,200,200,30);  
        f.add(reports);
	}
	
	public void clearFrame()	// clear all components on frame
	{
		f.getContentPane().removeAll();
		f.validate();
        f.repaint();
	}
	
	
}
