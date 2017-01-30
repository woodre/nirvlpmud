#include "/players/mythos/closed/guild/def.h"
string ti, pt;
id(str) {return str == "form_ob"; }
		
get() {return 0; }
drop() {return 1;}

query_weight() {return 0;}
query_value() {return 0; }

reset(arg) {
  if(arg) return;
   call_out("resetter",3);
}

init() {
 /* help file */
 
  add_action("shelp","shape_help");
  
 /* emotes */
 
#ifndef __LDMUD
  add_action("flap");add_xverb("flap");
#else
 add_action("flap", "flap", 3);
#endif
  add_action("takeoff","takeoff");
  add_action("land","land");
  add_action("soar","soar");
  add_action("preen","preen");
  add_action("squawk","squawk");
  add_action("circle","circle");
  add_action("dive","dive");

 /* effective actions */
 
  add_action("first_strike","first_strike");
  add_action("fly_to","fly");
  add_action("not","wear");
  add_action("nott","wield");
  add_action("normal","smn");
}

resetter() {
if(ep) {
 ep->set_wc(17);
 ep->set_ac(3);
 if(ep->query_hp() > 200) {
   ep->add_hit_point(-((ep->query_hp()) - 200));} }
 call_out("resetter",3);
return 1;}

normal() {
  destruct(present("prevent",tp));
  destruct(present("aura_of_shape",tp));
  tp->set_title(ti);
  tp->set_pretitle(pt);
  tp->set_wc(3);
  tp->set_ac(0);
  tp->save_me();
  return 0;
}

shelp() {
  write("New emotes:   flap1  flap2  flap3  soar  preen \n"+
        "              squawk  circle  dive  land  takeoff\n\n");
  write("New actions:  first_strike <name>  - a deadly first attack\n"+
        "              fly <area name>      - fly to certain places\n"+
        "                  <church> <shrine> <chamber> <shop> <forest_path>\n"+
        "                  <library> <advance> <hotel> <post>\n");
  write("                  also a guild member <name>\n\n"+
        "Notes:\n"+
        "        1> You may not wear or wield anything in this form\n"+
        "        2> You do have a set amount of protection and strength\n"+
        "        3> Your hp may not go above 200\n");
return 1;}

not() {
  write("You may not do that!\n");
return 1;}

nott(str) {
  if(str != "aura_of_shape") { not(); return 1;}
  pt=tp->query_pretitle();
  ti=tp->query_title();
  tp->set_title(NORM+RED+"the Blood Bird"+NORM);
  tp->set_pretitle(RED+"<o> ");
}

/* emotes */

flap(str) {
  if(str == "1") {  write("You lazily flap your wings.\n");
                    say("The bird lazily flaps its wings.\n"); }
  if(str == "2") {  write("You flap your wings.\n");
                    say("The "+RED+"Blood Bird"+NORM+" flaps its wings.\n"); }
  if(str == "3") {  write("You flap your wings in frustration.\n");
                    say("The "+RED+"Blood Bird"+NORM+" flaps its wings in frustration.\n"); }
return 1;}

soar() {
  write("You soar above everyone and everything.\n");
  say("The "+RED+"Blood Bird"+NORM+" soars overhead.\n");
return 1;}

preen() {
  write("You clean your feathers.\n");
  say("The "+RED+"Blood Bird"+NORM+" preens itself.\n");
return 1;}

squawk() {
  write("You cry out.\n");
  say("The "+RED+"Blood Bird"+NORM+" squawks.\n");
return 1;}

circle() {
  write("You circle above everything.\n");
  say("The "+RED+"Blood Bird"+NORM+" circles above.\n");
return 1;}

dive(str) {
  if(!str) { write("You dive down, creating terror in everone.\n");
             say("The "+RED+"Blood Bird"+NORM+" dives down at you!  Terror fills you!\n");
            return 1;}
  if(str && present(str,environment(tp))) {
            write("You dive down at "+str+".\n");         
            tell_object(present(str,environment(tp)),"The "+RED+"Blood Bird"+NORM+" dives down at you!\n"+
            "Terror fills you!\n");
            say("The "+RED+"Blood Bird"+NORM+" dives down at "+str+"!\n");
            return 1;}
            write("There is no "+str+".\n");
return 1;}

land(str) {
   if(!str) { write("You land.\n");
             say("The "+RED+"Blood Bird"+NORM+" lands.\n");
            return 1;}
  if(str && present(str,environment(tp))) {
            write("You land on "+str+".\n");       
            tell_object(present(str,environment(tp)),"The "+RED+"Blood Bird"+NORM+" lands on you!\n");
            say("The "+RED+"Blood Bird"+NORM+" lands on "+str+"!\n");
            return 1;}
            write("There is no "+str+".\n");
return 1;}

takeoff() {
  write("You take to the air.\n");
  say("The "+RED+"Blood Bird"+NORM+" rises into the air.\n");
return 1;}

/*effective actions*/

fly_to(str) {
  if(environment(tp)->realm() == "NT") { write("You are in an area that is hard to fly out of.\n");
     return 1;}
  if(tsp < 40) {  write("You do not have the energy to fly off.\n"); return 1;}
  tell_room(environment(tp),"The "+RED+"Blood Bird"+NORM+" rises into the air and soars off.\n");
  if(str == "shrine") {  move_object(tp,"/players/mythos/aroom/shrinear3.c"); }
  if(str == "library") { move_object(tp,"/players/mythos/lroom/hall.c"); }
  if(str == "forest_path") { move_object(tp,"/players/mythos/aroom/forest/pathway4.c"); }
  if(str == "church") { move_object(tp,"/room/church.c"); }
  if(str == "chamber") { move_object(tp,"/players/mythos/enterance.c"); }
  if(str == "advance") { move_object(tp,"/room/adv_guild.c"); }
  if(str == "hotel") { move_object(tp,"/players/boltar/hotel/hotel.c"); }
  if(str == "post") { move_object(tp,"/room/post.c"); }
  if(str == "shop") { move_object(tp,"/room/shop.c"); }
  if(str != "shrine" && str != "church" && str != "library" && str != "forest_path" &&
    str != "chamber" && str != "advance" && str != "hotel" && str != "post" &&
    str != "shop") {
    if(!find_player(str)) { write("What?\n"); return 1;}
    if(tsp < 60) {  write("You do not have the energy to fly off.\n"); return 1;}
    if(!present(fear,find_player(str))) { write("Not a guild member...\n"); return 1;}
    if(environment(find_player(str))->realm() != "NT") {
      write("That person is in an area into which you may not fly.\n"); return 1;}
    move_object(tp,environment(find_player(str))); 
    tp->add_spell_point(-20);}
    command("l",tp);
  tell_room(environment(tp),"A "+RED+"Blood Bird"+NORM+" soars in.\n");
  tp->add_spell_point(-40);
return 1;}

/* this first_strike is an attack spell that may only be
 * cast once on a target (and only as a surprise attack)
 * - thus i ask to be allowed to do abit more damage
 * than legal [ 90 sp for 50 damage instead of 100 sp for 50]
 *                                                   - Mythos */

first_strike(str) {
string name;
object target;
if(qtf < 19) { write("Your control over fae is not enough!\n"); return 1;}
if(tsp < 90) { write("You do not have enough energy!\n"); return 1;}
if(scrp < 90) { write("The darkness calls for a sacrifice.\n"); return 1;}
if(!str) { write("Usage: first_strike <name>\n"); return 1;}
name = str;
if(tp->query_attack() && (tp->query_attack())->id(name)) {
  write("You are attacking that creature already.\n"+
        "Therefore you may not do a 'first' strike on it.\n");
  return 1;}
  target = present(name,environment(tp));
  if(!target) {write("That is not here.\n"); return 1;}
  if(!living(target) || target->query_ghost()) { 
  write("That is not something to attack.\n");
  return   1;}
  if(!(target->query_npc()) &&  !dpp) {
    write("You may not use this on players at this time.\n"); return 1;} 
  if(present("deathmark",target)) {
    write("You can only do first_strike once on a target!\n"); return 1;}
  move_object(clone_object("/players/mythos/closed/guild/death/ddeath.c"),target);
  tell_room(environment(tp),"The "+RED+"Blood Bird"+NORM+" flies straight up.\n"+
            "Higher...  Higher...\nSuddenly, surrounded in "+BLU+"COLD FIRE,"+NORM+
            "it....\n\n\t"+BLU+"D\n\t  I\n\t    V\n\t      E\n\t        S\n\n"+NORM+
            "into "+capitalize(name)+"!\n");
  tell_room(environment(tp),capitalize(name)+" screams in terror and pain!\n");
  target->set_heal(0,1000);
  target->heal_self(-50);
  target->attack_object(tp);
  tp->atack_object(target);
  tp->add_spell_point(-90);
  pp->add_sacrifice(-90);
return 1;}
