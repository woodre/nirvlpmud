#include "/players/novowels/ansi.h"
inherit "/players/wocket/std/wiztell.c";

reset(arg){
  if(arg) return;
  owner = "novowels";
  cap_owner = "Novowels";
  color = HIK;
  extra_look = "Novowels is spiffy";
}
