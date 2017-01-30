#include "/players/feldegast/defines.h"
#include "/players/wocket/mages/def.h"

inherit "/players/wocket/mages/obj/page";

reset(arg) {
  if(arg) return;
  spell="dazzle";
  spell_short="Dazzle";
  spell_desc=
"   Although frivolous and gauche, Erasmus' Razzle Dazzle spell\n\
is considered the height of magical power by many foolish and\n\
ignorant villagers.  Even many well-educated and respectable\n\
individuals have been known to stop in the middle of battle to\n\
watch this otherwise useless spell in action.\n";
  time=1;
  size=7;
  spcost=60;
  hpcost=0;
  type="ill";
}
check_spell(object mage, string str) {
  return 1;
}
cast_spell(object mage) {
  object target;
  tell_object(mage,"You conjure a cloud of shimmering lights and glowing bubbles,\n"+
                   "a shower of sparks, and a fountain of colored flames.\n");
  target=first_inventory(environment(mage));
  while(target) {
    if(target!=mage)
      tell_object(target,mage->query_name()+"dazzles you with a magnificent display of flashing lights\n");
    target->stop_fight();
    target->stop_fight();
    target->stop_hunter();
    target=next_inventory(target);
  }
}  