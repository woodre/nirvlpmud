


#include  "std.h"

reset(arg) {
     if(!arg)
       set_light(1);
}

object mage;

/*  move Galileo to ~/CASTLE/wellrm2  Eurale 4/7/97
extra_reset() {
     if(!present("mage")) {
       mage = clone_object("players/molasar/MONSTERS/mage");
       move_object(mage, this_object());
     }
}
*/

short() { return "Top of the tower"; }

long() {
     write("This is the top of the northwestern tower.\n");
     write("It provides a spectacular view of the entire countryside.\n");
     write("To the north lies a great river seperating the desert to the\n");
     write("west and forest to the east.  Southwest of you lies a large\n");
     write("body of water while a row of mountain lies east of that.\n");
     write("   There is one obvious exit:  down\n");
}

init() {
     add_action("down","down");
     add_action("no_kill","kill");
     add_action("no_kill","missile");
     add_action("no_kill","mi");
     add_action("no_kill","shock");
     add_action("no_kill","sh");
     add_action("no_kill","fireball");
     add_action("no_kill","fi");
}

down() {
     call_other(this_player(),"move_player",
         "down#players/molasar/CASTLE/Etower3_3");
     return 1;
}

no_kill(str) {
     if(str == "mage" || str == "galileo") {
     if(present("mage")) {
       write("Galileo chuckles and waves.\n");
       write("Galileo disappears in a puff of smoke.\n");
       destruct(mage);
       return 1;
     }
     }
}

