inherit "/obj/monster.c";
#include <ansi.h>
#define TPN this_player()->query_name()
#include "/sys/lib.h"
reset(arg) {
  ::reset(arg);
  if(arg) return;
	
  set_name("batman");
  set_alias("batman_1");
  set_race("hologram");
  set_short(""+HIK+"Batman"+NORM);
  set_long(
    " It's"+HIK+" Batman"+NORM+". Dressed in his traditional black and grey suit with\n"+
    " his yellow utility belt. This man does not look like someone to\n"+
    " mess with.\n");
  set_level(21);
  set_hp(1200+random(250));
  set_al(-800);
  set_ac(30+random(4));
  set_wc(40);
  set_aggressive(0);
 move_object(clone_object("/players/sami/area/coinarea/obj/barter/projector.c"),this_object());
   move_object(clone_object("/players/sami/area/coinarea/obj/armor/ubelt.c"),this_object());
   init_command("wear belt");
  set_multi_cast(2);
  
  add_spell("hook_shot",
  ""+HIK+"Batman"+NORM+" takes out his hookshot and shoots you with deadly"+HIY+" precision"+NORM+".\n",
  " "+HIK+"Batman"+NORM+" shoots his hookshot at #TN# and #TN# falls cracking their "+HIR+"S K U L L"+NORM+".\n",
  50,({25,25}),({"other|physical","other|light"}),1);
   
   add_spell("bat_stars", 
   ""+HIK+" #MN# "+NORM+" throws some bat shaped "+HIB+"B A T E R A N G S"+NORM+" at "+HIK+"YOU"+NORM+" with skill.\n"+
  "                    You"+HIY+" Flop "+NORM+"on the ground in "+HIR+"A G O N Y "+NORM+"\n", 
  ""+HIK+"#MN#"+NORM+" throws "+HIB+"B A T E R A N G S"+NORM+" at #TN# with deadly precision.\n",
  30,({45,20}),({"other|physical","other|light"}),1);
   }
