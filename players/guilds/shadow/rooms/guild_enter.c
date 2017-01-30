#include "/players/guilds/shadow/shadow_lib/basic.h"
#include "/players/guilds/shadow/shadow_lib/color.h"

short() { return BOLD +"The Entrance to Darkness"+NOSTYLE; }
long() { 
  if(present("shadow-mark",this_player())) {
    move_object(this_player(),"/players/guilds/shadow/rooms/meeting");
    command("look", this_player());
    return 1;
  } else 
  write("You are floating a pool of total nothingness and darkness.\n"+
        "The blackness surrounds you and appears to go on forever in\n"+
        "every direction. All you can see is the spot of light from\n"+
        "which you came. For this is the entrance to darkness, a place\n"+
        "to choose a life in the Shadows as your future. Once you go\n"+
        "further you will forever be a creature of the darkness, and of\n"+
        "the Shadows.  Do you wish this?  The only answer can be 'yes'\n"+
        "or 'no'.\n");
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
           " guild owner or\nSandman explaining the problem.\n");
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
  if(TP->query_guild_name() && TP->query_guild_name() != "shadow") { return 1; }
  if(!TP->query_guild_exp()) TP->add_guild_exp(1);
  if(TP->query_guild_name()!="shadow"&&TP->query_guild_rank()) {
    temp = TP->query_guild_rank();
    TP->add_guild_rank(1 - temp);
  }
  TP->set_guild_file("/players/guilds/shadow/shadow");
   move_object(clone_object("/players/guilds/shadow/shadow.c"), TP);
   present("shadow-mark", TP)->lost_mark();
   write("You now have a "+BOLD+"Mark of the Shadows."+NOSTYLE+"\n");
   write("You are a Shadow.\n");
   enter_guild();
   return 1;
}

enter_guild() {
   write("You float through the pool for a distance and appear at the \n"+
    "other side.\n");
   TP->move_player("darkness#players/guilds/shadow/rooms/meeting");
   return 1;
}

no_guild() {
   write("Very well then.\n");
   write("You rocket upwards towards the light you came from and emerge\n"+
         "from the pool.\n");
   TP->move_player("out#/room/plane2");
   return 1;
}

leave() {
   TP->move_player("out#/room/plane2");
   return 1;
}
