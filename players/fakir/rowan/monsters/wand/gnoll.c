
/*
 * GNOLL -- AC 4; WC 14; LVL 9; HP 90; 
 */

inherit "obj/monster";

reset(arg) {
   if(arg) return;
   set_name("gnoll");
   set_alt_name("wand_monst");
   set_short("A gnoll");
   set_long("The gnoll resembles a humanoid version of a hyena.\n"+
            "Its gray skin is covered in spots by rust colored fur.\n");
   set_level(9);
   set_ac(4);
   set_wc(14);
   set_hp(90);
   set_al(-100);
   set_aggressive(1);
   call_other("/players/molasar/rowan/obj/tr_gen","get_money", 150);
   ::reset();
}

