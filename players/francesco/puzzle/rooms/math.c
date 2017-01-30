#include "/players/francesco/univ/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
int x, play;
string dummy;

reset(arg) {
  if(arg) return;

set_light(1);

short_desc = "Math puzzles" ;
long_desc =
     "   Several desks are aligned one after the other, with their\n"+
     "respective chairs.  They are separated from one another by \n"+
     "transparent screens which do not allow any exchange of information\n"+
     "between the players.  On each desk are some sheets of paper, some\n"+
     "pencils, one hand-held calculator and a flier.\n",

items = ({
   "chairs","Made by soft leather with support for the arms and the head",
   "desks","Each one is about one square meter, made by wooden",
   "screens","Made by some transparent plastic, about one and a half meter tall",
   "pencils","Some are red and some are black",
   "sheets","Of european A4 format, 21 by 30 centimetres",
   "calculator","They look very cheap, maybe they can only do the four basic operations",
   "flier","Made by four folded pages, it can be read",
});


dest_dir = ({
  "/players/francesco/puzzle/rooms/hub.c","back",
});

}

init() {
    add_action("read_book","read");
}

read_book(stri) {
     if (!stri)
      {
      write("Read what?\n");
      return 1;
      }
     if(stri == "flier")
      {
      write("What page do you want to read?\n");
      return 1;
      }
     if(stri == "page a") {
     write("Congratulations for joining the Math Puzzles.\n"+
           "You can now prove your ability in this field.\n");
     return 1; }
     if (stri=="page b")  {
     write("There are four levels of increasing difficulty available.\n"+
           "Just type the number of level you want to try to get your puzzle.\n"+
           "The format is like this one: 'level #'\n");
     return 1; }
     if (stri=="page c")  {
     write("The answers must be given in a simple format like this one:\n"+
           "'answer #'   Be careful to exactly type your answer.\n");
     return 1;  }
     if (stri=="page d")  {
     write("Three chances are given to say the right answer.\n");
     return 1;  }
     if (stri=="puzzle"){
      write("     a + b = c\n"+
            "     *   -   -\n"+
            "     d / e = d/6\n"+
            "     =   =   =\n"+
            "    ef   a   d\n");
      write("\nWhat is the value of a?\n\n");
      return 1;}
}

