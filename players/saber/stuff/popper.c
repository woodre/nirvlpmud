/*
 *  Based on the popper of Merlin aka Ted Spence.
  *  Modified to kingdom come by Saber.
  */

inherit "obj/treasure";
#include "/players/saber/closed/ansi.h"

object streamer;
int i ;

reset(arg)  {
  if(arg) return;
  set_id("popper");
  set_short("A popper");
  set_long("This is your average party popper.  When the string is pulled,\n"+
      "it shoots streamers at your target.  To use, type POP <player>.\n");
        }

init()  {
  ::init();
  add_action("pop","pop");
        }

pop(str)  {
object popat;
string who, color;
  color = HIR+"M"+HIG+"U"+HIY+"L"+HIB+"T"+HIM+"I"+HIC+"C"+HIR+"O"+HIG+"L"+HIY+"O"+HIB+"R"+HIM+"E"+HIC+"D"+NORM;
  if(str != "")  {
    who = lower_case(str);
    popat = find_living(who);
     if(!popat) { write("That is not living.\n"); return 1; }
    if(present(who, environment(this_player())))  {
      while(i<4)  {
      i++;
      streamer = clone_object("/players/saber/stuff/streamer.c");
      transfer(streamer, popat);
        }
  write(color+" streamers fly all over "+str+"!!\n");
  say(this_player()->query_name()+" shoots "+color+" streamers all over "+popat->query_name()+".\n");
  destruct(this_object());
  return 1;
        }
  write("No "+str+" here!\n");
  return 1;
        }
  return 0;
        }
