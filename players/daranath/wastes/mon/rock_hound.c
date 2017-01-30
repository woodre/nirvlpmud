#include <ansi.h>
#define ROOT "/players/daranath/wastes/"

inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

object ob;
 ob = clone_object("obj/money");
  ob->set_money(random(300) + 300);
/*average coins of 450, less then monster guide */
  move_object(ob, this_object());

set_name("Rock Hound");
set_alias("hound");
set_alt_name("platmon");
set_race("construct");
set_gender("creature");

set_short("A "+YEL+"rock hound"+NORM);
set_long("The rock hound is a construct made entirely of dark grey stone. The\n"+
         "body of the hound was formed to look like a large fighting dog,\n"+
         "complete with collar and sharp, biting teeth. Whoever created these\n"+
         "long ago left them up upon the Gundar Plateau for a long lost reason.\n");

set_level(11);
set_ac(9);
set_wc(13 + random(5));
set_hp(150 + random(50));
set_al(0);
set_aggressive(0);

set_a_chat_chance(10);
load_a_chat("Rock hound snaps at you with its rocky jaws.\n");
load_a_chat("Rock hound rears back and howls at an unknown source.\n");
load_a_chat("Rock hound snarls and attacks again!\n");

   }
}
