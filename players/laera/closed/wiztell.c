#include "/players/wocket/closed/ansi.h"
inherit "/players/wocket/std/wiztell.c";

reset(arg){
  if(arg) return;
  owner = "laera";
  cap_owner = "Laera";
color = MAG;
  extra_look = "Laera's eyes sparkle with a glint of pure heaven";
}
