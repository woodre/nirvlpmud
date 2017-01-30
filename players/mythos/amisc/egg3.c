#include "/players/mythos/closed/ansi.h"
#define tp this_player()->query_name()
#define tg this_player()->query_possessive()

inherit "obj/treasure";

reset(arg) {
  if(arg) return;

  set_id("egg");
  set_short("A strange looking egg");
  set_long("A wierd looking egg.  It is a bright "+YEL+"yellow"+NORM+" color.\n"+
  "Legend says that blood must flow to hatch it.\n");
  set_weight(2);
  set_value(10);
}
init() {
  add_action("flow_blood","flow");
}

flow_blood(str) {
  object mon;
  if(str == "blood")  {
  write("You cut your finger and let a few drops of blood drip\n"+
      "down onto the egg.\n");
  say(tp+" cuts "+tg+" and finger and lets the blood drip onto the egg.\n");
  write(HIR+"Drip\n\n");
  write("   Drip\n\n");
  write("      Drip\n\n");
  write("         Drip\n\n");
  write(NORM+"The blood soon covers the egg....THEN....\n");
  write("\n        s  ~  m  ~  o  ~  k  ~  e\n\n");
  write("\n When it all clears you see the egg gone...and in its place is a monster!\n");
  say("\n\n      s  ~  m  ~  o  ~  k  ~  e\n\n");
  say("When it clears.... a monster is in the place where the egg was!\n");
  mon=clone_object("/players/mythos/amon/sean.c");
  move_object(mon,environment(this_object()));
  destruct(this_object());
  return 1;  }
}
