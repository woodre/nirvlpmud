/* Test cloning object */

inherit "obj/treasure";

reset(arg)  {
  if(arg) return;

   set_id("board");
   set_short("Bulletin Board");
   set_long("This is a bulletin board that clones a mob elsewhere.\n");
   set_weight(1);
   set_value(50);
   move_object(clone_object("/players/aingeal/casino/NPC/elvis.c"),"/players/boltar/casino/hall1e1.c");
}

