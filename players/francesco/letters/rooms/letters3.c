#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
/*  if(arg) return; */
 object board;

if (!present("board")) {
     board = clone_object("players/francesco/letters/items/board1.c");
     board->set_datafile("fiction");
     board->set_name("fiction");
     move_object(board,this_object());  }

set_light(1);

short_desc = "Letters Department" ;
long_desc =
     "    The Nirvana Fiction room is only filled with a desk, a business chair\n"+
     "and a shelf.  On the desk there are a notebook and a pencil.  A suffuse\n"+
     "light comes from a chandelier on the ceiling.\n",

items = ({
   "room","This room is about ten by ten square feet wide",
   "chandelier","It has four lamps, which send a weak and relaxing light",
   "ceiling","Of a semi-circular shape, like the old roman arches",
   "notebook","It has a light gray color, most likely made by recycled paper",
   "pencil","A wood yellow pencil with a graphite lead",
   "desk","A small metallic desk, just a bit wider than a notebook",
   "chair","It looks very comfortable, with a high back",
   "shelf","It is locked with a glass window.  Some papers are held inside",

});

dest_dir = ({
  "/players/francesco/letters/rooms/letters2.c","east"
});

}

init() {
    ::init();
}

