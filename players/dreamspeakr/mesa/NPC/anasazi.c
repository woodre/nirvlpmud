#include "/players/dreamspeakr/closed/ansi.h"
inherit "/obj/monster";

reset(arg){
int i;
    ::reset(arg);
    if(!arg){
     set_name("anasazi indian");
     set_race("american indian");
     set_aggressive(0);
     set_al(500-random(100));
    i = random(4);
       if(i == 0){ warrior(); }
       if(i == 1){ ywarior(); }
       if(i == 2){ squaw(); }
       if(i == 3){ ysquaw(); }
    }
}

warrior(){
      set_short(HIG+"Tribal Warrior"+NORM);
      set_long(
        "Tried and proven in the ways of the Anasazi this warrior is \n"+
        "ready for battle.  Protecting his family and tribe from all \n"+
        "who dare to trespass, he paces back and forth.  Streaks of \n"+
        "paint stain his face, making one wonder if they are treading \n"+
        "on dangerous territory here.\n");

      set_alias("warrior");
      set_level(18);
      set_hp(450);
      set_gender("male");

  if(!present("loincloth")) {
    move_object(clone_object("players/dreamspeakr/mesa/OBJ/loin.c"),
      this_object()); 
  }

      init_command("wear loincloth");

  if(!present("bow")) {
    move_object(clone_object("players/dreamspeakr/mesa/OBJ/bow.c"),
      this_object()); 
  }

      init_command("wield bow");

      set_ac(15);
      set_wc(26);
      set_chat_chance(5);
         load_chat("The warrior lets out a loud shrilling battlecry!\n");
      set_a_chat_chance(35);
         load_a_chat("The warrior says:  Prepare to die! \n");
         load_a_chat("The warrior lets out a loud "+RED+"shrilling "+NORM+"battlecry!\n");
         load_a_chat("The warrior picks up a large rock and "+BLU+"lunges"+NORM+" it at you.\n");
}

ywarior(){
      set_short(HIG+"Young Anasazi Warrior"+NORM);
      set_long(
        "Not much older then 10 he appears to be quite busy learning how \n"+
        "to fight and feed the family.  Dark skin tanned from the exposure \n"+
        "of the clifftops, he sharpens on a arrowhead awaiting the next hunt.\n");

      set_alias("warrior");
      set_level(12);
      set_hp(180);
      set_gender("male");

  if(!present("loincloth")) {
    move_object(clone_object("players/dreamspeakr/mesa/OBJ/loin.c"),
      this_object()); 
  }

      init_command("wear loincloth");

  if(!present("necklace")) {
    move_object(clone_object("players/dreamspeakr/mesa/OBJ/neck.c"),
      this_object()); 
  }

      init_command("wear necklace");

      set_wc(16);
      set_ac(9);
      set_chat_chance(5);
        load_chat("The young warrior says:  I shall be a strong and brave warrior\n"+
          "one day, just like my father.\n");
      set_a_chat_chance (25);
        load_a_chat("The young warrior gets a handful of "+YEL+"sand"+NORM+" and throws it in your face.\n");

}

squaw(){
      set_short(HIY+"Anasazi Squaw"+NORM);
      set_long(
        "Busy in her daily routine, she stands, grinding meal to \n"+
        "prepare for the next meal.  Working steadily, she sings \n"+
        "softly to the child in the small pappose strapped to her \n"+
        "back.  Callosed hands bear the markings of a hard working \n"+
        "woman.\n");

      set_alias("squaw");
      set_level(16);
      set_hp(400);
      set_gender("female");

if(!present("apron")) {
     move_object(clone_object("players/dreamspeakr/mesa/OBJ/apron.c"),
       this_object()); 
     }

     init_command("wear apron");

     set_wc(22);
     set_ac(13);
     set_chat_chance(5);
       load_chat("The squaw sings in a calming voice to the small child she carries.\n");
     set_a_chat_chance(35);
       load_a_chat("The squaw screams "+HIG+"HELP"+NORM+"! "+HIG+"HELP"+NORM+"!\n");
       load_a_chat("The Anasazi squaw throws a bowl of "+HIR+"hot"+NORM+" water on you.\n");
       load_a_chat("The squaw gets a flaming stick from the "+HIR+"fire"+NORM+" and hurls it at you.\n");

}

ysquaw(){
     set_short(HIY+"Young Anasazi Squaw"+NORM);
     set_long(
       "Pretty little thing she is.  Long flowing jet black hair, her \n"+
       "hands move with grace as she weaves the beautiful baskets for \n"+
       "her family. \n");

     set_alias("squaw");
     set_level(10);
     set_hp(150);
     set_gender("female");

if(!present("basket")) {
     move_object(clone_object("players/dreamspeakr/mesa/OBJ/basket1.c"),
       this_object()); 
     }

     set_wc(14);
     set_ac(8);
     set_chat_chance(5);
       load_chat("The young squaw looks up at you and smiles, then goes back to weaving.\n");
     set_a_chat_chance(25);
       load_a_chat("The young squaw screams for "+HIG+"HELP"+NORM+"!\n");

}