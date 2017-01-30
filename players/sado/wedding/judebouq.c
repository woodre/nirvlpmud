#include "/players/sado/defines.h"

int tossed;

get() { return 1; }
drop() { return 0; }
id(str) { return str == "bouquet"; }
long() { write("A pretty bouquet of white roses.\n"); }
short() { return "A lovely bouquet"; }
init() { add_action("throw","throw"); }
reset(arg) { if(arg) return; tossed = 0; }
throw(str)
{
   if(!id(str)) return 0;
   if(tossed != 0)
   {
      write("You don't want to get rid of that!  It was a tough fight to win it!\n");
      return 1;
   }
   write("You toss the bouquet high into the air over your shoulder!\n");
   say(tp->query_name()+" tosses the bouquet high into the air over her shoulder!\n");
   tell_room(env(tp),"The bouquet goes sailing into the air.  All the unmarried women\n");
   tell_room(env(tp),"around clamber over each other in a mass, grabbing at the bouquet.\n");
   tossed = 1;
   call_out("do_zenith",2,tp);
   return 1;
}

do_zenith(p)
{
  tell_room(env(p),"The bouqet reaches the zenith of its arc, and begins to descend.\n");
  tell_room(env(p),"The unmarried women begin to jostle for position.\n");
  call_out("do_catch",2,p);
}

do_catch(p)
{
   array u,t;
   int n;
   int i,j;
   n = 0;
   u = ai(env(p));
   j = sizeof(u);
   t = allocate(j);
i=0;
u[i]=fp("esoterica");
   say(u[i]->query_name()+" leaps over the others and snatched the bouquet!\n", u[i]);
   tell_object(u[i],"You make a giant leap just as you figure the bouquet has descended enough to\n");
   tell_object(u[i],"make a grab for it.  You SUCCEED!  You caught the bouquet!  YOU GOT IT!\n");
   say(u[i]->query_name()+" jumps up and down for joy from having caught the bouquet!\n");
   move_object(this_object(),u[i]);
}
