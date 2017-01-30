inherit "obj/monster";
object ob, gold;
reset(arg)
{
::reset(arg);
if(arg) return;
set_name("alcohol");
set_short("Alcohol");
set_long("Will these groups never end. This one has a C-O-H bond.\n");
set_level(16);
set_hp(400);
set_wc(22);
set_ac(13);
gold=clone_object("obj/money");
gold->set_money(890);
move_object(gold, this_object());
}

/* gold was 2500 - mythos <6-17-96> */
