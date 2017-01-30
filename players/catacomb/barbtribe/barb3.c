inherit "obj/monster.c";
object cloak;

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("barbarian");
set_race("human");
set_short("A barbarian");
set_long(
  "  A large muscular man, going about his daily business.  The\n"+
  "barbarian looks like he is always ready to do battle.  Along\n"+
  "his arms are two snake tattos, the marking of the clan.  Living\n"+
  "by such primitive means has had its toll on his calloused hands.\n");
 
set_level(11);
set_hp(165);
set_al(50+random(50));
set_ac(9);
set_wc(15);
add_money(300);
set_aggressive(0);
set_chat_chance(2);
  load_chat("The barbarian asks you if you are here to help them.\n");
cloak = clone_object("/players/catacomb/barbtribe/wskinhide.c");
move_object(cloak, this_object());
init_command("wear cloak");
}
 
