inherit "obj/monster";
object coins,dagger;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("vampire");
set_short("Young vampire");
set_long("This is a very young and weak vampire.  He seems to be wearing\n"+
         "very long clothes to protect him when the sun appears.\n");
set_level(6);
set_wc(10);
set_aggressive(0);
coins = clone_object("obj/money");
coins->set_money(100+(random(100)));
move_object(coins,this_object());
dagger = clone_object("players/grimm/weapon/dagger1");
move_object(dagger,this_object());
}
