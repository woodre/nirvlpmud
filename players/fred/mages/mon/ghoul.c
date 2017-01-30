#include "/players/fred/mages/defs.h"

inherit "obj/monster";

object owner, ob;
string who;
object target;
int sit, mon_ok, life, decay, auto_ok;
 
init() {
::init();
    if(TP && TP == owner && !TP->query_ghost()) {
    add_action("fight","gkill");
    add_action("dismiss", "dismiss");
    add_action("drop_item","toss");
    add_action("give_object","gtransfer");
    add_action("stop_it","gstop");
    add_action("ghoulfood","absorb");
    add_action("gready","gready");
    add_action("gsit","gsit");
    add_action("gmon","gmon");
    add_action("pick_up","snag");
    add_action("use_weapon","guse");
    add_action("put_on","gwear");
    add_action("coin_drop","gcoins");
    add_action("auto_check","gauto");
  }
}
 
reset(arg) {
::reset();
    if(arg) return;
    set_name("ghoul");
    set_alias("ghoul_obj");
    set_race("undead");
    set_short("Ghoul the Horrible (nasty)");
    set_level(0);
    set_wc(0);
    set_ac(0);
    set_gender("male");
    set_hp(0);
    set_ep(1);
    set_dead_ob(this_object());
    set_can_kill(1);
    cap_name = "Ghoul";
    auto_ok = 1; 
    mon_ok = 1;
    set_no_exp_value(1);
    }

long(){
  write("A Ghoul belonging to a Black Circle Mage.\n");
  if(TP == owner){
    write("Use 'gcmds' for more details.\n"); }
    if(hit_point < (max_hp/10)) {
      write("Ghoul is in very bad shape.\n"); return; }
    if(hit_point < (max_hp/5)) {
      write("Ghoul is in bad shape.\n"); return; }
    if(hit_point < (max_hp/2)) {
      write("Ghoul is somewhat hurt.\n"); return; }
    if(hit_point < (max_hp - 20)){
      write("Ghoul is slightly hurt.\n"); return;}
      write("Ghoul is in good shape.\n");
 }

patch_owner(o) { owner = o; }

query_owner(){ return owner; }


set_life(num){
  life = num;
  call_out("decay", life); }
 
set_decay(num){
  decay = num;
  call_out("show_decay", decay); }

gsit(str){
  if(TO->query_attack()){
    write("Your Ghoul is too busy fighting.\n");
    return 1; 
    }
  say("Ghoul nods at "+owner->query_name()+" and sits on the ground.\n");
  sit = 1;
  return 1;
  }

is_pet(){ return 0; }

gmon(str){ 
 if(!str){  tell_object(owner, 
     BOLD+HIY+"Ghoul: "+((hit_point * 10)/max_hp)+" / 10"+NORM+"\n");
     return 1; }
 if(str == "on" && mon_ok == 1){
   write("The Ghoul's monitor is already on.\n"); return 1; }
 if(str == "on" && mon_ok != 1){
   write("You turn the Ghoul's monitor on.\n");
   mon_ok = 1;
   return 1; }
 if(str == "off" && mon_ok != 1){
   write("The Ghoul's monitor is already off.\n"); return 1; }
 if(str == "off" && mon_ok == 1){
   write("You turn the Ghoul's monitor off.\n");
   mon_ok = 0;
   return 1; }
  }

auto_check(str){ 
 if(!str){  tell_object(owner, 
     "Please use 'gauto <on/off>'\n"); return 1; }
 if(str == "on" && auto_ok == 1){
   write(BOLD+HIY+"Your Ghoul's auto attack is already: ON.\n"+NORM); return 1; }
 if(str == "on" && auto_ok != 1){
   write(BOLD+HIY+"Your Ghoul's auto attack is now: ON.\n"+NORM);
   auto_ok = 1;
   return 1; }
 if(str == "off" && auto_ok != 1){
   write(BOLD+HIY+"Your Ghoul's auto attack is already: OFF.\n"+NORM); return 1; }
 if(str == "off" && auto_ok == 1){
   write(BOLD+HIY+"Your Ghoul's auto attack is now: OFF.\n"+NORM);
   auto_ok = 0;
   return 1; }
  }
 


dismiss(str) {
  ob = present("dark_circle", TP);
 if(str != "ghoul"){ write("Dismiss what?\n"); return 1;}
   say("Ghoul digs a grave.\n");
   say("Ghoul jumps in.\n");
   say("Ghoul pulls the dirt in on top of itself.\n");
   ob->set_has_ghoul(0);
   ob->ssave();
   destruct(TO);
   return 1;
 }	    

fight(str){
 if(!str && !owner->query_attack()){ write("Your Ghoul looks puzzled.\n"); return 1;} 
 if(!str && TO->query_attack()){ 
   write("Your Ghoul is already attacking "+TO->query_attack()->query_name()+".\n");
   return 1; }
 if(!str && owner->query_attack() && !attacker_ob &&
    !owner->query_attack()->is_player()){
   say("Ghoul nogs and attacks "+owner->query_attack()->query_name()+".\n");
   attacker_ob = owner->query_attack();
   return 1; }
 target = present(str, ENV(TO));
 if(!target){ write("Your Ghoul doesn't see any "+str+" here.\n"); return 1;}
    if(target->query_npc() == 0) {
    write("Ghoul's won't attack players.\n");
    return 1;
    }
   say("Ghoul nogs and attacks "+target->query_name()+".\n");
   attacker_ob = target;
   return 1;
 }

stop_it(){
 object target;
 say(capitalize(TPRN)+" slaps "+TP->query_possessive()+" Ghoul upside the head.\n");
 say("The ghoul nogs.\n");
 target = TO->query_attack();
 if(target){
  TO->stop_fight();
  target->stop_fight();
  target->stop_fight();
  TO->stop_fight();
 }
 set_heart_beat(1);
 sit = 0;
 return 1;
}

/*
add_exp(arg) {
 if(arg < 0) return 1;
 if(owner)owner->add_exp(arg);
}
*/

give_object(str){ 
 string item, dest;
 object item_ob, dest_ob;
 int weight;
 int coins;
   if(!str) return 0;
   if(sscanf(str, "%s to %s", item, dest) != 2) {
     write("Ghoul rasps: Transfer what to whom?\n");
     return 1;
    }
    dest = lower_case(dest);
    if(item){
      item = lower_case(item);
      item_ob = present(item, TO);
      if(!item_ob){
        write("Ghoul doesn't see any " + item + " here.\n");
	return 1;
	}
      if(ENV(item_ob) == TO && 
	    call_other(item_ob, "drop", 0) == 1) {
	    return 1;
	} else {
	    if(!call_other(item_ob, "get")) {
	     write("Ghoul cannot transfer that item.\n");
	     return 1;
	    }
	}
    }
    dest_ob = present(dest, ENV(TO));
    if(!dest_ob) {
     write("Ghoul doesn't see "+capitalize(dest)+ " here.\n");
     return 1;
    }
    if(!living(dest_ob)) {
      write("Ghoul doesn't give stuff to non-living objects.\n");
      return 1;
    }
    weight = call_other(item_ob, "query_weight", 0);
    if(!call_other(dest_ob, "add_weight", weight)) {
      write("Ghoul realizes "+capitalize(dest) + " can't carry any more.\n");
      return 1;
    }
    add_weight(-weight);
    move_object(item_ob, dest_ob);
    tell_room(ENV(TO),
        "Ghoul gives "+item+" to "+capitalize(dest)+".\n");
        return 1;
    }

get_all(from) {
 object thing, next_ob;
 string it;
  thing = first_inventory(from);
   while(thing) {
     string item;
     next_ob = next_inventory(thing);
     item = call_other(thing, "short", 0);
     if(item && !thing->is_money() && call_other(thing, "get", 0)){
       int weight;
       weight = call_other(thing, "query_weight", 0);
       if(add_weight(weight)) {
         MO(thing, TO);
         say("Ghoul takes: " + item + ".\n");
       } else {
           write("Ghoul rasps: "+item + " Too heavy.\n");
	 }
       it = item;
       }
     thing = next_ob;
    }
  }
   
pick_up(str){
 string item;
 string container;
 object item_o;
 object container_o;
 int weight;
   if(!str){
     write("Ghoul looks confused.\n"); return 1; }
   if(str == "all"){
     get_all(environment()); return 1; }
   if(sscanf(str, "%s from %s", item, container) != 2) {
     pick_item(str);
     return 1; }
   container_o = present(lower_case(container));
   if(!container_o) {
     write("Ghoul sees no " + container + " here.\n");
     return 1; }
   if(!call_other(container_o, "can_put_and_get", 0)) {
     write("Ghoul can't do that!\n");
     return 1; }
   item_o = present(item, container_o);
     if(!item_o){
       write("Ghoul sees no " + item + " in the " + container + ".\n");
       return 1; }
   if(!call_other(item_o, "get", item)) {
     write("Ghoul cannot take " + item + " from " +
     container + ".\n");
     return 1; }
   weight = call_other(item_o, "query_weight", 0);
   if(!add_weight(weight)) {
     write("Ghoul cannot carry more.\n");
     return 1; }
   call_other(container_o, "add_weight", -weight);
   MO(item_o, TO);
     say("Ghoul takes " + item + " from " + container + ".\n");
     return 1; }

pick_item(obj) {
 object ob;
 int i;
 string it;
 obj = lower_case(obj);
  if(ENV(TO)->id(obj)) {
     write("Ghoul can't take that.\n");
     return 1;
   }
   ob = present(obj, ENV(TO));
   if(!ob){
     write("Ghoul doesn't see it.\n");
     return 1;
   }
     if(ob->is_money()){
       write("Your Ghoul can't take coins.\n");
     return 1;
   }
   if(ENV(ob) == TO){
     write("Ghoul already has it.\n");
     return 1;
   }
   if(call_other(ob, "get", 0) == 0) {
     write("Ghoul cannot take that.\n");
     return 1;
   }
   i = call_other(ob, "query_weight", 0);
   if(add_weight(i)){
     MO(ob, TO);
     say("Ghoul takes " + obj + ".\n");
     it = obj;
     return 1;
   }
   write("Ghoul can't carry that much.\n");
   return 1;
  }

use_weapon(str){
 command("wield "+str);
 return 1;
}

put_on(str){
 object ob;
 if(!str){ write("Gwear what?.. example. 'gwear shield'.\n"); return 1; }
 ob = present(str, TO);
 if(!ob){ write("Your ghoul doesn't have a "+str+".\n"); return 1; }
 if(ob->armor_class() || ob->is_armor()){
   if(ob->query_type() == "shield" || ob->query_type() == "ring"){
     command("wear "+str);
     return 1; }
   write("Your Ghoul can not wear "+ob->query_name()+".\n"); return 1; }
 }

drop_item(obj) {
 string tmp;
 string tmp2;
 int i;
  if(!obj) {
    write("What ?\n");
    return 1;
  }
   tmp = obj;
   obj = present(lower_case(obj), this_object());
   if(!obj) {
     write("Your Ghoul is not carrying that.\n");
     return 1;
   }
   if(drop_one_item(obj)) {
     obj = tmp;
     write("Ok.\n");
     say("Ghoul drops the " + tmp + ".\n");
   }
   return 1;
 }

drop_one_item(ob){
 int weight;
 if(call_other(ob, "drop", 0)) return 0;
   weight = call_other(ob, "query_weight", 0);
   if(!weight)
     weight = 0;
     add_weight(-weight);
     MO(ob, ENV(TO));
     return 1;
}

ghoulfood(){
 object ob;
  ob = present("corpse", ENV(TO));
  if(!ob){
    notify_fail("Your Ghoul looks around but can't find a corpse.\n");
    return 0;
  }
  say("Ghoul reaches down and absorbs "+ob->short()+".\n");
  hit_point += ob->heal_value();
  if(hit_point > max_hp) hit_point = max_hp;
  destruct(ob);
  return 1;
}

gready(){ 
 string item;
 item = first_inventory(TO);
 while(item){
  object next;
  object str;
  string ob;
  next = next_inventory(item);
  if(!living(item)){
    str = item->short();
    if(str){
     write(str+ "...\n");
     ob = item->query_name();
     item->wield(ob);
      if(item->armor_class() || item->is_armor())
       if(item->query_type() == "shield" || item->query_type() == "ring"){
        command("wear "+ob); }
       else{
        write("Your Ghoul can't wear "+ob+".\n"); }
      if(item->weapon_class())
        command("wield "+ob);
      }
    }
   item = next;
  }
 return 1;
}

heart_beat(){
 
 if(root()) return;
 if(!owner) return;
 ::heart_beat();
  if(owner && sit != 1 && !owner->query_ghost()){
  if(ENV(TO) != ENV(owner)){
    say("Ghoul crawls after "+capitalize(owner->query_name())+".\n");
    MO(TO, ENV(owner));
    say("Ghoul stumbles in after "+capitalize(owner->query_name())+".\n");
    set_heart_beat(1);
  }
  if(TO->query_attack() && mon_ok == 1){
    tell_object(owner, 
     BOLD+HIY+"Ghoul: "+((hit_point * 10)/max_hp)+" / 10"+NORM+"\n");
  } 
  if(!TO->query_attack() && owner->query_attack() && !owner->query_attack()->is_player() && auto_ok != 0){
     say("Ghoul nogs and attacks "+owner->query_attack()->query_name()+".\n");
    attacker_ob = owner->query_attack();
  }
 }
}

show_decay(){
  tell_object(owner,
   BOLD+HIY+"\n\tYour ghoul starts to decompose...\n\n"+NORM);
  }

decay(){
 if(!owner) return destruct(TO);
 ob = present("dark_circle", owner);
  tell_room(ENV(TO),
    TO->short()+" slowly decomposes into dust and blows away.\n");
  tell_object(owner,
    BOLD+YEL+"\n\tYour ghoul decomposes and blows away.\n"+NORM);
    ob->set_has_ghoul(0);
    ob->ssave();
  destruct(TO);
  }

coin_drop(obj){
 object bling;
 int amt, total;
 total = TO->query_money();
   if(!obj){
     tell_object(owner, "Ghoul has "+total+" coins how much should it drop?\n"); return 1;}
   if(owner->query_ghost()){
     tell_object(owner, "The ghoul ignores your lifeless body.\n"); return 1;}
   if(sscanf(obj, "%d coins", amt) || sscanf(obj, "%d money", amt) ||
      sscanf(obj, "%d gold coins", amt) || sscanf(obj, "%d coin", amt))
   {
     if(amt <= 0 || total < amt)
     return (tell_object(owner, "Your Ghoul only has "+total+" coins.\n"), 1);
   bling = CO("/obj/money");
   bling->set_money(amt);
   MO(bling, ENV(TO));
   TO->add_money(-amt);
   write("Ghoul drops "+amt+" coins.\n");
   return 1; }
 }
 
second_life(){
 if(owner){
 ob = present("dark_circle", owner);
 ob->set_has_ghoul(0);
 ob->ssave();
 ::second_life();
 }
}

is_ghoul(){ return 1; }
