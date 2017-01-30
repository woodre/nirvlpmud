inherit "room/room";
#include "definitions.h"


reset(arg)
{
  if(!arg)
  {
    set_light(1);
    short_desc=("Enki-o Shao'saye");
    long_desc=
"     The vast ruins of lost Enki-o Shao'saye rest before you. Huge white\n"+
"carved stones lie scattered like spilt rice upon the rain forest floor.\n"+
"The only intact piece of Shao'saye left is a large diagram in the center\n"+
"of the ruins.\n";

    dest_dir=({
CASTLEROOM+"/forestpath1.c","leave"  ,
CASTLEROOM+"/diagram.c","diagram"  ,
    });

    items=({
"ruins",  "     Enki-o Shao'saye used to be the mightiest of Sithi cities",
"stones", "     The stones are broken pieces of building",
"block",  "     In the center of the block, you see an imprint of a hand",
"diagram","     The diagram measures 40 feet in diameter",
    });
  }
}
