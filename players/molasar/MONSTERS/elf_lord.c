
inherit "obj/monster";

reset(x) {
    if(x) return;
   set_name("elven lord");
   set_alias("lord");
   set_race("elf");
   set_short("An elven lord");
   set_long("One of the elven noblemen.\n");
   set_level(19);
   set_hp(600);
   set_ac(10);
   set_wc(32);
   set_al(253);
   ::reset(0);
}

