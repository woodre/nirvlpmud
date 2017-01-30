
inherit "obj/monster";

reset(x) { if(x) return;
   set_name("nomad");
   set_short("A nomad");
   set_long("A rugged looking nomad.\n");
   set_level(5);
   set_hp(150);
   set_ac(2);
   set_wc(8);
   set_al(0);
   ::reset(0);
}

