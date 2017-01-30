#include "/players/fred/ansi.h"
inherit "/players/vertebraker/closed/std/room";
inherit "/players/earwax/housing/land";

reset(int arg)
{
   if(arg) return;
   set_light(1);
   set_short("South Park");
   set_long(
      "  The town is ever more run down to the north of town.  Garbage is\n"+ 
      "scattered all around on the side of the street.  There is an old rusted\n"+
      "out car and truck that seems to have just been abandoned here.  Way off\n"+
      "to the north there is an open gate with a large sign above it.\n");

   add_item("garbage","Nasty old garbage....don't people pick up stuff around here?");
   add_item("street","A run down street.  Old empty shops line either side");
   add_item("car","Is that pinto?");
   add_item("truck","You notice a \"Keep Honking....I'm reloading\" bumper sticker plastered\n"+
            "on the back window next to a Nascar sticker");
   add_item("gate","A large metal gate that is swung open");
   add_item("sign","You squint to try to read it but you can't quite make it out yet");
   add_smell("main","You take a deep breath and start to cough.....");
   add_listen("main","You hear a loud gunshot followed by someone yelling, \"Woooo eeee!!!!\".");
   add_exit("/players/fred/SP/Rooms/r5.c","south");
   add_exit("/players/fred/SP/Rooms/r19.c","north");
}
