 *    Notes:                                                          *
 *                                                                    *
 *                                                                    *
 *    Change History:                                                 *
 */
#include "/players/fred/ansi.h";
inherit "/obj/monster";
{
  ::reset(arg);
  if(arg) return;
  set_name("Doink");
   set_race("Klown");
  set_alias("doink");
  set_short("Doink");
  set_long("Doink has bright green hair protrudeing from both sides\n"+
        "of his narrow skull. A large red rubber nose is upon his \n"+
        "face, above a wicked set of dagger sized teeth.\n");
  set_level(26);
  set_hp(1700+random(95));
  set_al(0);
  set_wc(47);
  set_ac(20);
  move_object(clone_object("/players/sami/area/carnival/obj/weapons/sword_of_might.c"),this_object());
init_command("wield sword");
  move_object(clone_object("/players/sami/area/carnival/obj/armors/TEST.c"),this_object())
init_command("wear armor");
}
