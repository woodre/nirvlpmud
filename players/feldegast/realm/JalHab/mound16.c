#include "defs.h"

inherit MNDROOM;

int peeps;

void reset(int arg) 
{
  int i;
  if(!arg)
  {
    short_desc=RED+"The Myrmidar Mound"+NORM;
    long_desc=
"  The ceiling of this cavern is so high that you can't quite make it\n\
out.  The air in here is unusually warm and humid.  Two tunnels lead\n\
out of it in opposite directions.  A deep pit, roughly ten meters in\n\
diameter is on the far side of the cavern.  A thin ledge spirals down\n\
inside it and into the darkness.\n";
    items=({
      "ceiling", "You can't quite make it out.  It is too dark",
      "tunnels", "The tunnel to the south appears to be much larger\n"+
                 "than the one to the north",
      "pit", "The pit is roughly ten meters in diameter and descends into\n"+
             "darkness.  A ledge spirals down inside it",
      "ledge", "It is a couple of feet wide and spirals down into the darkness",
    });
    dest_dir=({
      PATH+"mound15.c","southwest",
      PATH+"mound17.c","northwest",
      PATH+"mound19.c","down",
    });
  }
  for(i=random(3)+1; i > 0; i--)
    move_object(clone_object(MON_PATH+(random(2)?"myrm-warrior":"myrm-worker")),this_object());
  if(!random(2)) move_object(clone_object(MON_PATH+"myrm-leader"),this_object());
}

void init() 
{
  ::init();
  if(this_player()->is_player()) 
    peeps++;
  if(!peeps) call_out("breathing",5);
}

void exit() 
{
  peeps--;
  if(peeps <= 0) while(remove_call_out("breathing")!=-1) ;
}

void breathing()
{
 /* present() check fixed by Vertebraker [5.25.01] */
  object ob;
  while(remove_call_out("breathing")!=-1) ;
  ob = find_object(PATH + "mound20.c");
   if(!ob)
   {
     (PATH + "mound20.c")->load_me();
      ob = find_object(PATH + "mound20");
   }
   if(present("queen", ob))
    tell_room(this_object(),
"You hear a raspy breathing sound as a gust of air rises up out of the pit.\n");
  call_out("breathing",10+random(30));
}
