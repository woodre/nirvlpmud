inherit "obj/monster.talk";
object coins, item;
int i;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("pit bull");
set_alias("dog");
set_short("A Large Pit Bull");
set_long("This is a very husky looking pit bull.\n");
set_al(-250);
set_level(10);
set_wc(12);
set_hp(160);
set_ac(6);
set_aggressive(1);
set_chat_chance(40);
set_a_chat_chance(40);
load_chat("Pit Bull growls at you.\n");
load_a_chat("Pit Bull snaps at your heals.\n");
coins = clone_object("obj/money");
coins->set_money(100+(random(200)));
move_object(coins,this_object());
i=random(100);
if (i<45) {
  item = clone_object("players/grimm/armor/spike_nek");
  move_object(item, this_object());
}
}
