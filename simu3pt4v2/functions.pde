void initPoints(){
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

void roam(){
  for (Point p : points) {
    p.zPos = p.zPos + random(-1,1);
  }
}

void farN(int index) {
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
      points.get(index).zPos += 0.25;
    }
  }
  if(points.get(index).zPos > newP){
    while(points.get(index).zPos > newP){
      points.get(index).zPos -= 0.25;
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

void calc(){
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
