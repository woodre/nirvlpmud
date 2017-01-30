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
 
  add_action("growl","growl");
  add_action("pounce","pounce");
  add_action("howl","howl");
  add_action("bark","bark");
  add_action("whine","whine");

 /* effective actions */
 
  add_action("run_to","run");
  add_action("not","wear");
  add_action("nott","wield");
  add_action("normal","smn");
}

resetter() {
if(ep) {
 ep->set_wc(15);
 ep->set_ac(6);
 if(ep->query_hp() > 220) {
   ep->add_hit_point(-((ep->query_hp()) - 220));} }
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
  write("New emotes:   growl  bark  howl  whine  pounce \n\n");
  write("New actions:  run <area name> - run to certain places\n"+
        "                  <church> <shrine> <chamber> <shop> <forest_path>\n"+
        "                  <library> <advance> <hotel> <post>\n");
  write("                  also a guild member <name>\n\n"+
        "Notes:\n"+
        "        1> You may not wear or wield anything in this form\n"+
        "        2> You do have a set amount of protection and strength\n"+
        "        3> Your hp may not go above 220\n");
return 1;}

not() {
  write("You may not do that!\n");
return 1;}

nott(str) {
  if(str != "aura_of_shape") { not(); return 1;}
  pt=tp->query_pretitle();
  ti=tp->query_title();
  tp->set_title(NORM+HIY+"the Winter Wolf"+NORM);
  tp->set_pretitle(HIY+"<"+NORM+HIR+"0"+NORM+HIY+"> ");
}

/* emotes */

growl() {
object ob,ob2; 
int mk; 
  write("You growl like only a wolf could.\n");
  say("The "+HIY+"Winter Wolf"+NORM+" growls- a frightening sound.\n");
  ob=all_inventory(environment(tp));
  for(mk=0;mk<sizeof(ob);mk++) {
  if(living(ob[mk]) && (call_other(ob[mk],"id","wolf") || call_other(ob[mk],"id","dog"))) {
  tell_room(environment(tp),"A dog runs away from the "+HIY+"Winter Wolf"+NORM+".\n");
  ob[mk]->run_away(); }
  }
return 1;}

howl() {
object ob;
int n;
ob = users();
write("You HOWL like only a wolf could.\n");
for(n=0;n<sizeof(ob);n++){
 if(present(fear,ob[n])) {
    tell_object(ob[n],"<dt> You hear a wolf <"+tpn+"> HOWL in the distance....\n"); }
  }
say("The "+HIY+"Winter Wolf"+NORM+" lets out a hair raising   H  O  W  L !\n");
emit_channel("gossip","<gossip>     "+RED+"You hear a hair-raising howl off in the distance!\n"+NORM);
return 1;}

bark() {
  write("You bark.\n");
  say("The "+HIY+"Winter Wolf"+NORM+" barks loudly and sharply!\n");
return 1;}

whine() {
  write("You whine.\n");
  say("The "+HIY+"Winter Wolf"+NORM+" lets out a sad whine that touches your heart.\n");
return 1;}

pounce(str) {
  if(!str) { write("You pounce around.\n");
             say("The "+HIY+"Winter Wolf"+NORM+" pounces on some random object.\n");
             return 1;}
    if(present(str,environment(tp))) {
      if(living(present(str,environment(tp)))) {
            write("You pounce on "+capitalize(str)+".\n");   
            tell_object(present(str,environment(tp)),"The "+HIY+"Winter Wolf"+
            NORM+" pounces on you!\n");             
            say("The "+HIY+"Winter Wolf"+NORM+" pounces on "+capitalize(str)+"!\n"); 
            return 1;} 
          write("You pounce on "+str+"\n");
          say(" The "+HIY+"Winter Wolf"+NORM+" pounces on "+str+"!\n");
          return 1;}
            write("There is no "+str+".\n");
return 1;}

/*effective actions*/

run_to(str) {
  if(environment(tp)->realm() == "NT") { write("You are in an area that is hard to run out of.\n");
     return 1;}
  if(tsp < 40) {  write("You do not have the energy to run off.\n"); return 1;}
  tell_room(environment(tp),"The "+HIY+"Winter Wolf"+NORM+" runs off.\n");
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
    if(tsp < 60) {  write("You do not have the energy to run off.\n"); return 1;}
    if(!present(fear,find_player(str))) { write("Not a guild member...\n"); return 1;}
    if(environment(find_player(str))->realm() != "NT") {
      write("That person is in an area into which you may not run.\n"); return 1;}
    move_object(tp,environment(find_player(str))); 
    tp->add_spell_point(-20);}
    command("l",tp);
  tell_room(environment(tp),"A "+HIY+"Winter Wolf"+NORM+" runs in.\n");
  tp->add_spell_point(-40);
return 1;}
