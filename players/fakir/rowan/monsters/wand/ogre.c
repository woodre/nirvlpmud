
/*
 * OGRE -- AC 3; WC 17; LVL 7; HP 80;
 */

inherit "obj/monster";

reset(arg) {
   if(arg) return;
   set_name("ogre");
   set_alt_name("wand_monst");
   set_short("An Ogre");
   set_long("A large mongoloid beast well over eight feet tall.\n");
   set_level(7);
   set_ac(3);
   set_wc(17);
   set_hp(80);
   set_aggressive(1);
   call_other("/players/molasar/rowan/obj/tr_gen", "get_money", 200);
   ::reset();
}

