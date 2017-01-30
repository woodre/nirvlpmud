inherit "room/room";
#include <ansi.h>


int i, b, c, d;


reset(arg)
{

  if (!present("aerial servant"))
  {
    b = random(2)+1;
    for(i = 1; i<=b; i++)
     move_object(clone_object("/players/dune/monsters/airservant.c"),
       this_object());
  }

  if (!present("air elemental"))
  {
    c = random(2)+1;
    for(d = 1; d<=c; i++)
     move_object(clone_object("/players/dune/monsters/airelement.c"),
       this_object());
  }

  if(!arg)
  {
    set_light(1);
    short_desc="Air";
    long_desc=
HIW+
" ..       .....             ....     ..........        \n"+
"  .......{    }.........    ,  ..... {         }  ,,,,,\n"+
"  {         }{          }     {     } `````````......  \n"+
"   ```{       }```````````  {          }     {       } \n"+
"   ...````````     ...      ````````````      ```````` \n"+
"         ..              ..     ,,         ..          \n"+OFF+
"     You are on the walkway of air. Raging winds and\n"+
"swirling clouds surround you. The only thing you can\n"+
"see is the walkway in front of you.\n";

    items=({
 "walkway", "The wide walkway is made of ruby",
 "clouds","The white and gray clouds swarm overhead",
 "winds","The winds push you every which way along the walkway",
    });

    dest_dir=({
 "/players/dune/room/air4.c","south",
 "/players/dune/room/air2.c","west",
    });
  }
}


realm() { return "NT"; }
