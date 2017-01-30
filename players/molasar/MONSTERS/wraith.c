
inherit "obj/monster";

reset(x) { if(x) return;
   set_name("wraith");
   set_short("A wraith");
   set_level(17);
   set_hp(425);
   set_ac(8);
   set_wc(25);
   set_al(-253);
   set_aggressive(1);
   ::reset(0);
}


