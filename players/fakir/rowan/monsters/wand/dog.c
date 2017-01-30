
/*
 * WILD DOG -- AC 1; WC 10; LVL 1; HP 30;
 */

inherit "obj/monster";

reset(arg) {
   if(arg) return;
   set_name("dog");
   set_alt_name("wand_monst");
   set_short("A wild dog");
   set_long("A mangy flea-bitten dog.\n");
   set_level(1);
   set_ac(1);
   set_wc(10);
   set_hp(30);
   set_aggressive(1);
   ::reset();
}

