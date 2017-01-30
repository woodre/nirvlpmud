#include "defs.h"

inherit ROOM;

void reset(int arg) {
  object guard;
  if(!present("goldcloak")) {
    move_object(clone_object(MON_PATH+"goldcloak.c"),this_object());
    guard=clone_object(MON_PATH+"goldcloak.c");
    guard->load_chat("The Goldcloak asks: What are you doing here?\n");
    move_object(guard,this_object());
  }
  if(arg) return;
  set_light(1);
  short_desc="Tower of the Righteous";
  long_desc = 
    "  This is the common room of the guards.  A large table with some\n"+
    "cards and chips scattered around it is in the center of the room.\n"+
    "A couple of paintings are on the wall.  On one side of a hearth, a\n"+
    "flight of stone stairs leads up, and on the other side a stairwell\n"+
    "leads down.\n";
  items=({
    "table", "A long table made out of oak with some cards and\n"+
             "wooden chips scattered on it",
    "cards", "A few hand-painted cards",
    "chips", "Wooden chips, used to keep track of who's winning",
    "paintings", "The painting on the north wall is of the Sultan and\n"+
                 "the painting on the south wall is of Sudakan as seen\n"+
                 "from the desert",
    "hearth", "The heart is not lit, it is too hot today",
    "stairs", "A flight of stone stairs lead up",
    "stairwell", "The stairs lead down into the dungeon",
  });
  dest_dir=({
    PATH+"barrack1.c","west",
    PATH+"barrack3.c","up",
    PATH+"barrack0.c","down",
  });
}

void init() {
  ::init();
  add_action("cmd_block","down");
  add_action("cmd_block","up");
}

int cmd_block(string str) {
  if(present("goldcloak")) {
    write("The guard asks: Where do you think YOU'RE going?\n");
    return 1;
  }
}
