#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"("+HIR+"The Phoenix Inn"+NORM+")");
    long_desc=
"Wooden walls are a stark contrast to the grey stone flooring here. A bright red\n"+
"sigil has been drawn upon the floor, a magical construct for summoning and dismissing\n"+
"creatures from other worlds.\n"+
"There is a small sign upon the far wall.\n";

    items=({
"sigil","The glowing sigil pulses with a life all its own, reaching out and \n"+
     "attempting to bring players into nirvana",
"sign","The sign reads:\n\n"+
     "The login point for the City of Qual'tor.\n\n"+
     "To log into Nirvana and arrive here, type: "+HIR+"login city"+NORM+"\n"+
     "To once again log into the church, type: "+HIR+"login church"+NORM+"\n\n"+
     "Note: A couple of guilds may not allow you to login into the city.\n"+
     "      These commands will only work within this single room",
    });

    dest_dir=({
"/players/daranath/qualtor/newstuff/pheonix.c","east",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
add_action("set_login","login");
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
write("You will now login to the City of Qual'tor when entering Nirvana.\n");
this_player()->set_home("/players/daranath/qualtor/newstuff/login_point.c"); }
  if(str == "church") {
write("You will once again log into the Church when entering Nirvana.\n");
this_player()->set_home("/room/church.c"); }
  if((str != "church") && (str != "city")) {
write("Usage: login city or login church only!\n");
return 1; }
write_file("/players/daranath/closed/log/login_point",ctime(time())+" "+this_player()->query_real_name()+" set to "+str+"\n");
return 1;
}
