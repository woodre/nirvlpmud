/*  Added cosmetic changes 8/16/02 - Eurale  */

inherit "obj/armor";
#include "/open/ansi.h"
reset(arg){
   ::reset(arg);
   set_name("dragon helm");
   set_alias("helm");
   set_short(BOLD+"H"+HIR+"elm of "+NORM+BOLD+"R"+HIR+"anzarak"+NORM);
   set_long("One of the legendary helmets of the lost dragon lords.\n"+
           "The helmet has been carved from the bones of an ancient\n"+
           "red dragon, and is inlaid with silver runes of enchantment.\n"+
           "Beware the power of the dragon lords!\n");
   set_type("helmet");
   set_ac(2);
   /* Protection from the elements
      Added by Illarion 2 Dec 2004 */
   set_params("other|fire",0,15,"element_emote");
   set_params("other|ice",0,15,"element_emote");
   set_params("other|wind",0,15,"element_emote");
   set_params("other|earth",0,15,"element_emote");
   set_weight(2);
   set_value(2000);
}

init() {
  ::init();
  if (environment() && living(environment(this_object())) && environment(this_object())->is_player())
    call_out("dragon_talk",120);
}

dragon_talk()  {
int chance;
string chat;
object ob;

  while(remove_call_out("dragon_talk") != -1);
  ob = environment(this_object());
  if(!ob) return 1;
  if (living(ob) && ob->is_player()) {
    if(random(10) > 6)  {
      chance = random(8);
      if(chance == 0) chat = RED+"You feel a strange power invade your mind and scan your thoughts"+NORM;
      if(chance == 1) chat = RED+"You hear the flapping of mighty wings"+NORM;
      if(chance == 2) chat = RED+"You see the brief image of a dragon before you"+NORM;
      if(chance == 3) chat = RED+"You feel a cold wind race past your skin"+NORM;
      if(chance == 4) {  chat = RED+"Feelings of ancient power surge through you, and then are gone"+NORM;  environment(this_object())->heal_self(random(10));  }
      if(chance == 5) chat = RED+"You feel a yearning for dragon gold"+NORM;
      if(chance == 6) chat = RED+"Lightning flashes overhead"+NORM;
      if(chance == 7) {  chat = RED+"The power of the dragon lords saps your strength"+NORM;
            environment(this_object())->heal_self(-random(10));
          }
      tell_object(ob, chat+".\n");
    }
    call_out("dragon_talk",random(280));
    return 1;
  }
}
element_emote() {
  if(!random(5) && environment()) tell_object(environment(),
"You sense your helmet protecting you from the elements.\n");
}
