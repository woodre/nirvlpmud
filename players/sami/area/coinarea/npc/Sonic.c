inherit "/obj/monster.c";
#include <ansi.h>
#define tpn this_player()->query_name()
#include "/sys/lib.h"

reset(arg) {
  ::reset(arg);
  if(arg) return;
	
  set_name("sonic");
   set_alias("hedgehog");
  set_race("Hologram");
  set_short(""+HIB+"Sonic"+NORM+" the hedgehog");
  set_long(
    "  Short and lean with blue spiky hair is Sonic. He is \n"+
    "  not much to look at, but do not let the looks fool you! \n");
  set_level(20);
  set_hp(1200+random(500));
  set_al(-800);
  set_ac(30+random(4));
  set_wc(40);
  set_aggressive(0);
   move_object(clone_object("/players/sami/area/coinarea/obj/barter/projector.c"),this_object());
  set_multi_cast(1);
  
 add_spell("sonic_dash",
    "#MN#"+HIY+" runs"+NORM+" to you with "+BOLD+"Super Speed"+NORM+" and "+HIR+" S L A M S"+NORM+" into you. \n",
	"#MN# "+HIR+" S L A M S"+NORM+" #TN# with "+BOLD+" Super Speed"+NORM+".\n",
35,({20,20}),({"other|sonic","other|good"}),1);
	
	add_spell("Sonic_Roll",
    "#MN# "+HIY+"charges"+NORM+" his "+BOLD+" Super Spin Dash"+NORM+" and shoots at"+HIR+" you"+NORM+"\n",
	"#MN# "+HIB+"devastates"+NORM+" #TN# with a "+HIR+"Super Spin Dash"+NORM+".\n",
35,({20,20}),({"other|sonic","other|good"}),1);
}
