inherit "obj/armor";
#include "/players/zeus/closed/ansi.h"
int a;
object nmy;

reset(arg){
   ::reset(arg);
   if(arg) return;

   set_name("desert cloak");
   set_alias("cloak");
   set_short(YEL+"Cloak of the Desert"+NORM);
   set_long(
"This magical cloak seems to be made of sand.  It is unclear exactly how\n"+
"the cloak maintains its form, but it is quite beautiful to behold.  The\n"+
"length of the cloak flutters gently in the wind.  Looking closely, you\n"+
"can actually make out the individual particles of sand which make up the\n"+
"cloak as they shift around.  This is truly a magical piece of armor.\n");
   set_type("cloak");
   set_ac(1);
  set_params("magical",1,0,0);
  set_params("other|fire",0,10,0);
  set_params("other|ice",0,-10,0);
   set_weight(1);
   set_value(3120);
   set_arm_light(1);
   set_params("other|earth",5,35,"glimmer"); /* +5 ac, -35% dmg */
}

id(str){ return (::id(str) || str == "desert cloak"|| str == "zeus_inculta_q_cloak"); }

query_save_flag(){  return 0; } /* storable */
query_dest_flag(){  return 0; } /* doesn't dest */

glimmer(object owner)
{
  if(!owner) return;
  tell_object(owner,
    HIY+"\nThe sands expand around you in a glimmer of light!\n\n"+NORM);
}

do_special(owner){
  if(!owner || !owner->query_attack()) return 1;
  if(!owner->is_player()) return 1;
  if(owner->query_ac() < 7 && owner->query_attrib("int") > random(70))
  {
    a = random(7);
    switch(a)
    {
    case 0:
      tell_object(owner, YEL+
        "The sands whip around your body.\n"+NORM);
      tell_room(environment(owner), YEL+
        "Sands whip around "+owner->query_name()+"'s body.\n"+NORM,
        ({ owner }));
      owner->add_spell_point(4);
      break;
    case 1:
      tell_object(owner, YEL+
        "The sands suddenly surge across your body.\n"+NORM);
      tell_room(environment(owner), YEL+
        "Sands suddenly surge across "+owner->query_name()+"'s body.\n"+NORM,
        ({ owner }));
      owner->heal_self(2);
      break;
    case 2:
      tell_object(owner, HIY+
        "Your cloak explodes in a burst of bright light.\n"+NORM);
      tell_room(environment(owner), HIY+owner->query_name()+
        "'s cloak explodes in a burst of bright light.\n"+NORM,
        ({ owner }));
      owner->heal_self(1+random(3));
      break;
    case 3:
      tell_object(owner, HIY+
        "The particles of sand glow with a magical light.\n"+NORM);
      tell_room(environment(owner), HIY+
        "The particles of sand around "+owner->query_name()+
        " glow with a magical light.\n"+NORM, ({ owner }));
      break;
    case 4:
      tell_object(owner, HIY+
        "Your cloak radiates with a soft aura of light.\n"+NORM);
      tell_room(environment(owner), HIY+owner->query_name()+
        "'s cloak radiates with a soft aura of light.\n"+NORM,
        ({ owner }));
      break;
    case 5:
      if((nmy = (object)owner->query_attack()))
      {
        if(present(nmy, environment(owner)))
        {
          tell_object(owner, YEL+
            "Sands whip out from your cloak and lash into "+
            nmy->query_name()+"!\n"+NORM);
          tell_room(environment(owner), YEL+
            "Sands whip out from "+owner->query_name()+"'s cloak "+
            "and lash into "+nmy->query_name()+"!"+NORM+"\n", ({ owner }));
          nmy->hit_player(15, "other|earth");
        }
      }
      break;
    case 6:
      tell_object(owner, YEL+
        "Sands rush across your body as you fight.\n"+NORM);
      tell_room(environment(owner), YEL+
        "Sands rush across "+owner->query_name()+"'s body as "+
        owner->query_pronoun()+" fights.\n"+NORM, ({ owner }));
      owner->add_hit_point(4);
      break;
    }
    return 1+random(2);
  }
  else if(owner->query_ac() > 6 && !random(10))
  {
    tell_object(owner,
      "Your cloak flutters in the wind gracefully.\n");
    tell_room(environment(owner), owner->query_name()+
      "'s cloak flutters in the wind gracefully.\n", ({ owner }));
  }
  return 0; 
}

