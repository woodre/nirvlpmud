#include "std.h"
#undef EXTRA_INIT
#define EXTRA_INIT extra_init();
extra_init() {
   add_action("sing","sing");
   add_action("kill","kill");
   add_action("spellf","missile");
   add_action("spellf","shock");
   add_action("spellf","fireball");
   add_action("spellf","flare");
   }
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
  extra_reset() {
    object own;
     if(!present("man")) {
     own=clone_object("obj/monster.c");
       call_other(own,"set_name","man");
       call_other(own,"set_short","Wizened Old Man");
       call_other(own,"set_long","You see before you a very old man.\n");
       call_other(own,"set_ac",15);
       call_other(own,"set_wc",15);
       call_other(own,"set_level",2);
       call_other(own,"set_al",50);
       call_other(own,"set_chat_chance",45);
       call_other(own,"load_chat","Man sings:You must sing open sesame to enter\n" +
               "and have the time of your life!!!\n");
       move_object(own,this_object());
   }
 }
  ONE_EXIT("players/haji/entrance.c", "east",

    "Castle Entrance",
        "This is the entrance to the king`s castle.\n" +
        "However the bridge over the moat is currently\n" +
        "up,but you see a man and he seems to be singing\n" +
        "something.You might want to listen to what he sings.\n",1)
  realm(){return "harem";}
sing(str) {
   if (str!="open sesame") {
     write("You must sing OPEN SESAME.\n");
     return 1;
     }
   tell_room(this_player(),"You watch as the bridge slowly lowers.\n");
   write("You watch as the bridge slowly lowers.\n");
   write("You are summoned into the castle.\n");
   call_other(this_player(),"move_player","leaves into the castle#players/haji/king/castleent.c");
   return 1;
 }
kill(str) {
  if(str=="man"||str=="a wizened old man") {
   write("You can't do that!!!!\n");
   return 1;
  }
 return 1;
 }
spellf(arg) {
  if(!"man"||!"wizened old man"||!"old man"||!"wizened old man") {return 0;}

   write("You really shouldn't do that!!!\n");
   return 1;
  }
