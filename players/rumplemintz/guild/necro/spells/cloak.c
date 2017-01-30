#include "../defs.h"
/* Guild Level 4 - Misc Spell
   Cloak of Confusion lowers the targets WC while slightly
   raising the AC of the target. 
   TotalCost - 37 sp (25sp, 1 skin, 2 blood)    */
cmd(str) {
int dam, armchange, wepchange;
object ob, ob2, att;
string caster_msg,room_msg,target_msg;
  ob = GOB;
  armchange = 2;
  wepchange = 3;
  if(!ob) return;
  if(!GOB->checklev(4,8)) return 1;
  if(!str){
    if(tp->query_attack()) att = tp->query_attack();
    else{
      notify_fail("Who would you like to cloak in a fog?\n");
      return 0; 
    } 
  }
  else{
    att = present(str, environment(tp)); 
  }
  if(!att){
    notify_fail("There is no "+str+" here to writhe.\n"); 
    return 0; 
  }
  if(!att->is_npc()){
    notify_fail("That is not something you can attack.\n");
    return 0;
  }
  if(tp->query_sp() < 25) {
    write("You do not have the spell points available for this spell.\n");
    return 1;
  }
  if((ob->query_blood() < 2) || (ob->query_skin() < 1)) {
    write("You do not have the spell components available for the spell.\n");
    return 1;
  }

  ob2 = present("necro_stat_change",att);
  if(!ob2) {
    ob2 = clone_object(OBJ+"/spells/necro_stat_modifyer.c");
    move_object(ob2,att);
    ob2->set_orgwc(att->query_wc());
    ob2->set_orgac(att->query_ac());
    ob2->set_time(25+(tp->query_guild_rank()*2));
  }
  if(ob2->query_wc_times() > 1) {
  write("You can only cast Cloak of Confusion twice at the same target.\n");
  return 1; }
  else ob2->add_wc_times(1);
  caster_msg = "You rip a piece of skin into 4 sections and soak them in blood.  As\n"+
               "you whisper arcane words a "+BOLD+"mist"+OFF+" begins to rise enveloping "+att->query_name()+".\n"+
               "Covered by a cloak of fog "+att->query_name()+" loses sense of "+att->query_possessive()+" surroundings.\n";
  room_msg = "As "+tpn+" takes out things from his pouch and begins chanting a strange fog rises\n"+
             "surrounding "+att->query_name()+".\n";
  target_msg = "";
  if(BLOODMOON) {
    caster_msg+=ROD+"The Bloodmoon increases the power of your spell.\n";
    wepchange += 2; 
  }
  if(GRAVESITE) {
    caster_msg+=ROD+"The Graveyard increases the power of your spell.\n";
    armchange += 2; 
  }  
  tp->add_spell_point(-25);
  ob->add_val(1);
  ob->add_blood(-2);
  ob->add_skin(-1);
  ob->save_me();
  mset_wc(wepchange,ob2,att);
  mset_ac(armchange,ob2,att);
  tp->spell_object(att,"cloak", 0, 0, caster_msg, target_msg, room_msg);
return 1; 
}

mset_wc(change,ob2,ob){
int threeforths,minus7;
int cwc,dif;
  threeforths = (ob2->query_orgwc() * 3)/4;
  minus7 = ob2->query_orgwc() - 7;
  cwc = ob->query_wc();
  dif = cwc-change;
  if(threeforths > minus7){
    if( dif < threeforths ){
      ob->set_wc(threeforths);
    }
    else{
      ob->set_wc(dif);
    }
  }
  else{
    if( dif < minus7 ){
      ob->set_wc(minus7);
    }
    else{
      ob->set_wc(dif);
   }
  }
}

mset_ac(change,ob2,ob){
int twothirds,minus4;
int dif,cac;
   twothirds = (ob2->query_orgac() * 2)/4;
   minus4 = ob2->query_orgac() - 4;
   cac = ob->query_ac();
   dif = cac-change;
  if(twothirds > minus4){
    if( dif < twothirds ){
      ob->set_ac(twothirds);
    }
    else{
      ob->set_ac(dif);
    }
  }
  else{
    if( (dif) < minus4 ){
      ob->set_ac(minus4);
    }
    else{
      ob->set_ac(dif);
    }
  }
}


