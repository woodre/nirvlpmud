#include "/players/wizardchild/toys/color.h"
short() { return "A firework (BIG)"; }
long() {
  write("An ENORMOUS firework. Type \"light firework\"\n");
  write("to light it. Remember to drop it after that...\n");
}
id(str) { return str == "firework" || str == "big firework"; }
get() { return 1; }
init() { add_action("light", "light"); }
light(str) {
  if(!id(str)) return 0;
  write("You light the firework!\n");
  say(this_player()->query_name()+" lights a firework!\n");
  call_out("explode", 8);
  return 1;
}
explode() {
  int i,x;
  say("The firework EXPLODES!!!!\n");
  for(x = 0; x < 80; x++) {
    i = 31+random(5);
    say(SPACE()+(esc+"["+i+"m")+"POW!"+END);
  }
}
SPACE() {
  string s;
  int i,x;
  i = random(5)+1;
  for(x = 0; x < i; x++)
    if(!s) s= " "; else s += " ";
  return s;
}
