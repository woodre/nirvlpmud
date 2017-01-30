#include "../defs.h"

light_damage() 
{
  int is_light;
  object lightmob;
  string msg;
  if(!environment()) return 1;
  if(!environment(environment()) || 
     environment(environment())->no_light_damage() ||
     present("no_light_damage", environment())) 
    return (call_out("light_damage", 3), 1);
  is_light = set_light(0);
  
  if(environment(this_object())->query_level() < 20 &&
    !environment(this_object())->query_ghost())    
  {
    if(is_light > 0) 
    {
      switch(random(10)) 
      {
        case 0:  msg = HIW+"The light burns you flesh...\n"+NORM; break;
        case 1:  msg = HIY+"The light burns you flesh...\n"+NORM; break;
        case 2:  msg = HIW+"Your skin sizzles from the light...\n"+NORM; break;
        case 3:  msg = HIY+"Your skin sizzles from the light...\n"+NORM; break;
        case 4:  msg = HIW+"Blisters form as you skin burns from the light...\n"+NORM; break;
        case 5:  msg = HIY+"Blisters form as you skin burns from the light...\n"+NORM; break;
        case 6:  msg = HIW+"You feel as if you are on fire...\n"+NORM; break;
        case 7:  msg = HIY+"You feel as if you are on fire...\n"+NORM; break;
        case 8:  msg = HIW+"You wince in pain as the light sears your body...\n"+NORM; break;
        case 9:  msg = HIY+"You wince in pain as the light sears your body...\n"+NORM; break;
      }
      if(msg) 
        tell_object(environment(this_object()), msg);
    }
    if(is_light < -2 &&
       environment(this_object())->query_mhp() != environment(this_object())->query_hp())
      if(!random(5))
        tell_object(environment(this_object()),
          HIK+"The darkness chills you to the core...\n"+NORM);
      if(is_light > 5) is_light = 5;
      if(is_light < -5) is_light = -5;
      if(is_light > 0) {
        if(environment(this_object())->query_interactive()) {
          if(environment(this_object())->query_hp() < (is_light * 3)) 
          {
            if(!environment(this_object())->query_attack() &&
               !environment(this_object())->query_ghost()) {
              tell_object(environment(this_object()), 
                "\n\n\tThe "+HIY+"light"+NORM+" overwhelms you.  You die.\n\n");
              lightmob = clone_object("/obj/monster.c");
              lightmob->set_name(HIY+"The light"+NORM);
              environment(this_object())->stop_fight();
              environment(this_object())->stop_fight();
              environment(this_object())->attacked_by(lightmob);
              environment(this_object())->hit_player(100000000, "other|lightdam");
              destruct(lightmob);
              return (call_out("light_damage", 3), 1);
            }
          }
          if(environment(this_object())->query_sp() < (is_light * 4))
            environment(this_object())->add_spell_point((0 - environment(this_object())->query_sp()));
          else 
            environment(this_object())->add_spell_point(-(is_light * 4));
          environment(this_object())->hit_player((is_light * 3), "other|lightdam");
        }
      }
      else 
      {
        if(environment(this_object())->query_interactive()) {
          environment(this_object())->add_hit_point(-is_light);
          environment(this_object())->add_spell_point(-is_light);
      }
    }
  }
  return (call_out("light_damage", 3), 1); 
}
