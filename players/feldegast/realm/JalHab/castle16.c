#include "defs.h"

inherit ROOM;

int taken; /* 0 = untaken, 1 = guardian spirit, 2 = taken */
int field; /* 0 = on, 1 = off */

void reset(int arg) {
  if(arg) return;
  set_light(1);
  short_desc=BOLD+BLK+"Castle Magnarn"+NORM;
  long_desc=
"  This room is a hexagon shaped vault with script on each wall\n"+
"indicating danger in six different languages.  In the center of the\n"+
"chamber is a pedestal with a glowing sphere on it.\n";
  items=({
    "vault","reflexive",
    "script", "You can understand some of the script.  The best translation would be,\n"+
              "\"Do not touch\"",
    "pedestal", "The pedestal is about waist-height, and constructed of gray marble.\n"+
                "There is a softly glowing field of some sort surrounding it, and a\n"+
                "golden indentation of some sort on the side.  If you had the key for\n"+
                "it, then you could insert it",
    "sphere", "There is a softly glowing sphere on the pedestal that you can 'grasp'",
  });
  dest_dir=({
    PATH+"castle8.c","west",
    PATH+"castle11.c","east",
  });
}

void init() {
  ::init();
  add_action("cmd_grasp", "grasp");
  add_action("cmd_unlock", "insert");
}

int cmd_unlock(string str) {
  object seal;
  if(str!="seal" && str!="key") {
    notify_fail("Insert what?\n");
    return 0;
  }
  seal=present("castle%magnarn%golden%seal",TP);
  if(!seal) {
    notify_fail("It doesn't fit.\n");
    return 0;
  }
  destruct(seal);
  TP->add_weight(-1);
  write("The field surrounding the pedestal disappears, revealing a\n"+
        "dark sphere.\n");
  items[5]="The pedestal is about waist-height, and constructed of gray marble.\n"+
           "There is a sphere sitting upon the pedestal";
  field=1;
  return 1;
}

int cmd_grasp(string str) {
  if(str!="sphere" && str!="soulstone" && str!="stone") {
    notify_fail("Grasp what?\n");
    return 0;
  }
  if(taken == 2) return 0;
  if(!field) {
    write(HIB+"The glowing field shocks you.\n"+NORM);
    TP->hit_player(15);
    return 1;
  }
  if(present("mardok")) {
    write("The guardian spirit prevents you.\n");
    return 1;
  }
  if(!taken) {
    move_object(clone_object(MON_PATH+"mardok.c"),this_object());
    tell_room(this_object(),"As "+TPN+" reaches for the stone, a strange, etheriel creature coalesces\n"+
                            "from the air itself.\n");
    taken=1;
    return 1;
  }
  write("You take the soulstone from the pedestal.\n");
  say(TPN+" takes the soulstone from the pedestal.\n");
  move_object(clone_object(OBJ_PATH+"soulstone.c"),TP);
present("soulstone",TP)->set_power(200);
  TP->add_weight(1);
  long_desc=
"  This room is a hexagon shaped vault with script on each wall\n"+
"indicating danger in six different languages.  In the center of the\n"+
"chamber is a pedestal.\n";
  items-=({ items[7] });
  items-=({ items[6] });
  items[5]="The pedestal is about waist-height, and constructed of gray marble";
  taken=2;
  return 1;
}
