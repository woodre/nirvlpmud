inherit "obj/monster";
#include "/players/persephone/rooms.h"
object pstl,wibble,patch;
object ke;
reset(arg) {
  ::reset(arg);
    if(arg) return;
      pstl = clone_object("players/persephone/closed/pistol.c");
      move_object(pstl,TOB);
      init_command("wield pistol");
      patch = clone_object("players/persephone/closed/pac.c");
      move_object(patch,TOB);
      init_command("wear patch");
      set_name("redbeard");
      set_alias("pirate");
      set_short("Redbeard the Pirate");
      set_long("A large rotund man with a flaming red beard\n"+
               "perhaps this is the famed Redbeard. If it is\n"+
               "you had best be careful as he is one of the\n" +
               "most feared pirates around.\n\n");
      set_level (30);
      set_wc (50);
      set_ac (27);
      set_hp(1100);
      set_al(-200);
      set_aggressive(0);
      set_gender ("male");
      set_chat_chance(20);
      set_a_chat_chance(20);
      load_chat("Redbeard snickers at you\n");
      load_chat("Redbeard says: You scurvy dog get to work\n");
      load_a_chat("Redbeard waves his pistol around giving orders\n");
      load_a_chat("Redbeard shouts: Get these mutinous dogs\n");
      load_a_chat("Redbeard says: You will walk the plank\n");
      set_chance(30);
      set_spell_dam(30);
      set_spell_mess1("Redbeard aims directly at his opponents head");
      set_spell_mess2("Redbeard shoves his Pistol down your throat");
}
second_life(){
  wibble=clone_object("players/persephone/closed/dady");
  move_object(wibble,TPL);
  ::second_life();
}


