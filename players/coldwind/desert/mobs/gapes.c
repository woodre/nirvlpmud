#include "/players/coldwind/define.h"
inherit "obj/monster.c";
#define attacked (this_object()->query_attack())
#define atn capitalize(attacked->query_name())

reset(arg)  {

  ::reset(arg);
  if(arg) return;
  
    move_object(clone_object("/players/coldwind/desert/weapons/claws.c"),this_object());
init_command("wield claws");
set_name("ape");
set_alt_name("winged ape");
set_wc_bonus(10);
set_alias("guard");
set_race("ape");
set_short(HIK+"Winged Ape "+YEL+"["+NORM+YEL+"Guard"+HIY+"]"+NORM);
set_level(18);
set_hp(400);
set_al(-700);
set_gender("male");
set_wc(26);
set_ac(15);
set_ac_bonus(2);
set_aggressive(0);
set_chat_chance(3);
  load_chat("The ape takes an offensive stand..\n");
  load_chat("Red eyes stares at you.\n");
  load_chat("The guard makes a threatening sound as it knocks on it's chest.\n");
set_a_chat_chance(10);
  load_a_chat("The guard dodges your attack.\n");
  load_a_chat("The ape scratches your arm!\n");
  load_a_chat(HIY+"The ape bites your neck!\n"+NORM);
  load_a_chat("The guard jumps back in agony..\n");
   set_chance(40);
  set_spell_dam(25);
  set_spell_mess1("The guard tears at it's foe with its claws, drawing blood...\n");
  set_spell_mess2("The guard tears at you with its claws, drawing blood...\n");

 

switch(random(6)){
  case 0:
    ape1();
   break;
  case 1:
    ape2();
   break;
  case 2:
    ape3();
   break;
  case 3:
    ape4();
   break;
   case 4:
   ape5();
   break;
   case 5:
   ape6();
   break;
   
  }
}	


                             
ape1(){
move_object(clone_object("/players/coldwind/desert/armor/gamulet.c"),this_object());
init_command("wear amulet");
set_long(
"  A strong looking ape is watching your moves curiously with its\n"+
"red eyes.  It has featherless wings that looks like giant bat wings.\n"+
"Silver chains cover its neck, while a thick brown hair covers most\n"+
"of its body.\n"+NORM);
}

ape2(){
move_object(clone_object("/players/coldwind/desert/armor/ghelmet.c"),this_object());
init_command("wear helmet");

set_long(
"  A strong looking ape is watching your moves curiously with its\n"+
"red eyes. It has featherless wings that looks like giant bat wings.\n"+
"Silver helm covers its head, while a thick brown hair covers most\n"+
"of its body.\n"+NORM);
}
ape3(){
move_object(clone_object("/players/coldwind/desert/armor/gboots.c"),this_object());
init_command("wear boots");

set_long(
"  A strong looking ape is watching your moves curiously with its\n"+
"red eyes.  It has featherless wings that looks like giant bat wings.\n"+
"The monkey is wearing funny dark boots in its feet, while a thick\n"+
"brown hair covers most of its body.\n"+NORM);
}
ape4(){

move_object(clone_object("/players/coldwind/desert/armor/gring.c"),this_object());
init_command("wear ring");

set_long(
"  A strong looking ape is watching your moves curiously with its\n"+
"red eyes.  It has featherless wings that looks like giant bat wings.\n"+
"The monkey is wearing blue fingerless gloves, while a thick brown\n"+ 
"hair covers most of its body.\n"+NORM);
}
ape5(){
move_object(clone_object("/players/coldwind/desert/armor/gcloak.c"),this_object());
init_command("wear belt");
set_long(
"  A strong looking ape is watching your moves curiously with its\n"+
"red eyes.  It has featherless wings that looks like giant bat wings.\n"+
"Blue belt covers its waist, while a thick brown hair covers most \n"+
"of the body.\n"+NORM);
}
ape6(){
move_object(clone_object("/players/coldwind/desert/armor/gshield.c"),this_object());
init_command("wear shield");

set_long(
"  A strong looking ape is watching your moves curiously with its\n"+
"red eyes. It has featherless wings that looks like giant bat wings.\n"+
"The ape is holding a dark shield with its left arm, while a thick\n"+
"brown hair covers most of its body.\n");
}