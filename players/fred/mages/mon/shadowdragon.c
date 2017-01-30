#include "/players/fred/mages/defs.h"

inherit "obj/monster";

object owner, rider, stalkee, ob;
string who, nameme, direction, target_name, it;
object target;
int rest, auto_ok, mon_ok, st;

long(){
  write("A Shadow Dragon is a creature from the plane of shadows.\n");
  write("It seeks darkness and squirms uncomfortably around in bright\n");
  write("light. You can't really get a good look at it.\n");
  if(TP == owner){
    write("Use 'dcmds' for more details.\n"); }
    if(hit_point < (max_hp/10)) {
      write(cap_name+" is in very bad shape.\n"); return; }
    if(hit_point < (max_hp/5)) {
      write(cap_name+" is in bad shape.\n"); return; }
    if(hit_point < (max_hp/2)) {
      write(cap_name+" is somewhat hurt.\n"); return; }
    if(hit_point < (max_hp - 20)){
      write(cap_name+" is slightly hurt.\n"); return; }
      write(cap_name+" is in good shape.\n");
 }

init(){
 ::init();
   if(TP && TP == owner && !TP->query_ghost()) {
   add_action("fight","dkill");
   add_action("fade","fade");
   add_action("release", "release");
   add_action("drest","drest");
   add_action("dstop","dstop");
   add_action("give_object","dtransfer");
   add_action("drop_item","dtoss");
   add_action("regenerate","regenerate");
   add_action("pick_up","dget");
   add_action("name","dname");
   add_action("mount", "mount");
   add_action("dismount", "dismount");
   add_action("auto_check","dauto");
   add_action("dmon","dmon");
   if(environment(this_player()) == this_object()){
   add_action("yell","yell");
   add_action("yell","say");
#ifndef __LDMUD__
  add_action("yell"); add_xverb("\"");
  add_action("yell"); add_xverb("'");
#else
  add_action("yell", "\"", 3);
  add_action("yell", "'", 3);
#endif
   add_action("go_north","n");
   add_action("go","go");
   add_action("see","see");
   add_action("see","view");
   add_action("go_south","s");
   add_action("go_east","e");
   add_action("go_west","w");
   add_action("go_up","u");
   add_action("go_down","d");
   add_action("go_northwest","nw");
   add_action("go_southwest","sw");
   add_action("go_northeast","ne");
   add_action("go_southeast","se");
   add_action("go_north","north");
   add_action("go_south","south");
   add_action("go_east","east");
   add_action("go_west","west");
   add_action("go_up","up");
   add_action("go_down","down");
   add_action("go_northwest","northwest");
   add_action("go_southwest","southwest");
   add_action("go_northeast","northeast");
   add_action("go_southeast","southeast");
   }
  }
 }

 
reset(arg) {
::reset();
    if(arg) return;
    set_race("dragon");
    set_name("shadow dragon");
    set_alias("dragon_obj");
    set_short(BOLD+BLK+"Shadow Dragon, the Dark Beast"+NORM+" (lord of evil)");
    set_level(8);
    set_wc(15);
    set_ac(7);
    set_hp(160);
    set_heal(2,2);
    set_ep(1);
    set_spell_mess1("Shadow Dragon releases a ray of withering.\n");
    set_spell_mess2("Shadow Dragon zaps you with a ray of withering.\n");
    set_chance(10);
    set_spell_dam(15+random(15));
    set_dead_ob(this_object());
    set_can_kill(1);
    enable_commands();
    auto_ok = 1;
    mon_ok = 1;
}

heart_beat(){
 ::heart_beat();
/*
 if(TO->query_attack() && (TO->query_attack()->query_hp() < 20)){
   say(cap_name+" disintegrates "+capitalize(TO->query_attack()->query_name())+" with a cone of disruption.\n");
   TO->query_attack()->death();
 }
*/
 if(owner && rest != 1 && !owner->query_ghost()){
  if(rider){ return; } 
  /*
  if(present(owner, ENV(TO))){
    MO(TO, ENV(owner));
    set_heart_beat(1);
    }
   */
  if(ENV(TO) != ENV(owner)){
    say(cap_name+" disappears after "+capitalize(owner->query_name())+".\n");
    MO(TO, ENV(owner));
    say(cap_name+" appears out of the shadows besides "+capitalize(owner->query_name())+".\n");
    set_heart_beat(1);
    }
  if(!TO->query_attack() && owner->query_attack() && !owner->query_attack()->is_player() && auto_ok != 0){
    say(cap_name+" becomes enraged and attacks "+owner->query_attack()->query_name()+".\n");
    attacker_ob = owner->query_attack();
  } 
  if(TO->query_attack() && mon_ok == 1){
    tell_object(owner, 
     HIY+cap_name+": "+((hit_point*10)/max_hp)+" / 10"+NORM+"\n");
  } 
 }
}

patch_owner(o) { owner = o; }

query_owner(){ return owner; }

is_pet(){ return 1; }

dstop(){
object target;
 say(capitalize(TPRN)+" hits "+TP->query_possessive()+" Dragon upside the head.\n");
 say(cap_name+" nods.\n");
 target = TO->query_attack();
 if(target){
  TO->stop_fight();
  target->stop_fight();
  target->stop_fight();
  TO->stop_fight();
 }
 set_heart_beat(1);
 rest = 0;
 return 1;
}

auto_check(str){ 
 if(!str){  tell_object(owner, 
     "Please use 'dauto <on/off>'\n"); return 1; }
 if(str == "on" && auto_ok == 1){
   write(HIY+cap_name+"'s auto attack is already: ON.\n"+NORM); return 1; }
 if(str == "on" && auto_ok != 1){
   write(HIY+cap_name+"'s auto attack is now: ON.\n"+NORM);
   auto_ok = 1;
   return 1; }
 if(str == "off" && auto_ok != 1){
   write(HIY+cap_name+"'s auto attack is already: OFF.\n"+NORM); return 1; }
 if(str == "off" && auto_ok == 1){
   write(HIY+cap_name+"'s auto attack is now: OFF.\n"+NORM);
   auto_ok = 0;
   return 1; }
  }

dmon(str){ 
 if(!str){  tell_object(owner, 
     HIY+cap_name+": "+((hit_point*10)/max_hp)+" / 10"+NORM+"\n");

     return 1; }
 if(str == "on" && mon_ok == 1){
   write(HIY+cap_name+"'s monitor is already: ON.\n"+NORM); return 1; }
 if(str == "on" && mon_ok != 1){
   write(HIY+cap_name+"'s monitor is now: ON.\n"+NORM);
   mon_ok = 1;
   return 1; }
 if(str == "off" && mon_ok != 1){
   write(HIY+cap_name+"'s monitor is already: OFF.\n"+NORM); return 1; }
 if(str == "off" && mon_ok == 1){
   write(HIY+cap_name+"'s monitor is now: OFF.\n"+NORM);
   mon_ok = 0;
   return 1; }
  }

drest(){
  if(TO->query_attack()){
    write(cap_name+" is too busy fighting.\n");
    return 1; 
    }
  say(cap_name+" nods at "+owner->query_name()+" and lays down to rest.\n");
  rest = 1;
  return 1;
 }

/*
add_exp(e){ 
 if(owner){
     owner->add_exp(e);
    return 1;
    }
  return 0;
}
*/
    
regenerate(){
  if(TP->query_sp() < 150){
    write("You need more spell points for this spell.\n"); return 1;}
     TO->set_hp(350);
     TO->heal_self(300);
  write(BOLD+BLK+"You regenerate your Shadow Dragon.\n"+NORM);
  say(capitalize(TPN)+" casts a regeneration spell upon "+cap_name+".\n");
  TP->add_spell_point(-150);
  return 1;
  } 

mount(){
 if(rider){
   write("You are already mounted.\n"); return 1;}
 if(TO->query_attack()){
   write(cap_name+" cannot be mounted in the heat of battle.\n"); return 1; }
   MO(TP, TO);
   write("You jump into the saddle of your Shadow Dragon.\n");
   say(capitalize(owner->query_name())+" mounts "+cap_name+",\n");
   rider = owner;
   return 1;
   }

dismount(str){
  if(rider){
    MO(TP, ENV(TO));
    write("You jump out of the saddle of your Shadow Dragon.\n");
    say(capitalize(owner->query_name())+" dismounts "+cap_name+".\n");
    rider = 0;
    return 1;
    }
  write("You are not mounted.\n");
  return 1;
  }

yell(str){
  tell_room( environment(), this_player()->query_name() +" shouts from atop the dragon:\n\
   '"+capitalize(str)+"'.\n");
  return 1;
  }
               
release(str){ 
 ob = present("dark_circle", TP); 
 if(str != "dragon" && str != nameme){ notify_fail("Release what?\n"); return 0; }
    say(cap_name+" says: I return to the Plane of Shadows.\n");
    say(cap_name+" flies away into an eveloping cloud of darkness.\n");
    ob->set_has_dragon(0);
    ob->ssave();
    destruct(TO);
    return 1;
   }        

name(str){
 object ob;
 ob = present("dark_circle", TP);
 if(!str) return 0;
  nameme = lower_case(str);
  set_name(nameme);
  ob->set_dragon_name(nameme);
  ob->ssave();
  set_short(BOLD+BLK+capitalize(nameme)+" the Shadowdragon"+NORM+" (lord of evil)");
  write("Name changed to: "+capitalize(nameme)+".\n");
  return 1;
 }
     
go(str){
 if(!str){ write(cap_name+" asks: Go where?\n"); return 1; }
  direction = str;
  command(str, TO);
  see();
  return 1;
 }

fight(str){
  if(!str && !owner->query_attack()){ write(cap_name+" looks puzzled.\n"); return 1; }
  if(!str && TO->query_attack()){ write(cap_name+" is already attacking "+TO->query_attack()->query_name()+".\n"); return 1; }
  if(!str && owner->query_attack() && !attacker_ob && !owner->query_attack()->is_player()) {
   say(cap_name+" becomes enraged and attacks "+owner->query_attack()->query_name()+".\n");
   attacker_ob = owner->query_attack();
   return 1; }
 target = present(str, ENV(TO));
 if(!target){
   write(cap_name+" doesn't see "+str+".\n"); return 1; }
 if(target->query_npc() == 1){
  say(cap_name+" becomes enraged and attacks "+target->query_name()+".\n");
     attacker_ob = target;
   if(rider){
      MO(rider, ENV(TO));
      write(cap_name+"'s wild attack throws you off.\n");
      rider = 0;
      }
     return 1;
    }
    write("Your dragon will not attack that.\n");
    return 1;
    }

give_object(str) { 
 string item, dest;
 object item_ob, dest_ob;
 int weight;
 int coins;
  if(!str) return 0;
    if(sscanf(str, "%s to %s", item, dest) != 2){
      write(cap_name+" rasps: Transfer what to whom?\n"); return 1; }
      dest = lower_case(dest);
     if(item){
       item = lower_case(item);
       item_ob = present(item, TO);
       if(!item_ob){
         write(cap_name+" doesn't see any "+item+" here.\n"); return 1; }
         if(environment(item_ob) == this_object() &&
         call_other(item_ob, "drop", 0) == 1) {
         return 1;}
        else{
         if(!call_other(item_ob, "get")){
           write(cap_name+" cannot transfer that item.\n");
           return 1;}
         }
       }
    dest_ob = present(dest, ENV(TO));
    if(!dest_ob){
      write(cap_name+" doesn't see any "+capitalize(dest)+" here.\n");
      return 1;}
    if(!living(dest_ob)) {
      write(cap_name+" doesn't give stuff to non-living objects.\n");
      return 1;}
    weight = call_other(item_ob, "query_weight", 0);
    if(!call_other(dest_ob, "add_weight", weight)){
      write(cap_name+" realizes "+capitalize(dest)+" can't carry any more.\n");
      return 1;}
    add_weight(-weight);
    MO(item_ob, dest_ob);
    write(cap_name+" gives "+item+" to "+capitalize(dest)+".\n");
    return 1;
    }

get_all(from){
 object thing, next_ob;
 string it;
  thing = first_inventory(from);
   while(thing) {
     string item;
     next_ob = next_inventory(thing);
     item = call_other(thing, "short", 0);
       if(item && call_other(thing, "get", 0)){
       int weight;
       weight = call_other(thing, "query_weight", 0);
         if(add_weight(weight)){
           MO(thing, TO);
           say(cap_name+" takes: "+item+".\n"); }
         else{
           write(cap_name+" rasps: "+item+" is Too heavy.\n"); }
         it = item;
         }
       thing = next_ob;
     }
   }
   
pick_up(str) {
 string item;
 string container;
 object item_o;
 object container_o;
 int weight;
  if(!str){
     write(cap_name+" is confused.\n"); return 1; }
   if(str == "all"){
     get_all(environment());
     return 1;}
   if(sscanf(str, "%s from %s", item, container) != 2){
     pick_item(str);
     return 1;}
    container_o = present(lower_case(container));
    if(!container_o){
      write(cap_name+" sees no "+container+" here.\n");
      return 1;}
    if(!call_other(container_o, "can_put_and_get", 0)){
      write(cap_name+" can't do that!\n");
      return 1;}
    item_o = present(item, container_o);
    if(!item_o){
      write(cap_name+" sees no "+item+" in the "+container+".\n");
      return 1;}
    if(!call_other(item_o, "get", item)){
      write(cap_name+" cannot take "+item+" from "+container+".\n");
       return 1;}
    weight = call_other(item_o, "query_weight", 0);
    if(!add_weight(weight)){
      write(cap_name+" cannot carry any more.\n");
      return 1;}
    call_other(container_o, "add_weight", -weight);
    MO(item_o, TO);
    say(cap_name+" takes "+item+" from "+container+".\n");
    return 1;
    }

pick_item(obj) {
 object ob;
 int i;
 string it;
 obj = lower_case(obj);
   if(ENV(TO)->id(obj)) {
     write(cap_name+" can't take that.\n");
     return 1;
     }
   ob = present(obj, environment(this_object()));
    if(!ob){
      write(cap_name+" doesn't see it.\n");
       return 1;
       }
     if(ENV(ob) == this_object()) {
       write(cap_name+" already has it.\n");
       return 1;
       }
     if(call_other(ob, "get", 0) == 0) {
       write(cap_name+" cannot take that.\n");
       return 1;
       }
     i = call_other(ob, "query_weight", 0);
     if(add_weight(i)) {
       MO(ob, TO);
       say(cap_name+" takes "+obj+".\n");
       it = obj;
       return 1;
      }
     write(cap_name+" can't carry that much.\n");
     return 1;
     }

drop_item(obj) {
 string tmp;
 string tmp2;
 int i;
   if(!obj) {
     write("What ?\n");
     return 1;
     }
   if(obj == "all") {
      drop_all(1);
       return 1;
       }
     tmp = obj;
     obj = present(lower_case(obj), TO);
     if(!obj) {
       write("Your pet is not carrying that.\n");
       return 1;
       }
     if(drop_one_item(obj)) {
       obj = tmp;
       write("Ok.\n");
       say(cap_name + " drops the " + tmp + ".\n");
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

drop_all(verbose){
 object ob;
 object next_ob;
 ob = first_inventory(this_object());
  while(ob) {
   string out;
   next_ob = next_inventory(ob);
   it = call_other(ob, "short", 0);
   if(drop_one_item(ob) && verbose) {
     out = it + ".\n";
     say(cap_name + " drops " + out);
     tell_object(this_object(), "drop: " + out);
     }
   ob = next_ob;
  }
}

catch_tell(str) {
  if(!rider) return 0;
  tell_object(rider, str);
  return 1;
 }
 
see() {
 object ob, ob_tmp;
 string item, it;
 int max;
   call_other(environment(), "long", 0);
   ob = first_inventory(environment());
   max = 40;
   while(ob && max > 0) {
    if(ob != this_object()) {
      string short_str;
      short_str = call_other(ob, "short", 0);
        if(short_str) {
          max -= 1;
          write(short_str + ".\n");
          it =short_str;
         }
       }
     ob = next_inventory(ob);
    }
  return 1;
 }
 
fade(str){
 if(str == "out") {
   TO->set_invis(20);
   tell_object(TP, cap_name+" silently fades out of view.\n");
   st = 1;
   return 1;
   }
 if(str == "in"){
   TO->set_invis(0);
   tell_object(TP, cap_name+" silently fades in to view.\n");
   st = 0;
   return 1;
   }
  write(cap_name+" wants to know if it should fade in or fade out.\n");
  return 1;
}
     
go_north() {
  if(rider = this_player()){
  command("north");
  command("see",this_player());
  return 1;
  }
 return 0;
}

go_south() {
  if(rider = this_player()){
  command("south");
  command("see",this_player());
  return 1;
  }
 return 0;
}
 
go_east() {
  if(rider = this_player()){
  command("east");
  command("see",this_player());
  return 1;
  }
 return 0;
}

go_west() {
  if(rider = this_player()){
  command("west");
  command("see",this_player());
  return 1;
  }
 return 0;
}

go_northwest() {
  if(rider = this_player()){
  command("northwest");
  command("see",this_player());
  return 1;
  }
 return 0;
}

go_northeast() {
  if(rider = this_player()){
  command("northeast");
  command("see",this_player());
  return 1;
  }
 return 0;
}

go_southwest() {
  if(rider = this_player()){
  command("southwest");
  command("see",this_player());
  return 1;
  }
 return 0;
}

go_southeast() {
  if(rider = this_player()){
  command("southeast");
  command("see",this_player());
  return 1;
  }
 return 0;
}

go_up() {
  if(rider = this_player()){
  command("up");
  command("see",this_player());
  return 1;
  }
 return 0;
}

go_down() {
  if(rider = this_player()){
  command("down");
  command("see",this_player());
  return 1;
  }
 return 0;
}

second_life(){
 if(owner){
 ob = present("dark_circle", owner);
 ob->set_has_dragon(0);
 ob->ssave();
  ::second_life();
 }
}
