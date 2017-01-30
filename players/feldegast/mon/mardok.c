#include "defs.h"

inherit MONSTER;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("mardok");
  set_alt_name("guardian");
  set_alias("spirit");
  set_short(HIM+"Mardok"+NORM);
  set_long(
"This guardian spirit has been magically bound to protect this\n"+
"vault from intruders.  Although barely sentient, it is extremely\n"+
"dangerous due to its predominantly psychic nature.\n"
  );
  set_gender(0);
  set_race("spirit");
  set_level(21);
  set_wc(32);
  set_ac(25);
  set_hp(600);
  set_al(0);
  load_spell(30,15,2,
  HIM+"\nThe Mardok steals some of your psychic energy!\n\n"+NORM,
  HIM+"\nThe Mardok steals some of #ATT#'s psychic energy!\n\n"+NORM);
  load_spell(40,15,1,
    HIR+"\nThe Mardok triggers memories of pain and old wounds!\n\n"+NORM,
  HIR+"\nThe Mardok triggers memories of pain and old wounds!\n\n"+NORM);
}
