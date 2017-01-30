inherit "/obj/monster.c";
#include <ansi.h>
#define tpn this_player()->query_name()
#include "/sys/lib.h"

reset(arg) {
  ::reset(arg);
  if(arg) return;
	
  set_name("zero");
   set_alias("ko_zero");
  set_race("Hologram");
  set_short(""+HIR+"Zero"+NORM);
  set_long(
    "  Tremendous amounts of light leaks from under this hero's \n"+
    "  awesome armor. Currently, it appears as if there is a \n"+
	"  shiny new Z sabre attached to his Right hand.\n");
  set_level(20);
  set_hp(1200+random(500));
  set_al(-800);
  set_ac(32+random(4));
  set_wc(40);
  set_aggressive(0);
   move_object(clone_object("/players/sami/area/coinarea/obj/barter/projector.c"),this_object());
  set_multi_cast(1);
  
 add_spell("z_saber_slash",
    "Zero"+HIY+" charges"+NORM+" his "+BOLD+"Z sabre"+NORM+" and "+HIR+" S L A S H E S"+NORM+" you. \n",
	"#MN# "+HIR+" S L A S H E S"+NORM+" #TN# with deadly precision.\n",
35,({20,20}),({"other|laser","other|evil"}),1);
	
	add_spell("z_saber_shot",
    "#MN# "+HIY+"charges"+NORM+" his "+BOLD+" Z sabre"+NORM+" and shoots a "+HIR+" B E A M"+NORM+" of light at you.\n",
	"#MN# "+HIB+"devastates"+NORM+" #TN# with a "+HIR+"B E A M"+NORM+" of light.\n",
35,({20,20}),({"other|laser","other|dark"}),1);
}
