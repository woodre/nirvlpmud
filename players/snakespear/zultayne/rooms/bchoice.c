#include "/players/snakespear/closed/ansi.h"
#define TP this_player()
inherit "room/room";

reset(arg){
   if(!present("teacher")) {
   move_object(clone_object("/players/snakespear/zultayne/critters/teach.c"),this_object());
   }
   if(arg) return;
      
set_light(3);
short_desc=HIR+"-#-  "+HIY+"Discipline Room  "+HIR+"-#-"+NORM;
long_desc=
  "  This large room has many corpses and gear laying around the room.\n"+
  "By the smell and looks of things here, this is not somewhere you wish\n"+
  "to be, however, you chose to be here.  You were given a warning, yet\n"+  
  "you proceded and tempted fate.  Now your choices are few and your fate\n"+
  "lies in your hands.\n\n"+HIW+
  "                     Fate is the:\n\n"+HIR+
  "                   Friend of the good,\n"+
  "                   Guide to the wise,\n"+
  "                   Tyrant of the foolish,\n"+
  "                   Enemy of the bad.\n\n"+NORM;

items=({
     "corpses", "Fallen mortals that were foolish in their choices",
     "gear","The equipment from foolish mortals that tried to 'escape'",
});
}
      
realm() { return "NT"; }

init()  {
    ::init();
    write("\n\n\t  YOU MADE YOUR CHOICE!  NOW DIE WITH IT!\n\n");
    add_action("search_room","search");
    add_action("smell","smell");
    add_action("listen","listen");
    add_action("break_out","escape");
    add_action("wish","wish");
}

search_room() {
      write("After hopelessly searching, you wish for death.\n");
      return 1;
}
smell() {
      write("Do you smell you own death?\n");
      return 1;
}
listen() {
      write("Your gut tells you: You made the wrong move, pal!\n");
      return 1;
}
break_out() {
      if(present("teacher")) { 
         write(GRY+"Teacher says: WRONG ANSWER! TRY AGAIN AFTER YOU DIE!\n"+NORM);
         present("teacher")->attack_object(this_player());
         return 1;
         }
      call_other(this_player(),"move_player","the room#room/vill_green.c");
      return 1;
}
wish() {
      if(present("teacher")) { 
         write(GRY+"You just ROYALLY pissed off the Teacher!\n"+NORM);
         present("teacher")->attack_object(this_player());
         return 1;
         }
      call_other(this_player(),"move_player","the room#players/snakespear/zultayne/rooms/portal.c");
      return 1;
}
