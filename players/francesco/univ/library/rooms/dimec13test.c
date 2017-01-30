#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
string *enter_already;

reset(arg) {
  if(arg) return;
if (!present("clerk3")) {
  move_object(clone_object("/players/francesco/univ/mob/clerk3.c"),
	this_object());  }
enter_already = ({ });
set_light(1);

short_desc = "The library" ;
long_desc =
     "   Textbooks, Magazines, Journals and Fliers fill the shelves around\n"+
     "this room in a perfect order.  Several signs show the various subjects\n"+
     "covered by the library items.  It is very easy then to search and to\n"+
     "achieve what you intend to get for your study purposes.  There is a\n"+
     "passage between two counters.\n",
items = ({
   "signs","They are written according to the international\n"+
           "library classification method",
   "shelves","Metallic shelves to hold the books",
   "textbooks","They are used by the students for the preparation of their exams",
   "magazines","Useful when you want to know about technical literature",
   "journals","Useful when you want to know about scientific literature",
   "fliers","They report the upcoming scientific events all around the world",
   "passage","It leads to the back part of the library",
   "counters","One meter far from one another, they are about one meter tall.\n"+
              "A metallic bar is positioned across them",

});

dest_dir = ({
   
   "/players/francesco/univ/rooms/dimec12.c","east",
/*   "/players/francesco/univ/library/rooms/front_library.c","west" */
   
   
});

}

  init(){
  ::init();
  add_action("show_id","show");
}

show_id(str) {
 if(!str) { write("Show what?\n"); return 1;}
  if(str == "id") {
   if(!present("marian",environment(tp))) {
      write("The librarian is off, please come back later.\n");
   return 1; }
   if(sizeof(enter_already)) {
     write("The books had not properly repositioned within the shelves yet.\n"+
           "You cannot enter the library now, please come back later.\n");
    return 1;  }
   if(!present("id",tp)){
      write("You dont have any ID, what are you trying to show?\n");
   return 1; }
   write("You show your ID to the librarian which raises the bar across\n"+
         "the counters,  lets you pass through them and then says:\n"+
         "'Please, remember to read the rules of the library' \n");
   tp->move_player("to the library#players/francesco/univ/library/rooms/front_library.c");
   destruct(present("id",tp));
   enter_already += ({ this_player()->query_real_name() });
   return 1; }
   write("Showing the "+str+" is useless.\n");
return 1;}

