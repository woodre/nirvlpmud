
/*
 * HOBGOBLIN -- AC 3; WC 12; LVL 6; HP 60;
 */

inherit "obj/monster";

reset(arg) {
   if(arg) return;
   set_name("hobgoblin");
   set_alt_name("wand_monst");
   set_short("A hobgoblin");
   set_long("A crude off-breed of a goblin.  They have skin resembling\n"+
            "resembling their cousins, plus a light layer of reddish-\n"+
            "black fur\n");
   set_level(6);
   set_ac(3);
   set_wc(12);
   set_hp(60);
   set_al(-100);
   set_aggressive(1);
   call_other("/players/molasar/rowan/obj/tr_gen","get_money", 70);
   ::reset();
}

