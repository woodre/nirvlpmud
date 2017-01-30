inherit "obj/monster";

reset(x) {
    if(x) return;
   set_name("elven soldier");
   set_alias("soldier");
   set_race("elf");
   set_short("An elven soldier");
   set_long("An average elven soldier");
   set_level(4);
   set_hp(120);
   set_wc(12);
   set_al(94);
   ::reset(0);
}

