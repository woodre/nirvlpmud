#include "/players/jenny/define.h"

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
say(TPN+" sniffs around..\n");
          return 1; }

     write(""+smell+"\n");
 
     say(TPN+" listens intently..\n");

          return 1; }

  listen() {

   if(!listen) {
       write("You hear nothing unusual.\n");
          return 1; }

     write(""+listen+"\n");

     say(TPN+" listens intently..\n");
    
          return 1; }
  search() {
  
   if(!search) {
       write("You search the room, but find nothing.\n");
say(TPN+" searches the room.\n");
          return 1; }

     write(""+search+"\n");
 
     say(TPN+" searches the room.\n");

          return 1; }
