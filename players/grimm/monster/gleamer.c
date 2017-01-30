inherit "obj/monster.talk";
object coins, item;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("gleamer");
set_short("A Gleamer");
set_long("This is an odd creature that has no real characteristics;\n"+
"it is like a thin, silvery blob that is floating in front of you.\n");
set_al(-150);
set_level(12);
set_wc(15);
set_hp(200);
set_ac(6);
set_aggressive(0);

item = clone_object("players/grimm/object/disint");
move_object(item,this_object());
coins = clone_object("obj/money");
coins->set_money(100+(random(200)));
move_object(coins,this_object());
}
