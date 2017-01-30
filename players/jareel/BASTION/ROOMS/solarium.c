
#include "std.h"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
     object david, violin;
     if(!present("violinist")) {
          david=clone_object("obj/monster");
          david->set_name("david");
          david->set_alias("violinist");
          david->set_short("A young violinist");
          david->set_long("A handsome and elfin looking lad, he says his "+
                          "name is David.\n");
          david->set_level(10);
          david->set_hp(150);
          david->set_wc(14);
          david->set_ac(8);
          david->set_chat_chance(10);
          david->load_chat("David paces around nervously.\n");
          david->load_chat("David runs through a Mendelssohn concerto.\n");
          david->set_a_chat_chance(5);
          david->load_a_chat("David says: Hey! What'd I do you you?\n");
          violin=clone_object("obj/treasure");
          violin->set_id("violin");
          violin->set_alias("stradivarius");
          violin->set_short("A fine looking violin");
          violin->set_long("Through one of the sound holes you see inscribed\n"+
                           "'Stradivarius.'\n");
          violin->set_value(500);
          violin->set_weight(1);
          move_object(david, this_object());
          transfer(violin, david); 
          return 1; }
}
#undef EXTRA_LONG
#define EXTRA_LONG \
     if(str=="piano") { \
          write("It is a small grand piano, approximately six feet in\n"+ \
                "length. It's finish is a lustrous ebony; a small label\n"+ \
                "near the keyboard reads 'Yamaha.'\n"); \
          return; } \
     if(str=="stands") { \
          write("They are empty for the moment.\n"); \
          return; } \
     if(str=="window" || str=="windows" || str=="sea") { \
          write("The icy sea laps at the rock-strewn shore below.\n"); \
          return; } 


TWO_EXIT("players/bastion/isle/wiz/up_hall2", "west",
     "players/bastion/isle/wiz/observatory", "up",
     "Solarium",
     "You enter a spacious, circular room--apparently within the tower you\n"+
     "saw from outside. It's many windows provide an excellent view of the\n"+
     "surrounding sea. The room is brightly lit, the walls whitewashed,\n"+
     "with simple cornices. Low chairs and a sofa, all overstuffed, occupy\n"+
     "the southern portion of the room, while a piano stands to the west.\n"+
     "Various musical stands suggest this space may be used for small\n"+
     "performances. A small spiral stairway leads up near the door.\n",
     1)

id(str) {
     return(str=="piano"||str=="stands"||str=="window"||str=="windows"||
          str=="sea");
}
