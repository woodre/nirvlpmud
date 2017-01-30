inherit "obj/monster.talk";
object money, item;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("luigi");
set_short("Luigi");
set_long("This is the brother of Mario and is also a refugee of an antique\n"
+"arcade game.\n");
set_al(300);
set_level(14);
set_wc(12);
set_hp(200);
set_ac(7);
set_aggressive(0);

item = clone_object("players/grimm/weapons/silplunger");
move_object(item,this_object());
money = clone_object("obj/money");
money->set_money(100+(random(200)));
move_object(money,this_object());
}
