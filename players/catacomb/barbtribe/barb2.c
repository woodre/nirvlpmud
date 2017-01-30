inherit "obj/monster.c";
#define ATTACKED (this_object()->query_attack())
object bones,hammer;

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("guard");
set_race("human");
set_short("A barbarian guard");
set_long(
  "  Scarred from many battles, this warrior displays them all\n"+
  "with the utmost pride.  Having served in many wars, the chief\n"+
  "has bestowed upon him the honor of guarding the tribe from\n"+
  "intruders.\n");
 
set_level(14);
set_hp(220);
set_al(100+random(50));
set_ac(11);
set_dead_ob(this_object());
set_aggressive(0);
set_chat_chance(3);
  load_chat("The barbarian eyes you wondering if you are friend or foe.\n");
set_a_chat_chance(1);
  load_a_chat("The barbarian yells for you to identify yourself.\n");
hammer = clone_object("/players/catacomb/barbtribe/hammer.c");
move_object(hammer, this_object());
init_command("wield hammer");
set_wc(18);
}
 
monster_died(){
  tell_object(ATTACKED,
    "As the barbarian dies a small set of bones falls from his cloak.\n");
    bones = clone_object("/players/catacomb/barbtribe/bones.c");
    move_object(bones, this_object());
}   