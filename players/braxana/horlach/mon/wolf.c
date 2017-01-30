#include "/players/mythos/closed/ansi.h"
inherit "players/mythos/closed/guild/spells/monster2";
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("wolf");
  set_alias("white");
  set_alt_name("white wolf");
  set_race("creature");
  set_short("White Wolf");
  set_long("A great white wolf- albino in appearance,\n"+
           "blood red eyes and a coat of bright white.  Yet\n"+
           "unlike any other beast of the wild, a cunning\n"+
           "malevolence gleams through its eyes- hungering\n"+
           "for the taste of your blood and your fear!\n" );
  set_hp(550);
  set_level(20);
  set_al(-1000);
  set_wc(30);
  set_ac(15);
  set_wander();
  set_heal(2,20);
  set_aggressive(1);
  set_intel(16);
  set_dead_ob(this_object());
  set_chat_chance(15);
  set_a_chat_chance(10);
  load_chat("Red eyes gleam out from the darkness....\n");
  load_chat("Something hungers....\n");
  load_a_chat("A wolf growls....\n");
  load_a_chat("The white beast lunges at you!\n"); 
  set_chance(10);
  set_spell_dam(30);
  set_spell_mess1("A wolf suddenly lunges and its teeth sink into flesh!\n");
  set_spell_mess2("A wolf lunges at you and \n\n"+RED+
                  "                   P   A   I   N\n\n"+NORM+
                  "fills you as its jaws rip into your flesh!\n"); 
}

monster_died() {
  move_object(clone_object("/players/mythos/closed/guild/forest/misc/pelt"),
      environment(this_object()));
return 0; }
