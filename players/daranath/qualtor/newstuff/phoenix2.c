#define MAX_GUESTS 25
#define ROOM_COST 500
#define tp this_player()->query_name()
#include <ansi.h>

inherit "room/room";

string guests;
int full,done;
object box;
int is_done,guest_no,guest_count;

reset(int arg){
  if(!arg){
    
    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"("+HIR+"The Phoenix Inn"+NORM+")");
    long_desc=
"The walls of the Phoenix Inn are painted with a dark red stain, giving the\n"+
"entire place a deep, brooding feel. A pair of rooms branch off from\n"+
"the main chamber, with a small sign on the far wall giving directions.\n";

    items=({
"walls","The walls here are stained a dark red color",
"wall","The walls here are stained a dark red color",
"inn","The Phoenix Inn is a boon to explorers of Qual'tor",
"stain","The stain is dark red in color",
"place","The inn itself is a brooding place, with two small chambers off the\n"+
     "main one",
"rooms","The two smaller chambers each have thier own purpose",
"room","The two smaller chambers each have thier own purpose",
"chamber","The main chamber has a small sign on the far wall",
"sign","The sign reads:\n"+
     " "+WHT+"(--------------------------------------)\n"+
     "  |"+HIR+"    Welcome to the Phoenix Inn    "+NORM+" "+WHT+" |\n"+
     "  |"+WHT+"    --------------------------    "+NORM+" "+WHT+" |\n"+
     "  |"+HIR+"    Locker storage is East        "+NORM+" "+WHT+" |\n"+
     "  |"+HIR+"    Login Point is West           "+NORM+" "+WHT+" |\n"+
     " "+WHT+"(--------------------------------------)"+NORM+" ",
    });

    dest_dir=({
"/players/daranath/qualtor/east_road2.c","north",
"/players/daranath/dar_lockers.c","east",
"/players/daranath/qualtor/newstuff/login_point.c","west",
    });

    }
  }

    init(){
      ::init();
add_action("search","search");
add_action("register_room","register");
add_action("check_out","checkout");
add_action("south","south");
add_action("list_guests","list");
    }

    search(){
write("There is not much to search with the Phoenix Inn.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

set_login(str) {
if(!str) {write("Where do you want to login (city or church)?\n");
return 1;  }
if(str == "city") {
this_player()->set_home("/players/daranath/qualtor/newstuff/login_point.c"); }
if(str == "church") {
this_player()->set_home("/room/church.c"); }

return 1;
}
