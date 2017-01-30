/*    Notes:                                                          *
 *                                                                    *
 *                                                                    *
 *    Change History:                                                 *
 */
inherit "/obj/monster";
inherit "/players/darkfire/obj/color";

#include <ansi.h>
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("chandresh");
  set_alt_name("20k");
  set_race("monster");
  set_alias("ringmaster");
  set_short("Chandresh");
  set_long("The ringmaster is an elderly gentleman with a wicked gleam in his eyes. He grins at you through a salt-and-pepper beard trimmed into a long goatee with a flame red tip. He wears a black top hat and wields a riding crop that is flecked with blood.\n");
  set_level(20);
  set_hp(1600);
  set_al(0);
  set_wc(30);
  set_ac(22);
}