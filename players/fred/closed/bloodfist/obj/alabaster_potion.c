inherit "/obj/treasure.c";
#include "/players/fred/ansi.h"
int duration, dmg;
object nmy;

reset(arg){

  duration = 7;
  set_id("potion");
  set_alias("alabaster potion");
  set_short(HIY+"An Alabaster Potion"+NORM);
  set_long(
"  This clear potion is contained within a tinted yellow bottle.  It\n"+
"glows with a soft, white, cleansing aura that feels warm to the touch.\n"+
"Drinking this will either heal you or prevent you from taking damage.\n");
  set_weight(1);
  set_value(1430);
}

drop(){ if(!local_weight) return 1; return 0; }
id(str){ if(local_weight) return (::id(str)); else return "invis_ala_pot"; }
query_save_flag(){ return 1; }

void init(){
  ::init();
  add_action("use", "drink");
}

status use(string str)
{
  if(!present(this_object(), this_player())) return 0;
  if(str != "potion" && str != "alabaster" && str != "alabaster potion")
    return 0;
  write(HIY+
    "You pour the contents of the alabaster potion down your throat.\n"+
    "A warmth flows through your body as the potion takes effect.\n");
  say(HIY+this_player()->query_name()+" drinks an alabaster potion.\n"+NORM);
  local_weight = 0;
  short_desc = 0;
  long_desc = 0;
  this_player()->recalc_carry();
  set_heart_beat(1);
  return 1;
}

void heart_beat()
{
  if(!environment()) return;
  if(!environment()->is_player()) return;
  if((nmy = (object)environment()->query_attack())
    && present(nmy, environment(environment()))) /* prevent damage */
  {
    dmg = (int)environment()->query_dam_taken_this_round();
    if(dmg > 0)
    {
      tell_object(environment(), 
        HIY+"Pain is cleansed from your body.  "+dmg+"\n"+NORM);
      tell_room(environment(environment()), HIY+
        "Pain is cleansed from "+environment()->query_name()+"'s body.\n"+NORM,
        ({ environment() }));
      environment()->add_hp(dmg);
    }
  }
  else if(environment()->query_hp() < environment()->query_mhp()) /* heal */
  {
    tell_object(environment(),
      HIY+"You feel a healing warmth within your chest.\n"+NORM);
      tell_room(environment(environment()), HIY+
        environment()->query_name()+" glows with a healing warmth.\n"+NORM,
        ({ environment() }));
    environment()->add_hp(30);
  }
  duration--;
  if(duration <= 0)
  {
    tell_object(environment(),
      HIY+"\nThe effect of the alabaster potion fades away...\n\n"+NORM);
      tell_room(environment(environment()), HIY+
        "The effect of "+environment()->query_name()+
        "'s alabaster potion fades away...\n"+NORM, ({ environment() }));
    destruct(this_object());
    return;
  }
}
