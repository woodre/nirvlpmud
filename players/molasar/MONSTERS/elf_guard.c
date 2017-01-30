
inherit "obj/monster";

reset(x) { if(x) return;
   set_hp(210);
   set_ac(12);
   set_wc(18);
   set_name("elven guard");
   set_alias("guard");
   set_race("elf");
   set_short("An elven guard");
   set_long("A well trained elven guard.\n");
   set_level(14);
   set_al(145);
   ::reset(0);
}

