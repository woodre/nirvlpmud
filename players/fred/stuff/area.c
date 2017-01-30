#include <ansi.h>
#define FILE "/open/info/fred.nfo"


void reset(status arg)
{
  if(arg){ destruct(this_object()); return; }

  write_file(FILE,
    BOLD+"--- CRaZed FoReSt ---"+NORM+"\n"+
    "Venture into the forest to find some strange creatures!\n"+
    "Be amazed by the squirrels with parachutes, archer monkeys,\n"+
    "and of course giant ferrets!  This area is intended for mid\n"+
    "to high lvl players.  Proceed with caution as it can be an\n"+
    "unfriendly place.\n\n");
  write_file(FILE,
    BOLD+RED+"--- South Park ---"+NORM+"\n"+
    "That's right welcome to South Park.  Come and visit all the\n"+
    "characters you know and have grown to love!  This area is\n"+
    "intended for low lvl players.  Have fun.\n\n");
  write_file(FILE,
    BOLD+YEL+"From green: 6w, 3s, 4w, 4s, 10w, enter hole"+NORM+"\n");
}
