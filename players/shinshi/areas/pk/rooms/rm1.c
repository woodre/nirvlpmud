inherit "/players/shinshi/areas/pk/rooms/tourney_room.c";
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
	long_desc =
		"The Colosseum measures fourty-eight meters high, one hundred and eighty-eight\n"+
		"meters long, and one hundred and fifty-six meters wide. The wooden arena floor\n"+
		"is eighty-six meters by fifty-four meters, and covered by sand. Its elliptical\n"+
		"shape keeps the players from retreating to a corner, and allows the spectators\n"+
		"to be closer to the action than a circle would.\n";
		
dest_dir =
({
	"/players/shinshi/areas/pk/rooms/rm2.c",	"east",
	"/players/shinshi/areas/pk/rooms/rm5.c",	"south",
        "/players/shinshi/areas/pk/rooms/rm17.c",       "leave",
});

}

init()
{
  ::init();
  add_action("Cmd_leave","leave");
}

Cmd_leave()
{
  object *ppl;
  int i,x;
  
  x = 0;

  ppl=users();

  if(!this_player()->query_ghost())
  {
    for(i=0; i < sizeof(ppl); i++)
    {
 
      if(environment(ppl[i]) && 
         environment(ppl[i])->pk_tourney() &&
         ppl[i]->query_level() < 20)
      {
        x++;
      }
    }
    if(x > 1)
    {
      write("You cannot leave yet.  Keep fighting!\n");
      return 1;
    }
  }
  return 0;
}