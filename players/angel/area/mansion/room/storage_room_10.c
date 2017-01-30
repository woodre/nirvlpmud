#include <ansi.h>

inherit "room/room";

int unlocked;

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc = "Storage room";
  long_desc =
"A general storage room. \n";

  items =
  ({
});
  dest_dir =
  ({
    "/players/angel/area/mansion/room/broiler_room_10",   "broiler",
  });
}

init(){ 
  ::init();
    add_action("unlock","unlock");
    add_action("enter","enter");
    this_player()->set_fight_area();
}

exit(){    if(this_player()) this_player()->clear_fight_area();     }

realm(){ return "NT"; }

unlock(str)
{ object door;
  if(str!="door") { write("Open what?\n");
    return 1; }
    if(unlocked) { write("The door is already open!\n");
      return 1;}
      door=present("hiram's key",this_player());
      if(!door) { write("The door must have the correct key to be opened!!!\n");
        return 1; }
        unlocked=1;
        {write("As you unlock the door you hear a loud click.\n");
        items = ({ "door", "An unlocked door, maybe you could enter it"}); 
          return 1;}
}
enter(str)
{   if(str!="door") { write("Enter what?\n");
      return 1; }
      if(!unlocked) { write("The door must have the correct key to be opened!!!\n");
        return 1; }
        write("You enter the storage room and see what looks like a mason shrine.\n");
        this_player()->move_player("enter#"+"/players/angel/area/mansion/room/storage_room_11");
        return 1;
}