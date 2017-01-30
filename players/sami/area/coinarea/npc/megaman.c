inherit "/obj/monster.c";
#include <ansi.h>
#define tpn this_player()->query_name()
#include "/sys/lib.h"

reset(arg) {
  ::reset(arg);
  if(arg) return;
	
  set_name("megaman");
   set_alias("ko_megaman");
  set_race("Hologram");
  set_short(""+HIC+" Megaman"+NORM);
  set_long(
    "  Tremendous amounts of light leaks from under this Hero's \n"+
    "  awesome armor. Currently, it appears as if there is a \n"+
	"  shiny new Mega Buster attached to his right hand.\n");
  set_level(20);
  set_hp(1200+random(500));
  set_al(-800);
  set_ac(30+random(4));
  set_wc(40);
   move_object(clone_object("/players/sami/area/coinarea/obj/barter/projector.c"),this_object());
  set_aggressive(0);
  set_multi_cast(1);
  
 add_spell("xbuster_shot",
  "#MN# "+HIY+"charges"+NORM+" his "+BOLD+"Mega Buster"+NORM+" and unleashes a "+HIB+"F L A S H"+NORM+" of light.\n",
  " #MN# "+HIY+"charges"+NORM+" his "+BOLD+"Mega Buster"+NORM+" and hits his opponent with a "+HIB+"F L A S H"+NORM+".\n",
  35,({20,20}),({"other|laser","other|dark"}),1);

  add_spell("mischief_minion", 
   "#MN# "+HIG+"absorbs"+NORM+" your attack and "+BOLD+"reflects"+NORM+" it back at you.\n",
  "#MN# "+HIG+"absorbs"+NORM+" #TN#'s attack and "+BOLD+"reflects"+NORM+" it back at #TN#.\n",
  35,({40,20}),({"other|laser","other|evil"}),1);

    
}
