
inherit "obj/monster";

reset(x) { if(x) return;
   set_name("lord");
   set_alias("rohan");
   set_short("The Lord of Rohan");
   set_long("A visiting Lord who seeks council with the King.\n");
   set_hp(400);
   set_ac(14);
   set_wc(23);
   set_level(16);
   set_al(248);
   ::reset(0);
}

