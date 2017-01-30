inherit "players/mizan/closed/FuzzyBeast.c";

reset(arg){
   object gold, what;

   if(arg) return;

   if(!short_desc)
   short_desc = ({
     "Bitterment the Alchemist",
     "Bitterment, of Despair",
     "Bitterment",
   });

   if(!long_desc)
   long_desc = ({
      "  Before you stands a broken man. Clutching a boulder in his hand, and huddled\n"+
      "in the corner of the room, he is mumbling to himself over some lost empire of\n"+
      "ages ago. He carries no weapons but the mark on his forehead tells you that he\n"+
      "was once a powerful sorcerer or even a monk of some sort.\n",
   });

   set_name("Bitterment");
   set_race("bitterment");
   set_alias("bitter");
   set_level(19);
   set_hp(450 + random(50));
   set_al(-1000);
   set_wc(19);
   set_ac(29);
   set_chance(1);
   set_spell_dam(80);
   set_spell_mess1("Bitterment casts a sonic blast.");
   set_spell_mess2("Bitterment casts a fireball.");

   set_chat_chance(15);
   load_chat("Bitterment mumbles: All I wanted to do was create something wonderful.\n");
   load_chat("Bitterment mumbles: I think, therefore I exist. That is my only consolation.\n");
   load_chat("Bitterment mumbles: What have I done wrong?\n");
   load_chat("Bitterment mumbles: I no longer trust Scarthe. I think he has become a fanatic.\n");
   load_chat("Bitterment mumbles: Alas, I am a broken man. I am the picture of sorrow.\n");
   load_chat("Bitterment mumbles: Never again... All I tried to do was make gold from flesh...\n");

   gold=clone_object("obj/money");
   gold->set_money(random(800) + 3500);
   move_object(gold,this_object());

/*
   what=clone_object("players/mizan/etheriel/items/thingamajig.c");
   move_object(what, this_object());
*/

   ::reset(arg);

}
