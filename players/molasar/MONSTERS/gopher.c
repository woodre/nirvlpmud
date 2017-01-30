
inherit "obj/monster";

reset(x) {
    if(x) return;
   set_name("gopher");
   set_short("A gopher");
   set_long("A small little gopher.\n");
   set_ac(0);
   set_wc(3);
   set_al(0);
   set_level(2);
   set_hp(50);
   ::reset(0);
}

