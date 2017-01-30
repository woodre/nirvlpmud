/*
 library.c
*/

inherit "room/room";

string str, str2;

init() {
  ::init();

  add_action("read", "read");
}

read(str) {
  if (!str && str != "paper") return;
  command("look at paper", this_player());
  say (this_player()->query_name()+" examines the piece of paper.\n");
  return 1;
}

reset(arg) {
  if (arg) return;

  set_light(0);
  short_desc = "library";
  no_castle_flag=1;
  long_desc =
    "This is obviously a library.  The walls are lined with bookshelves.\n"+
    "There seems to be a piece of paper sticking out from under one of\n"+
    "the rotted volumes.\n";
  items =
    ({
      "volume", "The crumbled, dry remains of a large book.",
      "volumes", "The crumbled, dry remains of hundreds of books.",
      "book", "The crumbled, dry remains of a large volume.",
      "books", "The crumbled, dry remains of hundreds of volumes.",
      "bookshelves",
        "Unfortunately, all the books have long since rotted into uselessness.",
      "bookshelf",
        "Unfortunately, all the books have long since rotted into uselessness.",
      "shelves",
        "Unfortunately, all the books have long since rotted into uselessness.",
      "shelf",
        "Unfortunately, all the books have long since rotted into uselessness.",
      "paper", "Most of the writing on the paper has faded away.\n"+
               "What little is left says:\n"+
               "   .......................................................\n"+
               "   :                                                     :\n"+
               "   :      up and down.         twice for the master      :\n"+
               "   :                                                     :\n"+
               "   :         thrice for the mistress                     :\n"+
               "   :                                                     :\n"+
               "   :                                                     :\n"+
               "   :                                                     :\n"+
               "   :                                                     :\n"+
               "   :                                                     :\n"+
               "   :    for help with the master and his mistress, search:\n"+
               "   :                                                     :\n"+
               "   :    the violet  mist                                 :\n"+
               "   :                                                     :\n"+
               "   .......................................................",
    });
  dest_dir =
    ({
      "players/nooneelse/red/study", "west",
    });
}
