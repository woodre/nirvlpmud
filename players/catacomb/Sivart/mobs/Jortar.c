inherit "obj/monster.c";
object mace;

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("jortar");
set_race("durkor");
set_short("Jortar Shaigan");
set_long(
  "  The owner of Gloom's Breath stands before you.  His pale skin\n"+
  "makes his crimson eyes all the more creepy.  Jortar's muscular\n"+
  "build shows that Gloom's Breath has seen its fair share of brawls.\n"+
  "Hanging from his belt is a small mace to take care of any unruly\n"+
  "patrons.\n");
 
set_level(17);
set_hp(350);
set_al(0);
set_dead_ob(this_object());
set_aggressive(0);
set_ac(14);
add_money(1000 + random(500));
set_chat_chance(3);
  load_chat("Jortar asks you: Can I get you anything?\n");
set_a_chat_chance(2);
  load_a_chat("Jortar says: I've handled much worse than the likes of you!\n");

mace = clone_object("players/catacomb/Sivart/items/Jmace.c");
move_object(mace, this_object());
command("wield mace",this_object());
set_wc(22 + random(4));

}
  