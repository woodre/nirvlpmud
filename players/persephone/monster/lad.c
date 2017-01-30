inherit "obj/monster";
#include "/players/persephone/rooms.h"
reset(arg) {
  ::reset(arg);
    if(arg) return;
      set_name("pirate");
      set_alias("lad");
      set_short("An Eerie Pirate");
      set_long("A stripling of a pirate lad with scars all\n"+
               "over his face. Considering his size he looks\n"+
               "both fast and wiley\n");
      set_level (16);
      set_wc (22);
      set_ac (13);
      set_hp(400);
      set_al(0);
      set_aggressive(0);
      set_gender ("male");
      set_chance(10);
      set_spell_dam(20);
        set_spell_mess1("Prepares a flying kick");
        set_spell_mess2("Kicks you in the head ouch that hurts.");
      set_chat_chance(20);
      set_a_chat_chance(30);
      load_chat("The lad moves a crate around.\n");
      load_chat("The lad sits on the dock!\n");
      load_chat("The lad says: Why do I have to do all the work\n");
      load_a_chat("The lad says: Stop that you cannot hit me\n");
      load_a_chat("The lad punches you in the stomach\n");
      load_a_chat("The lad spits on your face in fury\n");
}
init(){
  ::init();
    add_action("gerble","board");
}
gerble(){
  write("The lad blocks your way\n");
  say("The lad blocks " + CAPTPLNM + "'s way\n");
return 1;
}
