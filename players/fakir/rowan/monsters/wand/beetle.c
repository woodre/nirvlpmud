
/*
 * BORING BEETLE  -- AC 3; WC 8; LVL 2; HP 30;
 */

inherit "obj/monster";

reset(arg) {
   if(arg) return;
   set_name("beetle");
   set_alt_name("wand_monst");
   set_short("A boring beetle");
   set_long("A huge beetle measuring over four feet in length.\n"+
            "It is portected by a thick endoskeleton.\n");
   set_level(2);
   set_ac(3);
   set_wc(8);
   set_hp(30);
   set_aggressive(1);
   ::reset();
}

