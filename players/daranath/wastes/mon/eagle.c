#include <ansi.h>
#define ROOT "/players/daranath/wastes/"

inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

object ob;
 ob = clone_object(ROOT+"wep/talon.c");
  move_object(ob, this_object());

set_name("Giant eagle");
set_alias("eagle");
set_alt_name("platmon");
set_race("bird");
set_gender("creature");

set_short("A "+YEL+"giant eagle"+NORM);
set_long("The eagles that live in the area of the Gundar plateau typically grow\n"+
         "larger then normal because they feed on the centipedes that plague\n"+
         "the area.\n");

set_level(14);
set_ac(11);
set_wc(16 + random(5));
set_hp(190 + random(50));
set_al(500);
set_aggressive(0);

init_command("wield talon");

set_a_chat_chance(10);
load_a_chat("The giant Eagle soars into the sky, then attacks you in a dive.\n");
load_a_chat("Giant eagle slashes at you with its talons.\n");
load_a_chat("Giant eagle flies up and pecks at you with its beak.\n");

   }
}
