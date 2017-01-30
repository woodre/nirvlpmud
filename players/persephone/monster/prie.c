inherit "obj/monster";
#include "/players/persephone/rooms.h"
object grubble;
object seal;
reset(arg) {
  ::reset(arg);
    if(arg) return;
      set_name("preacher");
      set_alias("priest");
      set_short("An Elderly Priest");
      set_long("The Priest of the sea-man's mission he looks old\n"+
               "and careworn his uniform has definately seen\n"+
               "better days. Still you feel to attack him would\n" +
               "indeed be rash.\n");
      set_level (20);
      set_wc (30);
      set_ac (17);
      set_hp(500);
      set_al(1000);
      set_aggressive(0);
      set_gender ("male");
      set_chat_chance(30);
      load_chat("The Priest reads from an old bible.\n");
      load_chat("The Priest sighs: We need a miracle to save the town\n");
      load_chat("The Priest blesses you\n");
      load_chat("The Priest cries: Why do they have to kill everyone?\n");
      load_chat("The Priest searches in his suit\n");
      load_chat("The Priest sighs: if only the Mayor had his seal.\n");
}
second_life(){
  grubble=clone_object("players/persephone/closed/nyny4");
   move_object(grubble, TPL);
  ::second_life();
}
init(){
  ::init();
    add_action("offer1","offer");
    add_action("nod1","nod");
}
offer1(str){
  if(str=="help"||str=="assistance"){
    write("You offer to help the priest and he asks are you\n" +
          "sure you want to help? nod yes if you do.\n");
    say("The Priest smiles happily\n");
    return 1;
  }
  write("What are you offerring?\n");
  return 1;
}
nod1(str){
  if(str=="yes"||str=="affirmatively"){
    write("The Priest says: Guard this seal with you life and\n" +
          "                 give it to the mayor who is wandering\n" +
          "                 Stormhold.\n");
    seal = clone_object("players/persephone/closed/sea.c");
    move_object(seal, environment(TOB));
    write ("The Priest bows and leaves the room placing a seal\n" +
           "as he leaves\n\n");
    destruct(TOB);
    return 1;
  }
  write("you nod solemnly\n");
  return 1;
}
