/* Market Value of 2100 coins, available at the Bone Shop for 
   1700 coins AND 1250 credits */

#include <ansi.h>
inherit "/players/daranath/qualtor/newstuff/heals/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;

  set_name("shard of bone");
  add_alias("bone");
  add_alias("shard");
  add_alias("marrow");
  set_short(WHT+"Shard of Bone"+NORM);
  set_long("A small shard of bone, it still has a bit of the marrow inside.\n"+
           "You may <"+HIW+"tear"+NORM+"> at the marrow left on the bone\n");

  set_msg("You tear a piece of the remaining marrow from the "+WHT+"Shard of Bone"+NORM+".\n");
  set_msg2(" takes a bite of something hidden in thier hand.\n");
  add_cmd("tear");
  set_type("bit");

  set_heal(50,50);
  set_charges(3);
  set_soak(12);
  set_value(700);
}

query_save_flag(){
  return 1;
  }
