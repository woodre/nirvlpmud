#include "/players/blue/closed/lib/basic.h"
#include "/players/blue/closed/lib/color.h"

short() { return BOLD +"The Entrance to Darkness"+NOSTYLE; }
   long() { if(present("shadow-mark",this_player())) {
        move_object(this_player(),"/players/blue/closed/shadow/rooms/meeting");
        command("look", this_player());
        return 1;
      } else write("This is the entrance to darkness.  Once you go further\n"+
"you will forever be a creature of the darkness, and of the Shadows.  Do you"+
"\nwish this?  The only answer can be 'yes' or 'no'.\n");
}


reset(arg) {
   
   if(arg) return;

   set_light(1);
 
}

init() {
   add_action("do_guild","yes");
   add_action("no_guild","no");

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
           " guild ownerr or\nSandman explaining the problem.\n");
      leave();
      return 1;
   }
   if(present("vampirefangs", TP)) {
      write("You are in the vampires guild.  You may only join one"+
            " guild.\n");
      leave();         
      return 1;
   }
   if(present("badge",TP)) {
      write("You have a badge of the dopplegangers guild.  You may only"+
            " join one\nguild at a time.\n");
      leave();
      return 1;
   }
   if(present("seal", TP)) {
      write("You have the seal of the mason's guild.  You may only join "+
            "one guild.\n");
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
   write("You now have a "+BOLD+"Mark of the Shadows."+NOSTYLE+"\n");
   write("You are a Shadow.\n");
   enter_guild();
    return 1;
}

enter_guild() {
    TP->move_player("darkness#players/blue/closed/shadow/rooms/guild_enter");
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
