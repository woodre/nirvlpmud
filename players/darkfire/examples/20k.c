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
  set_name("20k");
  set_alt_name("20k");
  set_race("monster");
  set_alias("20k");
  set_short("20k monster");
  set_long("20k monster");
  set_level(20);
  set_hp(1600);
  set_al(0);
  set_wc(30);
  set_ac(22);
}