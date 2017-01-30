#include "/open/ansi.h"
#include "std.h"
int done;

#undef EXTRA_INIT
#define EXTRA_INIT \
     add_action("out", "north"); \
     add_action("get", "take"); \
     add_action("get", "get");

#undef EXTRA_LONG
#define EXTRA_LONG \
     if(str=="pentagram" || str=="money" || str=="treasure") { \
         write("Someone has left a great deal of money within the confines\n"+\
               "of the pentagram.\n"); \
         return; }

get(str) {
     object demon, shield, amulet;
     if(!str=="money" || !str=="treasure")
          return 0;
     else if(str=="money" || str=="treasure") {
      if(done) return;
          if(!present("demon")) {
     write("You eagerly reach for the treasure, but you receive a shock\n"+
          "as your hand disrupts some unseen field of energy. The room\n"+
          "grows black as a chuckle resonates through the room.\n");
     say(call_other(this_player(), "query_name") +
          " gets a shock from some field of energy surrounding the\n"+
          "pentagram. The room grows dark as a chuckle fills the air.\n");
     demon=clone_object("players/bastion/monster/demon6");
     move_object(demon, this_object());
     shield=clone_object("obj/armor");
     shield->set_type("shield");
     shield->set_name("shield");
     shield->set_ac(2);
     shield->set_weight(1);
/* make save. -Bp
     shield->set_save_flag(1);
*/
     shield->set_value(4000);
     shield->set_short(BOLD+"An ebony shield"+NORM);
     shield->set_long("It is very sturdy and lightweight\n");
     move_object(shield, demon);
     amulet=clone_object("obj/armor");
     amulet->set_type("amulet");
     amulet->set_name("amulet");
     amulet->set_info("amulet of protection +2");
     amulet->set_short(HIY+"Brightly glowing amulet"+NORM);
     amulet->set_light(1);
     amulet->set_long("You feel safer with the amulet.\n");
     amulet->set_ac(2);
     amulet->set_weight(1);
     amulet->set_save_flag();
     amulet->set_value(2000);
     move_object(amulet, demon);
done = 1;
     return 1; } }
}

ONE_EXIT("players/bastion/isle/wiz/base_hall3", "north",
     "Casting Chamber",
     "You enter a dimly lit room. Surrounded by small candles, an ornate\n"+
     "pentagram is inscribed on the center floor. Within the wards you see\n"+
     "some treasure!\n",
     1)


id(str) {
     return str=="pentagram" || str=="treasure" || str=="money";
}

realm() { return "NT"; }


out() {
     int chance;
/*  Game demons were causing problems here - eurale 7/6/03
     if(!present("bdemon") || this_player()->query_ghost()) return 0;
     chance=this_player()->query_attrib("luc") + this_player()->query_level();
     f(this_player()->query_level() < 100) {
*/
  chance=this_player()->query_attrib("luc") + this_player()->query_level();
  if(present("bdemon") && this_player()->query_level() < 100) {
          if(random(80) < chance) return 0;
          write("The demon prevents you from leaving!\n");
          return 1; } 
}
