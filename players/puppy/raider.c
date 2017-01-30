#include "/players/puppy/define.h"
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
set_short(""+HIK+"R"+WHT+"a"+HIK+"i"+WHT+"d"+HIK+"e"+WHT+"r"+HIK+"s"+NORM+" L"+HIK+"o"+WHT+"c"+HIK+"k"+WHT+"e"+HIK+"r "+WHT+"R"+HIK+"o"+WHT+"o"+HIK+"m"+NORM+"");
   set_long(
      "From the box seats one is able to view the entire field.  Two\n"+
      "goal posts have been placed at each end behind the end zones.\n"+
      "The stands below are filled to capacity with your fellow Raiders\n"+
      "fans.  You may type 'commands' for ways to support the team.\n");
   set_light(1);
   add_listen("main", "You hear the roar from the Raiders fans.\n");
   add_smell("main", "You smell the many delights from the food stands.\n");
   add_property("NF");
   items = ({
         "something", "You look at something",
         "something", "You look at something"});
}
init() {
   add_action("commands","commands");
   add_action("rcheer","rcheer");
   add_action("rscore","rscore");
   add_action("rboo","rboo");
   add_action("rdefense","rdefense");
   add_action("rpennant","rpennant");
   add_action("rjerry","rjerry");
   add_action("rouch","rouch");
   add_action("rcringe","rcringe");
   add_action("rpain","rpain");
   add_action("rblind","rblind");
   add_action("rtd","rtd");
   add_action("rfumble","rfumble");
   add_action("rwhew","rwhew");
   add_action("rlounge","rlounge");
add_action("rover","rover");
}

commands(str) {
   write("\n");
   write("Commands:\n");
   write("rblind\n");
   write("rboo\n");
   write("rcheer\n");
   write("rcringe\n");
   write("rdefense\n");
   write("rfumble\n");
   write("rjerry\n");
   write("rlounge\n");
   write("rouch\n");
   write("rover\n");
   write("rpain\n");
   write("rpennant\n");
   write("rscore\n");
   write("rtd\n");
   write("rwhew\n");
   return 1;
}

rover(str) {
   write("Now that the game is over you decide to end your partying for the day.\n");
   say(this_player()->query_name()+" decides to head home now that the game is over.\n");
move_object(this_player(),"/room/church.c");
command("look",this_player());
   return 1;
}

rcheer(str) {
   write("You stand up and yell and your popcorn goes flying.\n");
   say(this_player()->query_name()+" jumps up and yells!  Popcorn go's flying!!!.\n");
   return 1;
}

rboo(str) {
   write("You pound your fist on your seat and yell BOO!!!\n");
   say(this_player()->query_name()+" pounds his seat and yells BOO!!!\n");
   return 1;
}

rlounge(str) {
   write("You sink into the huge leather barcalounger in disgust.\n");
   say(this_player()->query_name()+" sinks into the huge leather barcalounger.\n");
   return 1;
}

rdefense(str) {
   say(this_player()->query_name()+" Yells: DEFENSE!!!\n");
   return 1;
}

rtd(str) {
   write("You throw your hands in the air and yell T O U C H D O W N !!!!!\n");
   say(this_player()->query_name()+" yells T O U C H D O W N !!!!!\n");
   return 1;
}

rwhew(str) {
   write("You go WHEW!\n");
   say(this_player()->query_name()+" goes WHEW!\n");
   return 1;
} 

rfumble(str) {
   write("You yell FUMBLE!\n");
   say(this_player()->query_name()+" yells FUMBLE!\n");
   return 1;
}

rpennant(str) {
   write("You wave your Raiders pennant in the air.\n");
   say(this_player()->query_name()+" waves a Raiders pennant in the air.\n");
   return 1;
}

rjerry(str) {
   write("You yell: YOU THE MAN JERRY!!!!!\n");
   say(this_player()->query_name()+" Yells: YOU THE MAN JERRY!!!!!\n");
   return 1;
}

rouch(str) {
   write("You say: Oww that had to hurt.\n");
   say(this_player()->query_name()+" says: Oww that had to hurt.\n");
   return 1;
}

rcringe(str) {
   write("You cringe at that hit.\n");
   say(this_player()->query_name()+" cringes from that hit.\n");
   return 1;
}

rpain(str) {
   write("You yell: RIP HIS HEAD OFF!!!!!\n");
   say(this_player()->query_name()+" Yells: RIP HIS HEAD OFF!!!\n");
   return 1;
}

rblind(str) {
   write("You swear at the ref's.\n");
   say(this_player()->query_name()+" Yells: YOU'RE BLIND REF!\n");
   return 1;
}
rscore(str) {
   write("You yell: S C O R E !!!!!!!!!!!!!!!\n");
   say(this_player()->query_name()+" yells: SCORE!!!!!!!!!!!!!!!\n");
   return 1;
}
