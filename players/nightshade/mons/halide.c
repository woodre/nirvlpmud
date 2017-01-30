inherit "obj/monster";
object ob, gold;
reset(arg)
{
::reset(arg);
if(arg) return;
set_name("halide");
set_short("Halide");
set_long("Yet another functional group containing a c-x bond where\n"+
"x is equal to either F, Cl, Br, or I.\n");
set_level(16);
set_hp(400);
set_wc(22);
set_ac(13);
gold=clone_object("obj/money");
gold->set_money(890);
move_object(gold, this_object());
}
