inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
 object ladder;
reset (int arg){
 if (arg) return;
 set_light(0);
 short_desc="Dark and Dingy Room";
  long_desc="You have entered a dark, dingy and damp room that has no windows and\n" +
            "a straw mat on the floor that passes for the bed. It appears as if\n" +
            "the room once was habitable however you know wonder how any one could\n" +
            "sleep in it now. To the east you see a path leading out of the room\n" +
            "while there is a ladder leading up to a hatch in the ceiling.\n" +
           "\n";
  items=({"ladder","The ladder looks both rickety and dangerous\n" +
                   "you think you would be lucky for it to stand\n" +
                   "your weight",
          "mat","It is difinitely made out of straw and looks uncomfortable",
          "floor","It is barely visible through the years of filth",
          "hatch","It appears to be both wooden and heavy",
        });
  dest_dir=({"players/persephone/rooms/paphot1e","east",
  });
}
init(){
 ::init();
  add_action("climb1","climb");
}
climb1(str){
 if(str=="ladder"){
  write("You tentatively climb up the old ladder and push the hatch open far enough\n" +
        "for you to squeeze through the opening.\n");
  say (capitalize(this_player()->query_name())+" climbs up the ladder and disappears through\n" +
       "a hatch in the ceiling\n");
  this_player()->move_player("#"+"players/persephone/rooms/jennysrm");
  return 1;
 }
}
realm(){ return "NT";}
