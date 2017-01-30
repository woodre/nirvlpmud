#include "/players/vertebraker/define.h"
inherit "/obj/monster";
int coins;
int w, wander_time;
object gold;
reset(arg)  {   
   ::reset(arg);
   if(arg) return;
   set_alt_name("villager");
   set_aggressive(0);
   set_bullshit(0, 20);
   set_heart_beat(2);
   switch(random(5)) {
      case 0: civilian1(); break;
      case 1: civilian2(); break;
      case 2: civilian3(); break;
      case 3: civilian4(); break;
      case 4: civilian5(); break; }
   coins = 100+random(200);
   if(coins){  
      gold = clone_object("obj/money");
      gold->set_money(coins);
      move_object(gold,this_object());
   }
}


civilian1(){
   set_short("A small boy");
   set_long(
      "  A small boy of about nine.  He is wearing a blue bandanna\n"+
      "a pair of tattered slacks, and a tight white shirt.  He has a\n"+
      "baseball in one hand and casually tosses it up in the air.\n");
   set_race("human");
   set_level(5);
   set_gender("male");
   set_name("boy");
   set_hp(60);
   set_ac(6);
   set_wc(7);
   set_al(150);
   set_chat_chance(5);
   load_chat("The small boy tosses his ball up in the air.\n");
   load_chat("The small boy looks at you inquisitively.\n");
   set_a_chat_chance(15);
   load_a_chat("The small boy attempts to run, but fails.\n");
   load_a_chat("The small boy calls for his parents!\n");
}

civilian2(){
   set_short("A young woman");
   set_long(
      "  Plain-looking and slender, this young lady has seen some\n"+
      "work on the village.  She performs duties like clothes-washing\n"+
      "at the pool and retrieving nuts and berries from the forests.\n"+
      "She is carrying a small clothesbasket.\n");
   set_level(5);
   set_race("human");
   set_alias("young");
   set_gender("female");
   set_name("woman");
   set_hp(75);
   set_ac(5);
   set_wc(9);
   set_al(200);
   set_chat_chance(5);
   load_chat("The young woman smiles brightly at you.\n");
   load_chat("A young woman passes by.\n");
   set_a_chat_chance(15);
   load_a_chat("The young woman calls for a guard!\n");
   load_a_chat("The young woman gets a very scared look on her face.\n");  
}

civilian3(){
   set_short("An angry villager");
   set_long(
      "  Obviously annoyed at someone or something, this man\n"+
      "seems to be trying to get somewhere fast.  He wears a\n"+
      "pair of blue pants and a dark red robe.\n");
   set_level(5);
   set_race("human");
   set_alias("angry");
   set_name("angry villager");
   set_gender("male");
   set_hp(70);
   set_ac(5);
   set_wc(12);
   set_al(100);
   set_chat_chance(5);
   load_chat("The villager says: \"I hate this place!\"\n");
   load_chat("The villager yells: \"Out of my way!\"\n");
   load_chat("The villager shoves you around.\n");
   set_a_chat_chance(15);
   load_a_chat("The villager punches you in the face!\n");
   load_a_chat("The villager yells: \"You idiot!\"\n");
}

civilian4(){
   set_short("A strong villager");
   set_long(
      "Barrel-chested and strong as an axe, this villager\n"+
      "dreamt of being a guard for a while.  Unfortunately\n"+
      "he never made the cut, and now works bringing food\n"+
      "barrels back and forth through the village.\n");
   set_level(5);
   set_race("human");
   set_alias("strong");
   set_name("strong villager");
   set_gender("male");
   set_hp(100);
   set_ac(5);
   set_wc(12);
   set_al(100);
   set_chat_chance(5);
   load_chat("The strong villager says: \"Whistle while we work...\"\n");
   load_chat("The villager whistles a little tune.\n");
   load_chat("The strong villager yells: \"Heave-ho!\"\n");
   set_a_chat_chance(15);
   load_a_chat("The villager punches you in the face!\n");
   load_a_chat("The villager throws a handful of rice in your eye!\n");
}


civilian5(){
   set_short("An older villager");
   set_long(
      "Old with a short grey beard, this villager is enjoying\n"
      +"the twilight years.  He holds a simple garden hoe and\n"
      +"has retired from being a disciple of Juribel and is\n"
      +"resigned to life's simple pleasures.\n");
   set_level(5);
   set_race("human");
   set_name("old man");
   set_gender("male");
   set_alias("older");
   set_hp(85);
   set_ac(6);
   set_wc(8);
   set_al(200);
   set_chat_chance(5);
   load_chat("The older villager asks: \"How are you today?\"\n");
   load_chat("The older villager picks at some roots in the ground.\n");
   set_a_chat_chance(15);
   load_a_chat("The older villager fails to dodge your attack.\n");
}      


void set_bullshit(int chance, int time) {  
   w = time;  
   set_heart_beat(1); 
}  

heart_beat(){
   ::heart_beat();
   if(w && !query_attack()) {  
      if(wander_time++ > w && !random(4)) {
         random_move();  
      } 
   }
}    

