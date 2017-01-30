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
  set_name("celia");
  set_alt_name("20k");
  set_race("monster");
  set_alias("illusionist");
  set_short("Celia");
  set_long("The illusionist is a tall young woman dressed in a deep green velvet dress. Her long, bell sleeves fade from dark green into a midnight black so dark it seems as if her arms have disappeared. Her white-gloved hands appear to float in the air of their own accord. Her long " + red("red") + " hair cascades down her shoulders in loose curls.\n");
  set_level(20);
  set_hp(1600);
  set_al(0);
  set_wc(30);
  set_ac(22);
}