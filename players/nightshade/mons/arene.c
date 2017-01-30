inherit "obj/monster";
object ob, gold;
reset(arg)
{
::reset(arg);
if(arg) return;
set_name("arene");
set_short("Arene");
set_long("A functional group with 6 carbons in a ring but with no less\n\
3 C=C bonds.\n");
set_level(16);
set_hp(400);
set_wc(22);
set_ac(13);
gold=clone_object("obj/money");
gold->set_money(890);
move_object(gold, this_object());
}

/* gold was 2000 - mythos <6-17-96> */
