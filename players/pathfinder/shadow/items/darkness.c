int numtimes = 0;
id(str) { return str == "notanobject" || str == "darknessobject"; } 
init() {
  set_light(-1);
  call_out("darkness",1);
}

darkness() {
 if(numtimes < 20) {
  if(random(200) < 20) {
    say("You feel something pass by you in the darkness.\n");
  }
  set_light(-1);
  numtimes++;
  call_out("darkness", 20);
  return 1;
 }
  say("You can see the darkness fading away.\n");
  set_light(1);
  destruct(this_object());
}
