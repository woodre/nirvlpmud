int counter;

reset()
{counter= 0; }

short() { return "A wooden desk"; }

long() {
 write("This desk is used to 'put' the 'book's 'on it' when you want \n"+
       "to 'apply for degree'.  It has "+counter+" books on it.\n"); }
    
init() {
    add_action("put_book","put");
    add_action("apply_degree","apply");
}

id(str) { return str == "desk" ; }


get(str) {
    if (str == "desk") {
	write("What?  Get this desk?  Naawww.\n");
	return 0;}
    return 0;
}

put_book(str) {
    if(!str) { write("Put what?\n") ; return 1; }
    if(str == "book on desk") {
     if(present("book",this_player())) {
      counter++;
     write("You put a book on the librarian desk.  It now holds "+counter+" books.\n");
     destruct(present("book",this_player()));
     return 1;}  
     write("You dont have any book to put there.\n");
     return 1;}
     write("You cant put that on desk.\n");
     return 1;

}

apply_degree(str) {
   object ob;
    if(!str) { write("Apply what?\n") ; return 1; }
    if(str == "for degree") {
      if(counter == 21) {
      ob = (clone_object("/players/francesco/quest/items/degree.c"));
      move_object(ob,this_player());
      write("Well done, now you can go to the Dean of the Department\n"+
            "for the graduation ceremony.\n");
      counter = 0;
      return 1; }
      write("No, sorry, you still didnt complete the whole curriculum.\n");
      return 1; }
      write("You cant apply for that,\n");
      return 1;
}

