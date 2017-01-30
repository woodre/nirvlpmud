inherit "/obj/monster.c";
#include <ansi.h>
#define tpn this_player()->query_name()
#include "/sys/lib.h"

reset(arg) {
  ::reset(arg);
  if(arg) return;
	
  set_name("loki");
  set_alias("LOKI_1");
  set_race("hologram");
  set_short(""+HIR+"L"+HIB+"oki"+NORM);
  set_long(
    "Norse God of mischief,"+HIR+" L"+HIB+"oki"+NORM+". Armors made of some unidentifiable material\n"+
    "are equipped upon this god. Light shines through this Gods' chainmail.\n");
     
  set_level(21);
  set_hp(1200+random(250));
  set_al(-800);
  set_ac(30+random(4));
  set_wc(40);
  set_aggressive(0);
 move_object(clone_object("/players/sami/area/coinarea/obj/barter/projector.c"),this_object());

  set_multi_cast(1);
   add_spell("mystery_box",
    HIK+" #MN#"+NORM+" tosses a small "+HIY+"box"+NORM+" at your feet and it"+HIR+" E X P L O D E S"+NORM+"!!!\n",
  " "+HIK+"#MN#"+NORM+" detonates a "+HIC+"Mystery Box"+NORM+" at #TN#'s feet.\n",
  35,({20,20}),({"other|light","other|dark"}),1);
   add_spell("mischief_minion", 
   ""+HIK+"#MN#"+NORM+" summons a minion which "+HIG+" M A I M S"+NORM+" #TN# with its "+HIR+"H E L L  F I R E"+NORM+".\n",
  ""+HIK+"#MN#"+NORM+" summons a minion which "+HIG+" M A I M S"+NORM+" #TN# with its "+HIR+"H E L L  F I R E"+NORM+".\n",
  35,({40,20}),({"other|fire","other|evil"}),1);
}
