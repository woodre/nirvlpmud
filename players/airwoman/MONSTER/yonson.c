inherit "obj/monster";

reset(arg){
object gold;
::reset(arg);
if (!arg) {
set_name("yonson");
set_level(10);
set_whimpy(150);
set_al(200);
set_ac(8);
set_wc(14);
set_short("Yon Yonson");
set_long("This is Yon the WWII Veteran.  He's been working\n"+
	"for years over his book on his experience in Dresden\n");
gold = clone_object ("obj/money");
call_other (gold, "set_money", 400+random(70));
move_object(gold, this_object());
}
}
