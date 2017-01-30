inherit "obj/monster";
#include "/players/persephone/rooms.h"
object cup;
reset(arg) {
  ::reset(arg);
    if(arg) return;
      cup = clone_object("players/persephone/object/cup.c");
      move_object(cup, this_object());
      set_name("beggar");
      set_alias("man");
      set_short("An Unfortunate Old Man");
      set_long("One of Stormhold's and Nirvana's poor and unfortunate\n"+
               "underclass. He is dressed in ragged and tatty clothes.\n"+
               "He looks so poor you almost feel sorry for him.\n"
               "So sorry you want to put a coin in his cup!!\n");
      set_level (10);
      set_wc (14);
      set_ac (8);
      set_hp(150);
      set_al(0);
      set_aggressive(0);
      set_gender ("male");
      set_chat_chance(40);
      set_a_chat_chance(40);
      load_chat("The beggar shakes his cup in hope\n".);
      load_chat("The beggar sighs: Have you seen the mayor he is \n" +
                "wandering around somewhere\n");
      load_chat("The beggar asks: Have you come to save Stormhold?\n");
      load_chat("The beggar asks: Do you have something from me?\n");
      load_a_chat("The beggar shouts: YOUR NOTHING BUT A RUFFIAN\n");
      load_a_chat("The beggar sighs: Youth today they have no respect\n");
      load_a_chat("The beggar sighs: What has happened to this fair town?\n");
      load_a_chat("The beggar asks: Why do you do this to me??\n");
      load_a_chat("The beggar states: I have done nothing to you!!\n");
}
