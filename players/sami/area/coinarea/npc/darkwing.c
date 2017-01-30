inherit "/obj/monster.c";
#include <ansi.h>
#define tpn this_player()->query_name()
#include "/sys/lib.h"

reset(arg) {
  ::reset(arg);
  if(arg) return;
	
  set_name("darkwing");
   set_alias("duck");
  set_race("hologram");
  set_short(""+BOLD+" Darkwing Duck"+NORM);
  set_long(
    "  Tremendous amounts of light leaks from under this hero's purple \n"+
    "  cape. Almost translucent, Darkwing has a purple mask covering his\n"+
	"  face and purple gloves on his hands, but where are his pants?\n");
  add_money(2000+random(4000));
  set_level(20);
  set_hp(1000+random(500));
  set_al(-800);
  set_ac(25+random(4));
  set_wc(40);
  set_aggressive(0);
   move_object(clone_object("/players/sami/area/coinarea/obj/barter/projector.c"),this_object());
set_multi_cast(1);
  
 add_spell("dark_slam",
    "Darkwing "+HIY+"SLAMS"+NORM+" you into the metallic wall with his"+BOLD+" Super Strength."+NORM+"\n",
"Darkwing "+HIY+"SLAMS"+NORM+" #TN# into the metallic wall with his"+BOLD+" Super Strength."+NORM+"\n",
 35,({30,30}),({"other|physical","other|dark"}),1); 
 add_spell("duck_kick",
    "Darkness settles as #MN# "+HIY+"KICKS"+NORM+" you with his"+HIK+" Shadow Kick."+NORM+"\n",
"Darkness settles as #MN# "+HIY+"KICKS"+NORM+" #TN# with his"+HIK+" Shadow Kick."+NORM+".\n",
 35,({30,30}),({"other|evil","other|dark"}),1);
}
