object room;

status start(object r) {
  if(!r) return 0;  
  room = r;
  shadow(room,1);
  return 1;
}

void init() {}

status stop() {
  shadow(room,0);
}