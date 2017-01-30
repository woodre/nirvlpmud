#define TP this_player()
#include "/players/wocket/closed/ansi.h"
#define TPN this_player()->query_name()

string name, short_desc, long_desc, drinking_msg,
    drinker_msg, alias, alt_name, empty_container, cmd;
string TYPE, destruct_msg2, destruct_msg1;
int COST, HEAL, STRENGTH, weight, charges;

reset(arg){
    if(arg) return;

    name = short_desc = long_desc = "object";
    alias = alt_name = "object";
    cmd = "intake";
    empty_container = "destructme";
    COST = HEAL = STRENGTH = weight = charges = 1;
    TYPE = "drink_alcohol";
    destruct_msg2="The heal disapears.\n";
}

init(){
    add_action("intake",cmd);
}



id(str){
    if(charges == 0){ return str = empty_container; }
  else
    return str == name || str == alt_name || str == alias;
}

short(){
    if(charges == 0){
      return "An empty "+empty_container;
}
    return short_desc+" ("+BOLD+charges+NORM+")";
}

long(){
    if(charges == 0){
    write(short()+".\n");
}
    write(long_desc+"\n");
}

get(){   return 1; }

intake(str){

if(!charges) return;

if(!str || !id(str)){
    notify_fail("What would you like to "+cmd+"?\n");
    return 0;
}


if(!call_other(TP,TYPE,STRENGTH)) return 1;

charges--;
TP->heal_self(HEAL);
TP->recalc_carry();

if(drinker_msg){
    write(drinker_msg);
    }
      else write("You "+cmd+" "+short_desc+".\n");
    write("You may "+cmd+" "+charges+" more times.\n");
if(drinking_msg){
      say(TPN+" "+drinking_msg);
    }
      else say(TPN+" "+cmd+"s "+short_desc+".\n");

write(HIB+"<qm> "+NORM+"hp: "+TP->query_hp()+" sp: "+TP->query_spell_point());
write(HIB+"\tI: "+NORM+((TP->query_intoxination())/(TP->query_max_intox()) ) );
write(HIB+"  F: "+NORM+((TP->query_stuffed()*100)/(TP->query_max_stuff()) ) );
write(HIB+"  S: "+NORM+((TP->query_soaked()*100)/(TP->query_max_soak()) ) );
write("\n");
if(empty_container == "destructme" && charges == 0){
    if(destruct_msg2)   write(destruct_msg2);
    if(destruct_msg1)  say(TPN+" "+destruct_msg1);
      destruct(this_object());
}
	return 1;
}

set_name(n){    name = n; }
set_short(s){    short_desc = s; }
set_long(l){   long_desc = l; }
set_cost(c){    COST = c; }
set_weight(w){   weight = w; }
set_strength(s){   STRENGTH = s; }
set_alias(a){    alias = a; }
set_alt_name(an){   alt_name = an; }
set_drinking_msg(dm){   drinking_msg = dm; }
set_drinker_msg(dm){    drinker_msg = dm; }
set_empty_container(ec){   empty_container = ec; }
set_type(t){   TYPE = t; }
set_destruct_msg2(dm){   destruct_msg2 = dm; }
set_destruct_msg1(dm){ destruct_msg1 = dm; }
set_charges(c){   charges = c; }
set_heal(h){    HEAL = h; }
set_cmd(c){   cmd = c; }
query_value(){   return HEAL*COST*charges; }
query_save_flag() { return 1; }
query_weight(){ if(charges < 3) return 1;
    else return charges/3;
}
query_charges(){ return charges; }
