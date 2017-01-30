inherit "obj/monster";
object ob, gold;
reset(arg)
{
::reset(arg);
if(arg) return;
set_name("sulfoxide");
set_short("Sulfoxide");
set_long("Another C-S-C bond but with an O bonded to the S.\n");
set_level(16);
set_hp(400);
set_wc(22);
set_ac(13);
gold=clone_object("obj/money");
gold->set_money(890);
move_object(gold, this_object());
}
/* money was 2000 - mythos <6-17-96> */
