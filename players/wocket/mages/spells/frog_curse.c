#include "/players/wocket/closed/ansi.h"
#include "../def.h"
inherit "/players/wocket/mages/obj/page.c";

object target;

reset(){
  spell = "frog curse";
  spell_short = "Frog curse";
  spell_desc = "Legends upon legends have for told of witches turning brave\n"+
               "men into frogs.  Entire towns would be abandoned as the\n"+
               "surrounding area would fill with the sound of croaking.  None\n"+
               "is more common and more effective for vanquishing your foe.\n";
  spcost = 60;
  hpcost = 0;
  coincost = 0;
  type = "enc";
  size = 1;
  time = 1;
}

check_spell(object mage,string str){
  target = previous_object()->get_target(str);
  if(!target){
    tell_object(mage,"There must be a target for this spell.\n");
    return 0;
  }
  if(!target->is_player()){
    tell_object(mage,"This can only be cast upon a player.\n");
    return 0;
  }
  if(present("w_frog_curse",target)){
    tell_object(mage,"That person is already a frog.\n");
    return 0;;
  }
  if(environment(target) != environment(mage)){
    tell_object(mage,"That player is not here.\n");
    return 0;
  }
  return 1;
}

cast_spell(object mage){
int blah;
object frogcurse;
  blah = (mage->query_level()+mage->query_extra_level())*50;
  frogcurse = clone_object(OBJDIR+"frog_curse_ob.c");
  frogcurse->set_duration(blah);
  tell_object(mage,"You point at "+target->query_name()+" and yell, \"FROGNIPITIS\"\n");
  mage->remote_say(mage->query_name()+" points at "+target->query_name()+" and yells, \"FROGNIPITIS\"\n");
  move_object(frogcurse,target);
  return 1;
}
