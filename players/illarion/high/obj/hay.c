inherit "obj/treasure";
#include "/players/illarion/dfns.h"

reset(arg) {
  if(arg) return;

  set_id("hay");
  set_short("Some itchy hay");
    set_long("A clump of hay, relatively clean but quite itchy.\n");  set_value(0);
  set_weight(1);
}
init() {
  ::init();
  add_action("cmd_scratch","scratch");
  if(environment()) set_heart_beat(1);
}
cmd_scratch(string str) {
  if(environment() != TP) return 0;
  if(!str || str !="itch") FAIL("Scratch what?\n");
  write("You scratch the spots the hay makes itch, but get no real\n"+
        "relief.\n");
  say(TPN+" scratches "+TP->query_objective()+"self.\n");
  return 1;
}
drop(int s) {
  if(random(25)) {
    write("You try to brush the hay off, to no avail.\n");
    say(TPN+" brushes "+TP->query_objective()+"self off.\n");
    return 1;
  }
  else
    return 0;
}
heart_beat() {
  if(!environment() || !environment()->query_level()) {
    set_heart_beat(0);
    return;
  }
  if(!random(10))
    tell_object(environment(),"The hay itches uncomfortably.\n");
}
long() {
  ::long();
  if(TP==environment(this_object()))
    write("It is stuck in your clothing, and will be hard to drop.\n");
}
