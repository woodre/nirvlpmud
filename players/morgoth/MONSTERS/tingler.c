
inherit"obj/monster";

reset(arg) {
::reset(arg);
if(arg) return;
set_name("tingler");
set_alias("tingler");
set_short("A tingler");
set_long(
"A creature inhabiting the astaroid.  The Tingler is 4 foot, 6 inches tall  and\n"
+"resembles a scorpion with a praying mantis head.  It feeds on\n"
+"the spinal fluid of wayward adventurers like you....\n");
set_level(10);
set_wc(14);
set_ac(8);
set_al(-200);
set_chance(20);
set_spell_dam(12);
set_spell_mess2("Tingler sucks the fluid from your spine !\n");
}
