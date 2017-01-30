/*
 * Azlyn
 * Cloud 2009
 */
 
 
#include "/obj/ansi.h"

inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
	   
object bottle;
  bottle = clone_object("/players/cloud/Fayawyn/obj/fheal.c");
  move_object(bottle,this_object());
  

     set_name("azlyn");
     set_alt_name("catcher");
     set_alt_name("kobold");
     set_short(""+HIK+"Azlyn "+HIR+"the Fairy Catcher"+NORM+"");
     set_race( "kobold");
     set_gender("male");
     set_long(
     "Small, golden scales plate this kobold's body from head \n" +
     "to toe. He has brightly-glowing orange eyes and a long\n" + 
     "lizard-like tail. Although unclothed, he wears a necklace\n" +
     "of bells around his neck that jingles when he moves.\n");
     
     set_level(20);
     set_ac(21);
     set_wc(30 + random(3));
     set_hp(800);
     set_al(-500);
     set_aggressive(0);
     set_chat_chance(3);
     load_chat("Azlyn grabs a fairy from within the cage and swallows it whole.\n");
     load_chat("Azlyn says, \"Ever since Ekimmu took over this village, things have been great.\"\n"); 
   }
}
heart_beat()
{
  ::heart_beat();
  if(!environment()) return;
  if(attacker_ob && present(attacker_ob, environment(this_object())))
  {
    if(random(200) > 160) kobold_heal();

  }
}

kobold_heal()
{
    tell_room(environment(),
      ""+HIR+"\n\t"+query_name()+" takes a fairy from the cage and eats it, healing himself."+NORM+"\n\n");

    this_object()->add_hit_point(25 + random(30));

}
