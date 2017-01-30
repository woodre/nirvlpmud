#define tp this_player()->query_name()
inherit "room/room";
#include <ansi.h>
#include "/players/saber/closed/esc.h"

reset(int arg){
  if(!arg){
    
    set_light(1);
    short_desc= "Library of the Mage";
    long_desc=
      "Books and shelves line the walls of this small room, with small\n"+
      "gaps inbetween housing a smoldering torch for lighting. A large\n"+
      "table rests on the far side of the room, bubbling cauldrons and\n"+
      "glass beakers filled with foreign liquids sitting atop it. Heavy\n"+
      "oak makes up a large desk in the far left corner of the room. A\n"+
      "large open book lays upon the desk.\n";
      
    items=({
      "torches", "Smoldering torches are lined along the walls, shedding\n"+
                 "some light about the area",
      "books", "Various books and tomes line the shelves about the room\n"+
               "in no particular order. The books are of all types and\n"+
               "sizes, making one have to take the time to "+HIY+"<"+NORM+"search"+HIY+">"+NORM+" the\n"+
               "the books to find anything of interest",
      "shelves", "The bookshelves are made of a sturdy oak",
      "table", "The large table on the far side of the room looks much\n"+
               "like a laboratory table found in most alchemy rooms",
      "beakers", "The glass beakers are filled with colorful and strange\n"+
                 "liquids about them",
      "cauldrons", "The boiling liquids within the cauldrons are nothing\n"+
                   "you want to mess with",
      "desk", "The large wooden desk is made of an ancient oak and looks\n"+
              "as if it might hold something of interest.\n"+
              "Maybe you should "+HIY+"<"+NORM+"search"+HIY+">"+NORM+" it",
      "book", "The large open book on the desk is much too heavy to take\n"+
              "with you, though you could "+HIY+"<"+NORM+"read"+HIY+">"+NORM+" it",
              });

    dest_dir=({
      "/players/daranath/underdark/crypt/hall2.c","east",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    add_action("read","read");
    add_action("search books","search books");
    add_action("search desk","search desk");
    }

    search(){
    write("You find nothing about the room.\n");
    say(tp +" searches the room.\n");
     return 1;
    }

    read(){
    write("place something that is written on the book here");
    say(tp +"reads the book.\n");
     return 1;
    }

    search desk(){
    write("You dig through the drawers and area about the desk.\n"+
          "You seem to find something.\n");
    move_object(clone_object("/players/daranath/stuff/dagger_rose.c"->tp));
    say(tp +"searches the desk.\n");
     return 1;
    }

    search books(){
    write("You search the bookshelves and find a book of interest.\n");
    say(tp +"searches the bookshelves.\n");
    move_object(clone_object("/players/daranath/stuff/book1.c"->tp));
     return 1;
    }


arate() { return "YES"; }
