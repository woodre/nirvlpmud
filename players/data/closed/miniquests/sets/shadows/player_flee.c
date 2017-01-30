#include "/players/data/defs.h"

int	refreshing;
/*this object prevents the player from fleeing at all while in combat
  while for some reason it must be kept as the first item in the inventory
  so I had to make it constantly refresh, though ive tried to use
  heart_beat, for some reason doesn't work so I use call_out instead, also
  having call_out in the init will for some reason make no_flee not function
  it keeps the item in the top, but while fighting you can still flee, secondly
  having call_out where its at will create two no_flees in the inventory
  so when the player unwields, both have to be destructed. Maybe another
  wizard can help with that.*/



int	needs_refresh;


inherit "/obj/treasure.c";
reset(arg) {
  if(arg) return;
  set_id("no_flee");
  set_weight(0);
  set_value(0);
  call_out("refresh_this", 1);
}

 init() {

 if(this_player()->query_attack())
 {
       add_action("no_flee", "west");
       add_action("no_flee", "east");
       add_action("no_flee", "north");
       add_action("no_flee", "south");
       add_action("no_flee", "northwest");
       add_action("no_flee", "northeast");
       add_action("no_flee", "southwest");
       add_action("no_flee", "southeast");
       add_action("no_flee", "up");
       add_action("no_flee", "down");
       add_action("no_flee", "enter"); 
       add_action("no_flee", "goportal");      
      add_action("no_flee", "pass");      
      add_action("no_flee", "travel");      
      add_action("no_flee", "step");      
      add_action("no_flee", "church");      
      add_action("no_flee", "teleport");      
      add_action("no_flee", "back");      
      add_action("no_flee", "out");      
      add_action("no_flee", "exit");      
      add_action("no_flee", "leave");      
      add_action("no_flee", "around");
       add_action("no_flee", "rat");
      

      }

}

drop() { return 0; }
no_flee()
{
write ("You can't flee from combat!\n");
return 1;
}

refresh_this() 
{
  refresh(this_player());
  call_out("refresh_this", 1);

}
refresh(obj) {
    
    if(first_inventory(obj) != this_object()) 
    move_object(this_object(), this_player());

    return 1;
}


