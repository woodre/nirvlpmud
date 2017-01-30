
/*
 * GIANT SPIDER -- AC 2; WC 12; LVL 2; HP 40; 
 */

inherit "obj/monster";

reset(arg) {
   if(arg) return;
   set_name("spider");
   set_alt_name("wand_monst");
   set_short("A giant spider");
   set_level(2);
   set_ac(2);
   set_wc(12);
   set_hp(40);
   set_aggressive(1);
   ::reset();
}

