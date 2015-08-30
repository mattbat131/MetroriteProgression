// import java.awt.BorderLayout;
// import java.net.URL;
// import java.awt.FlowLayout;
// import java.awt.event.*;
// import javax.swing.*;
// public class SlideShowApplet extends JApplet implements ActionListener
// {

//     JLabel display = new JLabel();
    
//     JButton back = new JButton("Back");
//     JButton stop = new JButton("Stop");
//     JButton next = new JButton("Next");
    
//     int currentImage = -1;
//     String images[] = {"image0.jpg", "image1.jpg", "image2.jpg"};

//     public void init()
//     {
//     	  JPanel buttons = new JPanel(new FlowLayout());
//         buttons.add(back);
//         buttons.add(stop);
//         buttons.add(next);
        
//         getContentPane().setLayout(new BorderLayout());
//         getContentPane().add("Center", new JScrollPane(display));
//         getContentPane().add("South", buttons);
        
//         back.addActionListener(this);
//         stop.addActionListener(this);
//         next.addActionListener(this);
//     }

//     public void showCurrentImage()
//     {
//     	display.setIcon(new ImageIcon(images[currentImage]));
//     }
//     public void showNextImage()
//     {
//     	currentImage = currentImage + 1;
//         if (currentImage >= images.length)
//             currentImage = 0;
//         showCurrentImage();
//     }
//     public void showPreviousImage()
//     {
//     	currentImage = currentImage - 1;
//         if (currentImage < 0)
//             currentImage = images.length-1;
//         showCurrentImage();
//     }
    
//     public void actionPerformed(ActionEvent e)
//     {
//     	if (e.getSource() == next)
//             showNextImage();
//         else if (e.getSource() == back)
//             showPreviousImage();
//     }
// }
import java.awt.*;
import java.awt.image.*;
import java.io.*;
import java.applet.*;
public class slideshow extends Applet implements Runnable {
String imgpath;
Thread t;
Image img;
int j=0;
File folder=new File("/mnt/wallpaper/wallpapers");
File[] listoffile=folder.listFiles();
 
public void init()
{
this.setSize(1400,800);
setBackground(Color.red);
}</pre>
<!--more-->
<pre>
public void start()
{
t=new Thread(this);
t.start();
}
 
public void run()
{
 
for(int i=0;i<listoffile.length;i++)
{
if(listoffile[i].isFile())
{
String name=listoffile[i].getName();
int l=name.length();
System.out.println("File "+listoffile[i].getName());
 
//if(name.substring(l-2, l)=="jpg")
//{
img=getImage(getDocumentBase(),listoffile[i].getAbsolutePath());
repaint();
System.out.println("jpg file is "+name);
//}
try{
t.sleep(2000);
 
}catch(InterruptedException e)
{
System.out.println("error");
}
}
else
System.out.println("no "+listoffile[i].getName());
}
 
}
public void paint(Graphics g)
{
 
g.drawImage(img,0,0,this);
}
}
