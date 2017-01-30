#include "/players/brittany/ansi"
inherit "obj/monster.c";

reset(arg)  {
object gold, ob, ob2;
  ::reset(arg);
  if(arg) return;

set_name("elder");
set_alias("sage");
set_alt_name("zoog");
set_race("creature");
set_short("Elder Sage");
set_long("This is the Elder of the zoogs, who leads the\n"+
"sacrifices around the dreaded circle of stones.  He is\n"+
"wearing a necklace in the shape of a pentagram.  His dark\n"+
"cloak covers his body from head to foot.  His eyes glow\n"+
"from inside of the hood.\n");

set_level(20);
set_hp(500);
set_al(-150);
ob=clone_object("/players/brittany/kadath/OBJ/scimiter.c");
move_object(ob,this_object());
ob2=clone_object("/players/brittany/kadath/OBJ/blrobe.c");
move_object(ob2,this_object());
  init_command("wield scimiter");
  init_command("wear robe");
set_wc(30);
set_ac(17);
set_aggressive(0);
set_dead_ob(this_object());
set_chat_chance(7);
load_chat("The Elder eyes you suspiciously.\n");
set_a_chat_chance(10);

set_chance(18);
set_spell_dam(40);

set_spell_mess1(
"The Elder slams its opponent into the ground, you hear bones crack.\n");
set_spell_mess2(
"The Elder slams you into the ground, your bones crack.\n");

  gold = clone_object("obj/money"); 
  gold->set_money(2500);
   move_object(gold,this_object());
}

monster_died() {
  tell_room(environment(this_object()),
"The Elder chants before hitting the ground.\n");
return 0; }
