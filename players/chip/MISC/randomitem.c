inherit "/obj/treasure.c";
#include "/players/fred/ansi.h";

reset (arg) {
 set_id("thingy");
 set_short(""+BLINK+"Race Changer Thingy"+NORM+"");
 set_long("This is a little tool that you can use to change\n"+
          "your race.  To use it just 'title_me'.\n");
}

init() {
 ::init();
 add_action("titler","title_me");
 }


titler() {
  this_player()->set_race("GIANT COCK");
  return 1;
}

drop() { return 1;}
