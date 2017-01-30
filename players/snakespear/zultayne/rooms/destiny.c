#include "/players/snakespear/closed/ansi.h"
#define TPN this_player()->query_name()
#define TP this_player()

inherit "room/room";

reset(arg){
   if(!present("king")) {
     move_object(clone_object("/players/snakespear/zultayne/critters/king.c"),this_object());
   }
   if(arg) return;
set_light(0);
short_desc=GRY+"?"+HIR+"?"+HIY+"?"+HIW+"?"+HIM+"?"+HIG+"?"+NORM;
long_desc=
 "  This room seems to have no constants.  The only constant here is change.\n"+
 "Swirling masses of color move on every side.  The masses have a strong\n"+
 "feeling that fills the room.  The colors are bright sometimes and other\n"+
 "times very dark.  The feeling that is giving off of these masses changes\n"+
 "with each color. The colors seem enchanted with an unknown power.\n";

items=({
     "masses","Large groups of colors that are constantly changing colors",
     "colors","Powerful beings, possibly a lost part of the Fae",
     "power","You only wish you could have that wonderous strength",
});
    
}

realm() { return "NT"; }

init() {
    ::init();
    write(HIB+"\n\nYou are thrown across space and time!\n\n"+NORM);
    add_action("search_room","search");
    add_action("listen","listen");
    add_action("smell","smell");
    add_action("feel","feel");
    add_action("touch","touch");
    add_action("leave","concentrate");
}

search_room() {
      write("You can't find anything to search.\n");
      return 1;
}
smell() {
      write("After taking in a deep whiff, you feel relaxed.\n");
      return 1; 
}
listen() {
      write("You hear small chattering from something.\n");
      return 1; 
}
feel(str) {
      if(str != "power") { 
         write("Feel what?\n");
         return 1;
         }
      write("There is an overwhelming feeling to 'concentrate'.\n");
      return 1;
}
leave() {
      if(present("king")) { 
         write(HIW+"Your path is blocked!!\n"+NORM);
         return 1;
         }
      call_other(TP,"move_player","power#players/snakespear/zultayne/rooms/portal.c");
      return 1;
}
