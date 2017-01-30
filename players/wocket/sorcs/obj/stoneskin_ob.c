#include "/players/wocket/closed/ansi.h"
inherit "/obj/armor.c";
object me;

id(str){ return (str == "w_stoneskin" || str == "pro_object" || str == "stoneskin"); }
get(){ return 0; }
drop(){ return 1; }
shield_bonus(obj){ return 75; }
query_type(){ return "spell_stoneskin"; }
query_combat_method(){ return 2; }
query_paladin_shield(){ return 1; }
query_name(){ return HIB+"stoneskin"+NORM; }
call_armor_special(){
  object mage;
  mage = environment(this_object());  
  if(mage->query_weapon()){
    tell_object(mage,BOLD+"Your stone hands makes you fumble your weapon.\n"+NORM);
    mage->stop_wielding();
  }
  tell_room(environment(mage),mage->query_name()+"'s stone skin deflects off the blow.\n");
  mage->add_spell_point(-2);
  return 0;
}

init(){
  me = this_player();
  me->remote_say(HIB+"An aura of blue light surrounds "+me->query_name()+" as "+me->query_pronoun()+" turns to stone.\n"+OFF);
  tell_object(me,HIB+"An aura of blue light surrounds you.\n"+OFF);
  tell_object(me,HIB+"Your skin turns to stone as your movement stiffens.\n"+OFF);
  add_action("frozen");add_xverb("");
  add_action("de","de");
  call_out("remove_stoneskin",100);
}

frozen(){
  if(!random(10)){
    write("You manage to move slightly.\n");
    return 0;
  }
  else
  write("You are concentrating to deeply on your stoneskin to do anything else.\n");
  return 1;
}

de(str){
if(str != "stone"){
  notify_fail("What spell are you trying to cancel?\n");
  return 0;
}
write("You command your skin to return to normal.\n");
remove_stoneskin();
return 1;
}

remove_stoneskin(){
  remove_call_out("remove_stoneskin");
    me->remote_say(HIB+"The blue aura surrounding "+me->query_name()+" begins to fade.\n"+NORM);
    me->remove_say(HIB+me->query_name()+"'s skin changes from stone to flesh.\n"+NORM);
    tell_object(me,HIB+"The blue aura surrounding you fades.\n"+OFF);
    tell_object(me,HIB+"You skin reverts to flesh and you can move again.\n"+OFF);
    me->stop_wearing("stoneskin");
  destruct(this_object());
}

extra_look(){
string blah;
blah = HIB+"\t[ skin as hard as stone ]"+NORM;
return blah;
}
