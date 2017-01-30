inherit "players/mizan/closed/FuzzyBeast.c";

reset(arg){
   object gold, what;

   if(arg) return;

   if(!short_desc)
   short_desc = ({
     "An Alchemist Apprentice",
     "A 'wannabe' Alchemist Apprentice",
     "An annoying Alchemist Apprentice",
     "Apprentice of the Chicken Foot Order",
     "Alchemist Apprentice (quivering)",
     "A leper Apprentice",
   });

   if(!long_desc)
   long_desc = ({
      "  Before you stands a broken man. Clutching a boulder in his hand, and huddled\n"+
      "in the corner of the room, he is mumbling to himself over some lost empire of\n"+
      "ages ago. He carries no weapons but the mark on his forehead tells you that he\n"+
      "was once a powerful sorcerer or even a monk of some sort.\n",
   });

   set_name("Apprentice");
   set_race("alchemist");
   set_alias("alchie");
   set_level(15);
   set_hp(225 + random(50));
   set_al(-500);
   set_wc(20);
   set_ac(12);

   set_chat_chance(3);
   load_chat("Apprentice says: We need to make the bodies more soupy for Scarthe.\n");
   load_chat("Apprentice says: Nobody has seen Brother Bitterment for weeks now...\n");
   load_chat("Apprentice stirs the pot of rotting flesh.\n");
   load_chat("Apprentice says: Does anyone think this will really make gold?");
   load_chat("Apprentice says: Scarthe says beatings will continue until morale improves.\n");
   load_chat("Apprentice says: I really do not want to be fed to the Hydra.\n");
   load_chat("Apprentice puts another log into the fire.\n");

   gold=clone_object("obj/money");
   gold->set_money(random(400) + 700);
   move_object(gold,this_object());

/*
   what=clone_object("players/mizan/etheriel/items/thingamajig.c");
   move_object(what, this_object());
*/

   ::reset(arg);

}
