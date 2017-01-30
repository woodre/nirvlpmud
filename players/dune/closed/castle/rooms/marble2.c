inherit "room/room";
#include "definitions.h"


reset(arg)
{
  if (!arg)
  {
    set_light(1);
    short_desc=("Marble Halls of Lothlorien");
    long_desc=
"     You are in the Marble Halls of Lothlorien. As you pass along\n"+
"the pillars of marble, you hear singing echoed through the halls:\n"+
"\n"+
"     ...so the world goes round and round\n"+
"     with all you ever knew-\n"+
"     They say the sky high above\n"+
"     is Caribbean blue...\n"+
"\n"+
"     ...if all you told was turned to gold,\n"+
"     if all you dreamed were new,\n"+
"     imagine sky high above\n"+
"     in Caribbean blue...\n"+
"                                                 Enya\n";

    dest_dir=({
"room/church.c","north"  ,
    });

    items=({
"halls", "     The Marble Halls shine with white blury light",
"marble","     The Marble Halls shine with white blury light",
    });
  }
}
