
/*
 * GIANT CENTIPEDE -- AC 1; WC 12; LVL 1; HP 50;
 */

inherit "obj/monster";

reset(arg) {
   if(arg) return;
   set_name("centipede");
   set_alt_name("wand_monst");
   set_short("A giant centipede");
   set_long("A centipede measuring over six feet in length.\n");
   set_level(1);
   set_ac(1);
   set_wc(12);
   set_hp(50);
   set_aggressive(1);
   ::reset();
}

