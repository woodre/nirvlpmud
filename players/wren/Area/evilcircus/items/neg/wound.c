/*  Poison type object for the claw attack on D-raptor. Idea is to 
    simulate an infected injury or just jagged injury. Wanting to 
    have some extra options for dealing with it. Should increase the
    popularity of healers with an infuse check to 'close' the wound
    will need help figuring that part out though.

    Code borrowed heavily from Feldegast's Venom obj. Its a solid working 
         piece so I don't have to worry about crashing things.  

*/

#define DAMAGE (15+random(10))     /* Damage done */
#define LONGEVITY 100+random(400)  /* length, in ticks */

int duration, cnt, old_inf;

id(str) { return str=="wound"; }

reset(arg) {
  if(!arg && !root()) {
    duration=LONGEVITY;
    call_out("poison_player",1);
    old_inf=0;
  }
}

poison_player() {
  if(environment())
  {
    if((int)environment()->query_infuse() > old_inf)
    {
      object x;
      tell_object(environment(),
"Your wound closes magically.\n");
      if(x=environment(environment()))
        tell_room(x,
environment()->query_name()+"'s wound closes magically.\n",
         ({ environment() }));
      destruct(this_object());
      return;
    }
    if(++cnt == 5)
    {
      tell_object(environment(),
        "Blood and icor seep from the jagged wounds.\n");
      /* New dam type code */
      environment()->hit_player(DAMAGE, "magical");
      cnt=0;
    }
    duration--;
    if(duration <= 0)
    {
      tell_object(environment(),
       "The bleeding slows and you feel stronger.\n");
      destruct(this_object());
      return;
    }
    call_out("poison_player",1);
  }
}

drop()  { return 1; } /* Cannot drop */
get()   { return 0; } /* Cannot get */

extra_look()
{
  return environment()->query_name()+" bleeds from gaping claw marks";
}
