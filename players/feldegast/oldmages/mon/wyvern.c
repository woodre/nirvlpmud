#include "def.h"
#include "/players/feldegast/defines.h"
inherit PET;

int rampage;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("wyvern");
  set_short(HIM+"Wyvern"+NORM);
  set_long(
"Although some consider wyverns to be just small dragons, after\n\
looking at this one, you know better.  For one thing, wyverns lack\n\
the inherent grace and majesty attributed to all dragons.  For\n\
another, wyvernskin is not soft and supple like dragonskin, but\n\
rather a hard, horny surface that rather than gleaming, seems to\n\
actually absorb light with its dull colour.  And finally, although\n\
dragons tend to range in personality and attitude, wyverns appear\n\
to be universally cruel, mean and deadly.\n"
  );
  set_gender(0); /* "male","female" */
  set_race("summoned");
  set_level(15);
  set_wc(13);
  set_ac(10);
  set_hp(120+random(30));
  set_al(0);
}
upkeep() {
  if(owner->query_sp() > -15) {
    owner->add_spell_point(-15);
    if(!random((int)this_player()->query_attrib("wil"))) {
      tell_object(owner,"You struggle in a battle of wills with "+short()+".\n");
      this_player()->add_spell_point(-random(5));
    }
    upkeep_timer=random(16);
  }
  else {
    tell_object(owner,name+" shakes off your control.\n");
    move_object(this_object(),environment(owner));
    attacked_by(owner);
  }
  upkeep_timer=random(10);
}
faux_hb() {
  if(!rampage) ::faux_hb();
  else
    if(environment(this_object())!=environment(owner)) {
      move_object(this_object(),environment(owner));
      attacked_by(owner);
    }
}
cmd_hook(str) {
  if(!rampage)
    return ::cmd_hook(str);
  else return 0;
}
dismissed() {
  say("Casting a last, scathing glance at you, the Wyvern stretches its\n"+
      "wings and flies off into the sky.\n");
  destruct(this_object());
}
