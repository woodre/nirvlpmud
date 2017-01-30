inherit "obj/monster";

reset(arg){
object gold;
set_name("bud");
set_level(10);
set_hp(150);
set_whimpy(150);
set_al(200);
set_ac(8);
set_wc(14);
set_short("Bud");
set_long("HERE'S Bud!  It's what u asked for wasnt it?\n"+
	"or was that Bud light?\n");
gold = clone_object ("obj/money");
call_other(gold, "set_money", 350+random(100));
move_object(gold, this_object());
::reset();
}
