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
 
  add_action("flap","flap");
  add_action("takeoff","takeoff");
  add_action("land","land");
  add_action("soar","soar");
  add_action("glare","glare");
  add_action("roar","roar");
  add_action("circle","circle");
  add_action("dive","dive");

 /* effective actions */
 
  add_action("breathe","breathe");
  add_action("fly_to","fly");
  add_action("not","wear");
  add_action("nott","wield");
  add_action("normal","smn");
}

resetter() {
if(ep) {
 ep->set_wc(18);
 ep->set_ac(7); }
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
  write("New emotes:   flap  soar  roar  circle  dive\n"+
        "              land  takeoff  glare\n\n");
  write("New actions:  breathe <name>  - a deadly attack\n"+
        "              fly <area name> - fly to certain places\n"+
        "                  <church> <shrine> <chamber> <shop> <forest_path>\n"+
        "                  <library> <advance> <hotel> <post>\n");
  write("                  also a guild member <name>\n\n"+
        "Notes:\n"+
        "        1> You may not wear or wield anything in this form\n"+
        "        2> You do have a set amount of protection and strength\n");
return 1;}

not() {
  write("You may not do that!\n");
return 1;}

nott(str) {
  if(str != "aura_of_shape") { not(); return 1;}
  pt=tp->query_pretitle();
  ti=tp->query_title();
  tp->set_title(NORM+BOLD+"the Dragon"+NORM);
  tp->set_pretitle(BOLD+"<"+NORM+HIY+"I"+NORM+BOLD+"> ");
}

/* emotes */

roar() {
write("You ROAR!\n");
say("The "+BOLD+"Dragon"+NORM+" lets out a thunderous  ROAR!\n");
 emit_channel("gossip","<gossip>     "+BOLD+"A Dragon roars in the distance....\n"+NORM);
return 1;}

glare(str) {
if(!str) {
     write("You glare at everyone.\n");
     say("The "+BOLD+"Dragon"+NORM+" glares at you with its firey eyes.\n"+
         "You feel FEAR!\n");
return 1;}
if(!present(str,environment(tp))){ write("Not here.\n"); return 1;}
  write("You glare at "+str+".\n");
  say("The "+BOLD+"Dragon"+NORM+" glares at "+str+".\n");
  tell_object(present(str,environment(tp)),
  "The "+BOLD+"Dragon"+NORM+" glares at you with its firey eyes.\n"+
         "You feel FEAR!\n"); 
return 1;}

flap(str) {
          write("You flap your wings.\n");
          say("The "+BOLD+"Dragon"+NORM+" flaps its leather-like wings.\n");
return 1;}

soar() {
  write("You soar above everyone and everything.\n");
  say("The "+BOLD+"Dragon"+NORM+" soars overhead.\n");
return 1;}

circle() {
  write("You circle above everything.\n");
  say("The "+BOLD+"Dragon"+NORM+" circles above.\n");
return 1;}

dive(str) {
  if(!str) { write("You dive down, creating terror in everone.\n");
             say("The "+BOLD+"Dragon"+NORM+" dives down at you!  Terror fills you!\n");
            return 1;}
  if(str && present(str,environment(tp))) {
            write("You dive down at "+str+".\n");      
            tell_object(present(str,environment(tp)),
            "The "+BOLD+"Dragon"+NORM+" dives down at you!\n"+
            "Terror fills you!\n");
            say("The "+BOLD+"Dragon"+NORM+" dives down at "+str+"!\n");
            return 1;}
            write("There is no "+str+".\n"); 
return 1;}

land(str) {
             write("You land.\n");
             say("The "+BOLD+"Dragon"+NORM+" lands.\n");
return 1;}

takeoff() {
  write("You take to the air.\n");
  say("The "+BOLD+"Dragon"+NORM+" rises into the air.\n");
return 1;}

/*effective actions*/

fly_to(str) {
  if(environment(tp)->realm() == "NT") { write("You are in an area that is hard to fly out of.\n");
     return 1;}
  if(tsp < 40) {  write("You do not have the energy to fly off.\n"); return 1;}
  tell_room(environment(tp),"The "+BOLD+"Dragon"+NORM+" rises into the air and flies off.\n");
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
  tell_room(environment(tp),"The "+BOLD+"Dragon"+NORM+" flies in.\n");
  tp->add_spell_point(-40);
return 1;}

/* The amount of sacrifice needed and spell points
 * actually make this spell slightly unbalanced 
 * against the player- you are doing a mere 100 points
 * of damage with 120 spell points and 20 hp and 900 points in
 * sacrifice (1 levels worth) and target wc goes up by 10
 *
 *                                           -Mythos */

breathe(str) {
string nam;
object target;
if(qtf < 19) { write("Your control over fae is not enough!\n"); return 1;}
if(tsp < 120) { write("You do not have enough energy!\n"); return 1;}
if(scrp < 750) { write("The darkness calls for a sacrifice.\n"); return 1;}
if(!str) { write("Usage: breathe <name>\n"); return 1;}
nam = str;
target = present(nam,environment(tp));
if(!target) {write("That is not here.\n"); return 1;}
  if(!(living(target)) || target->query_ghost()) { 
  write("That is not something to attack.\n"); return 1;}
  if(!(target->query_npc()) &&  !dpp) {
    write("You may not use this on players at this time.\n"); return 1;}
  write("You breathe "+BLU+"COLD FIRE"+NORM+" on "+capitalize(nam)+".\n");
  tell_room(environment(tp),"The "+BOLD+"Dragon"+NORM+" spews"+BLU+"\n\n"+
"      ****    ****    *       ***       ****    *    ***     ****\n");
tell_room(environment(tp),NORM+BLU+
"      *       *  *    *       *  *      *       *    *  *    *\n"+
"      *       *  *    *       *  *      ****    *    ***     ****\n");
tell_room(environment(tp),NORM+BLU+
"      *       *  *    *       *  *      *       *    *  *    *\n"+
"      ****    ****    ****    ***       *       *    *  *    ****\n\n"+NORM+
"onto "+capitalize(nam)+"!\n");
  command("scream",target);
  tell_object(target,"You feel "+BLU+"COLD"+NORM+".\n"+
              "The "+BLU+"COLD FIRE"+NORM+" has frozen you!\n");
  move_object(clone_object("/players/mythos/closed/guild/spells/freeze.c"),target);
  write("Your body can not handle the stress...\n");
  target->set_heal(0,1000);
  target->heal_self(-100);
  target->set_wc(target->query_wc() + 10);
  target->attack_object(tp);
  tp->atack_object(target);
  tp->heal_self(-20);
  tp->add_spell_point(-100);
  pp->add_sacrifice(-900);
return 1;}
