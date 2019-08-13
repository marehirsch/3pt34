import peasy.PeasyCam;
import processing.serial.*;

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

void setup(){
  // size(800,800,P3D);
  fullScreen(P3D);
  cam = new PeasyCam(this, 400);
  cam.rotateX(radians(90));
  dist = new FloatList();
  initPoints();

  String portName = Serial.list()[1];
  println(portName);
  myPort = new Serial(this, portName, 9600);
  myPort.clear();
}

void draw(){
  disp();
  calc();
}
