#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
string *enter_already;

reset(arg) {
  if(arg) return;
if (!present("clerk3")) {
  move_object(clone_object("/players/francesco/univ/mob/clerk3bis.c"),
	this_object());  }
if (!present("desk")) {
  move_object(clone_object("/players/francesco/quest/items/desk2.c"),
	this_object());  }enter_already = ({ });
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
/*   "/players/francesco/quest/rooms/front_library.c","west" */
});

}

init(){
  ::init();
  add_action("show_id","show");
  add_action("ask","ask");
}

show_id(str) {
 if(!str) { write("Show what?\n"); return 1;}
  if(str == "id" || str =="ID") {
   if(!present("marian",environment(tp))) {
      write("The librarian is off, please come back later.\n");
   return 1; }
   if(!present("id",tp)){
      write("Marian smiles at you:  'You dont have any ID, what are you trying to show?'\n");
   return 1; }
   write("You show your ID to the librarian which raises the bar across\n"+
         "the counters,  lets you pass through them and then says:\n"+
         "'Please, remember to read the rules of the library'. \n");
   tp->move_player("to the library#players/francesco/quest/rooms/front_library.c");
   return 1; }
   if(!present(str,tp)){
      write("You dont have any "+str+" to show.\n");
   return 1; }
   write("Showing the "+str+" is useless.\n");
return 1;}

ask(str) {
 if(!str) { write("Ask what?\n"); return 1;}
  if(str == "marian" || str =="Marian") {
   if(!present("marian",environment(tp))) {
      write("The librarian is off, please come back later.\n");
   return 1; }
   if(!present("id",tp)){
      write("Marian smiles at you:  'You dont have any ID,\n"+
            "you ought to enroll in order to graduate.'\n");
   return 1; }
   write("Marian softly whispers to you:  'Good thing you plan on graduating in\n"+
         "Mechanical Engineering, but be aware that it will be a tough goal and \n"+
         "will require lot of efforts to study all the related subjects.  Now, \n"+
         "if you can show me your ID, I will let you enter the library.'\n");
   return 1; }
      write("Ask what?\n");
return 1;}
