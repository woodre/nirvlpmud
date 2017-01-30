#include "/players/languilen/closed/ansi.h"
#define NAME "languilen"
inherit "room/room";

int shield;

string find_short(){
     int x;
     string ss;

     x = random(10) + 1;
     if(x<2) {
              ss = BLU+ "]" +NORM+ " Temporal Stasis " +BLU+ "[" +NORM+ " ";
              return ss;
     }
     if(x<5) {
              ss = BLU+ "Ghostbusters' H.Q." +NORM+" ";
              return ss;
     }
     ss = "Guido's Family Resturant";
     return ss;
}

short(){
     short_desc = (string)find_short();
     return ::short();
}

reset(arg){
     if(arg) return;
     set_light( 1);
     short_desc = (string)find_short();
     long_desc = "shields are at " + shield + "\n\
     Existing outside of space and time this room is well suited\n\
as a testing ground for new creations.  Several boxes lie stacked\n\
and strewn around the other side of the room out of reach.  It looks\n\
like someone's in the middle of moving in.\n";

     dest_dir=({
         "room/church","north",
         "room/adv_guild","south",
         "room/post","post",
    });

}
     

init() {
     ::init();
     if(this_player()->query_real_name() == NAME){
        add_action("on"); add_verb("on");
        add_action("off"); add_verb("off");
        add_action("hall"); add_verb("hall");
     }
     if(this_player()->query_real_name() != NAME && shield == 1) {
        write("You feel an electric shock and see a flash of white light as\n");
        write("you rebound off the defense shield.\n");
        this_player()->move_player("off the shields#room/church");
     }
}
static on() {
     shield = 1;
     write("shields activated.\n");
     return 1;
}
static off() {
     if (call_other(this_player(), "query_real_name", 0) != NAME) {
         write("You are not allowed to do that!!!!!!!\n");
         return 1;
     }
     shield = 0;
     write("shields deacivated.\n");
     return 1;
}
hall() {
     call_other(this_player(), "move_player", "hall#room/adv_inner.c");
     return 1;
}

