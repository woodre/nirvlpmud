#include "/players/pavlik/closed/colors.h"
#include "/players/pavlik/guild/mages/obj/dragon_spells"
#define DRAG present("mageobj", this_player())->query_dragon()
#define NME capitalize(DRAG->query_nme())

#define OWE DRAG->query_owner()

string dead_owners;
string dead_times;

reset(arg){
  if(arg) return;
  dead_owners = "none";
  dead_times = "100";
  move_object(this_object(), "players/pavlik/guild/mages/rooms/master_room");
}

id(str){ return str == "dragon-daemon"; }
short(){ return "Dragon Daemon"; }
long(){ write("The Dragon Daemon.\n"); return; }
get(){ return 1; }
drop(){ return 1; }
query_value(){ return 0; }
query_weight(){ return 999; }

query_dead_owner(){ return dead_owners; }
query_dead_times(){ return dead_times; }

exe_commands(str){
  string what, who;
    if(str == "save"){ dragon_save(); return 1; }
    if(str == "stay"){ dragon_stay(); return 1; }
    if(str == "follow"){ dragon_follow(); return 1; }
    if(str == "dismiss"){ dragon_dismiss(); return 1; }
    if(str == "report") { dragon_report(); return 1; }
    if(str == "setdescrip") { dragon_setdescrip(); return 1; }
    if(str == "assist") { dragon_assist(); return 1; }
    if(str == "lead") { dragon_lead(); return 1; }
    sscanf(str, "%s %s", what, who);
    if(what == "name"){ dragon_rename(who); return 1; }
    if(what == "guard"){ dragon_guard(who); return 1; }
    if(what == "giveme"){ dragon_give(who); return 1; }
    if(what == "kill"){ dragon_attack(who); return 1; }
    if(what == "say"){ dragon_say(who); return 1; }
    if(what == "emote"){ dragon_emote(who); return 1; }
    if(what == "setlook") { dragon_setlook(who); return 1; }
    if(what == "setmove") { dragon_setmove(who); return 1; }
    if(what == "wimpy"){ dragon_wimpy(who); return 1; }
    if(what == "assist"){ dragon_assist(who); return 1; }
}

dragon_save(){
  tell_room(environment(DRAG),
  NME+" appears to concentrate for a moment.\n"+
  NME+" gives you a toothy grin.");
  tell_object(find_player(OWE),"   (saved)");
  tell_room(environment(DRAG), "\n");
  DRAG->udate();
  return 1;
}

follow(str){
  object player;
  object dragon;
  object room;
  
  dragon=previous_object();
  room=environment(dragon);
  
  if(!(player=find_player(str)) || !room)
  {
    if(room)
      tell_room(room,
        capitalize(dragon->query_name())
        +" flaps his wings and flies off into the sky.\n");
    move_object(dragon, "/room/void");
    return destruct(dragon);
  }
  
  if(!dragon->query_follow() || !environment(player)) return;

  if(player->query_attack() && !dragon->query_attack()) {
    if(dragon->query_autoassist()) {
      dragon_autokill(player->query_attack(), dragon);
    }
  }

  if((dragon->query_hp() <= dragon->query_wimpy()) && (dragon->query_attack())) {
    tell_room(room,
    capitalize(dragon->query_name())+" panics and flees from the battle!\n"+
    capitalize(dragon->query_name())+" frantically flaps his wings and flies away!\n");
    tell_object(player,
    HIR+"Your dragon has fled from the battle.\n"+NORM);
    move_object(dragon, "players/pavlik/guild/mages/rooms/master_room");
    dragon->stop_fight();
    dragon->stop_hunter();
    dragon->set_follow(0);
    return 1;
  }

  if(!present(player,room)) {
    tell_room(room,
    capitalize(dragon->query_name())+" "+dragon->query_dragon_move()+" out.\n");
    move_object(dragon, environment(player));
    tell_room(environment(dragon),
    capitalize(dragon->query_name())+" "+dragon->query_dragon_move()+" in.\n");
  }
}

dragon_say(str){
  tell_room(environment(DRAG),
  NME+" says: "+str+"\n");
  return 1;
}

dragon_emote(str){
  tell_room(environment(DRAG),
  NME+" "+str+"\n");
  return 1;
}

dragon_stay(){
  write("You command "+NME+" to stay.\n");
  write(NME+" yawns and sits down.\n");
  say(NME+" yawns widely and sits down.\n");
  DRAG->set_follow(0);
  return 1;
}

dragon_follow(){
  write("You command "+NME+" to follow.\n");
  write(NME+"'s tail swishes happily from side to side.\n");
  say(capitalize(OWE)+" commands his dragon to follow.\n");
  say(NME+"'s tail swishes happily from side to side.\n");
  DRAG->set_follow(1);
  DRAG->follow();
  return 1;
}
 
dragon_give(str){
  object ob;

  if(!str) {
    write(NME+" peers at you quizically.\n");
    return 1;
  }

  if(!present(str, DRAG)){
    write(NME+" peers at you quizically.\n");
    return 1;
  }

  ob = present(str, DRAG);

  if(!transfer(ob, this_player())){
    write(NME+" gives you a "+capitalize(str)+".\n");
    say(NME+" gives a "+capitalize(str)+" to "+capitalize(OWE)+".\n");
  }
  else {
    write(NME+" is unable to give you that.\n");
  }

  return 1;
}

dragon_lead() {
  object tmp;

  if(!DRAG->query_attack()) {
    write(NME+" is not attacking anything.\n");
    return 1;
  }
  write(NME+" charges to the front of the battle!\n");
  say(NME+" charges to the front of the battle!\n");
  tmp = DRAG->query_attack();
  tmp->set_can_kill(1);
  tmp->attack_object(DRAG);
  DRAG->attack_object(tmp);
  return 1;
}
  
dragon_assist(str) {
  int assist;

  assist = DRAG->query_autoassist();

  if(!str) {
    if(!assist) {
      write("Dragon Autoassist is now on.\n");
      DRAG->set_autoassist(1);
    }
    else {
      write("Dragon Autoassist is now off.\n");
      DRAG->set_autoassist(0);
    }
    return 1;
  }
  else if(str == "on") {
    write("Dragon Autoassist is now on.\n");
    DRAG->set_autoassist(1);
    return 1;
  }
  else {
    write("Dragon Autoassist is now off.\n");
    DRAG->set_autoassist(0);
    return 1;
  }
}

dragon_dismiss(){
  write("You dismiss your Dragon.\n");
  write(NME+" bows before you and then turns into a cloud of whispy\n"+
  "smoke and disappears.\n");
  say(capitalize(OWE)+" dismisses his dragon.\n");
  say(NME+" turns into a cloud of mist and disappears.\n");
  DRAG->save_stats();
  destruct(DRAG);
  return 1;
}
   
dragon_attack(str){
  object ob;

  if(!str) {
    write(NME+" peers at you quizically.\n");
    return 1;
  }

  if(!(ob=present(str, environment(DRAG)))){
    write(NME+" peers at you quizically.\n");
    return 1;
  }

  if(!ob->query_npc()) {
    write(NME+" looks at the pathetitic human and laughs.\n");
    tell_object(ob, NME+" looks at you and snarls menacingly.\n");
    return 1;
  }

  if(environment(DRAG)->query_no_fight()) {
    tell_room(environment(DRAG), NME+" breathes haughty whisps of smoke through his nostrils.\n");
    return 1;
   }
  DRAG->set_can_kill(1);
  ob->set_can_kill(1);

  write("You command "+NME+" to attack!\n");
  tell_room(environment(this_player()),
  NME+" the dragon looses an ear-splitting roar and tears into "+
  capitalize(str)+"!\n");  

  if(!ob->query_attack()) ob->attack_object(DRAG);
  DRAG->attack_object(ob);

  return 1;
}

dragon_autokill(ob, thisob) {
  if(!ob->query_npc()) {
    return 1;
  }
  if(!present(ob, environment(thisob))) {
    return 1;
  }
  tell_room(environment(thisob),
  HIC+capitalize(thisob->query_name())+" jumps into the fray!\n"+NORM);
  tell_room(environment(thisob),
  capitalize(thisob->query_nme())+" the dragon lets loose an ear-splitting roar and tears into "+
  capitalize(ob->query_name())+"!\n");  
  ob->set_can_kill(1);
  thisob->set_can_kill(1);
  thisob->attack_object(ob);
  return 1;
}

dragon_rename(str){
  if(!str) {
    write("Dragon says: Name me what?\n");
    return 1;
  }
  if(strlen(str) > 20){
    write("Sorry, thats too long.  Max is 20 characters.\n");
    return 1;
  }

  str = lower_case(str);
  write("Dragon says: "+capitalize(str)+"... I like it.  It's catchy!\n");
  write(capitalize(str)+"'s tail swishes happily.\n");
  DRAG->set_nme(str);
  DRAG->udate();
  return 1;
}
   
/* DRAGON SPELLS */
cast_spell(drag){
 int spl, choice;

 if(!drag->query_attack()) return 1;
 if(!present(drag->query_attack(), environment(drag))) return 1;
 if(drag->query_casting()) return 1;
 if(drag->query_sp() < 5) return 1;

 choice = random(drag->query_level() + 1);
 spl = drag->query_sp_list();

/*
 if(choice >= 19){
   if(spl == 1) inferno(drag);
   else if(spl == 2) symbol_of_death(drag);
   else if(spl == 3) dont_know(drag);
 } else if(choice >= 16){
   if(spl == 1) blister(drag);
   else if(spl == 2) cyclone(drag);
   else if(spl == 3) ice_shield(drag);
 } else if(choice >= 13){
   if(spl == 1) fire_shield(drag);
*/
 if(choice >= 13){
   if(spl == 1) lightning_bolt(drag);
   else if(spl == 2) heal_spell(drag);
   else if(spl == 3) lightning_bolt(drag);
 } else if(choice >= 9){
   if(spl == 1 || spl == 3) heal_spell(drag);
   else acid_arrow(drag);
 } else if(choice >= 5){
   if(spl == 1) breath_fire(drag);
   else if(spl == 2) breath_acid(drag);
   else if(spl == 3) breath_ice(drag);
 } else
   dragon_klaw(drag);

 return 1;
}

dragon_setdescrip(){
  DRAG->set_dragon_long("");
  write("Enter the description for your dragon one line at a time.\n");
  write("type '**' on a line by itself to finish.\n");
  write("> ");
  input_to("add_descrip");
  return 1;
}

add_descrip(str){
  if(str == "**"){
    write("Done - all jaZZed up!\n");
    write("Don't forget to save now!\n");
    return 1;
  }
  else {
    DRAG->set_dragon_long(DRAG->query_dragon_long()+str+"\n");
    write("> ");
    input_to("add_descrip");
    return 1;
  }
  return 1;
}

dragon_setlook(str){
  if(!str){
    write("Set it to what?\n");
    return 1;
  }
  if(strlen(str) > 60){
    write("Sorry, thats too long.  Max is 60 characters.\n");
    return 1;
  }
  DRAG->set_dragon_short(str);
  write("You change the appearance of your dragon.\n");
  write("It will show as: "+DRAG->short()+"\n");
  write("Pretty cool, eh?\n");
  return 1;
}

dragon_wimpy(str) {
  int much;
  if(!str) {
    much = DRAG->query_mhp() / 10;
  }
  else {
    sscanf(str, "%d", much);
  }
  write(NME+" will wimpy at "+much+".\n");
  DRAG->set_wimpy(much);
  return 1;
}

dragon_setmove(str){
  if(!str){
    write("Set it to what?\n");
    return 1;
  }
  if(strlen(str) > 60) {
    write("Sorry, thats too long.  Max is 60 characters.\n");
    return 1;
  }
  DRAG->set_dragon_move(str);
  write("It will now look like:\n");
  write(NME+" "+DRAG->query_dragon_move()+" in/out.\n");
  write("when your Dragon enters/exits.\n");
  return 1;
}

dragon_report(){
  write(NME+" reports: "+HIM+
  DRAG->query_hp()+"/"+DRAG->query_mhp()+" hp  "+
  DRAG->query_sp()+"/"+DRAG->query_max_sp()+" sp\n"+NORM);
  return 1;
}



