inherit "/players/dune/closed/guild/boards/board";
#include "../DEFS.h"

#define BOARD_NAME ALTDUNEPATH+"/boards/guildboard"


status write_lock;


init()
{
  if((string)this_player()->query_guild_name()=="cyberninja" || 
(int)this_player()->query_level() >= 1)
  {
    add_action("read",   "read");
    add_action("read",   "output");
    if (write_lock)
    {
      add_action("writesDisabled", "note");
      add_action("writesDisabled", "remove");
      add_action("writesDisabled", "input");
      add_action("writesDisabled", "erase");
    }
    else
    {
      add_action("new",    "note");
      add_action("remove", "remove");
      add_action("new",    "input");
      add_action("remove", "erase");
    }
  }
}


void description()
{
  write("Before you stands the main guild board.\n");
  write("You glance upon the radiance of a Light Board.\n"+
        "Light Boards are high resolution flat panel displays.\n"+
        "Usage:   'note headline'\n"+
        "         'read messageNumber'\n"+
        "         'remove messageNumber'\n");
}


string short()
{
if(this_player() && ((string) this_player()->query_guild_name() == "cyberninja" || (int)this_player()->query_level() >= 1))
  return ("The "+FUNKYNAME+" Main Light Board(" + num_messages + " msgs)");
  else return 0;
}


void restore_me() { restore_object(BOARD_NAME); }


void save_me(int arg)
{
  object x;
  if(arg)
  {
  call_other(CHANNELD,"overchannel",this_player()->query_name()+" has posted a new note on the guildboard.\n");
  }
  save_object(BOARD_NAME);
  "/players/dune/closed/guild/rooms/guildhall"->load_me();
  "/players/dune/closed/guild/rooms/phase_hall"->load_me();
  if(x = present("board", find_object("/players/dune/closed/guild/rooms/guildhall")))
    x->restore_me();
  if(x = present("board", find_object("/players/dune/closed/guild/rooms/phase_hall")))
    x->restore_me();
}


void disableWrite()
{
  write_lock=1;
}


status writesDisabled()
{
  write("This is a read-only board.\n");
  write("Go to the Drowning Rat if you wish to write on the board.\n");
  return 1;
}
