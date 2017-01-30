
#include "std.h"

#undef EXTRA_INIT
#define EXTRA_INIT \
     add_action("search", "search");

#undef EXTRA_LONG
#define EXTRA_LONG \
     if(str=="books" || str=="table") { \
         search(); \
         return; }

id(str) { return str=="books" || str=="table"; }

search() {
     int find;
     string book;
     book=allocate(10);
     book[0]="a book entitled, 'Harmony of the Rock.'";
     book[1]="a green book called, 'The Wedford Dryads.'";
     book[2]="a small book titled, 'Mordenkainen's\n"+
             "Guide to Conjuration and Evocation.'";
     book[3]="a book entitled, 'Elminster Speaks.'";
     book[4]="a set of volumes entitled, 'Toben's\n"+
             "Spirit Guide.'";
     book[5]="a heavy tome called, 'Metamathematics.'";
     book[6]="a book entitled, 'Necromancy in 13\n"+
             "Easy Lessons.'";
     book[7]="'As Hot as Hell: A Discussion of the\n"+
             "Politics of the Nine Hells.'";
     book[8]="'The Hobbit,' by J.R.R. Tolkien.";
     book[9]="a piece of paper serving as a\n"+
             "book mark. You take it.";
     find=random(10);
     write("You find " + book[find] + "\n");
     if(find==9) get_paper();
     return 1;
}

get_paper() {
     string code;
     object paper, castle;
     castle=find_object("players/bastion/castle");
     code=castle->query_code();
     paper=clone_object("obj/treasure");
     paper->set_id("paper");
     paper->set_alias("slip");
     paper->set_short("a slip of paper");
     paper->set_long("There is something written on it.\n");
     paper->set_read(code + "\n");
     paper->set_value(5);
     move_object(paper, this_player());
     return 1;
}

ONE_EXIT("players/bastion/isle/wiz/base_hall2", "north",
     "Library",
     "The room is filled with bookcases of musty tomes. A large table sits\n"+
     "to one side of the room, several books and notes spread across it.\n"+
     "The smell of old leather fills the air; the light here is better than\n"+
     "in the hallway. A door leads north.\n",
     1)
