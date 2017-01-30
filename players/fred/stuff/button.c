#include "/players/fred/ansi.h"
inherit "/obj/treasure";

reset (arg){
  set_id("button");
  set_short("A magical button");
  set_long(
     "  A magical button that will make you a Knight.  Just type join.\n");
  set_weight(1);
  set_value(0);
}

init(){
  ::init();
    add_action("Cmd_join","join");
}

Cmd_join()
{
object spbrd;
  this_player()->add_guild_rank(1);
  this_player()->add_guild_exp(1);
  this_player()->set_guild_file("players/boltar/templar/templar");
  if(this_player()->query_attrib("ste") > 20 ) this_player()->set_attrib("ste", 20);
  if(this_player()->query_attrib("mag") > 25) this_player()->set_attrib("mag", 25);
  call_other(this_player(),"reset",1);
  call_other(this_player(),"save_me",0);
  spbrd=call_other("/players/boltar/templar/sponsorroom","query_board",0);
  spbrd->remove_entry(this_player()->query_real_name());
  write("You take a giant step through the giant arch of the Knights Templar.\n");
  write("You feel a tingle as your attributes are adjusted to match the Knights.\n");
  move_object(clone_object("players/boltar/templar/templar"), this_player());
  write("Congratulations on joining the Knights Templar!\n");
  write("You are given your cross as a symbol of your membership.\n");
  command("fixtitle", this_player());
  new_shout(this_player()->query_name()+" has just joined the Knights Templar.\n");
  return 1;
}
