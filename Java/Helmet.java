import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;

public class Helmet 
{
	JFrame f;
	JButton camera, location, health, feedback;
	
	public Helmet(JFrame f, boolean admin)
	{
		this.f = f;
		
		clearFrame();
		
		if (!admin)	// if worker
		{
			helmetWorkerOptions();
			
			camera.addActionListener(new ActionListener(){		// if user chooses camera button
	        	public void actionPerformed(ActionEvent event)
	        	{
	    			
	    			Camera cam = new Camera(f);
	    			cam.on();
	                
	        	}
	        });
			
			location.addActionListener(new ActionListener(){		// if user chooses location button
	        	public void actionPerformed(ActionEvent event)
	        	{
	    			
	    			// call location constructor
	                
	        	}
	        });
			
			health.addActionListener(new ActionListener(){		// if user chooses health button
	        	public void actionPerformed(ActionEvent event)
	        	{
	    			
	    			// call health constructor
	                
	        	}
	        });
			
			feedback.addActionListener(new ActionListener(){		// if user chooses feedback button
	        	public void actionPerformed(ActionEvent event)
	        	{
	    			
	    			// call feedback constructor
	                
	        	}
	        });
		}
		else	// if admin
		{
			displayWorkers();
		}
		
		
	}
	
	public void helmetWorkerOptions()
	{
		// buttons for  options
		camera = new JButton("1. 360 Camera");
		camera.setBounds(125,100,200,30);  
        f.add(camera);
        
        location = new JButton("2. Location");
        location.setBounds(125,150,200,30);  
        f.add(location);
        
        health = new JButton("3. Health Status");
        health.setBounds(125,200,200,30);  
        f.add(health);
        
        feedback = new JButton("4. Feedback");
        feedback.setBounds(125,250,200,30);  
        f.add(feedback);
	}
	
	public void displayWorkers()
    {
		int array[] = new int[5];
        for (int i=0; i<5; i++)
        {
            array[i] = (int) (Math.random() * 2000 + 2000);
        }
        
        JLabel Title = new JLabel("ACTIVE EMPLOYEES");
        Title.setBounds(125, 50, 300, 30);
        Title.setVisible(true);
    	f.add(Title);
        
        JLabel employeesLabel1 = new JLabel("1. Employee ID: " + array[0]);
    	employeesLabel1.setBounds(125, 150, 300, 30);
    	employeesLabel1.setVisible(true);
    	f.add(employeesLabel1);
    	
    	JLabel employeesLabel2 = new JLabel("2. Employee ID: " + array[1]);
    	employeesLabel2.setBounds(125, 200, 300, 30);
    	employeesLabel2.setVisible(true);
    	f.add(employeesLabel2);
    	
    	JLabel employeesLabel3 = new JLabel("3. Employee ID: " + array[2]);
    	employeesLabel3.setBounds(125, 250, 300, 30);
    	employeesLabel3.setVisible(true);
    	f.add(employeesLabel3);
    	
    	JLabel employeesLabel4 = new JLabel("4. Employee ID: " + array[3]);
    	employeesLabel4.setBounds(125, 300, 300, 30);
    	employeesLabel4.setVisible(true);
    	f.add(employeesLabel4);
    	
    	JLabel employeesLabel5 = new JLabel("5. Employee ID: " + array[4]);
    	employeesLabel5.setBounds(125, 350, 300, 30);
    	employeesLabel5.setVisible(true);
    	f.add(employeesLabel5);
    }
	
	public void clearFrame()	// clear all components on frame
	{
		f.getContentPane().removeAll();
		f.validate();
        f.repaint();
	}

}
