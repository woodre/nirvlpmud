
inherit "obj/monster";

reset(x) {
    if(x) return;
   set_hp(180);
   set_ac(6);
   set_wc(18);
   set_name("scout");
   set_alias("elven scout");
   set_race("elf");
   set_short("An elven scout");
   set_long("A lightly clad elven scout.\n");
   set_level(12);
   set_al(142);
   ::reset(0);
}

