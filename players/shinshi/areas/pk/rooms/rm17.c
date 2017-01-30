inherit "/room/room";
#include <ansi.h>

object *rooms;

reset(arg)
{
::reset(arg);

if(arg) return;

        rooms = ({
          "/players/shinshi/areas/pk/rooms/rm1.c",
          "/players/shinshi/areas/pk/rooms/rm2.c",
          "/players/shinshi/areas/pk/rooms/rm3.c",
          "/players/shinshi/areas/pk/rooms/rm4.c",
          "/players/shinshi/areas/pk/rooms/rm5.c",
          "/players/shinshi/areas/pk/rooms/rm6.c",
          "/players/shinshi/areas/pk/rooms/rm7.c",
          "/players/shinshi/areas/pk/rooms/rm8.c",
          "/players/shinshi/areas/pk/rooms/rm9.c",
          "/players/shinshi/areas/pk/rooms/rm10.c",
          "/players/shinshi/areas/pk/rooms/rm11.c",
          "/players/shinshi/areas/pk/rooms/rm12.c",
          "/players/shinshi/areas/pk/rooms/rm13.c",
          "/players/shinshi/areas/pk/rooms/rm14.c",
          "/players/shinshi/areas/pk/rooms/rm15.c",
          "/players/shinshi/areas/pk/rooms/rm16.c",
        });

	set_light(1);
	short_desc = HIK+"Tournament Reclaim Room"+NORM;
	long_desc =
		"There is not much in this room outside of some random stuff strewn about.\n";
		
dest_dir =
({
	"/room/vill_green.c",	"green",
});

}

init()
{
  ::init();
  
  if(this_player() && this_player()->query_ghost())
  {
    tell_object(this_player(),
      "Thank you for participating in the PK Tournament!\n"+
      "Please type 'pray' to be revived.\n\n"+
      "Once you are revived you can type 'reclaim' to claim your gear.\n");
  }  

  add_action("Cmd_pray","pray");
  add_action("Cmd_reclaim","reclaim");
}

Cmd_pray()
{
  if(this_player()->query_ghost())
  {
    call_other(this_player(), "remove_ghost_finish", 0);
    return 1;
  }
}

Cmd_reclaim()
{
  object *obj, *cobj; 
  object it, thing;
  int a,b,c,d;

  if(this_player()->query_ghost())
  {
    write("You should pray first.\n");
    return 1;
  }

  for(a=0; a < 16; a++)
  {

    it = first_inventory(rooms[a]);
    while(it)
    {
      thing = next_inventory(it);
      
      if(it->is_corpse())
      {
         
        if(it->query_name() == this_player()->query_real_name())
        {
              
          cobj = deep_inventory(it);
            
          for(d=0; d < sizeof(cobj); d++)
          {
         
            if(cobj[d]->is_heal())
            move_object(cobj[d], rooms[a]);
          }
        move_object(it, this_player());  
        tell_object(this_player(),
          "A tournament official enters the room and hands you your corpse\n"+
          "before leaving.\n");
        return 1;
        }
      }
    it = thing;
    }
  }
  tell_object(this_player(),
    "Your corpse could not be located.  Please contact the Tournament Official.\n");
  return 1;
}           

Cmd_loot_corpse()
{
  object *obj, *cobj; 
  object it, thing;
  int a,b,c,d;

  for(a=0; a < 16; a++)
  {

    it = first_inventory(rooms[a]);
    while(it)
    {
      thing = next_inventory(it);
      
      if(it->is_corpse())
      {
         
        cobj = deep_inventory(it);
            
        for(d=0; d < sizeof(cobj); d++)
        {
         
          if(cobj[d]->is_heal())
          move_object(cobj[d], rooms[a]);
        }
      }
    it = thing;
    }
  }
  return 1;
}           