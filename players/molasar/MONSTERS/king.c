
inherit "obj/monster";

reset(x) {
   if(x) return;
   set_name("king");
   set_short("The King");
   set_long("A very impressive man.\n");
   set_level(19);
   set_hp(600);
   set_ac(16);
   set_wc(32);
   set_al(392);
   ::reset(0);
}

