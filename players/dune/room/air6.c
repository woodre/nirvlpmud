inherit "room/room";
#include <ansi.h>


reset(arg)
{
  if(!present("Modron"))
  {
    move_object(clone_object("/players/dune/monsters/modron.c"),
      this_object());
  }

  if(!arg)
  {
    set_light(1);
    short_desc="Air lord";
    long_desc=
HIW+
" ..       .....             ....      ...              \n"+
"  ....    {    }......       ,,,,,,   { }         ,,,,,\n"+
"           {          }     {     }            ..{    }\n"+
"            ```````````      {          }     {       }\n"+
"   ...      ..            ____```````````      ````````\n"+
"                         |    |   ..                   \n"+
"         ..      ..      |    |              ....      \n"+
"                         |    |                        \n"+
"       .                 |____|            ..          \n"+OFF+
"     The walkway ends in a rectangular platform. A fury\n"+
"of wind rushes upward from beneath. Gray clouds swirl\n"+
"like a tornado above your head.\n";

    items=({
 "walkway", "The wide walkway is made of ruby",
 "clouds","The clouds are high overhead, yet make a sort of ceiling",
 "wind","The winds cannot be felt on the platform",
 "platform","The platform is made of ruby, and is quite large",
    });

    dest_dir=({
 "/players/dune/room/air5.c","west",
    });
  }
}


realm() { return "NT"; }
