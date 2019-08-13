import processing.core.*; 
import processing.data.*; 
import processing.event.*; 
import processing.opengl.*; 

import peasy.PeasyCam; 
import processing.serial.*; 

import java.util.HashMap; 
import java.util.ArrayList; 
import java.io.File; 
import java.io.BufferedReader; 
import java.io.PrintWriter; 
import java.io.InputStream; 
import java.io.OutputStream; 
import java.io.IOException; 

public class simu3pt4v2 extends PApplet {




Serial myPort;
PeasyCam cam;

ArrayList<Point> points = new ArrayList<Point>();
int xOff = 50;
int yOff = 50;
int offset = 50;

FloatList dist;
int furthest;
int count = 0;
int rCount = 0;
int bounding = 100;
int pointNum = 5;
int gridOffset = 8;

public void setup(){
  // size(800,800,P3D);
  
  cam = new PeasyCam(this, 400);
  cam.rotateX(radians(90));
  dist = new FloatList();
  initPoints();

  String portName = Serial.list()[1];
  println(portName);
  myPort = new Serial(this, portName, 9600);
  myPort.clear();
}

public void draw(){
  disp();
  calc();
}
public void disp(){
  cam.rotateY(.001f);
  background(40);

  pushMatrix();
  translate(75, 75, 0);
  noFill();
  stroke(255,60);
  strokeWeight(2);
  box(300);
  popMatrix();

  for (Point p : points) {
    if(p.index == 1){
      strokeWeight(3);
      stroke(240);
      point(p.xPos, p.yPos, p.zPos);
    }
  }
}
public void initPoints(){
  int index = 0;
  for(int i = 1; i<6; i++){
    for(int j = 1; j<5; j++){
      PVector pos = new PVector((xOff*i)-offset,(yOff*j)-offset, 0);
      Point p = new Point();
      p.xPos = pos.x;
      p.yPos = pos.y;
      p.zPos = pos.z;
      p.lastZ = pos.z;
      p.index = index;
      points.add(p);
      index++;
    }
  }
}

public void roam(){
  for (Point p : points) {
    p.zPos = p.zPos + random(-1,1);
  }
}

public void farN(int index) {
  for (int i=index; i<index+1; i++) {
    for (Point p : points) {
      if (p.index != points.get(i).index) {
        float d = dist(points.get(i).xPos, points.get(i).yPos, points.get(i).yPos,
          p.xPos, p.yPos, p.zPos);
        p.distToCurrent = d;
        dist.append(d);
      }
    }
  }

  float max = dist.max();

  dist.clear();

  for (Point p : points) {
    if (p.distToCurrent == max) {
      furthest = p.index;
    }
  }
  // points.get(index).xPos = points.get(furthest).xPos + random(10, 20);
  // points.get(index).yPos = points.get(furthest).yPos + random(10, 20);
  float newP = points.get(furthest).zPos + random(10, 20);
  // points.get(index).zPos = points.get(furthest).zPos + random(10, 20);
  if(points.get(index).zPos < newP){
    while(points.get(index).zPos < newP){
      points.get(index).zPos += 0.25f;
    }
  }
  if(points.get(index).zPos > newP){
    while(points.get(index).zPos > newP){
      points.get(index).zPos -= 0.25f;
    }
  }

  for (Point p : points) {
    if (p.zPos <= bounding*-1 || p.zPos >= bounding ) {

      PVector rand = new PVector(random(-bounding, bounding), random(-bounding, bounding), random(-bounding, bounding));
      // p.xPos = rand.x;
      // p.yPos = rand.y;
      p.zPos = rand.z;
    }
    p.steps = p.zPos - p.lastZ;
  }

}

public void calc(){
  if (frameCount % 100 == 0) {
    if (count >= points.size()) {
      count = 0;
    }
    farN(count);
    int sI = round(points.get(count).steps) * 100;
    String s = str(sI);
    myPort.write(s+'\n');
    if(count == 1){
      println(s);
    }

    count++;
  }
}
class Point{
  int index;
  float cXa, cXb, cYa, cYb, cZa, cZb;
  float xOrig, yOrig, zOrig;
  float xPos, yPos, zPos;
  float lastZ, steps;
  float distToCurrent;

  Point(){

  }

}
  public void settings() {  fullScreen(P3D); }
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "simu3pt4v2" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
