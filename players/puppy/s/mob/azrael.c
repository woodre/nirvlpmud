#include "/players/puppy/define.h"
inherit "/obj/monster";

reset(arg)  {
   ::reset(arg);
   if(arg) return;
   
   set_short(""+YEL+"Azrael"+NORM+"");
   set_name("azrael");
   set_alt_name("cat");
   set_race("feline");
   set_long(
      "This mangy cat is Gargamel's underling. He follows Gargamel\n"+
      "around hoping someday his master will catch a nice juicy\n"+
      "Smurf for him to eat.  He is much like his master and doesn't\n"+
      "seem to understand the ways of the Smurfs.\n");
   set_level(7);
   set_hp(300);
   set_wc(8);
   set_ac(6);
   set_al(-145);
   set_aggressive(1);
   set_a_chat_chance(15);
   load_a_chat("Azrael rakes his claws against your chest.\n");
   load_a_chat("Azrael hisses at you.\n");
   load_a_chat("Azrael gets ready for a tasty treat.\n");
   
}
