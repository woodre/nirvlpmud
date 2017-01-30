inherit "obj/monster";
#include "/players/persephone/rooms.h"
reset (arg){
 ::reset(arg);
  if(!arg){
   object jack;
   jack = clone_object("players/persephone/armour/jackt.c");
   move_object(jack, TOB);
   init_command("wear jacket");
   set_name("punk");
   set_alias("bully");
   set_short("An Angry Looking Punk");
   set_long("A Bully Boy that enjoys picking on people weaker than him\n" +
            "you can tell by the jacket he wears he thinks he is fairly tough\n\n");
   set_level (7);
   set_wc(11);
   set_ac(5);
   set_hp(105);
   set_al(-400);
   set_aggressive(0);
   set_gender(1);
   set_chat_chance(45);
    load_chat("The Punk says: You are a real wimp\n");
    load_chat("The Punk exclaims: I could beat you with one hand tied behind my back\n");
    load_chat("The Punk states: I am tougher than you are\n");
    load_chat("Thu Punk throws dirt in your face\n");
   set_a_chat_chance(50);
    load_a_chat("The Punk pushes you over\n");
    load_a_chat("The Punk spits on you\n");
    load_a_chat("The Punk exclaims: You cannot hurt me\n");
  }
}
