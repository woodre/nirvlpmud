#define tp this_player()->query_name()
inherit "obj/treasure";
reset(arg)
{   if (arg) return;
   set_id("door");
   set_alias("iron door");
   set_short("A large iron-bound door");
   set_long(
     "A large iron bound door covered with vines.\n");
   set_weight(0);
   set_value(1);
}

init()  {
  ::init();
  add_action("enter_door","open");
        }

enter_door(str)  {
  if(str == "door")  {
  if(present("silver key", this_player()))  {
  call_other(this_player(), "move_player", "through the door#players/saber/dar/rooms/swamp1.c");
  return 1;
        }
  write("You must have the correct key to open the door.\n");
  return 1;
        }
        }

get()  { return 0; }
