#include "ansi.h"
inherit "room/room";

    void reset(status arg) {
    if (arg) return;
    set_light(1);
    short_desc = GRN+"Movie Mania"+NORM;
    items = ({
        "dvd","Various DVDs for one to watch",
        "dvds","Various DVDs for one to watch",
        "video","Various video tapes for people to watch",
        "tape","A video tape that one can watch",
        "tapes","Various video tapes that people can watch",
        "row","A row of chairs",
        "chairs","Chairs that you'd see in a theater",
        "chair","A hard, uncomfortable chair",
        "screen","A pull down movie screen",
        "vcr","An older VCR player",
        "player","A new DVD player",
        "table","A small wooden table that holds a VCR/DVD player",
        "joe","It's Joe Dirt the movie!",
        "dirt","It's Joe Dirt the movie!",
        "dude","A Dude, Where's My Car DVD",
        "car","A Dude, Where's My Car DVD",
        "bubble","Bubble Boy on video",
        "boy","Bubble Boy on video",
        "floor","The carpeted floor is covered with DVDs and video tapes"});
        
    long_desc =
"   DVDs and video tapes are scattered all over the floor.  A row\n\
of theater chairs sits in front of a pull down screen.  A VCR and\n\
DVD player are on top of a small table.  Maybe one of the movies\n\
can be played.  Try Joe Dirt, Dude, Where's My Car, or Bubble Boy.\n";
    dest_dir = ({"players/martha/joedirt/station", "dirt",
    			 "players/martha/dude/house", "car",
 				 "players/martha/bubble/bubble", "bubble",
    			 "players/martha/store", "back",});
}
init () {
   ::init() ;
     add_action ("block","dirt");
     add_action ("block","car");
     add_action ("block","bubble");
     }

block(str) {
     write("This area is in the process of having inventory taken.\n");
     return 1;}
blocked(str) {
     write("Inventory is currently being taken, try again later.\n");
     return 1;
     }