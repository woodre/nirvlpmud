/* 

     Burn: Main attack spell

   Coded by Vertebraker@Nirvana (c) 2000

*/

#include "/players/vertebraker/ansi.h"
#include "../people.h"

#include "../std.h"
#include "../def.h"
#include "../tasks.h"
#include "../macros.h"

#define TP   this_player()
#define QN   query_name()
#define RN   query_real_name()
#define TPN (string)TP->QN

inherit CMD;

main(string who)
{
    int         base, cost, sub, dmg, l, bonus, my_factor, rnd_factor;
    object      x, flames, woot;
    string      g, c;

    needrank(8);
    flames = (mixed)previous_object()->query_flames();
    needtask(FLAMES_TASK);

    if((status)this_player()->query_ghost()) return 0;

    

   if(!present("shardak_fire", environment(this_player())))
   {
     write("You need flames in order to cast this spell.\n");
     return 1;
   }

   cost = 100;
   needmana(cost);

   if(!(x=TP->query_weapon()))
   {
     write("You must be wielding a weapon ..\n");
     return 1;
   }
   if(x->query_firegripped())
   {
     write(x->query_name()+" has already been firegripped.\n");
     return 1;
   }
   write("You intone a dark spell on "+x->query_name()+".\n");
   say(TP->QN+" intones a dark spell on "+x->query_name()+".\n");
   
   woot = clone_object(OBJDIR+"firegrip");
   woot->start_it(x);
   
    if(flames)
    flames->reduce_strength(1 + random(3));  
  
  TP->add_sp(-100);
 
    return 1;
}


