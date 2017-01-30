#include "defs.h"

inherit "/players/wocket/mages/obj/page.c";

reset(arg) {
  if(arg) return;
  spell="fleas";
  spell_short=BOLD+"Fleas"+NORM;
  spell_desc=
"  This spell is the creation of the sophomoric wizard Wally the\n"+
"Unwise.  Although not of much use in life or death situations, it\n"+
"is of some utility in certain social situations, particularly when\n"+
"the target is someone the caster dislikes.\n";
  time=1;
  size=1;
  spcost=20;
  hpcost=0;
  type="summon";
}
check_spell(object mage, string str) {
  object target;
  target=previous_object()->get_target(str);
  if(!living(target)) {
    tell_object(mage,"You cannot cast this spell on that.\n");
    return;
  }
  if(present("flea_obj",target)) {
    tell_object(mage,"That person already has fleas.\n");
    return 0;
  }
  return 1;
}  
cast_spell(object mage, string str) {
  object target;
  target=previous_object()->get_target(str);
  if(!target) {
    tell_object(mage,"That is not a valid target.\n");
    return;
  }
  if(!living(target)) {
    tell_object(mage,"You cannot cast this spell on that.\n");
    return;
  }
  if(present("flea_obj",target)) {
    tell_object(mage,"That person already has fleas.\n");
    return 0;
  }
  tell_object(mage,"You mutter a few magical words under your breath and casually\n"+
                   "pat "+target->query_name()+" on the shoulder.\n");
  tell_object(target,mage->query_name()+" pats you on the shoulder.\n");
  tell_room(environment(mage),mage->query_name()+" casually pats "+target->query_name()+" on the shoulder.\n",({ mage, target }));
  move_object(clone_object(OBJDIR+"flea_obj.c"),target);
}

