
/*
 * GIANT RAT -- AC 2; WC 10; LVL 1; HP 30;
 */

inherit "obj/monster";

reset(arg) {
   if(arg) return;
   set_name("rat");
   set_alt_name("wand_monst");
   set_short("A giant rat");
   set_long("A large carnivorous rat.  It looks angry.\n");
   set_level(1);
   set_ac(2);
   set_wc(10);
   set_hp(30);
   set_aggressive(1);
   ::reset();
}

