
/*
 * BUGBEAR -- AC 4; WC 14; LVL 8; HP 80;
 */

inherit "obj/monster";

reset(arg) {
   if(arg) return;
   set_name("bugbear");
   set_alt_name("wand_monst");
   set_short("A bugbear");
   set_long("A large grizzly monster covered in a dull yellow fur.\n"+
            "The stench from it almost overwhelms you.\n");
   set_level(8);
   set_ac(4);
   set_wc(14);
   set_hp(80);
   set_aggressive(1);
   set_al(-100);
   call_other("/players/molasar/rowan/obj/tr_gen","get_money",80);
   ::reset();
}

