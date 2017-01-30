/*
// [2005.06.22] Forbin
//   -Rewritten so it would work when player is casting other spells
//   -Fixed the id so embrace.h present check works correctly
// [2005.06.25] Forbin
//   -removed LastCasting/Casting variables and intalled Tick variable
//    instead - maybe it'll work now (who knows)
*/

inherit "/obj/treasure.c";
#include "../all.h"

int Embraced, Duration;
int Tick;
object Caster, Shadowee;

void reset(int arg)
{
  if(arg) return;

  set_weight(0);
  set_heart_beat(1);
  Tick = 4;
  Embraced = 0;
  Duration = 20+random(11);
}

id(str) { return str == "shadow_embrace_object"; }

status get()  { return 0; }
status drop() { return 0; }

void set_objects(object a, object b) { Caster = a; Shadowee = b; }

void extra_look()
{
  if(ENV->is_npc())
  {
    if(Embraced)
      return BOLD+BLK+(string)ENV->QN+BOLD+BLK+" is embraced by shadows"+NORM; 
    else
      return BOLD+WHT+"Shadows pour into "+(string)ENV->QN+BOLD+WHT+"."+NORM; 
  }
}

void heart_beat()
{
  int dmg, amt;
  object nmy, gob;
  
  nmy = environment();
  
  if(!nmy || !environment(nmy) || !living(nmy))
  {
    destruct(this_object());
    return; 
  }
  
  if(!Caster || !Shadowee) return;
  
  if(!(gob = present("circle_object", Caster)))
  {
    destruct(this_object());
    return;
  } 
  
  if(!Embraced)
  {  	
  	if(!random(2))
      tell_room(environment(nmy), 
        BOLD+BLK+"Shadows pour into "+(string)nmy->QN+BOLD+BLK+"!\n"+NORM);  	
  	
    if(Tick > 0) Tick --;

    dmg = (int)Caster->query_dam_taken_this_round();
    amt = ((dmg * (20+random(11))) / 100);
    
    if(!present(Caster, environment(nmy)))
    {
      gob->interrupt_casting(1);
    }
    
    if(dmg > 55+random(31))
    {
      tell_object(Caster, 
        "\n"+(string)nmy->QN+" knocks you back disrupting your embrace!\n\n");
      tell_room(environment(nmy), 
        "\n"+(string)nmy->QN+" knocks "+(string)Caster->QN+" off of "+
        ((string)nmy->query_gender() == "male" ? "him" : "her")+"!\n\n", ({ Caster }));
      gob->interrupt_casting(1);
      destruct(this_object());
      return;
    }
    if(Tick == 0) 
    {
      tell_object(Caster,
        BOLD+BLK+"\n\tYou step away from "+(string)nmy->QN+BOLD+BLK+"...\n\t"+
        (string)nmy->QN+BOLD+BLK+" has been embraced by the shadows!\n\n"+NORM);
      tell_room(environment(nmy), 
        "\n\t"+BOLD+BLK+(string)Caster->QN+" steps away from "+(string)nmy->QN+BOLD+BLK+"...\n\t"+
        (string)nmy->QN+BOLD+BLK+" has been embraced by the shadows!\n\n"+NORM, ({ Caster }));
      Embraced = 1;
    }  
  }
  if(Embraced)  
  {
    if(nmy->query_attack())
      Shadowee = (object)nmy->query_attack();  
    if(Duration <= 0 || ((int)gob->query_endurance() < 0 && !random(5)) ||
       (!present(Caster, environment(nmy)) && !random(3)))
    {
      tell_room(environment(nmy), 
        BOLD+BLK+"\n"+(string)nmy->QN+BOLD+BLK+
        " breaks free from the embrace of the shadows!\n\n"+NORM);
      destruct(this_object());
      return;
    }
    dmg = (int)Shadowee->query_dam_taken_this_round();
    if(dmg > 20+random(11))
    {
      amt = ((dmg * (20+random(11))) / 100);
      nmy->hit_player(amt, "other|mental");
      Shadowee->add_hit_point(amt);
      tell_room(environment(nmy), 
        "\n"+BOLD+(string)nmy->QN+" screams as the "+BLK+"shadows"+WHT+" tear apart "+
        (string)nmy->query_possessive()+" mind!\n"+NORM);
      if(gob)
      {
        gob->add_endurance(-(1+random(3)));
        if(!random(3))
          Duration--;
      }
      else
        Duration--;
    }
  }
}
