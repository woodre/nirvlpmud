#define tp this_player()
#define tpn this_player()->query_name()
int counter;

reset()
{counter= 0; }

short() { return "A wooden desk"; }

long() {
 write("This wooden desk is used to 'leave' the books on it when someone\n"+
       "wants to show that he completed the curriculum and wants to \n"+
       "'apply for degree'.  It has "+counter+" book(s) on it.  The books can be\n"+
       "'pick'ed back to 'return' them for coins.\n"); }
    
init() {
    add_action("put_book","leave");
    add_action("get_book","pick");
    add_action("apply_degree","apply");
}

id(str) { return str == "desk" || str== "wooden desk" || str == "Wooden desk" || str == "A wooden desk"; }

get(str) {
    if (str == "desk") {
	notify_fail("What?  Get this desk?  Naawww.\n");
	return 0;}
    return 0;
}

put_book(str) {
    object dummy;
    object desk;
    desk=(present("desk",environment(tp)));
    if(!str) { notify_fail("Leave what?\n") ; return 0; }
    if(str == "book on desk") {
     if(present("libro",tp)) {
      if(counter==21) {notify_fail(""); return 0;}
      counter++;
     write("You leave a book on the librarian desk.  It now holds "+counter+" book(s).\n");
     dummy = (present("libro",tp));
     move_object(dummy,desk);
     this_player()->recalc_carry();
     return 1;}  
     notify_fail("You dont have any book to leave there.\n");
     return 0;}
     notify_fail("You cant leave that on desk.\n");
     return 0;
}

get_book(str) {
    object dummy;
    object desk;
    desk=(present("desk",environment(tp)));
    if(!str) { notify_fail("Pick what?\n") ; return 1; }
    if(str == "book from desk") {
     if(present("book",desk)) {
      counter--;
     write("You get a book from the librarian desk.  It now holds "+counter+" book(s).\n");
     dummy = (present("book",desk));
     move_object(dummy,tp);
     tp->recalc_carry();
     return 1;}  
     write("The desk doesnt hold any book.\n");
     return 1;}
     write("You cant get that from the desk.\n");
     return 1;
}

apply_degree(str) {
   object ob;
   object desk;
    desk=(present("desk",environment(tp)));
    if(!str) { notify_fail("Apply for what?\n") ; return 0; }
    if(str == "for degree") {
      if(counter == 21) {
      ob = (clone_object("/players/francesco/quest/items/degree2.c"));
      move_object(ob,tp);
      write_file("/players/francesco/log/21books",
             ctime(time())+"  "+tpn+" dropped "+counter+" books\n");    
      write("The librarian hands you a diploma and says:  \n"+
            "Well done, "+tp->query_name()+", now you can go to the \n"+
            "Dean of the Department and 'graduate'.\n"+
            "She then picks the books from the desk and\n"+
            "puts them on a conveyor.\n");
      destruct(this_object());
      ob=clone_object("/players/francesco/quest/items/desk2.c");
      move_object(ob, environment(tp));
      return 1; }
      write_file("/players/francesco/log/incomplete",
             ctime(time())+"  "+tpn+" dropped "+counter+" books\n");    
      notify_fail("The librarian counts up to "+counter+", smiles at you and softly says:\n"+
                  "No, sorry, "+tp->query_name()+", you still didnt complete the whole curriculum.\n");
      return 0; }
      notify_fail("You cant apply for that.\n");
      return 0;
}



/*******************
int file_size_for_string(string filename, string check_string)
{
   int x;
   string file_input;

   x = file_size(filename);
   if (x == 0)
   {
      write("File does not exist or is 0 bytes.\n");
      return 0;
   }

   file_input = read_bytes(filename);
   if (sscanf(file_input, check_string))
      return 1;

   return 0;
}
******************/
