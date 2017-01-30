inherit "obj/monster";
#include "/players/persephone/rooms.h"
object cutlass,wobble;
reset(arg) {
  ::reset(arg);
    if(arg) return;
      cutlass = clone_object("players/persephone/closed/cutty.c");
      move_object(cutlass,TOB);
      init_command("wield cutlass");
      set_name("francis");
      set_alias("pirate");
      set_alias("drake");
      set_alias("sir francis drake");
      set_short("Sir Francis Drake");
      set_long("A wealthy looking pirate if pirate is the\n"+
               "correct term. He was once one of the most\n"+
               "feared men of the sees and followed the\n" +
               "wishes of Queen Elizabeth of England.\n\n");
      set_level (30);
      set_wc (50);
      set_ac (27);
      set_hp(1000);
      set_al(-200);
      set_aggressive(0);
      set_gender ("male");
      set_chat_chance(20);
      set_a_chat_chance(20);
      load_chat("Sir Francis broods around the deck\n");
      load_chat("Sir Francis mutters something to himself\n");
      load_chat("Sir Francis says: We will get the Spaniards\n");
      load_chat("Sir Francis looks you over");
      load_a_chat("Sir Francis yells: come to me men\n");
      load_a_chat("Sir Francis parries your blow\n");
      load_a_chat("Sir Francis says: Die you Spanish dog\n");
      set_chance(50);
      set_spell_dam(40);
      set_spell_mess1("Sir Francis Drake jabs his oponent with his cutlass");
      set_spell_mess2("Sir Francis Drake plunges his Cutlass into you");
}
}
second_life(){
  wobble=clone_object("players/persephone/closed/dudy");
  move_object(wobble,TPL);
  ::second_life();
}


