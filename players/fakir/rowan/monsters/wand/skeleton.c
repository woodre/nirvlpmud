
inherit "obj/monster";

reset(arg) {
   if(arg) return;
   set_name("skeleton");
   set_alias("undead");
   set_alt_name("wand_monst");
   set_short("A skeleton");
   set_long("A magically animated skeleton.\n");
   set_level(2);
   set_race("undead");
   set_hp(50);
   set_ac(3);
   set_wc(12);
   set_aggressive(1);
   ::reset();
}

