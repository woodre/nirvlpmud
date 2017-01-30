inherit "obj/monster";
object weap,ob,fart;
reset(arg)
{
::reset(arg);
if(arg) return;
set_name("mage");
set_short("Knowledgeable Mage");
set_alias("mage");
set_alias("count");
set_long(
"Since magic being the most supreme force amongst men, these apprentices to the arts are more formidable than their guild counterparts.\n");
set_level(15);
set_hp(250);
set_wc(20);
set_ac(12);
/* Mage has better chance (was 30) and better dam (was 5)  -Snow */
set_chance(45);
set_spell_dam(15);
set_spell_mess1("The mage raises his finger, chants, and releases a volley of magic missiles!");
set_spell_mess2("You see the mage raise his finger, mumble something, the suddenly watch as a volley of magic missiles head your way!");
ob=clone_object("players/nightshade/misc/spell_book");
move_object(ob, this_object());
}
/* wc was 15 ac was 10- mythos <6-17-96> */
