
inherit"obj/monster";
reset(arg) {
object money;
object armor;
object weapon;
::reset(arg);
if(arg) return;
set_name("wicker man");
set_alias("man");
set_short("Wicker Man");
set_long(
"The wicker man is an extremly large huminoid structure made of\n"
+ "not to surprising, wicker.  Within are stuffed human sacrifices\n"
+ "chosen from criminals.  It is then set on fire.  Sometimes the\n"
+ "wicker men come to life, like this one, running amok and causing havok.\n");
set_level(25);
set_agressive(1);
set_race("man");
set_hp(1500);
set_wc(30);
set_ac(15);
}
