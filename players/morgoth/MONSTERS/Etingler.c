
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

move_object(clone_object("players/morgoth/ARMOR/klez_armor.c"),
  this_object());
set_hp(450 + random(100));
set_level(20);
set_wc(30);
set_ac(18);
set_al(-200);
set_chance(20);
set_spell_dam(12);
set_spell_mess2("Tingler sucks the fluid from your spine !\n");
}
