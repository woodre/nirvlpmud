mapping Reverse;

/* checks the exits to make sure they match what they link to */

#include "/players/vertebraker/ansi.h"

/*
#define Reverse ([ "north" : "south", \
                   "south" : "north", \
                   "east"  : "west",  \
                   "west"  : "east",  \
                   "northwest" : "southeast", \
                   "northeast" : "southwest", \
                   "southwest" : "northeast", \
                   "southeast" : "northwest", ])
*/


void
reset(status arg)
{
    if(arg) return;
    Reverse = ([
                   "north" : "south",
                   "south" : "north", 
                   "east"  : "west",  
                   "west"  : "east",  
                   "northwest" : "southeast", 
                   "northeast" : "southwest", 
                   "southwest" : "northeast", 
                   "southeast" : "northwest", ]);
}

status
main()
{
   int i, s, a;
   string *d, *c, f, exit;
   object load, g;

   s = sizeof(d = (string *)environment(this_player())->query_dest_dir());

   write(BOLD + "\t\tEXITS\n\n" + NORM);

   f = file_name(environment(this_player()));
   for(i = 1; i < s; i += 2)
   {
     if(exit = d[i])
     {
       if(!(load = find_object(d[i-1])))
       {
         d[i-1]->badaBing();
         load = find_object(d[i-1]);
       }
       write("\t" + capitalize(exit) + "...");
       c = (string *)load->query_dest_dir();
       if(pointerp(c))
       {
         a = member_array(Reverse[exit], c);
         if(a >= 0)
         {
           g = find_object(c[a-1]);
           if(!g)
           {
             c[a-1]->badaBing();
             g = find_object(c[a-1]);
           }
           if(environment(this_player()) == g)
             write(HIG + "Ok!\n" + NORM);
           else
             write(HIR + "No!\n" + NORM);
         }
         else
           write(HIR + "No!\n" + NORM);
       }
       else
         write(HIR + "No!\n" + NORM);
     }
   }

   return 1;
}
