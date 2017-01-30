/*    Notes:                                                          *
 *                                                                    *
 *                                                                    *
 *    Change History:                                                 *
 */
inherit "/obj/monster";
#include <ansi.h>
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("carny");
  set_alt_name("20k");
  set_race("monster");
  set_alias("20k");
  set_short("Dunk Tank Carny");
  set_long("A very boring carny who runs the Dunk Tank game.\n");
  set_level(20);
  set_hp(1600);
  set_al(0);
  set_wc(30);
  set_ac(22);
}