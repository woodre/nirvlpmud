#include "../defs.h"

cmd(str) {
object ob,corpse;

  if(!str || str != "corpse") {
    notify_fail("What would you like to consume?\n");
    return 0;
  }
  corpse = present("corpse",environment(this_player()));
  ob = GOB;

  if(!corpse){
    notify_fail("There is no corpse here to be consumed.\n"); 
    return 0; 
  }
 if(!GOB->checklev(2,5)) return 1;
 if(tp->query_sp() < 20) {
    notify_fail("You do not have enough spell points for this ability.\n");
    return 0; 
  }
  if(ob->query_blood() < 1) {
    notify_fail("You do not have the material componets for this spell.\n");
    return 0; 
  }
  write("You whisper to the realm of death as you smear "+HIR+"blood"+OFF+" across the corpse's head.\n");
  say(tpn+" kneels down and spread blood across the corpse's head.\n");
  tp->add_spell_point(-20);
  ob->add_blood(-1);
  ob->add_val(1);
  call_out("killcorpse",3,corpse);
  return 1;
}


killcorpse(corpse){
string name;
object dust;
  if(!corpse) return;
  tell_room(environment(corpse),HIR+"A giant pillar of FIRE descends from the sky.\n"+OFF+"The corpse now lays in ashes.\n"+OFF);
  name = corpse->query_name();
  if(!name) name = "unknown victim";
  dust = clone_object(OBJ+"/misc/cdust.c");
  dust->set_name(name);
  move_object(dust,environment(corpse));
  destruct(corpse);
}