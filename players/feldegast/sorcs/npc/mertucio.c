#include "defs.h"
inherit TEACHER;

reset() {
  set_short(HIG+"Mertucio the Enchanter"+NORM);
  set_name("mertucio");
  set_level(30);
  set_long(
    "Mertucio is a small man with delicate features and pointy ears.\n"+
    "He is grinning from ear to ear and his eyes sparkle mischeviously.\n"+
    "He is wearing a flamboyantly blue robe and a cap with a red feather\n"+
    "in it.\n"
  );
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

