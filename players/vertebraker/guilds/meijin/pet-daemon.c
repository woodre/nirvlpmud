#include "/players/vertebraker/guilds/meijin/defs.h"
#define PET find_living(this_player()->query_real_name()+"'s meijin_pet")
#define NME capitalize(PET->query_nme())
#define OWE PET->query_owner()

reset(arg){
  if(arg) return;
  move_object(this_object(), OBJ_ROOM);
}

id(str){ return str == "pet-daemon"; }
short(){ return "The Pet Daemon"; }
long(){ write("The Pet Daemon.\n"); return; }
get(){ return 1; }
drop(){ return 1; }
query_value(){ return 0; }
query_weight(){ return 999; }

exe_commands(str){
  string what, who;
    if(str == "save"){ pet_save(); return 1; }
    if(str == "stay"){ pet_stay(); return 1; }
    if(str == "follow"){ pet_follow(); return 1; }
    if(str == "dismiss"){ pet_dismiss(); return 1; }
    if(str == "report") { pet_report(); return 1; }
    if(str == "setdescrip") { pet_setdescrip(); return 1; }
    if(str == "assist") { pet_assist(); return 1; }
    if(str == "lead") { pet_lead(); return 1; }
    if(str == "help" || str == "info") { pet_help(); return 1; }
    sscanf(str, "%s %s", what, who);
    if(what == "name"){ pet_rename(who); return 1; }
    if(what == "giveme"){ pet_give(who); return 1; }
    if(what == "kill"){ pet_attack(who); return 1; }
    if(what == "say"){ pet_say(who); return 1; }
    if(what == "emote"){ pet_emote(who); return 1; }
    if(what == "setlook") { pet_setlook(who); return 1; }
    if(what == "setmove") { pet_setmove(who); return 1; }
    if(what == "wimpy"){ pet_wimpy(who); return 1; }
    if(what == "assist"){ pet_assist(who); return 1; }
}

pet_help() {
  write(HIW+"                      Meijin Dragons			\n"+NORM);
  write(HIB+"[(>-----------------------------------------------------------<)]\n"+NORM);
  write(HIW+"   The Dragon is commanded by typing its name then the cmd.\n"+NORM);
  write(HIW+"   Meijin Dragons have the following commands avaliable:\n"+NORM);
  write("       "+HIW+"name <name>"+NORM+" - rename your dragon.\n");
  write("       "+HIW+"giveme <obj>"+NORM+" - give you something he holds.\n");
  write("       "+HIW+"get <obj>"+NORM+" - pick up an object.\n");
  write("       "+HIW+"kill <obj>"+NORM+" - attack something.\n");
  write("       "+HIW+"wimpy <#>"+NORM+" - set dragon's wimpy.\n");
  write("       "+HIW+"assist <on/off>"+NORM+" - toggle autoassist.\n");
  write("       "+HIW+"lead"+NORM+" - have dragon lead the fighting.\n");
  write("       "+HIW+"report"+NORM+" - report health status.\n");
  write("       "+HIW+"dismiss"+NORM+" - dismiss the dragon.\n");
  write("       "+HIW+"follow"+NORM+" - have the dragon follow you.\n");
  write("       "+HIW+"stay"+NORM+" - have the dragon stay put.\n");
  write("       "+HIW+"save"+NORM+" - have the dragon save.\n");
  write("       "+HIW+"say <msg>"+NORM+" - have dragon say something.\n");
  write("       "+HIW+"emote <msg>"+NORM+" - have dragon emote something.\n");
  write("       "+HIW+"setdescrip"+NORM+" - set the dragon's description.\n");
  write("       "+HIW+"setlook <str>"+NORM+" - set the dragon's short description.\n");
  write("       "+HIW+"setmove <str>"+NORM+" - set the dragon's move message.\n");
  write(HIB+"[(>-----------------------------------------------------------<)]\n"+NORM);
  return 1;
}

pet_save(){
  tell_room(environment(PET),
  NME+" appears to concentrate for a moment.\n"+
  NME+" gives you a toothy grin.");
  tell_object(find_player(OWE),"   (saved)");
  tell_room(environment(PET), "\n");
  PET->update_pet();
  return 1;
}

follow(str){
  object obj;

  obj = find_living(str+"'s meijin_pet");
  if(!obj) return 0;
  if(!obj->query_follow()) return 1;
  if(!find_player(str) || !find_player(str)->query_interactive()){
	tell_room(environment(obj),
	capitalize(obj->query_name())+" flaps his wings and flies off into the sky.\n");
	move_object(obj, OBJ_ROOM);
	obj->set_follow(0);
	return 1;
  }
  if(find_player(str)->query_ghost()) {
	tell_room(environment(obj),
	capitalize(obj->query_name())+" flaps his wings and flies off into the sky.\n");
	tell_object(find_player(str), HIW+capitalize(obj->query_name())+" leaves you.\n"+NORM);
	move_object(obj, OBJ_ROOM);
	destruct(obj);
	return 1;
  }
  if(find_player(str)->query_attack() && !obj->query_attack()) {
	if(obj->query_autoassist())
		pet_autokill(find_player(str)->query_attack(), obj);
  }
  if((obj->query_hp() <= obj->query_wimpy()) && (obj->query_attack())) {
	tell_room(environment(obj),
	capitalize(obj->query_name())+" panics and flees from the battle!\n"+
	capitalize(obj->query_name())+" frantically flaps his wings and flies away!\n");
	tell_object(find_player(str), HIB+"Your pet has fled from the battle.\n"+NORM);
	move_object(obj, OBJ_ROOM);
	obj->stop_fight();
	obj->stop_hunter();
	obj->set_follow(0);
	return 1;
  }
  if(!present(find_player(str), environment(obj))) {
	tell_room(environment(obj),
	capitalize(obj->query_name())+" "+obj->query_pet_move()+" out.\n");
	move_object(obj, environment(find_player(str)));
	tell_room(environment(obj),
	capitalize(obj->query_name())+" "+obj->query_pet_move()+" in.\n");
  }
  return 1;
}

pet_say(str){
  tell_room(environment(PET),
  NME+" says: "+str+"\n");
  return 1;
}

pet_emote(str){
  tell_room(environment(PET),
  NME+" "+str+"\n");
  return 1;
}

pet_stay(){
  write("You command "+NME+" to stay.\n");
  write(NME+" yawns and sits down.\n");
  say(NME+" yawns widely and sits down.\n");
  PET->set_follow(0);
  return 1;
}

pet_follow(){
  write("You command "+NME+" to follow.\n");
  write(NME+"'s tail swishes happily from side to side.\n");
  say(capitalize(OWE)+" commands "+NME+" to follow.\n");
  say(NME+"'s tail swishes happily from side to side.\n");
  PET->set_follow(1);
  return 1;
}
 
pet_give(str){
  object ob;

  if(!str) {
    write(NME+" peers at you quizically.\n");
    return 1;
  }

  if(!(ob=present(str, PET))) {
    write(NME+" peers at you quizically.\n");
    return 1;
  }

  if(!transfer(ob, this_player())) {
	write(NME+" gives you a "+capitalize(str)+".\n");
	say(NME+" gives a "+capitalize(str)+" to "+capitalize(OWE)+".\n");
  }
  else {
	write(NME+" is unable to give you that.\n");
  }
  return 1;
}

pet_lead() {
  object tmp;

  if(!PET->query_attack()) {
    write(NME+" is not attacking anything.\n");
    return 1;
  }
  write(NME+" charges to the front of the battle!\n");
  say(NME+" charges to the front of the battle!\n");
  tmp = PET->query_attack();
  tmp->set_can_kill(1);
  tmp->attack_object(PET);
  PET->attack_object(tmp);
  return 1;
}
  
pet_assist(str) {
  int assist;

  assist = PET->query_autoassist();

  if((!str && !assist) || str == "on") {
	write(PRE+"Autoassist is now "+HIW+"ON"+NORM+".\n");
	PET->set_autoassist(1);
  }
  else if((!str && assist) || str == "off") {
	write(PRE+"Autoassist is now "+HIW+"OFF"+NORM+".\n");
	PET->set_autoassist(0);
  }
  return 1;
}

pet_dismiss(){
  write(PRE+"You dismiss "+NME+".\n");
  write(NME+" turns into a cloud of whispy smoke and disappears.\n");
  say(capitalize(OWE)+" dismisses his pet.\n");
  say(NME+" turns into a cloud of mist and disappears.\n");
  PET->save_stats();
  destruct(PET);
  return 1;
}
   
pet_attack(str){
  object ob;

  if(!str) {
	write(NME+" peers at you quizically.\n");
	return 1;
  }
  if(!(ob=present(str, environment(PET)))){
	write(NME+" peers at you quizically.\n");
	return 1;
  }
  if(!ob->query_npc()) {
	write(NME+" looks at the pathetitic player and laughs.\n");
	tell_object(ob, NME+" looks at you and snarls menacingly.\n");
	return 1;
  }

  write(PRE+"You command "+NME+" to attack!\n");
  tell_room(environment(PET),
  NME+" looses and ear-splitting roar and tears into "+capitalize(str)+"!\n");

  PET->set_can_kill(1);
  ob->set_can_kill(1);
  if(!ob->query_attack()) ob->attack_object(PET);
  PET->attack_object(ob);
  return 1;
}

pet_autokill(ob, thisob) {
  if(!ob->query_npc()) {
	return 1;
  }
  if(!present(ob, thisob)) {
	return 1;
  }
  tell_room(environment(thisob),
  HIC+capitalize(thisob->query_name())+" jumps into the fray!\n"+NORM);
  tell_room(environment(thisob),
  NME+" the looses and ear-splitting roar and tears into "+
  capitalize(ob->query_name())+"!\n");  
  ob->set_can_kill(1);
  thisob->set_can_kill(1);
  thisob->attack_object(ob);
  return 1;
}

pet_rename(str){
  if(!str) {
	write("Dragon says: Name me what?\n");
	return 1;
  }
  if(strlen(str) > 20){
	write("Sorry, thats too long.  Max is 20 characters.\n");
	return 1;
  }
  str = lower_case(str);
  write(PRE+"Dragon says: "+capitalize(str)+"... I like it.  It's catchy!\n");
  write(capitalize(str)+"'s tail swishes happily.\n");
  PET->set_nme(str);
  PET->update_pet();
  return 1;
}
   
pet_setdescrip(){
  PET->set_pet_long("");
  write("Enter the description for your pet one line at a time.\n");
  write("Please note that description max is 5 lines.\n");
  write("type '**' on a line by itself to finish.\n");
  write("> ");
  input_to("add_descrip");
  return 1;
}

add_descrip(str){
  if(str == "**"){
	write("Done - all jaZZed up!\n");
	PET->update_pet();
	return 1;
  }
  else {
	PET->set_pet_long(PET->query_pet_long()+str+"\n");
	write("> ");
	input_to("add_descrip");
	return 1;
  }
}

pet_setlook(str){
  if(!str){
	write("Set it to what?\n");
	return 1;
  }
  if(strlen(str) > 60){
	write("Sorry, thats too long.  Max is 60 characters.\n");
	return 1;
  }
  PET->set_pet_short(str);
  PET->update_pet();
  write(PRE+"You change the appearance of your pet.\n");
  write("It will show as: "+PET->short()+"\n");
  return 1;
}

pet_wimpy(str) {
  int much;

  if(!str) much = PET->query_mhp() / 10;
  else sscanf(str, "%d", much);

  write(NME+" will wimpy at "+much+".\n");
  PET->set_wimpy(much);
  return 1;
}

pet_setmove(str){
  if(!str){
	write("Set it to what?\n");
	return 1;
  }
  if(strlen(str) > 60) {
	write("Sorry, thats too long.  Max is 60 characters.\n");
	return 1;
  }
  PET->set_pet_move(str);
  PET->update_pet();
  write("It will now look like:\n");
  write(NME+" "+PET->query_pet_move()+" in/out.\n");
  write("when your Dragon enters/exits.\n");
  return 1;
}

pet_report(){
  write(NME+" reports: "+HIM+
  PET->query_hp()+"/"+PET->query_mhp()+" hp  "+
  PET->query_sp()+"/"+PET->query_max_sp()+" sp\n"+NORM);
  return 1;
}

