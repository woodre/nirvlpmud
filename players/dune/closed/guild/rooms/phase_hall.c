inherit "/players/dune/closed/guild/rooms/room";
#include "../DEFS.h"


init()
{
  ::init();
  if(this_player()->is_player())
  {
    if(this_player()->query_guild_name() != "cyberninja" &&
       this_player()->query_level() < 20 && !present(RECRUIT, this_player()))
    {
      call_out("alert", 1, this_player());
      return;
    }
  }
}


/* This function can be made more specific, as desired. -Snow */
alert(object player)
{
  string msg, name;
  int lv, xlv;
name = capitalize(player->query_real_name());
  lv = player->query_level();
  xlv = player->query_extra_level();
  if (lv >= 21)
  {
    /* invading wizzes are ignored */
    return;
  }
  else if (lv == 19 && xlv > 0)
  {
    msg = "ATTENTION, SECURITY BREACH: "+name+" ("+lv+"+"+xlv+")";
  }
  else
  {
    msg = "ATTENTION, SECURITY BREACH: "+name+" ("+lv+")";
  }
  call_other(CHANNELD, "daemontell", msg);
  return 1;
}


reset(arg)
{
  object boardOb;

/* board reinstated by wocket 11/99.  changes where made to insure it is not misused. */
/* Phase Hall does not have a board due to conflicts.  Players will use the
   board at login or not at all. -Snow 11/99 */
#ifdef __LDMUD__
/* add back if mysql is implemented */
if(!present("board") && 1 == 2)
move_object(clone_object("/players/mokri/cybers/obj/ld_board"),this_object());
#endif
#ifndef __LDMUD__
  if (!present("terminal"))
  {
    boardOb = clone_object(BOARDDIR+"/guildboard.c");
    boardOb->disableWrite();
    move_object(boardOb, this_object());
  }
#endif

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
