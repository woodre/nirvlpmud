inherit "/players/jenny/room";
#include "/players/jenny/define.h"
realm() { return "NT"; }
string PA;
reset(arg) {
if(!present("budd lynch"))  {
MOCO("/players/jenny/wings/mobs/other/lynch.c"),this_object()); }
    if(arg) return;
    set_light(1);
set_listen(BOLD+"You hear some activity down on the ice surface."+NORM);
set_search(BOLD+"You notice two roster sheets on the table."+NORM);
long_desc=
"This is a small both used by the public address announcer.  It has\n"+      
"plain white walls and thin red carpet.  A large window gives a view\n"+
"of the ice surface.  There is a chair and a long table with a telephone\n"+
"and a microphone on top of it.\n";
items = ({
"carpet","This is cheap thin red carpet which is very worn.  It has many dark\n"+
               "stains from spilled food",
"stains","Many dark stains which are splattered on the carpet",
"window","This is a large opening that gives a good view of the ice surface",

"chairs","A lightly padded chair",
"table","A long wooden table that has a microphone, telephone, and roster\n"+
            "sheets on top of it",
"microphone","A round metal microphone held in a little metal stand.  The P.A.\n"+
                       "announcer uses this to give information to the crowd.  You could\n"+
                        "'announce' something to the people in the stands with it",
"roster sheets","Pieces of paper with the rosters of the Detroit Red Wings and\n"+
                         "the Toronto Maple Leafs",
"telephone","A plain black telephone, which has a direct line to the timekeepers\n"+
                    "box.  The P.A. announcer uses this to get the information he needs\n"+
                    "to announce",
"sheets","Pieces of paper with the rosters of the Detroit Red Wings and\n"+
"the Toronto Maple Leafs",
});
dest_dir = ({
 "/players/jenny/wings/rooms/2h8","north",
});
}
short() {
return BOLD+WHT+"Public Address Booth"+NORM; }
init() { 
    ::init(); 
add_action("tellcrowd","announce");
   this_player()->set_fight_area();
 }
tellcrowd(str)  {
   if(!str) {
      notify_fail("What do you want to announce?\n");
      return 0; }
write(BOLD+"You announce:  "+str+NORM+"\n");
PA = BOLD+CYN+"* "+WHT+"P.A. "+CYN+"*   "+NORM+BOLD+str+NORM;
tell_room("/players/jenny/wings/rooms/stands1c1.c",PA+"\n");
tell_room("/players/jenny/wings/rooms/stands1c3.c",PA+"\n");
tell_room("/players/jenny/wings/rooms/stands1c5.c",PA+"\n");
tell_room("/players/jenny/wings/rooms/stands1c7.c",PA+"\n");
tell_room("/players/jenny/wings/rooms/stands2c1.c",PA+"\n");
tell_room("/players/jenny/wings/rooms/stands2c3.c",PA+"\n");
tell_room("/players/jenny/wings/rooms/stands2c5.c",PA+"\n");
tell_room("/players/jenny/wings/rooms/stands2c7.c",PA+"\n");
tell_room("/players/jenny/wings/rooms/box2.c",PA+"\n");
tell_room("/players/jenny/wings/rooms/box1.c",PA+"\n");
tell_room("/players/jenny/wings/rooms/bench2.c",PA+"\n");
tell_room("/players/jenny/wings/rooms/bench1.c",PA+"\n");
tell_room("/players/jenny/wings/rooms/ice2.c",PA+"\n");
tell_room("/players/jenny/wings/rooms/ice1.c",PA+"\n");
 return 1; }
