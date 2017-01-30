#include "/players/laera/closed/ldef.h"


inherit "room/room";

string smell,listen,search;

set_smell(sm) { smell = sm; }

set_listen(li) { listen = li; }

set_search(sr) { search = sr; }


init() {

    ::init();

add_action("smell","smell");

add_action("listen","listen");

add_action("search","search");

}

  smell() {

   if(!smell) {
       write("You smell nothing unusual.\n");
say(tpn+" sniffs around..\n");
          return 1; }

     write(""+smell+"\n");

     say(tpn+" listens intently..\n");

          return 1; }

  listen() {

   if(!listen) {
       write("You hear nothing unusual.\n");
          return 1; }

     write(""+listen+"\n");

     say(tpn+" listens intently..\n");

          return 1; }
  search() {

   if(!search) {
       write("You search the room, but find nothing.\n");
say(tpn+" searches the room.\n");
          return 1; }

     write(""+search+"\n");

     say(tpn+" searches the room.\n");

          return 1; }
exit() { if(this_player())
this_player()->clear_fight_area(); }
