#include "/players/feldegast/defines.h"
inherit ROOM;

int warded;

reset(arg) {
  if(arg) return;
  short_desc="A subterranean cave";
  long_desc=
"  This is a subterranean cave deep beneath the Crystal Tower.  Powerful\n"+
"runes of protection are etched with glowing lines of force into the\n"+
"surrounding rock.  White candles are placed on the floor and on\n"+
"several rocks, casting flickering shadows.  A rough staircase, cut\n"+
"from the cave wall leads back up to the tower.\n";
  set_light(1);
  dest_dir=({
    "/players/feldegast/closed/tower/study.c","east"
  });
}
init() {
  ::init();
  if(TPRN!="Feldegast") {
    write("The cave's magical wards flare brightly as they envelop you.\n");
    tell_room(this_object(),TPRN+" is enveloped in flames erupting from the cave's runes.\n");
    destruct(TP);
  }
  add_action("cmd_runes","runes");
}
cmd_runes() {
  if(warded)
    write("You break the key rune etched into the center of the chamber, thus\n"+
          "breaking the ward which sealed this chamber.\n");
  else
    write("You complete the key rune etched into the center of the chamber, thus\n"+
          "invoking the ward which now seals this chamber.\n");
  warded=!warded;
  return 1;
}
exit() {
  return warded?clone_object("blah"):0;
}
