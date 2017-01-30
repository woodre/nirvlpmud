
/*
 * GIANT SCORPION -- AC 5; WC 12; LVL 3; HP 50;
 */

inherit "obj/monster";

reset(arg) {
   if(arg) return;
   set_name("scorpion");
   set_alt_name("wand_monst");
   set_short("A giant scorpion");
   set_long("A deadly scorpion.  It's poisonous stinger is poised to "+
            "strike.\n");
   set_level(3);
   set_ac(5);
   set_wc(12);
   set_hp(50);
   set_aggressive(1);
   ::reset();
}

