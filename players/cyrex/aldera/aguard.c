
inherit"obj/monster";
reset(arg) {
object money;
object armour;
::reset(arg);
if(arg) return;
set_name("aldera guard");
set_alias("guard");
set_short("Aldera Guard");
set_long(
"A guard that protects the village of Aldera. He wishes that someday he will\n"
+ "be promoted to a Royal Guard to guard the Aldera Castle.\n");
set_level(15);
set_race("human");
set_hp(500);
set_al(-500);
set_wc(20);
set_ac(15);
set_spell_mess2("");
money = clone_object("obj/money");
money->set_money(100);
move_object(money, this_object());
armour = clone_object("/players/cyrex/aldera/ashield");
if(armour) {
move_object(armour,this_object());
  }
}
