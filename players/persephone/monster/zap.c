inherit "obj/monster";
#include "/players/persephone/rooms.h"
reset (arg){
 ::reset(arg);
  if(!arg){
   object speck;
   speck = clone_object("players/persephone/armour/shades.c");
   move_object(speck, TOB);
   init_command("wear shades");
   set_name("zapphod");
   set_alias("frood");
   set_short("Zapphod Beeblebrox");
   set_long("The king of froods himself the hippest dude in the\n" +
            "universe he always knows where his towel is yes it is\n" +
            "the Zapphod Beeblebrox\n");
   set_level (5);
   set_wc(8);
   set_ac(4);
   set_hp(105);
   set_al(0);
   set_aggressive(0);
   set_gender(1);
   set_chat_chance(45);
    load_chat("Zapphod asks: So where is the party?\n");
    load_chat("Zapphod says: I am so cool you could freeze a side of beef\n");
    load_chat("Zapphod asks: So where are the girls?\n");
    load_chat("Zapphod says: Froody get up dude.\n");
   set_a_chat_chance(50);
    load_a_chat("Zapphod exclaims: Hey I cannot be attacked\n");
    load_a_chat("Zapphod asks: Do you know who I am?\n");
    load_a_chat("Zapphod exclaims: I am the President of the Galaxy stop!!\n");
  }
}
