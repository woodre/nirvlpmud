
#include "std.h"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
     object ob;
     if(!present("dwarf sailor")) {
          ob=clone_object("players/bastion/obj/static");
          ob->set_name("dwarf sailor");
          ob->set_alias("dwarf");
          ob->set_short("a dwarf sailor");
          ob->set_long("The dwarf tugs at its beard as it apparently "+
            "converses\nwith its shoes. He notices your stare and looks hard\n"+
            "and long into your eyes. You find him more than a little\n"+
            "intimidating.\n"+
            "Dwarf sailor is in good shape.\n");
          ob->set_object(this_object());
          ob->load_chat("Dwarf exclaims: Acch! Da wizard is na sane!\n");
          ob->load_chat("Dwarf mutters: If onli ah could get ah "+
             "customer...\n");
          ob->load_chat("Dwarf asks: What mat ye want?\n");
          ob->load_chat("Dwarf laments: Whe is a good meal whan ya need on?\n");
          move_object(ob, this_object());
          ob->start_check(); }
}

#undef EXTRA_LONG
#define EXTRA_LONG \
     if(str=="booth" || str=="sign") { \
          write("The sign reads:\n"+ \
                "\nDOCK CLOSED 'TIL FURTHER NOTICE\n"+ \
                "\n--Damian the Sorcerer\n"); \
          return; }

TWO_EXIT("players/bastion/isle/wiz/shack", "east",
     "players/bastion/isle/wiz/nearcave", "southwest",
     "Quay",
     "You come upon a small quay on the northern shore, a jeddy curving\n"+
     "out from the beach to form a safe harbor. You see a two small\n"+
     "sailing craft moored to the dock, a small shack or booth by the\n"+
     "entrance to the dock. A dwarf stands here, muttering to himself\n"+
     "in harsh tones. A sign is posted on the side of the booth.\n",
     1)

id(str) {
     return str=="sign" || str=="booth"; 
}
