inherit "obj/monster";
object ob, gold;
reset(arg)
{
::reset(arg);
if(arg) return;
set_name("amine");
set_short("Amine");
set_long("The group with a C-N bond.\n");
set_level(16);
set_hp(400);
set_wc(22);
set_ac(13);
set_heal(10);
gold=clone_object("obj/money");
gold->set_money(890);
move_object(gold, this_object());
}

/* gold was 2000 - mythos <6-17-96> */
