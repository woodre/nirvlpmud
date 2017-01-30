/* i hate everyone */

#include <ansi.h>

#define dmg 40 + random(40)

id(str) { return (str == "curse_of_the_dark_gods_348834" || str == "ND"); }

reset(x) { if(!x && !root()) call_out("bloody_sundae", 10 + random(30)); }

drop() { return 1; }

init()
{
   object x;
   if(x = environment())
     x->RegisterArmor(this_object(), ({ "physical", 0, 0, "do_special" }));
}

do_special(x)
{
   return -(random(3));
}

bloody_sundae() {
   object x;
   if((x = environment()) && living(x))
   {
     if(!random(3))
       tell_object(x, "Dark forces ripple into you...\n");
     if(!random(3))
       tell_object(x, "Power shrieks and tears over you...\n");
     if(!random(5))
       tell_object(x, "\n\t" + BLU + "Magic flares" + NORM + "\n\n");
     if(!random(3))
       tell_object(x, "\n\tSoul energy is ripped from you...\n\n");
     if(!random(3))
       tell_object(x, "Death energy funnels into you....\n");
     x->hit_player(dmg, "other|dark");
     if(!random(3))
       x->hit_player(dmg, "other|dark");
     if(!random(3))
       x->lower_attrib();
     if(!random(3))
       x->lower_attrib();
     if(!random(3))
       x->lower_attrib();
     if(!random(3))
       x->add_spell_point(-((int)x->query_spell_point()));
     if(!random(100000))
     {
       tell_object(x, "\n\tThe curse of the dark gods falls upon you, and the life streams out of your body.\n\n");
       x->death();
     }
   }
    call_out("bloody_sundae", 666 + random(666));
}

query_auto_load() { return "/players/earwax/closed/shardak/fuckoffannoyingwiz:0"; }
