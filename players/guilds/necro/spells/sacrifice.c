/* Hidden spell gained by embracing death 3 times */

#include "../defs.h"
string *types;

cmd(str){
  if(!GOB) return 0;
  if(!GOB->query_sacrifice()) return 0;
  types = TYPES;
  if(!str){
    notify_fail("What would you like to sacrifice? <self>/<corpse>\n");
    return 0;
  }
  switch(str){
    case "corpse":  return saccorpse(); break;
    case "self":    return sacme();     break;
    default: notify_fail("That is not something the Realm of Death wants.\n"); return 0;
  }
return 0;
}
 
saccorpse(){
object ob,wep;
object corpse;
int heal;
string msg;
  ob = GOB;
  corpse = present("corpse",this_player());
  if(!corpse){
    corpse = present("corpse",environment(this_player()));
  }
  if(!corpse){
    notify_fail("You do not have a corpse to sacrifice.\n");
    return 0;
  }
  wep = tp->query_weapon();
  if(!wep){
    write("You must have a weapon wielded!\n"); return 1;
  }
  if(member_array(wep->query_type(),types) == -1){
    write("That weapon is not sharp enough to harvest components.\n");
    return 1;
  }
  if(tp->query_attack()) { 
    notify_fail("You can not hold your knife still enough to sacrifice the corpse while in combat.\n");
    return 0;
  }
  heal = (corpse->heal_value()*5)/6;
  msg = "";
  if(BLOODMOON){
    msg += ROD+"Your spell grows stronger by the presence of the BloodMoon\n";
    heal = heal+3;
  }
  write("You begin to dissect the corpse with utter care and precision. Warm living\n"+
        "blood flows from the slashes, as you drain the precious life from your\n"+
        "corpse.\n");
  say(tp->query_name()+" begins to slash apart the corpse and drain its blood.\n");
  write(msg);
  ob->add_val(1);
  if(heal < 1) heal = 1;
  call_out("saccorpse2",2,({ tp,heal })); 
  destruct(corpse);
  return 1;
  return 1;
}

saccorpse2(mixed *arg){
  if(!arg[0]) return;
  if(!arg[1]) return;
  tell_object(arg[0],"The pooled blood rises into a mist. You feel vitalized by the Realm of Death.\n");
  arg[0]->add_spell_point(arg[1]*2);
} 

sacme(){
int cost,heal;
object ob,wep;
string msg;
  ob = GOB;
  
  if(!ob) return 0;
  if(tp->query_attack()) { 
    notify_fail("You can not hold your knife still enough to sacrifice yourself while in combat.\n");
    return 0;
  }
  wep = tp->query_weapon();
  if(!wep){
    write("You must have a weapon wielded!\n"); return 1;
  }
  if(member_array(wep->query_type(),TYPES) == -1){
    write("That weapon is not sharp enough to harvest components.\n");
    return 1;
  }
  cost = 30+random(tp->query_level())+random(tp->query_guild_rank());
  heal = ( ( 20+random(tp->query_level())+random(tp->query_guild_rank()) )*9 )/10;
  msg = "";
  if(tp->query_hp() < cost){
    notify_fail("You do not have the health for that sacrifice.\n");
    return 0;
  }
  if(BLOODMOON){
    msg += ROD+"Your spell grows stronger by the presence of the BloodMoon\n";
    heal = heal+3;
  }
  write("You wield your knife with delicate precision as you slash into your wrist.\n"+
        "Blood flows from your wound, as your precious life is drained from your\n"+
        "body.\n");
  say(tp->query_name()+" begins to slash into "+tp->query_possessive()+" wrists letting the blood\n"+
      "flow from the wounds.\n");
  write(msg);
  ob->add_val(1);
  if( ob->query_icutmyself() ) {
    ob->add_icutmyself(1);
  }
  else{
    ob->add_icutmyself(2);
    ob->amihealed();
  }
  tp->add_hit_point(-cost);
  call_out("sacme2",2,({ tp,heal})); 
  return 1;
}

sacme2(mixed *arg){
  if(!arg[0]) return;
  if(!arg[1]) return;
  tell_object(arg[0],"Your blood rises into a mist.  You feel vitalized by the Realm of Death.\n");
  arg[0]->add_spell_point(arg[1]);
} 