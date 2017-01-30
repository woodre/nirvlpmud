#include "/players/francesco/univ//ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

string *entered;

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "The front library";
long_desc =
"  After you pass through the counters you are now in what looks\n"+
"like a transit room.  You can come back to the librarian desk\n"+
"through a passage,  or you can go forward to the shelves through\n"+
"a doorway.  A small table is on the right side of the room, a \n"+
"flier laying on it.\n";

entered = ({ });



items = ({
  "shelves",
  "Through the glass door, you can see the metallic shelves holding the books",
  "doorway",
  "A revolving door made by transparent glass",
  "table",
  "A simple wooden table, about three feet large",
  "flier",
  "Consists of few pages, it can be read",
  "passage",
  "Just a narrow path between two counters",

  });

}

  init(){
  ::init();
  add_action("read_flier","read");
  add_action("go_forward","go");
  add_action("come_back","come");
}

go_forward(str) {
 if(!str) { write("Go where?\n"); return 1;}
  if(str == "forward") {
    if(sizeof(entered)) {
     write("The books had not properly repositioned within the shelves yet.\n"+
           "You cannot enter the inner library now, please come back later.\n");
    return 1;  }
   entered += ({ this_player()->query_real_name() });
   write("You pass the transparent doorway and you find yourself within the \n"+
         "shelves of the library of the Department of Mechanical Engineering.\n");
   tp->move_player("into the shelves#players/francesco/univ/library/rooms/back_library.c");
   write_file("/players/francesco/log/enter_library", ctime(time())+"  "+tpn+
             "    [Level  "+tp->query_level()+"+"+tp->query_extra_level()+"]\n");    
   return 1; }
   write("You cant go there.\n");
return 1;}

come_back(str) {
  if(!str) { write("Come where?\n"); return 1;}
  if(str == "back") {
   write("You pass within the two counters and see the librarian smiling at you:\n"+
         "'Did you find the books you were looking for?' she asks gently.\n");
   tp->move_player("into the shelves#players/francesco/univ/library/rooms/dimec13test.c");
   return 1; }
   write("You cant come there.\n");
return 1;}


read_flier(str){
  if(!str) { write("Read what?\n"); return 1;}
  
  if(str=="flier") {
     write("Reading the external part of the flier shows the following words:\n"+
           "     T H E   S I X   R U L E S   O F   T H E   L I B R A R Y   \n"); 
     return 1;}

  if(str == "rules") {
     write("What rule do you want to read?\n");
     return 1;}

  if(str == "rule 1") {
     write("The service is addressed towards those who are really\n"+
           "willing to learn something more about mechanical engineering,\n"+
           "therefore it will not be tolerated that people come here \n"+
           "only for wasting their time.\n");
     return 1; }

  if(str == "rule 2") {
     write("Once you come here you are requested to stay solo, so \n"+
           "that you can concentrate on your study.\n");
     return 1; }

  if(str == "rule 3") {
     write("It is allowed to pickup only one book per subject.\n"+
           "You can read the book here and then return it to \n"+
           "the librarian.\n");
     return 1; }

   if(str == "rule 4") {
     write("The books are electronically marked and therefore they are\n"+
           "worthless outside of the library.  Remind, worthless but \n"+
           "not useless.\n");
     return 1; }

   if(str == "rule 5") {
      write("It is allowed to go outside of the library with the whole set\n"+
            "of books in mechanical engineering if you want to apply for\n"+
            "a degree.  The Dean of the Department will take care of it.\n");
     return 1; }

   if(str == "rule 6") {
     write("One person at a time is allowed to enter the shelves area.\n"+
           "If this person needs to go back to the front library, he is\n"+
           "not allowed to re-enter before the clerks have repositioned\n"+
           "all the books in the proper shelves.  This time may vary.\n");
     return 1;  }

     write("What do you want to read?\n"); 
  return 1;
}

 realm(){ return "NT"; }
 
