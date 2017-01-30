#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
if (!present("clerk3")) {
  move_object(clone_object("/players/francesco/univ/mob/clerk3.c"),
	this_object());  }

set_light(1);

short_desc = "The library" ;
long_desc =
     "   Textbooks, Magazines, Journals and Fliers fill the shelves around\n"+
     "this room in a perfect order.  Several signs show the various subjects\n"+
     "covered by the library items.  It is very easy then to search and to\n"+
     "achieve what you intend to get for your study purposes.\n",
items = ({
   "signs","They are written according to the international\n"+
           "library classification method",
   "shelves","Metallic shelves to hold the books",
   "textbooks","They are used by the students for the preparation of their exams",
   "magazines","Useful when you want to know about technical literature",
   "journals","Useful when you want to know about scientific literature",
   "fliers","They report the upcoming scientific events all around the world",

});

dest_dir = ({
   
   "/players/francesco/univ/rooms/dimec12.c","east",
   
   
});

}
