#include "/players/wocket/closed/ansi.h"
#include "../def.h"
inherit "/players/wocket/mages/npc/teacher.c";

reset() {
  set_short(HIR+"Janoc the Crimson Death"+NORM);
  set_name("janoc");
  set_level(30);
  set_long(
    "Before you stands Janoc, often called 'Crimson Death' in the tales of his\n"+
    "exploits.  He is a master sorcerer and peerless master of offensive magic.\n"+
    "He wears a crimson robe and a hood which almost covers his flame-ravaged face,\n"+
    "a valuable lesson that the path of magic is fraught with peril.\n");
  set_hp(500);
  set_wc(50);
  set_ac(30);

  spell_name=({ });
  spell_path=({ });
  spell_xp=({ });
  spell_difficulty=({ });

  add_spell("magic missile","magic_missile",5000,90);
  add_spell("shock","shock",15000,15);
  add_spell("fireball","fireball",100000,20);
  add_spell("sonic","sonic",1000000,25);
  add_spell("escape","escape",20000,15);
  add_spell("firebolt","firebolt",30000,20);
  add_spell("flame whip","flame_whip",45000,20);
  add_spell("flamesnake","flamesnake",50000,25);
  add_spell("freezing touch","freezing_touch",200000,30);
}

