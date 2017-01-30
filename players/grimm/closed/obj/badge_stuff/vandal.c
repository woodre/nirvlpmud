inherit "/obj/treasure";
int timer;
string nme;
reset(arg) {
  if(arg) return;
  set_id("vandalism");
  if(!nme)
  nme = "Nobody";
  timer = time() + 300;
  set_heart_beat(1);
}

short() {
  return "Vandalism that says: \""+capitalize(nme)+" was here!\"";
}
long() {
  write(short()+"\n");
  return 1;
}

set_nme(str) { nme = str; }
heart_beat() {
  if(timer < time()) {
  say("The vandalism runs down off the wall.\n");
  destruct(this_object());
  return 1;
  }
}

get() { return; }
