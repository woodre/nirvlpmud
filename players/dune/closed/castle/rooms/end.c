inherit "room/room";
#include "definitions.h"


reset(arg)
{
  if (!arg)
  {
    set_light(1);
    short_desc=("Marble Halls of Lothlorien");
    long_desc=
"     You see white light all around you. As your eyes adjust, you\n"+
"realize you are surrounded by etherial beauty. You are in the\n"+
"Marble Halls of Lothlorien. The souls of the Sithi that you saved\n"+
"are all around you. They greet and thank you. As you walk along the\n"+
"white halls, more and more Sithi come to kneel before you.\n"+
"     Though all the Sithi are dead, their race destroyed, they may\n"+
"now spend eternity in a better place.\n"+
"You have saved them all from their magical prison. You have found\n"+
"the lost Sithi cities and have learned the secret of the stones.\n"+
"You are a true hero.\n\n";

    dest_dir=({
CASTLEROOM+"/marble1.c","north"  ,
    });

    items=({
"halls", "     The Marble Halls shine with white blury light",
"marble","     The Marble Halls shine with white blury light",
"sithi", "     They are beautiful spirits, awaiting their ascention",
    });
  }
}
