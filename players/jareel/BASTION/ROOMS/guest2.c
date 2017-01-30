
#include "std.h"

#undef EXTRA_INIT
#define EXTRA_INIT extra_init();

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

int door_found;

extra_init() {
     add_action("search", "search");
     add_action("north", "north");
}

extra_reset() {
     object chest, scribe, wand;
     door_found=0;
     if(!present("scribe")) {
          scribe=clone_object("obj/monster");
          scribe->set_name("redstan");
          scribe->set_alias("scribe");
          scribe->set_short("Redstan the scribe");
          scribe->set_long(
               "A lean man stands before you, his robes rich and impeccably\n"+
               "tailored. He places a beringed finger to the side of his\n"+
               "chin, considering some ineffable detail of the far wall.\n");
          scribe->set_level(25);
          scribe->set_hp(1000);
          scribe->set_ac(22);
          scribe->set_wc(40);
          scribe->add_money(5000);
          scribe->set_chat_chance(20);
          scribe->load_chat("Redstan begins rustling through a stack of "+
               "papers\non the nightstand.\n");
          scribe->load_chat("Redstan says: Hmmph...I must have left my "+
               "journal\nin the vault.\n");
          scribe->set_a_chat_chance(5);
          scribe->load_a_chat("Redstan says: You are a fool!\n");
          scribe->set_chance(95);
          scribe->set_spell_dam(15 + random(35));
          scribe->set_spell_mess2("You are hit by a fireball.");
          scribe->set_spell_mess1("Redstan casts a fireball.");
          wand=clone_object("players/bastion/obj/destwand");
          move_object(scribe, this_object());
          transfer(wand, scribe); }
}

ONE_EXIT("players/bastion/isle/wiz/up_hall1", "east",
     "Guest Bedroom",
     "A large bed with comfortable linens stands against the west wall of\n"+
     "this room. An oaken chest lies at the foot of it. The walls are\n"+
     "mahoganey wainscotting and white plaster, with gold sconces fixed in\n"+
     "several places. A door leads east.\n",
     1)

north() {
     if(door_found) {
          write("You enter a secret passageway.\n");
          say(call_other(this_player(), "query_name") +
               " enters a secret passageway.\n");
          this_player()->move_player("north#players/bastion/isle/wiz/secret2");
          return 1; }
}

search(str) {
     int chance;
     chance=call_other(this_player(), "query_attrib", "int") + call_other(this_player(), "query_level");
     if(random(100) < chance) {
          write("You find a secret door in the northern wall.\n");
          say(call_other(this_player(), "query_name") +
               " finds a secret door.\n");
          door_found=1;
          return 1; }
     else {
          write("You find nothing of interest.\n");
          return 1; }
}

realm() {
     if(present("redstan")) 
          return "NT";
}
