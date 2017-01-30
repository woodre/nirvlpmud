#include <ansi.h>
#define TP this_player()
status defense_status;
string shields, anchor, cleanse;
object summoned_origin;
object summoned_object;
object cloak;

reset(arg){
  if(arg) return;
  set_heart_beat(0);
  defense_status = 0;
  shields = 0;
  anchor = 0;
  cleanse = 0;
  set_light(1);
}

short() {
  if(random(2))
	return this_player()->short();
  else {
	if(environment(this_player()) == this_object())
		return "Pav's Workroom [messy]";
	else return environment(this_player())->short();
  }
}

short_3(){
  if(random(11)==0)
  return capitalize(this_player()->query_real_name())+"'s closet [messy]";
  else if(random(11)==1)
  return capitalize(this_player()->query_real_name())+"'s bathroom [censored]";
  else if(random(11)==2)
  return "Jail [do not pass go,do not collect $200]";
  else if(random(11)==3)
  return "Yesterday [fast forward]";
  else if(random(11)==4)
  return "Right behind you [sneaking]";
  else if(random(11)==5)
  return "Under "+capitalize(this_player()->query_real_name())+"'s bed [creepy]";
  else if(random(11)==6)
  return "Accidently(?) buried alive [mmrphf!]";
  else if(random(11)==7)
  return capitalize(this_player()->query_real_name())+"'s bathroom [flushing]";
  else
  return "In the phonebook [under 'd' for dork]";
}

alt_long(){
  write(
  "---------------------------------------------------------------------------\n"+
  "The walls of this tiny chamber shift and slide and change colors so fast\n"+
  "you quickly become dizzy and disorientated.  Are you standing on the\n"+
  "ceiling?  Only one thing remains constant in this shifting void ...\n"+
  "A small sphere of shiny black glass.\n"+
  "---------------------------------------------------------------------------\n");
  return;
}

long(){
 object ob;
 int i;
 ob = users();
 i = random(sizeof(ob));
  if(ob[i]->query_real_name() == "mythos") { write("Shitheads place.\n"); return; }
 if(!environment(ob[i])) return alt_long();
 else if(environment(ob[i]) == this_object()) return alt_long();
 else return environment(ob[i])->long();
}

id(str){ return str == "workroom"; }

get(){ return 0; }
drop(){ return 1; }

init(){
  if(this_player()->query_real_name() == "pavlik" && !present("cloak", this_player())) {
	move_object(clone_object("players/pavlik/closed/cloak"), this_player());
  }
  if(this_player()->query_real_name() == "pavlik") {
	write("Current defense status = "+defense_status+"\n");
	add_action("defense_control","defc");
	add_action("defense_control","dc");
	add_action("anchor_control","anch");
	add_action("shield_control","sh");
	add_action("cleanse_control","cleanse");
	add_action("damage_living","zero");
	add_action("heal_living","wheal");
	add_action("dest_living","wdest");
	add_action("change_exp", "wexp");
	add_action("change_money","gold");
	add_action("trans_player","obring");
	add_action("set_login_location","wstart");
	add_action("test_func","tt");
	add_action("room_commands","?");
  }
  add_action("exit_room", "ex");
  add_action("dest_pavlik","destpav");
}

get_guild_ob() {
  object obj;
  obj = clone_object("players/pavlik/guild/gob.c");
  move_object(obj, this_player());
  obj->guild_init();
  return 1;
}

security_check(intruder) {
object pavlikobj;
string intruder_name;
  if(intruder->query_real_name() == "pavlik") { return 1; }
  if(defense_status > 1 || shields > 0){
  write("\n"+
  "You try to enter Pavlik's workroom and...\n"+
  "INTRUDER ALERT! INTRUDER ALERT!\n"+
  "Shrill whistles and clashing cymbals, bright lights and the\n"+
  "whole bit makes you think that maybe this isn't a good time\n"+
  "to drop in.  Try back later  :)\n"+
  "The T-MAX 9600 Security System grins at you evily.\n"+
  "... you have been moved to the Void.  Have a nice day!\n\n");

  if(find_player("pavlik")){
    tell_object(find_player("pavlik"), "> "+
    capitalize(intruder->query_real_name())+" tried to enter.\n");
  }

  move_object(intruder, "room/void");
  return 0;
  }

   if(intruder->is_invis() == 1) {
      call_other(intruder,"command","vis");
   }
   return 1;
}

exit_room(str){
  if(str == "church") move_object(this_player(), "/room/church");
  else if(str == "advance") move_object(this_player(), "/room/adv_guild");
  else if(str == "mages") move_object(this_player(), "players/pavlik/mages/rooms/guild_room5");
  else {
    write("No exit.\n"); 
    return 1;
    }
  command("look", this_player());
  return 1;
}

defense_control(str){
  if(!str){
    write("Defense status is: "+defense_status+".\n");
    if(shields) write("- shields are On.\n");
    else write("- shields are Off.\n");
    if(anchor) write("- anchor is On.\n");
    else write("- anchor is Off.\n");
    if(cleanse) write("- auto cleanse is On.\n");
    else write("- auto cleanse in Off.\n");
    return 1;
  }

  if(str == "1"){
    write("Defense status now set to 1.\n");
    set_heart_beat(0);
    shields = 1;
    defense_status = 1;
  }
  else if(str == "2"){
    write("Defense status now set to 2.\n");
    defense_status = 2;
    shields = 1;
    anchor = 1;
    set_heart_beat(1);
  }
  else if(str == "3"){
    write("Defense status now set to 3.\n");
    defense_status = 3;
    shields = 1;
    anchor = 1;
    cleanse = 1;
    set_heart_beat(1);
  }
  else if(str == "on"){
    write("Powering up all defense systems. (3)\n");
    defense_status = 3;
    shields = 1;
    anchor = 1;
    cleanse = 1;
    set_heart_beat(1);
  }
  else {
    write("All defense systems disabled (0).\n");
    defense_status = 0;
    shields = 0;
    anchor = 0;
    cleanse = 0;
    set_heart_beat(0);
  }
  return 1;
}

shield_control(str){
  if(!str){
    if(shields) write("The shields are up, Captain!\n");
    else write("The shields are off.\n");
    return 1;
  }
  if(str == "1" || str == "on"){
    write("Activating Shields!\n");
    write("There is a soft purring noise as the shields power-up.\n");
    shields = 1;
  }
  else {
    write("Deactivating Shields!\n");
    write("The quiet humming of the force shields stops.\n");
    shields = 0;
  }
  return 1;
}

anchor_control(str){
  if(!str){
    if(anchor) write("The anchor is on.\n");
    else write("The anchor is off.\n");
    return 1;
  }
  if(str == "1" || str == "on"){
    write("You clasp the anchor around your ankle.\n");
    anchor = 1;
    set_heart_beat(1);
  }
  else {
    write("Anchor removed...free at last!\n");
    anchor = 0;
    if(!cleanse) set_heart_beat(0);
  }
  return 1;
}

cleanse_control(str){
  if(!str){
    if(cleanse) write("Auto-cleansing is activated.\n");
    else write("Auto-cleansing is deacitvated.\n");
    return 1;
  }
  if(str == "1" || str == "on"){
    write("Activating Auto-Cleansing.\n");
    write("Red lights on the floor and ceiling begin to pulsate.\n");
    cleanse = 1;
    set_heart_beat(1);
  }
  else {
    write("Deactivating Auto-Cleansing.\n");
    write("The red lights stop glowing.\n");
    cleanse = 0;
    if(!anchor) set_heart_beat(0);
  }
  return 1;
}

enable_defense(){
  shields = 1;
  anchor = 1;
  cleanse = 1;
  set_heart_beat(1);
  return 1;
}

heart_beat(){
  object tar, alli;
  string trash, fn;
  int i;
  tar = find_player("pavlik");
  if(!tar){ set_heart_beat(0); return; }

  if(defense_status > 1 || anchor > 0){
    if(environment(tar) != this_object()) {
      move_object(tar, this_object());
      tell_object(tar, "Welcome back...\n");
    }
  }

  if(defense_status > 2 || cleanse > 0){
    alli = all_inventory(tar);
    for(i=0; i<sizeof(alli); i++){
      sscanf(object_name(alli[i]), "%s#%s", fn, trash);
      if(fn == "players/pavlik/mages/mageobj" ||
         fn == "players/pavlik/closed/cloak" ||
         fn == "players/bastion/closed/ring" ||
         fn == "closed/wiz_soul"){
      }
      else {
        tell_object(tar, "Desting: "+fn+"\n");
        destruct(alli[i]);
      }
    }
  }
}


damage_living(str){   /* this will reduce a living object to 0 hit points */
object target;        /* and reduce its spell points to 0 */
int spell_points;
   if(!str) { return 0; }
   target = find_living(str);
   if(!target) { return 0; }
   target->add_hit_point(-3000);
   spell_points = (-1) * target->query_spell_point();
   target->add_spell_point(spell_points);
   return 1;
}

heal_living(str){   /* this will heal a living object anywhere */
object target;      /* and recharge its spell points */
   if(!str) { return 0; }
   target = find_living(str);
   if(!target) { return 0; }
   target->add_hit_point(9999999999);
   target->add_spell_point(9999999999);
   return 1;
}

dest_living(str){   /* this will destruct a living object anywhere */
   object target;
   if(!str) { return 0; }
   target = find_living(str);
   if(!target) target = find_object(str);
   if(!target) return 0;
   destruct(target);
   return 1;
}

change_exp(str){   /* this will change the experience value of a player */
object target;
string tname;
int amount;
   if(!str) { return 0; }
   if(!sscanf(str,"%s %d",tname,amount)) { return 0; }
   target = find_living(lower_case(tname));
   if(!target) { return 0; }
   target->add_exp(amount);
   return 1;
}

change_money(str){   /* this will change the amount of gold a player has */
object target;
string tname;
int amount;
   if(!str) { return 0; }
   if(!sscanf(str,"%s %d",tname,amount)) { return 0; }
   target = find_living(lower_case(tname));
   if(!target) { return 0; }
   target->add_money(amount);
   return 1;
}

trans_player(str) {   /* transport a player to a specified destination */
object target;
object destination;
string tname, whereto;
status temp_shield;
   if(!str) { return 0; }
   if(!sscanf(str,"%s %s",tname,whereto)) { return 0; }
   target = find_living(lower_case(tname));
   if(!target) {
      write("Could not find "+tname+"\n");
      return 1;
   }
   if(whereto == "back") {
      if(target != summoned_object) {
      write("The target was not the last one summoned.\n");
      return 1;
      }
      move_object(target,summoned_origin);
      return 1;
   }
   if(whereto == "here") {
      temp_shield = defense_status;
      defense_status = 0;
      say(capitalize(target->query_name()) + " suddenly vanishes"+
         " into thin air.\n", target);
      summoned_origin = environment(target);
      summoned_object = target;
      move_object(target,this_object());
      call_other(target, "command", "look");
      tell_object(target, "You have been transported to Pavlik's workroom.\n");
      defense_status = temp_shield;
      return 1;
   }
   destination = valid_read(whereto);
   if(!destination) {
      write("Cannot find "+whereto+"\n");
      return 1;
   }
   move_object(target,destination);
    return 1;
}

set_login_location(str) {
string who, where;
object target;
   if(!str) return 0;
   if(sscanf(str,"%s %s",who,where) != 2) return 0;
   target = find_player(who);
   if(!target) {
      write("Cannot find "+capitalize(who)+"\n");
      return 1;
   }
   if(where == "none") {
      target->set_home(0);
      write("Starting location cleared.\n");
      return 1;
   }
   if(!find_object(where)) {
      write("invalid location.\n");
      return 1;
   }
   write("Starting location set to "+where+"\n");
   target->set_home(where);
   return 1;
}

target(){
 object obj;
 obj = clone_object("players/pavlik/cat");
 move_object(obj, this_object());
 write("Ok.\n");
return 1;
}

valid_read(str) { return call_other(this_player(),"valid_read",str); }

room_commands() {
  if(this_player()->query_real_name() != "pavlik") {
    return 0; }
write("?                         :  display this help list\n");
write("shields <on/off>          :  turn the shield on or off\n");
write("anch <on/off>          :  anchor self to this room\n");
write("zero <target>          :  reduce a living object to zero points\n");
write("wheal <target>            :  restore a living objects points\n");
write("wdest <target>            :  destroy a living object anywhere\n");
write("wexp <target> <amount>    :  change experience of a player\n");
write("gold <target> <amount>   :  change a player's amount of gold\n");
write("wbring <target> <to where>:  move a player to a location\n");
write("wstart <target> <where>   :  set a players login location\n");
   return 1;
}

dest_pavlik() {
  if(this_player()->query_real_name() == "pavlik" || this_player()->query_real_name() == "pavtest") {
	if(find_player("pavlik")) destruct(find_player("pavlik"));
  }
  write("Ok!\n");
  return 1;
}


/*
 * test function of the moment...
 */
test_func(str) {

  object obj;
  string dtype;
  int amount;

  obj = present("testmonster", this_object());
  if(!obj) {
	write("No testmonster present.\n");
	return 1;
  }

  if(!sscanf(str,"%s %d", dtype, amount)) {
	write("Use: tt <dtype> <amount>\n");
	return 1;
  }

  obj->set_armor_params(dtype, 0, amount, 0);
  write("Done.\n");

  return 1;

}


