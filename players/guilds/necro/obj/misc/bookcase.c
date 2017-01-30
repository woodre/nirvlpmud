#include "../../DEFS"

id(str){ return (str=="bookcases" || str=="bookcase" || str=="shelf" || str=="shelves" || str=="bookshelves" || str=="bookshelf"); }

long(){
    object book;
    book = first_inventory(this_object());
    write("Oak bookcases that stretch from the floor to the ceiling.  Many of\n"+
      "them hold very old books, some of which one could retrieve and read.\n"+
      "They however always put the books back on the bookcase when they are\n"+
      "done.\n");
    if(book){
	write("    The bookcase contain:\n");
	while(book){
	    if(book) write(book->short()+"\n");
	    book = next_inventory(book); 
	}
    }
}

reset(arg){
    if(arg) return;
    move_object(clone_object(OBJ+"/misc/history.c"),this_object());
    move_object(clone_object(OBJ+"/misc/handbook.c"),this_object());
    move_object(clone_object(OBJ+"/misc/levelguide.c"),this_object());
    move_object(clone_object(OBJ+"/misc/spellguide.c"),this_object());
}

can_put_and_get(str){
/* commented out after titan reported problems getting the books - miz - 15 may 2010 */

/*
    if(query_verb() == "get" || query_verb() == "take"){
	return str == 0;
    } 
    return 0;
*/
    return 1;
}

init(){
    add_action("put","put");
    add_action("retrieve_book","retrieve");
    add_action("get_me","get");
}

get_me(str){
    string first,last;
    int which;
  if(!str) return 1;
    if(str == "book"){
	if(present("book", environment(this_player()))){
	    return 0;
	}
	write("Where would you like to get the book from?\n");
	return 1;
    }
    if(sscanf(str,"%s %d from %s",first,which,last) == 3){
	if(first == "book" && id(last)){
	    if(present("book "+which,this_object())){
            move_object(present("book "+which, this_object()), this_player());
		write("You get book "+which+" from the "+last+".\n");
		return 1;
	    }
	}
    }
}

retrieve_book(str){
    command("get "+str,this_player());
    return 1;
}

put(str){
    string what,where;
    object item;
    if(!str) return;
    sscanf(str,"%s on %s",what,where);
    if(!where) return;
    if(present(where,environment(this_player())) != this_object())
	return;
    item = present(what,this_player());
    if(!item) return;
    if(!item->query_necro_book()){
	write("That is not something you can put on this bookshelf.\n");
	return 1;
    }
    if(item->query_open()){
	write("You must close the book before putting it back on the shelf.\n");
	return 1; 
    }
    move_object(item,this_object());
    this_player()->recalc_carry();
    write("You put "+what+" on to the "+where+".\n");
    return 1;
}
