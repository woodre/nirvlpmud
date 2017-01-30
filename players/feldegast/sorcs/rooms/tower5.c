#include "defs.h"

inherit ROOM;

string intoner;

void reset(int arg)
{
  if(arg) return;
  set_light(1);
  short_desc=TOWER;
  long_desc=
"  This appears to be the residential level of the tower.  A hallway\n\
to the north leads to several rooms.  Seven even evenly spaced mahogany\n\
doors lead into the living quarters of different residents of the\n\
tower.  Interspersed between each of the doors are several paintings.\n\
The door to the southwest is blackened and soot-stained.  A glowing\n\
matrix of protective bonds surrounds it.\n";
  items=({
    "doors","The doors are all identical.  You cannot tell which is which",
    "door","The blackened door looks like it is barely on its hinges, and yet it\n"+
           "is guarded by a powerful magic field",
    "paintings","There are eight paintings",
    "painting 1","This painting is a portrait of the Archmage Myr-Den, the founder of\n"+
                 "the school of sorcery that eventually became known as the Misty Tower",

    "painting 2","This painting portrays the Archmage Myr-Den raising his oaken staff\n"+
                 "high into the air as he summons elementals of earth, air, fire and\n"+
                 "water to create the Misty Tower",
    "painting 3","This painting is entitled 'Field of Flames'.  It depicts the infamous\n"+
                 "sorcerer's duel fought between Alysius Focht and Nephrin the Terramancer.\n"+
                 "At the center of a green valley, the powers of earth and flame meet\n"+
                 "in a maelstrom of carnage",
/* Gimme some ideas, Wocket.  These should pertain to the history of the Misty Tower, or
to any guild related quests. -Feld */
    "painting 4","You don't find this painting very interesting",
    "painting 5","You don't find this painting very interesting",
    "painting 6","You don't find this painting very interesting",
    "painting 7","You don't find this painting very interesting",
    "painting 8","You don't find this painting very interesting",
  });
  dest_dir=({
    ROOMPATH+"tower6.c","up",
    ROOMPATH+"tower4.c","down",
    ROOMDIR+"hallway.c","north", /* Wocket's */
/* These don't necessarily lead anywhere, but are here for future possible guild quests. -F */
    ROOMPATH+"res1.c","northwest",
    ROOMPATH+"res2.c","northeast",
    ROOMPATH+"res3.c","west",
    ROOMPATH+"res4.c","east",
    ROOMPATH+"res5.c","southwest",
    ROOMPATH+"res6.c","south",
    ROOMPATH+"res7.c","southeast",
  });
}
void init() {
  ::init();
  add_action("cmd_block","northwest");
  add_action("cmd_block","northeast");
  add_action("cmd_block","west");
  add_action("cmd_block","east");
  add_action("cmd_block","southeast");
  add_action("cmd_block","south");
  add_action("cmd_sw","southwest");
  add_action("cmd_intone","intone");
}

int cmd_block(string str) {
  write("This door is locked.\n");
  return 1;
}

int cmd_sw(string str) {
  if(intoner==(string)this_player()->query_real_name()) {
    write("You pass through the protective field about the scorched door.\n");
    return (int)::cmd_move(str);
  }
  write("You cannot even approach the magical field.\n");
  return 1;
}

int cmd_intone(string str) {
  if(!str) {
    notify_fail("Intone what?\n");
    return 0;
  }
  write("You intone: "+str+".\n");
  if(str!="kimi-waki-tu-du-la") {
    write("Nothing happens.\n");
    return 1;
  }
  intoner=(string)this_player()->query_real_name();
/*
  write_file(LOGDIR+"quests.log",ctime(time())+" "+intoner+" dispeled the force field.\n");
*/
  write("The protective field about the door fades and seems to lose substance.\n");
  return 1;
}

    
