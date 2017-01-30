#include "/players/feldegast/closed/ansi.h"
#include "/players/feldegast/closed/shortcut.h"
inherit "/obj/monster";

int skins;

reset(arg) {
  ::reset(arg);
  skins=4;
  if(arg) return;
  set_name("maria");
  set_alt_name("lady");
  set_short("Lady Maria");
  set_long(
"Lady Maria is a young teenager who has been betrothed to\n"+
"the chief man's son since birth.  Since the chief man's\n"+
"son is missing, she makes herself useful as the village\n"+
"tailor.\n"
  );
  set_gender("female");
  set_race("human");
  set_level(4);
  set_wc(9);
  set_ac(4);
  set_hp(60);
  set_al(50);
  set_aggressive(0); 
  set_chat_chance(5);
  load_chat("Maria sighs moodily.\n");
  load_chat("Maria mends a loincloth.\n");
  load_chat("Maria stares out the window with a dreamy expression on her face.\n");
  set_a_chat_chance(5);
  load_a_chat("Maria screams for help!\n");
  load_a_chat("Maria yells, 'Pirate!'\n");
}
init() {
  add_action("give","give");
  add_action("ask","ask");
}
give(str) {
  object armor;
  if(!str) return 0;
  if(str=="snakeskin to maria"||str=="snakeskin to lady") {
    if(!attacker_ob) {
      if(present("material for maria",this_player())) {
        say("Maria says: Thank you for the material.\n");
        destruct(present("material for maria",this_player()));
        skins--;
        if(skins)
          say(
"\nMaria says: If you give me "+skins+" more snakeskins,\n"+
"            I can make you something special.\n");
        else {
          armor=clone_object("/players/feldegast/island/npc/snake_armor");
          armor->set_owner(TPN);
          skins=4;
          write("Maria makes you a suit of armor out of the snakeskins.\n");
          write("Maria smiles happily.\n");
          write("Maria says: Here you go!\n");
          move_object(armor,environment());
        }
      }
    }
    return 1;
  }
}

int ask(string str) {
  if(!str) {
    write("Ask about what?\n");
    return 1;
  }
  if(str=="about ideas"||str=="about skybeast") {
    write(
"Maria says: The Skybeast is a horrible monster that spits\n"+
"  jelly-fire on its foe from above.  The jelly-fire burns\n"+
"  through all forms of armor and seeps around shields.  The\n"+
"  only way to protect yourself is to wear a complete suit of\n"+
"  snakeskin armor.  If you bring me four snakeskins from the\n"+
"  jungle, then I can make a suit for you.\n"
    );
    return 1;
  }
  if(str=="about ngana") {
    write(
"Maria gets a distant look on her face and doesn't answer your question.\n");
    return 1;
  }
  if(str=="about doctor"||str=="about witch doctor") {
    write(
"Maria says: The Doctor is a good friend of mine.  He is a fool,\n"+
"  but a compassionate fool.  I don't know what I'd do if he\n"+
"  hadn't been there for me when Ngana was taken from us.\n"
    );
    return 1;
  }
  write("Ask about what?\n");
  return 1;
}
