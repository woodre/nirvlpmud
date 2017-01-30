inherit "room/room";
#include "../DEFS.h"


init()
{
  ::init();
  if (this_player()->is_player())
  {
    /* So that Bannock does not get bothered by this guild again.-Snow */
    if(query_ip_number(this_player()) == "134.129.239.13")
    {
      move_object(this_player(),"/room/church");
    }
    if (this_player()->query_guild_name() != "cyberninja" &&
       this_player()->query_level() < 20 && !present(RECRUIT, this_player()))
    {
      tell_object(this_player(),REV_RED+"\tYou sense a spacial displacement.\n"+OFF);
      move_object(this_player(), "players/snow/ROOMS/tundra/tundra_ice");
      return;
    }

    /* Because wiz tools cannot auto-load, give Dune his tool upon startup */
    if ((string)this_player()->query_real_name() == "dune")
    {
      if (!present("spice", this_player()))
      {
        move_object(clone_object("/players/dune/closed/spice.c"), this_player());
      }
    }
  }
}


reset(arg)
{
  object boardOb;

  if (!present("terminal"))
  {
    boardOb = clone_object(BOARDDIR+"/guildboard.c");
    boardOb->disableWrite();
    move_object(boardOb, this_object());
  }

  if(!arg)
  {
    set_light(1);
    short_desc=FUNKYNAME+" Main Guild Hall";
    long_desc=
"     The Grand Hall of the "+FUNKYNAME+" lies before you.\n"+
"Columns of raging fire stand along the sides of the black\n"+
"marble floor.  Gigantic red statues of past ninja warriors\n"+
"cast their flickering shadows upon the high white walls.\n"+
"The Hall is circular in shape, with the ceiling tapering to\n"+
"a glass dome overhead.\n";

    items=({
"fire", "The blazing fire shoots from the top of the columns",
"columns","Several large marble columns encircle the center of the room",
"floor","The black marble floor shines with a polished surface",
"statues","The statues stand over 20 feet high, near each column",
"ceiling","The ceiling opens up into a glass viewing window",
"dome","The glass dome gives you a clear view of the sky outside",
    });

    dest_dir=({
    ROOMDIR + "/hallway1.c", "north",
    ROOMDIR + "/entrance.c", "east",
    ROOMDIR + "/hallway2.c", "west",
    ROOMDIR + "/teleport.c", "up",
    ROOMDIR + "/archives.c", "down", 
    });
  }
}


realm() { return "NT"; }
feel() { return "no"; }
