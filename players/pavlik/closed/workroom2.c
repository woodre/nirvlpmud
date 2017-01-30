#include <ansi.h>
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

short(){
  if(environment(this_player()) == this_object())
  return "Pav's Workroom [messy]";
  else return environment(this_player())->short();
}

short_old(){
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
 if(!environment(ob[i])) return alt_long();
 else if(environment(ob[i]) == this_object()) return alt_long();
 else return environment(ob[i])->long();
}

id(str){ return str == "workroom"; }

get(){ return 0; }
drop(){ return 1; }

init(){
  if(this_player()->query_real_name() == "pavlik" &&
  !present("cloak", this_player())){
    cloak = clone_object("players/pavlik/closed/cloak");
    move_object(cloak, this_player());
                                   }
   if(security_check(this_player())) {
   if(this_player()->query_real_name() == "pavlik") {
      write("Current defense status = "+defense_status+"\n");
      add_action("defense_control","defc");
      add_action("defense_control","dc");
      add_action("anchor_control","anch");
      add_action("shield_control","sh");
      add_action("room_commands","?");
      add_action("exit_room", "ex");
      }
   }
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
