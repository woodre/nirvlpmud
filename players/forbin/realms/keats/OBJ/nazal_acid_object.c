#include "/players/forbin/realms/keats/keatsdefine.h"

inherit "obj/treasure";

int Time;

void reset(int arg) 
{
  if(arg) return;
  SetMultipleIds(({"nazal_acid_object","acid"}));
  Time = 5;
}

void add_time() { Time += 5; }

void init() 
{
   ::init();
   remove_call_out("call_acid_burn");
   call_out("call_acid_burn", 3);
}

int call_acid_burn() 
{
   object burnee;
   burnee = environment(this_object());
   if(!living(burnee)) 
     return 1;
   switch(random(2)) 
   {
      case 0: 
        tell_object(burnee,
          "Your skin sizzles from the acid arrow residue.\n");
        break;
      case 1:  
        tell_object(burnee,
          "You cry out in pain as your skin burns from the acid arrow.\n");
        tell_room(environment(burnee),
          (string)burnee->query_name()+" cries out in pain.\n", ({ burnee}));
        break;
   }
   burnee->hit_player(5 + random(20), "other|poison");
   Time--;
   if(!Time) 
   {
     tell_object(burnee,
       HIG+"\n\tYou feel the effects of the acid residue fade.\n\n"+NORM);
     destruct(this_object());
     return 1; 
   }
   else 
     call_out("call_acid_burn", 3+random(4));
   return 1; 
}

drop() { return 1; }
