#include "/players/coldwind/define.h"
inherit "obj/monster.c";
#define attacked (this_object()->query_attack())
#define atn capitalize(attacked->query_name())


reset(arg)  {
  ::reset(arg);
  if(arg) return;
move_object(clone_object("/players/coldwind/desert/weapons/ball.c"),this_object());
init_command("wield weapon");
move_object(clone_object("/players/coldwind/desert/armor/witch_hat.c"),this_object());
init_command("wear hat");
set_name("ashgan");
set_alt_name("witch");
set_short(HIK+"Ashgan the witch"+NORM);
set_long(HIK+
"  Dressed all in black, the ugly witch stands before you. Her wicked smile\n"+ 
"and features reveal her evil nature. A dark gray aura surrounds her and souls \n"+
"of her preys appear in a lighter gray in the field of the aura and vanish.\n"+
"Ashgan holds a small crystal ball in her right hand, while reading from a black\n"+
"book that she carries with her left.\n"+NORM);
set_level(24);
set_hp(900);
set_al(-1000);
set_gender(0);
set_wc(45);
set_ac(30);
set_ac_bonus(1);
set_aggressive(0);
set_chat_chance(5);
  load_chat("Ashgan whispers a dark prayer.\n");
  load_chat("You take a step to the back.\n");
  load_chat("The witch cackles madly...\n");
}

heart_beat(){
 int blah;
 blah = random(100);
  :: heart_beat();
    if(!environment()) return;
    if(!attacked) return;
     if(blah > 80){
       woo(); }
  }

woo(){
  tell_room(environment(attacked),
  HIK+"Ashgan holds her crystal above her head and drains "+atn+"'s\n\n"+
     ""+HIW+"                        L I F E"+NORM+"\n\n");
  attacked->heal_self(random(20)+15);
  }

query_attrib(str){ if(str == "int") return 20; }