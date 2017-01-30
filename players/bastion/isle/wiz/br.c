#include "std.h"

object wardrobe, desk;
int door_found;

#undef EXTRA_INIT
#define EXTRA_INIT \
     add_action("search", "search"); \
     add_action("west", "west");

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
     door_found=0;
     if(!wardrobe) {
          wardrobe=clone_object("players/bastion/obj/static");
          wardrobe->set_name("wardrobe");
          wardrobe->set_alias("wardrobe");
          wardrobe->set_short("wardrobe");
          wardrobe->set_long(
               "The workmanship must be very costly.\n");
          wardrobe->set_object(this_object());
          wardrobe->set_summon("summon_sorcerer");
          wardrobe->set_beat(4);
          move_object(wardrobe, this_object());
          wardrobe->start_check(); }
     wardrobe->load_summon();
}

summon_sorcerer(arg) {
     object damian;
     if(present("damian the sorcerer")) {
          wardrobe->unload_summon();
          return 1; }
     damian=clone_object("players/bastion/monster/sorcerer");
     damian->set_heart_beat(1);
     tell_room(this_object(), "Damian arrives in a puff of smoke.\n");
     move_object(damian, this_object());
     call_out("dest_damian", 15);
     wardrobe->unload_summon();
}

dest_damian() {
     object ob;
     ob=present("damian");
     ob->self_destruct();
     return 1;
}

west() {
     if(call_other(this_player(), "query_level")<21) {
          write("A strong magic force stops you.\n");
          say(call_other(this_player(),"query_name") +
             " tries to go through the field and fails.\n");
          return 1;}
     write("You wriggle through the force field...\n");
     this_player()->move_player("north#players/bastion/closed/workroom");
     return 1;
}

TWO_EXIT("players/bastion/isle/wiz/masterbath", "southeast",
     "players/bastion/isle/wiz/up_hall2", "south",
     "Master Bedroom",
     "You have entered a richly appointed bedroom. A canopy bed, hung\n"+
     "with red silk and vermeil, occupies the northern portion of the\n"+
     "room. A rosewood wardrobe stands on your left, while to the east\m"+
     "you see a small, roll-top, writing desk. A small door leads\n"+
     "southeast, while the door to the hallway opens south.\n",
     1)
