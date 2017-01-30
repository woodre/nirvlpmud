inherit "room/room";
#include "definitions.h"


reset(arg)
{
  if(!arg)
  {
    set_light(1);
    short_desc=("Marble Halls of Lothlorien");
    long_desc=
"     You are in the Marble Halls of Lothlorien. As you pass along\n"+
"the pillars of marble, you hear singing echoed through the halls:\n"+
"\n"+
"     I dreamt I dwelt in marble halls\n"+
"     with vassels and serfs at my side,\n"+
"     and of all who assembled within those walls\n"+
"     that I was the hope and the pride.\n"+
"\n"+
"     I had riches all too great to count\n"+
"     and high ancestral name\n"+
"     But I also dreamt which pleased me most\n"+
"     that you loved me still the same.\n"+
"                                                 Enya\n";

    dest_dir=({
CASTLEROOM+"/marble2.c","north"  ,
    });

    items=({
"halls", "     The Marble Halls shine with white blury light",
"marble","     The Marble Halls shine with white blury light",
    });
  }
}
