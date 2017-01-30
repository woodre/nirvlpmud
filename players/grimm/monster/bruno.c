inherit "obj/monster.talk";
object coins;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("bruno");
set_short("Bruno the bouncer");
set_long("This is the saloon's bouncer.  He IS real mean and does not like\n"
+"people fighting in his favorite area.\n");
set_al(500);
set_level(1);
/* Bruno's job is to just sit in the pub and take hits...the player's in the
past have spent mega $ trying to kill him for no exp or $ to show for it */
set_hp(50000);
set_ep(10);
set_wc(5);
set_ac(5);
set_aggressive(0);
coins = clone_object("obj/money");
coins->set_money(10+(random(20)));
move_object(coins,this_object());
}
init() {
  add_action("kill","kill");
  add_action("kill","fang");
  add_action("kill","blast");
}
kill(str) {
  say("Bruno steps in to stop a fight.\n");
  attack_object(this_player());
  return 1;
 }
