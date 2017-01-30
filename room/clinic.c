#include <std.h>

#undef EXTRA_INIT
#define EXTRA_INIT  add_action("register", "register");

TWO_EXIT("room/church", "west",
         "room/vill_track", "southeast",
   "The clinic",
         "This room is a simple plain medically clean room. It appears to\n"+
         "be designed as a self-service outpatient clinic. It is for\n"+
         "adventurers who find themselves with minor problems needing a fix.\n"+  
         "This clinic can treat problems such as your not being\n" +
   "able to fight, not being able to carry as much as you should, and\n" +
   "similar inconveniences.  If you have one of these problems, just type\n" +
         "'register' and the problem should go away. There is a door to\n"+
         "the church to the west and one to the outside to the southeast.\n"+
"\n",1)

register(str) {
    if(call_other(this_player(),"query_ghost")) {
       write("You are beyond the power of the clinic to help.\n" +
             "You need to deal with your maker.\n");
       return 1;
    }
    call_other(this_player(),"reset",1);
    this_player()->recalc_quest();
    return 1;
}
guild_me() {
 string gnam;
 string file;
     gnam=this_player()->query_guild_name();
      if(!gnam) {
        write("Your guild name is not set.\n");
        return 1;
        }
       if(gnam =="XXXX") file="players/wizard/guild/guild";
   if(gnam == "undead")  file = "players/hurtbrain/life";
   if(gnam == "shadow")  file = "players/pathfinder/closed/shadow/shadow";
       if(gnam =="vampire") file="players/nooneelse/black/vampire_fangs";
    move_object(clone_object(file),this_player());
    write("Guild object loading procedure complete.\n");
  return 1;
}
