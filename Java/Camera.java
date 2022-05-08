import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;


public class Camera 
{
	JFrame f;
	
	public Camera(JFrame f)
	{
		this.f = f;
		clearFrame();
	}
	
	public void on()
	{
		try 
		{
			BufferedImage myPicture = ImageIO.read(new File("/Users/hazemwalidf/Desktop/camera.jpeg"));
			JLabel picLabel = new JLabel(new ImageIcon(myPicture));
			picLabel.setSize(400, 400);
			picLabel.setLayout(null);
			picLabel.setVisible(true);
			f.add(picLabel);
		} 
		catch (IOException e) 
		{
			e.printStackTrace();
		}
		
		
	}
	
	public void clearFrame()	// clear all components on frame
	{
		f.getContentPane().removeAll();
		f.validate();
        f.repaint();
	}
	
}
