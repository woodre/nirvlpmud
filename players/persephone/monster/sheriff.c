inherit "obj/monster";
#include "/players/persephone/rooms.h"
object grubble;
object wibble;
reset(arg) {
  ::reset(arg);
    if(arg) return;
      set_name("prisoner");
      set_alias("sheriff");
      set_alias("man");
      set_short("A Convicted Fellon");
      set_long("A prisoner of Stormhold's jail he looks like a real\n"+
               "ruffian. As you examine him more closely however\n"+
               "you notice that he might not be a fellon but the sheriff!!\n" +
               "He looks both strong and angry maybe because it is\n" +
               "because he is wearing handcuffs\n");
      set_level (16);
      set_wc (22);
      set_ac (13);
      set_hp(400);
      set_al(800);
      set_aggressive(0);
      set_gender ("male");
      set_chat_chance(20);
      set_a_chat_chance(30);
      load_chat("The Criminal sighs!!\n");
      load_chat("The Criminal says: Jeny's head will not be with her.\n");
      load_chat("The Criminal remarks: They showed me no respect!!\n");
      load_chat("The Criminal sighs: Look at me chained up like a dog.\n");
      load_chat("The Criminal asks: Have you come to save me\n");
      load_a_chat("The Criminal shouts: YOUR NOTHING BUT A RUFFIAN\n");
      load_a_chat("The Criminal states: You Should be killing pirates not me\n");
      load_a_chat("The Criminal sighs:  You will not save Stormhold\n");
      load_a_chat("The Criminal curses you\n");
}
second_life(){
  grubble=clone_object("players/persephone/closed/nyny5");
   move_object(grubble, TPL);
  ::second_life();
}
init(){
  ::init();
    add_action("unlock1","unlock");
    add_action("unlock1","release");
}
