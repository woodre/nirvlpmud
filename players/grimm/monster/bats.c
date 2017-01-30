inherit "obj/monster";
object coins;

reset(arg) {
::reset(arg);
if(arg) return;
set_name("bat");
set_short("A Bat");
set_long("This is rather large size bat.  It has no other use but to protect\n"
       + "the lair of its master.\n");
set_al(10);
set_level(2);
set_aggressive(1);
coins = clone_object("obj/money");
coins->set_money(random(30));
move_object(coins,this_object());
}
