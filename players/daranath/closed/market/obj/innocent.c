/* Market Value of 1800 coins, available at the Bone Shop for 
   1500 coins AND 1000 credits */

#include <ansi.h>
inherit "/players/daranath/qualtor/newstuff/heals/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;

  set_name("blood of the innocent");
  add_alias("blood");
  add_alias("vial");
  set_short(RED+"Blood of the Innocent"+NORM);
  set_long("In ancient times, the "+RED+"Blood of the Innocent"+NORM+" was used to revive the\n"+
           "spirits and heal the flesh of the faithful, and the practice\n"+
           "continues today. Quite intoxicating once you have a <"+HIR+"drink"+NORM+">.\n");

  set_msg("You raise the "+HIR+"Vial of Blood"+NORM+" to your lips and drink from the\n"+
         "lifeforce of the innocent.\n");
  set_msg2(" takes a drink from a small crystalline vial.\n");
  add_cmd("drink");
  set_type("drink");

  set_heal(50,50);
  set_charges(3);
  set_intox(15);
  set_value(600);
}

query_save_flag(){
  return 1;
  }
