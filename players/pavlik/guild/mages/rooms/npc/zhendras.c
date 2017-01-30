inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
 set_name("Zhendras");
 set_alias("zhendras");
 set_short("Zhendras the Weapons Master");
 set_long(
 "Zhendras is the Weapons Master of the Mage's Guild.  Zhendras is a\n"+
 "tall muscular man with short black hair.  He carries an ancient\n"+
 "oaken staff and wears three daggers comfortably at his waist.  It\n"+
 "would not be a good idea to upset this man.\n");
 set_level(30);
 set_ac(10);
 set_wc(30);
 set_hp(10000);
 set_al(10000);
 set_aggressive(0);
   }
}

