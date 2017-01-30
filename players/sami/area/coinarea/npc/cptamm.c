inherit "/obj/monster.c";
#include <ansi.h>
#define tpn this_player()->query_name()
#include "/sys/lib.h"

reset(arg) {
  ::reset(arg);
  if(arg) return;
	
  set_name("captain");
  set_alias("captain_1");
  set_race("hologram");
  set_short(""+HIR+"C"+HIB+"aptain"+HIR+" A"+HIB+"merica"+NORM);
  set_long(
    "Americas Hero,"+HIR+" C"+HIB+"aptain"+HIR+" A"+HIB+"merica "+NORM+" in all his glory. Equipped with his\n"+
    " stars and stripes uniform and shield. This is the ultimate"+HIY+" hero"+NORM+".\n"+
    " You notice light pouring out from under his"+HIR+" shield"+NORM+" \n");
  set_level(21);
  set_hp(1200+random(250));
  set_al(-800);
  set_ac(30+random(4));
  set_wc(40);
  set_aggressive(0);
  move_object(clone_object("/players/sami/area/coinarea/obj/barter/projector.c"),this_object());
   move_object(clone_object("/players/sami/area/coinarea/obj/armor/ammshield.c"),this_object());
   init_command("wear shield");
  set_multi_cast(1);
   add_spell("Justice_punch",
HIR+"C"+HIB+"aptain"+NORM+" draws back and unleashes a critical punch to your "+HIY+"H E A D"+NORM+"!!!\n",
  " "+HIR+"C"+HIB+"aptain"+NORM+" lands a critical strike on his attackers "+HIR+"S K U L L"+NORM+".\n",
  50,({15,15}),({"other|light","other|light"}),1);
   add_spell("shield_toss", 
   HIR+"C"+HIB+"aptain "+HIR+" D E S T R O Y S"+NORM+" you with his "+HIB+"S H I E L D"+NORM+" throw.\n"+
"You "+HIY+"burst "+NORM+" into "+HIR+"FLAMES"+NORM+"!\n",
  HIR+"C"+HIB+"aptain "+HIR+" D E S T R O Y S"+NORM+" #TN# with his "+HIB+"S H I E L D"+NORM+" throw.\n",
  60,({45,20}),({"other|fire","other|evil"}),1);
}
