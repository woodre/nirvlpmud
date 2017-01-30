#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";
int ill;

reset(arg)  {
  ::reset(arg);
  if(arg) return;
ill = 0;

set_name("disir");
set_alias("green");
set_alt_name("green disir");
set_race("creature");
set_short(HIG+"Green Disir"+NORM);
set_long(
	"This creature stands about 7 feet tall, although it is shorter\n"+
	"because it is hunched over.  Parts of it's body are covered\n"+
	"with a natural armor, while other areas show exposed, rubbery\n"+
	"flesh.  It's skin is a pasty green color and it's pores exude\n"+
	"a thick coating of slimy gel which is normally polluted with\n"+
	"dirt, debris, and bits of dead flesh.  An aura of stench and\n"+
	"decay hangs around it.\n");

set_level(20);
  set_hp(500);
  set_al(0);
  set_wc(28);
  set_ac(17);
  set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(15);
  load_chat("The Disir watches you closely...\n");
  load_chat("A gob of slimy gel drips off the Disir..\n");
  load_chat("The Disir snarls...\n");
set_a_chat_chance(20);
  load_a_chat("\nThe Disir rakes at you with it's poisonous claws...\n");
  load_a_chat("\nThe Disir BITES at you....\n");

set_chance(14);
set_spell_dam(30);

set_spell_mess1(
  "\nThe Diser "+BOLD+"* CLAWS *"+NORM+" it's target.....\n");
set_spell_mess2(
  "\nThe Diser "+BOLD+"* CLAWS *"+NORM+" you! \n\n");

}

heart_beat() {
  ::heart_beat();
  if (query_attack()) {
    if(query_attack()->query_attrib("luc") < random(28)
    && ill == 0) {
      move_object(clone_object("players/eurale/Keep/OBJ/poison.c"),
        query_attack()); 
    ill = 1;
      tell_object(environment(this_object()),
        "You feel a burning sensation......\n");
      return 1; }
  }
}

monster_died() {
move_object(clone_object("players/eurale/Keep/OBJ/disir_slime.c"),
  environment(this_object()));
return 0; }
