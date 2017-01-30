#include "/players/puppy/define.h"
inherit "/obj/monster";

reset(arg)  {
   ::reset(arg);
   if(arg) return;
   
   set_name("sassette");
   set_alt_name("smurf");
   set_short(""+CYN+"Sassette"+NORM+"");
   set_race("smurf");
   set_long(
      "Sassette was created by the Smurflings to keep Smurfette\n"+
      "company.  She has red pig tails and freckles all over her\n"+
      "face.  She is a very curious thing and is always asking\n"+
      "questions like: How come? and For why?\n");
   set_level(3);
   set_hp(60);
   set_wc(4);
   set_ac(3);
   set_al(20);
   set_chat_chance(10);
   set_a_chat_chance(7);
   load_chat("Sassette says: How come the sky is blue?\n");
   load_chat("Sassette says: Do you know where Smurfette is?\n");
   load_a_chat("Sassette says: Why are you being so mean to me?\n");
   load_a_chat("Sassette says: I'm going to tell on you.\n");
   load_a_chat("Sassette says: Do you know how much this hurts?\n");
   load_a_chat("Sassette says: I'm going to start to cry if you keep this up.\n");
   
}
