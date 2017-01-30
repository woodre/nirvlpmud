/*guild_enter.c*/
#include "/players/blue/closed/lib/basic.h"
#include "/players/pathfinder/closed/shadow/color.h"
 
short() { return BOLD +"The Entrance to Darkness"+NOSTYLE; }
   long() { if(present("shadow-mark",this_player())) {
        move_object(this_player(),"/players/pathfinder/closed/shadow/rooms/meeting");
        command("look", this_player());
        return 1;
      } else write("The Master Shadow appears before you.\n"+
"The Master Shadow says: This is the entrance to darkness.  Once you go further\n"+
"you will forever be a creature of the darkness, and of the Shadows.  Do you\n"+
"wish this?  Your only response can be 'yes' or 'no'.\n");
}
 
 
reset(arg) {
 
   if(arg) return;
 
   set_light(1);
 
}
 
init() {
   add_action("do_guild","yes");
   add_action("no_guild","no");
   add_action("leave","leave");
 
}
 
 
do_guild(str) {
   int temp;
   if(present("shadow-mark", TP)) {
      write("You already are a shadow.  Are you lost?\n");
      enter_guild();
      return 1;
   }
   if(TP->query_level() < 3) {
      write("You must be 3rd level to join a guild.\n");
      leave();
      return 1;
   }
   if(TP->query_guild_exp() == 1234) {
       write("You are not allowed to join any guilds.\n");
      leave();
      return 1;
   }
   if(TP->query_guild_exp()&&TP->query_guild_name() != "shadow") {
      write("You are still shown as being in a guild.  Mail your former"+
           " guild master or\nSandman explaining the problem.\n");
      leave();
      return 1;
   }
   if(TP->query_guild_name()&&TP->query_guild_name() != "none"&&
      TP->query_guild_name() != "shadow") {
      write("You are still shown as being in a guild.  Mail your former"+
           " guild master or\nSandman explaining the problem.\n");
      leave();
      return 1;
   }
   if(!TP->query_guild_exp()) TP->add_guild_exp(1);
    if(TP->query_guild_name()!="shadow"&&TP->query_guild_rank()) {
       temp = TP->query_guild_rank();
      TP->add_guild_rank(1 - temp);
   }
   TP->set_guild_file(0);
   move_object(clone_object("/players/blue/closed/shadow/shadow.c"), TP);
   present("shadow-mark", TP)->lost_mark();
   write("The Master Shadow gives you a "+BOLD+"Mark of the Shadows"+NOSTYLE+".\n");
   write("You are now a Shadow.\n");
   enter_guild();
    return 1;
}
 
enter_guild() {
        move_object(this_player(),"/players/pathfinder/closed/shadow/rooms/meeting");
        command("look", this_player());
   return 1;
}
 
no_guild() {
   write("Very well then.\n");
   TP->move_player("out#/room/plane2");
   return 1;
}
 
leave() {
   TP->move_player("out#/room/plane2");
   return 1;
}
