inherit "obj/monster.c";
object spear, helmet;

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("warrior");
set_race("creature");
set_short("A Durkor warrior");
set_long(
  "  A slim and muscular humanoid.  The warrior's dark face almost has a \n"+
  "deadly charm to it.  A Durkor female stands before you ready to kill \n"+
  "all who venture near her home who aren't Durkor.  Looking at her eyes \n"+
  "you see an evil glint eminating from within ready to kill the intruders.\n");
 
set_level(18);
set_hp(400 + random(50));
set_al(-450);
set_dead_ob(this_object());
set_aggressive(0);
add_money(500 + random(1000));
set_chat_chance(3);
  load_chat("The warrior urges you to attack her.\n");
set_a_chat_chance(4);
  load_a_chat("The warrior grins evilly at you.\n");
  load_a_chat("The warrior eyes you over looking for weak points.\n");
set_chance(10);
set_spell_dam(30);
set_spell_mess1(
  "The warrior thrusts the spear into her foe.\n");
set_spell_mess2(
  "The warrior thrusts the spear through your armor.\nBlood sprays from the deep wound.\n");

spear = clone_object("players/catacomb/Cavern/items/Dspear.c");
move_object(spear, this_object());
init_command("wield spear",this_object());
set_wc(27);

helmet = clone_object("/players/catacomb/Cavern/items/Dhelmet.c");
move_object(helmet, this_object());
init_command("wear helmet", this_object());
set_ac(16);

}
  