#include "ansi.h"
inherit "room/room";

    void reset(status arg) {
    if (arg) return;
    set_light(1);
    short_desc = CYN+"Musica Festivus"+NORM;
    items = ({
        "tape","An older audio tape",
        "tapes","A stack of older audio tapes",
        "CD","A compact disc in a jewel case",
        "cd","A compact disc in a jewel case",
        "cds","A stack of compact disc's",
        "CD's","A stack of compact disc's",
        "wall","The wall is painted white and has CD players along it",
        "player","A CD player for one to sample music on",
        "nin","The latest Nine Inch Nails CD",
        "NIN","The latest Nine Inch Nails CD",
        "incubus","The latest Incubus CD",
        "staind","The latest Staind CD",
        "floor","The carpeted floor is covered with CDs and audio tapes"});
        
    long_desc =
"   Audio tapes and CD's are scattered all over the floor.  Along\n\
the wall is a row of CD players which allow people to listen to\n\
samples of CD's before they buy them.  If people wanted to, they\n\
could listen to NIN, Incubus, or Staind.\n";
    dest_dir = ({"players/martha/nin/stage", "nin",
    			 "players/martha/incubus/stage", "incubus",
 				 "players/martha/bubble/staind", "staind",
    			 "players/martha/store", "back",});
}
init () {
   ::init() ;
     add_action ("block","nin");
     add_action ("block","incubus");
     add_action ("block","staind");
     }

block(str) {
     write("This area is in the process of having inventory taken.\n");
     return 1;}
blocked(str) {
     write("Inventory is currently being taken, try again later.\n");
     return 1;
     }