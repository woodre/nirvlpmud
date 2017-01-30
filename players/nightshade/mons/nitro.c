inherit "obj/monster";
object ob, gold;
reset(arg)
{
::reset(arg);
if(arg) return;
set_name("nitro");
set_short("Nitro");
set_long("A functional group with a C-N bond which has two O bonded to the N, one a single bond, the other a double.\n");
set_level(16);
set_hp(400);
set_wc(22);
set_ac(13);
gold=clone_object("obj/money");
gold->set_money(890);
move_object(gold, this_object());
}
/* money was 2000 - mythos <6-17-96> */
