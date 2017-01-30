#include "std.h"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
#undef EXTRA_INIT
#define EXTRA_INIT extra_init();

int shield_status;
object summoned_origin;
object omegaobj;
object intruder;
string intruder_name;
object summoned_object;

extra_reset(arg) {
   if(arg) { return; }
   shield_status = 1;
   set_heart_beat(1);
   set_light(1);
}

init(){
      add_action("quit","quit");
     if(this_player()->query_real_name() == "deathmonger"){
      write("Current screen status = "+shield_status+"\n");
      add_action("shield_control","screen");
      add_action("anchor_control","lockme");
      add_action("damage_living","sicken");
      add_action("heal_living","heal");
      add_action("dest_living","dest!");
      add_action("change_exp", "exp");
      add_action("change_money","money");
      add_action("post","post");
      add_action("set_login_location","sethome");
      add_action("room_commands","?");
      add_action("up","up");
      add_action("guild", "guild");
      add_action("down","down");

}

     intruder_name = this_player()->query_real_name();
    if(this_player()->id("deathmonger")) return 1;
   if(shield_status == 1) {
      write("Deathmonger's defensive screen is up.\n");
      write("You must ask him for permission to enter.\n");
      write("You are being moved to the void.\n");
      write("\n");
     omegaobj = find_player("deathmonger");
      if(omegaobj){
         tell_object(omegaobj, capitalize(intruder_name)
            + " just tried to enter your workroom.\n");
      }
       intruder = this_player();
      move_object(this_player(), "room/void");
     command("look", intruder);
      return 1;
   }
   return 1;
}


shield_control(str){   /* activates and deactivates the shield */
   if(!str) {
      write("Screen status:  "+shield_status+"\n");
      return 1;
   }                        /* if the shield is on, the player is sent to */
   if(str == "on") {        /* the void and told a message. */
      shield_status = 1;
      return 1;
   }
   if(str == "off") {
      shield_status = 0;
      return 1;
   }
   return 0;
}

anchor_control(str){   /* anchors you to this room */
   if(!str) return;
   if( str == "on" ){
      set_heart_beat(1);
      return 1;
   }
   if( str == "off" ){
      set_heart_beat(0);
      return 1;
   }
   return 0;
}

heart_beat() {
object target;
   target = find_player("deathmonger");
   if(!target) return;
   if( environment(target) != this_object() ) {
      move_object(target, this_object());
      tell_object(target, "Welcome back.\n");
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
   target->add_hit_point(3000);
   target->add_spell_point(3000);
   return 1;
}


post(){
     call_other(this_player(), "move_player",
     "to read his mail#room/post");
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
      temp_shield = shield_status;
      shield_status = 0;
      say(capitalize(target->query_name()) + " suddenly vanishes"+
         " into thin air.\n", target);
      summoned_origin = environment(target);
      summoned_object = target;
      move_object(target,this_object());
     command("look", target);
      tell_object(target, "You have been transported to Omega's workroom.\n");
      shield_status = temp_shield;
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


room_commands() {
  if(this_player()->query_real_name() != "deathmonger") {
    return 0; }
write("?                         :  display this help list\n");
write("screen <on/off>              turn screen on/off\n");
write("lockme <on/off>              lock self to workroom\n");
write("sicken <who>                 sets hp & sp of <who> to 0\n");
write("heal <who>                   heal who\n");
write("dest! <what>                  remote dest\n");
write("exp <who> <amount>           change player exp\n");
write("money <who> <amount>         change player money\n");
write("sethome <who> <where>        set player's login location\n");
   return 1;
}

guild(){
    this_player()->move_player("to the Guild of Assassins#players/deathmonger/ASSASSIN/cenguild");
      return 1;
}

up(){
     this_player()->move_player("up#room/adv_guild");
     return 1;
}
down(){
     this_player()->move_player("down#players/deathmonger/hall3");
     return 1;
}
short(){  return "Deathmonger's Workroom"; }
long(){
write("Deathmonger's workroom is painted jet black, with a large,\n");
write("comfortable chair in one corner from which Deathmonger ponders\n");
write("philosophy and the state of the mud.\n");
}

