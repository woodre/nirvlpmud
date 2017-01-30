#include "/players/mizan/esc.h"

id(str) { return str == "sign"; }

short()
{
  return ESC + "[1m" + ESC + "[5m" + ESC + "[31m" + "A Blinking Neon sign" + ESC + "[25m" + ESC + "[0m";
}

long()
{
  write("This is a sign that reads:\n"+
  "You feel that if you wear a Pentagram in this cave, misfortune shall\n"+
  "soon befall you. This is the Alchie BEATING ZONE! SO BEAT IT,\n"+
  "BEFORE I BEAT YOU!\n");
}

init()
{
  add_action("readme","read");
}

readme(str)
{
   if(str && str == "sign")
   {
      long();
      return 1;
   }
}
