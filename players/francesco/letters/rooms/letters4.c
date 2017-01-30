#include "/players/francesco/univ/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
/*  if(arg) return; */
 object board;

if (!present("board")) {
     board = clone_object("players/francesco/letters/items/board2.c");
     board->set_datafile("history");
     board->set_name("history");
     move_object(board,this_object());  }

set_light(1);

short_desc = "Letters Department" ;
long_desc =
     "   The Nirvana Characters History room is only filled with a desk, a  \n"+
     "business chair and a shelf.  On the desk there are a notebook, a pencil\n"+
     "and a plaque.  A suffuse light comes from a chandelier on the ceiling.\n",

items = ({
   "room","This room is about ten by ten square feet wide",
   "chandelier","It has four lamps, which send a weak and relaxing light",
   "ceiling","Of a semi-circular shape, like the old roman arches",
   "notebook","It has a light gray color, most likely made by recycled paper",
   "pencil","A wood yellow pencil with a graphite lead",
   "desk","It is just a bit wider than a notebook",
   "chair","It looks very comfortable, with a high back",
   "shelf","It is locked with a glass window.  Some papers are held inside",
   "plaque","A wooden plaque which can be viewed"
});

dest_dir = ({
  "/players/francesco/letters/rooms/letters2.c","west"
});

}

init() {
    ::init();
    add_action("view","view");
}


view(str){
     if(str=="plaque"){
     write("     ---------------------------------------------------------\n"+
           "    |              "+HIR+"A K N O W L E D G M E N T S "+NORM+"               |\n"+
           "    |  "+HIW+"                    "+NORM+"                                   |\n"+
           "    |  "+HIW+"    Thanks are due to Kylie and to Stone for their    "+NORM+" |\n"+
           "    |  "+HIW+"    suggestion of making new bulletin boards."+NORM+"          |\n"+
           "    |  "+HIW+"                    "+NORM+"                                   |\n"+
           "    |  "+HIW+"    Other proposals and requests will be welcome  "+NORM+"     |\n"+
           "    |  "+HIW+"    and acknowledged. "+NORM+"                                 |\n"+
           "    |  "+HIW+"                    "+NORM+"                                   |\n"+
           "     ---------------------------------------------------------\n");
     return 1; }
  notify_fail("View what?\n");
  return 0;
}
