
/*
 * ANHKHEG - AC 6; WC 14; LVL 3; HP 60;
 */

inherit "obj/monster";

reset(arg) {
   if(arg) return;
   set_name("anhkheg");
   set_alias("bug");
   set_alt_name("wand_monst");
   set_short("An Anhkheg");
   set_long("The Anhkheg resembles a large bug.  It is covered with\n"+
            "a chitinous exoskeleton and has powerful mandibles which\n"+
            "it uses to crush its prey.\n");
   set_level(3);
   set_ac(6);
   set_wc(14);
   set_hp(60);
   set_aggressive(1);
   ::reset();
}

