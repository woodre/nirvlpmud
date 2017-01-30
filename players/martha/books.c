#include "ansi.h"
inherit "room/room";

    void reset(status arg) {
    if (arg) return;
    set_light(1);
    short_desc = RED+"Readers Heaven"+NORM;
    items = ({
        "books","Various books for you to read",
        "floor","The carpeted floor is covered with books",
        "couch","A big cushy red couch is here for your comfort",
        "recliner","A tan recliner for you to relax in",
        "recliners","Tan recliners for you to relax in",
        "pokey","The Pokey Little Puppy is a great childrens book",
        "puppy","The Pokey Little Puppy is a great childrens book",
        "harry","Harry Potter is a great midlevel book",
        "potter","Harry Potter is a great midlevel book",
        "black","Black Notice is a good book for the advanced reader",
        "notice","Notice is a good book for the advanced reader"});
        
    long_desc =
"   Books lay all around the floor in this area.  There are books\n\
for those of all reading levels.  A long cushy couch and a couple\n\
of recliners are set up for people who wish to read while in the\n\
store.  Maybe you want to read something now?  How about The Pokey\n\
Little Puppy, Harry Potter or Black Notice?\n";
    dest_dir = ({"players/martha/pokeypup/page1", "puppy",
    			 "players/martha/potter/page1", "potter",
 				 "players/martha/notice/page1", "notice",
    			 "players/martha/store", "back",});
}
init () {
   ::init() ;
     add_action ("block","puppy");
     add_action ("block","potter");
     add_action ("block","notice");
     }

block(str) {
     write("This area is in the process of having inventory taken.\n");
     return 1;}
blocked(str) {
     write("Inventory is currently being taken, try again later.\n");
     return 1;
     }
     