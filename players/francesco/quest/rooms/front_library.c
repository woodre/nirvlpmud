#include "/players/francesco/univ/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

string *entered;

reset(arg) {
  if(arg) return 0;
set_light(1);

short_desc = "Passage room";
long_desc =
"  The passage room from the outer and the inner part of the library \n"+
"of the Department of Mechanical Engineering is used also as a waiting \n"+
"room during the work of the employees to reposition the books within \n"+
"the shelves.  There is a passage leading back to the librarian desk\n"+
"and a doorway to go to the inner part of the library.  A small table\n"+
"is on the right side of the room, a flier laying on it.\n";

entered = ({ });

items = ({
  "shelves",
  "Through the glass door, you can see the metallic shelves holding the books",
  "doorway",
  "A revolving door made by transparent glass.  'Enter' it to proceed",
  "table",
  "A simple wooden table, about three feet large",
  "flier",
  "It is chained to the table. It consists of few pages and can be read",
  "passage",
  "Just a narrow path between two counters.  'Pass' it to go back",

  });

}

  init(){
  ::init();
  add_action("read_flier","read");
  add_action("forth","enter");
  add_action("back","pass");
}

forth(str) {
 if(!str) { write("Enter where?\n"); return 1;}
  if(str == "door") {
    if(sizeof(entered)) {
     write("The books had not properly repositioned within the shelves yet.\n"+
           "You cannot enter the inner library now, please come back later.\n");
    return 1;  }
   entered += ({ this_player()->query_real_name() });
   write("You pass the transparent doorway and you find yourself within the \n"+
         "shelves of the library of the Department of Mechanical Engineering.\n");
   tp->move_player("into the shelves#players/francesco/quest/rooms/back_library.c");
   write_file("/players/francesco/log/enter_library", ctime(time())+"  "+tpn+
             "    [Level  "+tp->query_level()+"+"+tp->query_extra_level()+"]\n");    
   return 1; }
   write("You cant enter there.\n");
return 1;}

back(str) {
  if(!str) { write("Pass where?\n"); return 1;}
  if(str == "path") {
   write("You pass within the two counters and see the librarian smiling at you:\n"+
         "'Did you find the books you were looking for?' she asks gently.\n");
   tp->move_player("into the shelves#players/francesco/quest/rooms/dimec13test.c");
   return 1; }
   write("You cant pass there.\n");
return 1;}


read_flier(str){
  if(!str) { write("Read what?\n"); return 1;}
  
  if(str=="flier") {
     write("Reading the external part of the flier shows the following words:\n"+
           "     T H E   S I X   R U L E S   O F   T H E   L I B R A R Y   \n"); 
     return 1;}

  if(str == "rules" || str=="rule") {
     write("What rule number do you want to read?\n");
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
     write("One person at a time is allowed to enter the shelves area.\n"+
           "If this person needs to go back to this transit room, he is\n"+
           "not allowed to re-enter before the clerks have repositioned\n"+
           "all the books in the proper shelves.  This time may vary.\n");
     return 1;  }

  if(str == "rule 4") {
     write("It is allowed to pickup only one book per subject.\n"+
           "You can read the book here and then 'return' it to \n"+
           "the librarian.\n");
     return 1; }

   if(str == "rule 5") {
     write("The books are electronically marked and therefore they are\n"+
           "worthless outside of the library.  Remind, worthless but \n"+
           "not useless.  The books can be 'return'ed to the librarian\n"+
           "for a price.\n");
     return 1; }

   if(str == "rule 6") {
      write("It is allowed to get a whole set of books in mechanical\n"+
            "engineering with the goal of applying for a degree.  The \n"+
            "librarian might give you a certificate if the books are \n"+
            "properly 'return'ed.  The Dean of the Department will then\n"+
            "perform the final ceremony.\n");
     return 1; }

     write("What do you want to read?\n"); 
  return 1;
}

 realm(){ return "NT"; }
 
