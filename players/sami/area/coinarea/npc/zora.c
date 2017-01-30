inherit "/obj/monster.c";
#include <ansi.h>
#define tpn this_player()->query_name()
#include "/sys/lib.h"

reset(arg) {
  ::reset(arg);
  if(arg) return;
	
  set_name("zora");
  set_alias("zora_1");
  set_race("hologram");
  set_short(""+HIB+"Zora"+NORM);
  set_long(
    " From Hyrule, it's a beast known as a Zora. This creature is pale\n"+
    " blue in colour and has blades protruding from his forearms. Zora\n"+
    " is wearing a loin cloth which light pours from.\n");
  set_level(21);
  set_hp(1200+random(250));
  set_al(-800);
  set_ac(34+random(4));
  set_wc(40);
  set_aggressive(0);
   move_object(clone_object("/players/sami/area/coinarea/obj/barter/projector.c"),this_object());
  set_multi_cast(2);
  add_spell("fin_cutter",
  ""+HIR+"#MN#"+NORM+" raises his arms and shoots deadly"+HIG+" fins"+NORM+"at your "+HIY+"H E A D"+NORM+"!!!\n",
  " "+HIR+"#MN#"+NORM+" shoots his "+HIG+"Fins"+NORM+" at #TN#'s "+HIR+"S K U L L"+NORM+"\n",
  50,({15,15}),({"other|water","other|light"}),1);
   add_spell("water_blast", 
   ""+HIB+"Zora "+NORM+" summons a "+HIB+"Tidal Wave"+NORM+" of"+HIB+"\n"+
    "@@@@    @@@    @@@@     @@@@@@     @@@@@@@@@  @@@@@@@@  @@@@@@@\n"+
	"@@@@    @@@    @@@@    @@@  @@@    @@@@@@@@@  @@@@@@@@  @@@@  @@\n"+
	 "@@@@   @@@   @@@@    @@@@@@@@@@      @@@     @@@@      @@@@   @@\n"+
	  "@@@@  @@@  @@@@    @@@      @@@     @@@     @@@@@@@   @@@@    @@\n"+
	   "@@@@ @@@ @@@@    @@@@      @@@@    @@@     @@@@@@@   @@@@   @@\n"+
		"@@@@@@@@@@@     @@@@      @@@@    @@@     @@@@      @@@@  @@\n"+
	     "@@@@@@@@@      @@@@      @@@@    @@@     @@@@@@@@  @@@@ @@@@\n"+
		  "@@@@@@@       @@@@      @@@@    @@@     @@@@@@@@  @@@@   @@@ "+NORM+" \n"+
  " You are "+HIB+" Washed "+NORM+"away by the amazing"+HIG+" Power"+NORM+"\n", 
  ""+HIB+"Zora"+NORM+" summons a "+HIB+"Tidal Wave"+NORM+" at #TN#.\n"+
      " A Typhoon of Water washes over #TN#.\n",
     
  40,({55,20}),({"other|water","other|ice"}),1);
   } 
