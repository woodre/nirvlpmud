inherit "obj/monster.talk";
object coins;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("duck");
set_short("Sea Duck");
set_long("This is a rather large duck.  He is known to live on the sea\n"+
"(surprise, surprise).  He is probably using the surrounding area as his\n"+
"home.\n");
set_al(-250);
set_level(14);
set_wc(18);
set_hp(210);
set_ac(7);
set_aggressive(0);
set_dead_ob(this_object());
set_chat_chance(60);
load_chat("Duck says: Quack!\n");
load_chat("The duck does one hell of a quack.\n");
load_chat("Duck says: What are you quackin down here for?\n");
move_object(clone_object("players/grimm/weapons/duck_sword"),this_object());
coins = clone_object("obj/money");
coins->set_money(100+(random(200)));
move_object(coins,this_object());
}
monster_died() {
  say(this_player()->query_name()+"'s last hit on the duck sent out a poof of feathers that covered\nthe room.\n");
  return 0;
 }
