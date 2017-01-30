#include "/players/coldwind/define.h"
inherit "/players/vertebraker/closed/std/monster.c";
#define attacked (this_object()->query_attack())
#define atn capitalize(attacked->query_name())

reset(arg)  {

  ::reset(arg);
  if(arg) return;
  
    move_object(clone_object("/players/coldwind/desert/weapons/claws.c"),this_object());
init_command("wield claws");
set_name("ape");
set_alt_name("windged ape");
set_alias("guard");
set_race("ape");
set_short(HIK+"Winged Ape"+NORM);
set_level(17);
set_hp(350);
set_al(-700);
set_gender("male");
set_wc(24);
set_ac(14);
set_wander(30 + random (200), 0);
set_ac_bonus(1);
set_aggressive(0);
set_chat_chance(3);
  load_chat("The winged ape takes an offensive stand...\n");
  load_chat(HIY+"Yellow eyes stare at you.\n"+NORM);
  load_chat("The ape makes a threatening sound as it knocks on it's chest.\n");
set_a_chat_chance(10);
  load_a_chat("The ape parries your attack.\n");
  load_a_chat("The ape scratches your arm!\n");
  load_a_chat(HIR+"The ape bites your neck!\n"+NORM);
  load_a_chat("The winged ape jumps back in agony...\n");

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
move_object(clone_object("/players/coldwind/desert/armor/amulet.c"),this_object());
init_command("wear amulet");
set_long(
"  A strong looking ape is watching your moves curiously with its\n"+
"red eyes.  It has featherless wings that looks like giant bat wings.\n"+
"Silver chains cover its neck, while a thick brown hair covers most\n"+
"of its body.\n"+NORM);
}

ape2(){
move_object(clone_object("/players/coldwind/desert/armor/helmet.c"),this_object());
init_command("wear helmet");

set_long(
"  A strong looking ape is watching your moves curiously with its\n"+
"red eyes. It has featherless wings that looks like giant bat wings.\n"+
"Silver helm covers its head, while a thick brown hair covers most\n"+
"of its body.\n"+NORM);
}
ape3(){
move_object(clone_object("/players/coldwind/desert/armor/boots.c"),this_object());
init_command("wear boots");

set_long(
"  A strong looking ape is watching your moves curiously with its\n"+
"red eyes.  It has featherless wings that looks like giant bat wings.\n"+
"The winged ape is wearing funny dark boots in its feet, while a thick\n"+
"brown hair covers most of its body.\n"+NORM);
}
ape4(){

move_object(clone_object("/players/coldwind/desert/armor/ring.c"),this_object());
init_command("wear ring");

set_long(
"  A strong looking ape is watching your moves curiously with its\n"+
"red eyes.  It has featherless wings that looks like giant bat wings.\n"+
"The winged ape is wearing blue fingerless gloves, while a thick brown\n"+ 
"hair covers most of its body.\n"+NORM);
}
ape5(){
move_object(clone_object("/players/coldwind/desert/armor/cloak.c"),this_object());
init_command("wear belt");
set_long(
"  A strong looking ape is watching your moves curiously with its\n"+
"red eyes.  It has featherless wings that looks like giant bat wings.\n"+
"Blue belt covers its waist, while a thick brown hair covers most \n"+
"of the body.\n"+NORM);
}
ape6(){
move_object(clone_object("/players/coldwind/desert/armor/shield.c"),this_object());
init_command("wear shield");

set_long(
"  A strong looking ape is watching your moves curiously with its\n"+
"red eyes. It has featherless wings that looks like giant bat wings.\n"+
"The ape is holding a dark shield with its left arm, while a thick\n"+
"brown hair covers most of its body.\n");
}
