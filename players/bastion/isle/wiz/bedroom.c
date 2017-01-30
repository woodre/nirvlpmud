
#include "std.h"

#undef EXTRA_INIT
#define EXTRA_INIT extra_init();

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);

int door_found;
object ward, desk;

extra_init() {
     add_action("search", "search");
     add_action("west", "west");
}

extra_reset(arg) {
     object note, key;
     door_found=0;
     if(!ward) {
          ward=clone_object("players/bastion/obj/static");
          ward->set_name("wardrobe");
          ward->set_short("wardrobe");
          ward->set_long("The workmanship must be very costly.\n");
          ward->set_object(this_object());
          ward->set_summon("summon_damian");
          ward->set_beat(4);
          move_object(ward, this_object());
          ward->start_check(); }
     if(!desk) {
          desk=clone_object("players/bastion/obj/cont");
          desk->set_name("writing desk");
          desk->set_alias("desk");
          desk->set_short("writing desk");
          desk->set_max_weight(30);
          desk->set_can_open(1);
          move_object(desk, this_object()); } 
     get_stuff();
     ward->load_summon();
}

summon_damian(arg) {
     object damian;
     if(present("damian the sorcerer")) {
          ward->unload_summon();
          return 1; }
     if(!find_living("damian the sorcerer")) {
     damian=clone_object("players/bastion/monster/damian");
     damian->set_heart_beat(1);
     tell_room(this_object(), "Damian arrives in a puff of smoke.\n");
     move_object(damian, this_object());
     call_out("dest_damian", 20);
     ward->unload_summon(); }
}

west() {
     if(door_found) {
          write("You enter a secret passageway.\n");
          say(call_other(this_player(), "query_name") +
               " enters a secret passageway.\n");
          this_player()->move_player("west#players/bastion/isle/wiz/secret1");
          return 1; }
}

search(str) {
     int chance;
     chance=call_other(this_player(), "query_attrib", "int") + call_other(this_player(), "query_level");
     if(random(100) < chance) {
          write("You find a secret door in the western wall.\n");
          say(call_other(this_player(), "query_name") +
               " finds a secret door.\n");
          door_found=1;
          return 1; }
     else {
          write("You find nothing of interest.\n");
          return 1; }
}

dest_damian() {
  if(present("damian"))

     present("damian")->self_destruct();
}

get_stuff() {
     object note, key;
     if(!present("note", desk)) {
          note=clone_object("obj/treasure");
          note->set_id("note");
          note->set_alias("letter");
          note->set_short("a letter");
          note->set_long("Perhaps you you read it.\n");
          note->set_read("Delgard:\n"+
                         "\nI hope this letter finds you well. Myself\n"+
                         "things go as usual in suppressing the last of\n"+
                         "them at Belgaers: slowly.\n"+
                         "\nMy purpose in writing to you is to ask for\n"+
                         "your invaluable services--yes, I've misplaced\n"+
                         "it again. The council will have my hide should\n"+
                         "they suspect I am less than vigilant. (Let us\n"+
                         "forestall that impression!)\n"+
                         "\nYour friend,"+
                         "\nDamian the Sorcerer\n");
          note->set_weight(1);
          note->set_value(10);
          transfer(note, desk); }
     if(!present("key", desk)) {
          key=clone_object("obj/treasure");
          key->set_name("small key");
          key->set_alias("key");
          key->set_short("A small key");
          key->set_long("This is a small key. Wonder where it fits?\n");
          key->set_value(10);
          key->set_weight(1);
          transfer(key, desk); }
     return 1;
}

TWO_EXIT("players/bastion/isle/wiz/masterbath", "southeast",
     "players/bastion/isle/wiz/up_hall2", "south",
     "Master Bedroom",
     "You have entered a richly appointed bedroom. A canopy bed, hung\n"+
     "with red silk and vermeil, occupies the northern portion of the\n"+
     "room. A rosewood wardrobe stands on your left, while to the east\n"+
     "you see a small, roll-top, writing desk. A small door leads\n"+
     "southeast, while the door to the hallway opens south.\n",
     1)
