inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
 set_name("Myla");
 set_alias("myla");
 set_short("Myla Hougton");
 set_long(
 "Myla is the pretty little owner of this shop.  A small roundish\n"+
 "woman with big beautiful eyes, Myla enjoys her life as a shop\n"+
 "keeper very much.\n");
 set_level(30);
 set_ac(80);
 set_wc(80);
 set_hp(10000);
 set_al(10000);
 set_aggressive(0);
   }
}

