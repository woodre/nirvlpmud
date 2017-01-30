#include "../defs.h"

inherit ROOM;

string disguise; 
int peeps;

void reset(int arg) {
  if(arg) return;
  set_light(1);
  short_desc=HIM+"A comfortable lamp"+NORM;
  long_desc=
"  This is a cozy little room in vaguely the same shape as a brass\n\
lamp.  There is a teapot on a low circular table that sits in the\n\
middle of the room.  A pointy wizard's hat hangs from a peg on the\n\
wall.  An ivory statue of a nymph sits on a coffee table, and a vase\n\
of flowers sits on the table opposite it.\n";
  items=({
    "room","reflexive",
    "teapot", "A blue teapot with a daisy on the side sits on the table",
    "hat", "A pointy blue wizard's hat hangs from a peg on the wall",
    "statue", "The statue is of a nude nymph, posing modestly",
    "vase", "The blue vase is failed with daisies and wildflowers",
    "table", "There are several tables scattered around the room",
    "tables", "There are several tables scattered around the room",
  });
  dest_dir=({
    ROOMPATH+"lounge.c","leave",
  });
  switch(random(4)) {
    case 0: disguise = "teapot"; break;
    case 1: disguise = "hat"; break;
    case 2: disguise = "statue"; break;
    case 3: disguise = "vase"; break;
  }
}

void init() {
  ::init();
  add_action("cmd_wake","poke");  
  add_action("cmd_wake","prod");  
  add_action("cmd_wake","tickle");  
  add_action("cmd_wake","kick");  
  add_action("cmd_wake","touch");
  if(!find_call_out("chatter"))
    call_out("chatter",3);
  if(this_player()->is_player())
    peeps++;
}

void exit() {
  if(this_player() && this_player()->is_player())
    peeps--;
}

void chatter() {
  if(disguise=="none") return;
  tell_room(this_object(),"You hear giggling from somewhere in the room.\n");
  if(peeps > 0)
    call_out("chatter", 3+random(10));
}

void long(string str) {
  ::long(str);
  if(str==disguise)
    write("A pair of bright red lips grins at you.\n");
}

int cmd_wake(string str) {
  if(disguise=="none") 
    return 0;
  if(str==disguise) {
    write("\nAs you touch the "+str+", it falls to the floor, laughing hard\n"+
          "before it disappears in a flash of light and Mertucio the Enchanter\n"+
          "appears in its place.\n\n");
    say("Mertucio suddenly appears in a flash of light.\n");
    disguise = "none";
    move_object(clone_object(NPCDIR+"mertucio"),this_object());
    return 1;
  }
  write("You "+query_verb()+" the "+str+".  Nothing happens.\n");
  say(TPN+" "+query_verb()+"s the "+str+".\n");
  return 1;
}
