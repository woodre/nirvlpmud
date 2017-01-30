#include "ansi.h"
inherit "room/room";

    void reset(status arg) {
    if (arg) return;
    set_light(1);
    short_desc = BLU+"Games Galore"+NORM;
    items = ({
        "games","Various board games from your youth",
        "board","Various board games from your childhood",
        "floor","The carpet is scattered with board games",
        "tables","The tables are marble and round",
        "table","This table is made of grey marble and is round",
        "clue","Clue - the classic game of mystery and intrigue",
        "candyland","Candyland - the classic children's game",
        "monopoly","Monopoly - the classic game of real estate"});
        
    long_desc =
"   Board games lay all around the floor in this area.  There are\n\
games for all ages.  Small round tables are in the corner of this\n\
area for people to set up games and challenge each other.  If one\n\
is feeling really daring, they could set up their own game of Clue,\n\
Monopoly, or Candyland.  Do you dare?\n";
    dest_dir = ({"players/martha/area/rooms/ptrees", "candyland",
    			 "players/martha/clue/rooms/gate", "clue",
    			 "players/martha/monopoly/rooms/go", "monopoly",
    			 "players/martha/store", "back",});
}
init () {
   ::init();
     add_action ("block","clue");
     add_action ("block","monopoly");
     }

block(str) {
     write("This area is in the process of having inventory taken.\n");
     return 1;}
blocked(str) {
     write("Inventory is currently being taken, try again later.\n");
     return 1;
     }