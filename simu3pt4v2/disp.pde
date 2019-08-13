void disp(){
  cam.rotateY(.001);
  background(40);

  pushMatrix();
  translate(75, 75, 0);
  noFill();
  stroke(255,60);
  strokeWeight(2);
  box(300);
  popMatrix();

  for (Point p : points) {    
    strokeWeight(3);
    stroke(240);
    point(p.xPos, p.yPos, p.zPos);
  }
}
