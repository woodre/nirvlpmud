#include "/players/coldwind/define.h"
inherit "/players/vertebraker/closed/std/monster.c";

int coins;
object gold;

reset(arg)  {

  ::reset(arg);
  if(arg) return;

set_alias("villager");
set_race("human");
set_aggressive(0);
set_wander(100 + random (200), 0);
switch(random(4)){
  case 0:
    boy();
    coins = random(99) + 450;
   break;
  case 1:
    girl();
    coins = random(40) + 380;
   break;
  case 2:
    man();
    coins = random(175) + 900;
   break;
  case 3:
    woman();
    coins = random(173) + 500;
   break;
  }
gold = clone_object("obj/money");
gold->set_money(coins);
move_object(gold,this_object());
}	


                             
boy(){
set_alt_name("boy");
set_name("child");
set_gender("male");
get_short();
set_long("  The boy's childish features shows his fear and drowsiness. His\n"+
         "face is dirty and pale and he seems hungry. The child walks by\n"+
		 "you as he searches for his family or their corpses. \n");
set_level(11);
set_hp(165);
set_wc(15);
set_ac(9);
set_al(700);
set_chat_chance(5);
  load_chat("The boy yells, 'Mom...'\n");
  load_chat("The child burst into tears.\n");
  load_chat("The child eyes you with frightened eyes.\n");
  load_chat(BOLD+"The child says, 'I think i saw a knight climbing the mounatin\n"+
             "after the witch.'\n"+NORM);
set_a_chat_chance(15);
  load_a_chat("The boy screams for help!\n");
  load_a_chat("The child gives a weak punch!\n");
  load_a_chat("The boy fails to run away.\n");
}


get_short(){
int i;
i = random(4);
switch(i){
case 0:   set_short("A short boy ("+HIB+"Scared"+NORM+")");
break;
case 1:   set_short("A scared boy");
break;
case 2:   set_short("A weak boy ("+HIY+"Hungry"+NORM+")");
break;
case 3:   set_short("A tall boy");
break;
}
}

girl(){
set_alt_name("child");
set_name("girl");
set_gender("female");
Z_short();
set_long("  The young girl is looking around for her family. She is wearing\n"+
         "some dirty clothes, while her feet are blistered from escaping to\n"+
		 "the desert in bare feet.\n");
set_level(9);
set_hp(165);
set_wc(13);
set_ac(7);
set_al(700);

set_chat_chance(4);
  load_chat("The girl searches the sand for food.\n");
  load_chat("The little girl bursts into tears.\n");
  load_chat("The girl eyes you with frightened eyes.\n");
   set_a_chat_chance(15);
  load_a_chat("The child screams for help!\n");
  load_a_chat("The girl gives a weak kick!\n");
  load_a_chat("You are blinded, as the girl throws some sand in your eyes.\n");
}
Z_short(){
int f;
f = random(4);
switch(f){
case 0:   set_short("A short girl");
break;
case 1:   set_short("A scared girl ("+HIY+"Hungry"+NORM+")");
break;
case 2:   set_short("A weak girl");
break;
case 3:   set_short("A fat girl");
break;
}

}
man(){
set_alt_name("guy");
set_name("man");
set_gender("male");
he_short();
set_long("  A young man eyes you with frightened eyes. As you get a closer \n"+
         "look at the guy, you notice some scratches and wounds on his chest\n"+
		 "and arms. His skin and clothes are dirty, but he is one of a few\n"+
		 "that were able to survive the attack on the village.\n");
set_level(15);
set_hp(250);
set_wc(20);
set_ac(12);
set_al(700);

set_chat_chance(5);
  load_chat("The man lets out a deep sigh.\n");
  load_chat("The guy looks around for his kids.\n");
  load_chat("The man checks his wounds.\n");
    load_chat(BOLD+"The man thinks loadly, 'maybe my kids tracked the footprints\n"+
	          "and are hiding with Farha, the magician in her hut.'\n"+NORM);
set_a_chat_chance(15);
  load_a_chat("The man punches you in the face.\n");
  load_a_chat("The man grabs your leg!\n");
  load_a_chat("The guy fails to run away.\n");
}


he_short(){
int x;
x = random(4);
switch(x){
case 0:   set_short("A weak man");
break;
case 1:   set_short("A frightened man ");
break;
case 2:   set_short("A strong man");
break;
case 3:   set_short("A wounded man ("+HIR+"Bleeding"+NORM+")");
break;
}
}
woman(){
set_alt_name("lady");
set_name("woman");
set_gender("female");
she_short();
set_long("  As you get a closer look at the lady, you notice some scratches\n"+
         "and wounds on her neck and arms. Her skin and clothes are dirty.\n"+
		 "The woman seems to be searching for her family.\n");
set_level(13);
set_hp(195);
set_wc(17);
set_ac(10);
set_al(700);

set_chat_chance(2);
  load_chat("The woman searches the ground for food.\n");
  load_chat("The lady looks around for her husband.\n");
  load_chat("The old woman wipes a falling tear.\n");
set_a_chat_chance(15);
  load_a_chat("The woman scratches your face using her nails.\n");
  load_a_chat("The lady pushes you away!\n");
  load_a_chat("You are blinded, as the woman throws some sand in your eyes.\n");
}


she_short(){
int y;
y = random(5);
switch(y){
case 0:   set_short("An old woman ("+HIB+"Frightened"+NORM+") ");
break;
case 1:   set_short("A scared woman");
break;
case 2:   set_short("A weak woman ("+HIY+"Hungry"+NORM+")");
break;
case 3:   set_short("A short woman");
break;
case 4:   set_short("A old woman");
break;
}
}
