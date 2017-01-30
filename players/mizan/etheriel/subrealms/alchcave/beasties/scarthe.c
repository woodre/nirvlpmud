inherit "players/mizan/closed/FuzzyBeast.c";

/* Grime reaper? */

reset(arg){
   object gold, what;

   if(arg) return;

   if(!short_desc)
   short_desc = ({
     "Scarthe, Grand Regent of Filth and Stupidity",
     "Scarthe the Devious",
     "Scarthe the Arrogant",
     "Scarthe, High Grand Regent of Transmogrification",
     "Scarthe the Impotent",
   });

   if(!long_desc)
   long_desc = ({
      "Before you is a truly disgusting sight. This is Scarthe, the mad alchemist.\n"+
      "He is clad in chaps and what appears to be a boodied cotton thong.\n"+
      "He is not really paying attention to you because he is jumping on the bloated\n"+
      "two-week old corpse of a cow's belly as if it were some sort of trampoline.\n"+
      "You are sickened by the sight, and as if to rid the world of this hopeless mess\n"+
      "there is a deep rooted encouragement to kill this putrid bastard on the spot.\n",
   });

   set_name("Scarthe");
   set_race("scarthe");
   set_alias("idiot");
   set_level(19);
   set_hp(450 + random(50));
   set_al(-1000);
   set_wc(19);
   set_ac(29);
   set_chance(1);
   set_spell_dam(50);
   set_spell_mess1("Scarthe showers you with a bucket of pig vomit.");
   set_spell_mess2("Scarthe showers you with a fistful of poisoned cow stomach.");

   set_chat_chance(15);
   load_chat("Scarthe screams: JUMP! JUMP! JUMP!\n");
   load_chat("Scarthe screams: Peanut butter on the inside of the pants! Underwear on the outside!\n");
   load_chat("Scarthe bounces on the bloated corpse of a Cow.\n");
   load_chat("Bloated corpse of a Cow goes: mooo...\n");
   load_chat("Scarthe mutters: Animal matter is needed. More animal matter...\n");
   load_chat("Scarthe screams: Do I care about you? No I do not!\n");
   load_chat("Scarthe laughs: HAHAHAHAHAHA!\n");
   load_chat("Scarthe cries: My dear ANGELO! Why have you forsaken me you worthless wench!\n");

   gold=clone_object("obj/money");
   gold->set_money(random(800) + 3500);
   move_object(gold,this_object());
/*
   what=clone_object("players/mizan/etheriel/items/thingamajig.c");
   move_object(what, this_object());
*/

   ::reset(arg);

}
