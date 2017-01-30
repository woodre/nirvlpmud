#include "std.h"
#include "/players/pain/color.h"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
#undef EXTRA_INIT
#define EXTRA_INIT extra_init();

status shield_status;
object summoned_origin;
object summoned_object;

extra_reset(arg) {
   if(arg) { return; }
   shield_status = 1;
   set_heart_beat(0);
}

extra_init() {
   if(security_check(this_player())) {
   if(this_player()->query_real_name() == "pain") {
      write("Current shield status = "+shield_status+"\n");
      add_action("shield_control","sh");
      add_action("anchor_control","anch");
      add_action("damage_living","zero");
      add_action("heal_living","wheal");
      add_action("dest_living","wdest");
      add_action("change_exp", "wexp");
      add_action("change_money","gold");
      add_action("trans_player","obring");
      add_action("set_login_location","wstart");
      add_action("room_commands","?");
	add_action("set_title","set_title");
      }
   }
}


security_check(intruder) {
object pavlikobj;
string intruder_name;
   if(intruder->query_real_name() == "pain") { return 1; }
if(intruder->query_real_name() == "eurale") { return 1; }
if(intruder->query_real_name() == "rani") { return 1; }
if(intruder->query_real_name() == "laera") { return 1; }
if(intruder->query_level() >= 300) {return 1; }
   if(shield_status == 1) {
 write("You try to enter Pain's workroom, but\n"+
    "a large hand grabs you and chucks you in the waiting room!\n");
      write("\n");
      pavlikobj = find_player("pain");
      if(pavlikobj){
         intruder_name = intruder->query_real_name();
         tell_object(pavlikobj, capitalize(intruder_name)
            + " just tried to enter your workroom.\n");
      }
      move_object(intruder, "room/void");
      call_other(intruder,"command","look");
      return 0;
   }
   if(intruder->is_invis() == 1) {
      call_other(intruder,"command","vis");
   }
   return 1;
}


set_title() {

  if(this_player()->query_real_name() != "pain") { return 0; }

this_player()->set_title("the "+BOLD+RED+"F"+END+BOLD+GREEN+"I"+END+BLUE+"X"+END+BOLD+PURPLE+"E"+END+RED+"R"+END);
return 1;
}

shield_control(str){   /* activates and deactivates the shield */
if(this_player()->query_level() < 20) return 0;
   if(!str) {
      write("Shield status:  "+shield_status+"\n");
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
   target = find_player("pain");
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
if(this_player()->query_level() < 20) return 0;
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
if(this_player()->query_level() < 20) return 0;
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
if(this_player()->query_level() < 20) return 0;
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
if(this_player()->query_level() < 20) return 0;
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
if(this_player()->query_level() < 20) return 0;
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
      call_other(target, "command", "look");
      tell_object(target, "You have been transported to Pain's workroom.\n");
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
if(this_player()->query_level() < 20) return 0;
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

valid_read(str) { return call_other(this_player(),"valid_read",str); }

  ONE_EXIT("room/church.c", "manhattan",
"The End of the World",
"The End of the World\n"+
     "This is where Pain spends all of his time...\n"+
     "All around you are images of love and peace.\n"+
     "You feel fear and wonderment looking at the awesome power before you.\n"+
     "Budda hangs out here to rap with Pain.\n",1)

room_commands() {
  if(this_player()->query_real_name() != "pain") {
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
