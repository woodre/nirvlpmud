inherit "obj/monster";
object ob, gold;
reset(arg)
{
::reset(arg);
if(arg) return;
set_name("elf");
set_short("Elf");
set_long("An inhabitant of the tree.\n");
set_level(7);
set_hp(105);
set_wc(11);
set_ac(6);
ob=clone_object("players/nightshade/armor/elf_cloak");
move_object(ob, this_object());
gold=clone_object("obj/money");
gold->set_money(250);
move_object(gold, this_object());
}
