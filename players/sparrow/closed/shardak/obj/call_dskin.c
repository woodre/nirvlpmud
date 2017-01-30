/*
* Dragonskin call
* by Verte 2000
*/

#include "../def.h"
#define TOU(x) if(environment()) tell_object(environment(), x);
#define TRU(x) if(environment() && environment(environment())) tell_room(environment(environment()), x, ({ environment() }));
#define USER environment()

static int call;

id(str) { return str == "call_dskin"; }

drop() { return 1; }

get()  { return 1; }

reset(x)
{
   if(x) return;
   if(!root())
   call_out("call_it",8 + random(3));
}

init()
{
   add_action("cmd_hook"); add_xverb("");
}

cmd_hook(str)
{
   if(this_player()->query_real_name() == "vertebraker") return 0;
   write(
      "You are meditating deeply and are therefore unable to perform\n"
      +"that action..  be at peace with yourself.\n");
   return 1;
}

call_it()
{
   object d;

   call += 1;
   if(call > 4)
      {
      TOU("Your master commands you to rise..   As you do, the power of\n"+
         "the ancient dragons swirl around you, and you feel at ease\n"+
         "with your powers.\n");
      TRU(USER->query_name()+" rises..  A dark efluvium circles "+possessive(USER)+" person,\n"+
         "dancing around the dark dragonscales which now decorate "+possessive(USER)+" body...\n");
      d = clone_object(OBJDIR + "dskin");
      move_object(d, USER);
      USER->RegisterArmor(d, ({ "physical", 1, 0, "do_special" }));
      USER->RegisterArmor(d, ({ "other|fire", 0, (5 + random(5)), "do_special" }));
      destruct(this_object());
      return;
   }
   else if(call > 3)
      {
      TOU("Dark energy pulses and surges around in your veins....\n"+
         "The bloodscales of the ancient dragons harden around your body,\n"+
         "forming a natural protection against physical attack.\n");
      TRU("Black scaly patches harden around "+USER->query_name()+"'s body...\n");
   }
   else if(call > 2)
      {
      TOU("You feel as if your skin is being torn apart....  the massive\n"+
         "rip and tear of the dragonskin formation is assaulting your\n"+
         "senses...  Skin around your chest ruptures and splits...\n");
      TRU("Skin around "+USER->query_name()+"'s chest ruptures and splits...\n");
      USER->hit_player(25 + random(20), "other|evil");
      if(USER->query_ghost())
         {
         destruct(this_object());
         return; }
   }
   else if(call > 1)
      {
      TOU("Something is fighting within your body, as if for control of\n"+
         "your soul..   Darkness spreads, making your body feel cold..\n"+
         "an absence of warmth spreads...\n");
   }
   else
      {
      TOU("Your vision is blurred, and images of a spectral black dragon\n"+
         "manifest into your thoughts..   Gloom spreads and shadows your\n"+
         "flesh...  A pain strikes your heart as you wince in agony...\n");
      TRU(USER->query_name()+" jerks suddenly and winces in agony...\n");
      USER->hit_player(20 + random(20), "other|dark");
      if(USER->query_ghost())
         {
         destruct(this_object());
         return;
      }
   }
    call_out("call_it", 8 + random(3));
}
