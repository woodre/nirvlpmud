
/*
 * GARGOYLE -- AC 6; WC 16; LVL 10; HP 100;
 */

inherit "obj/monster";

reset(arg) {
   if(arg) return;
   set_name("gargoyle");
   set_alt_name("wand_monst");
   set_short("A gargoyle");
   set_long("An evil beast of magical origin.  They love to kill.\n");
   set_level(10);
   set_ac(6);
   set_wc(16);
   set_hp(100);
   set_al(-100);
   set_aggressive(1);
   ::reset();
}

