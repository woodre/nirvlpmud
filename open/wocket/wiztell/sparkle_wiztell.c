#include "/players/wocket/closed/ansi.h"
inherit "/players/wocket/std/wiztell.c";

reset(arg){
  if(arg) return;
  owner = "sparkle";
  cap_owner = "Sparkle";
  color = MAG;
  extra_look = "Paid for by the Sparkle's Quest for Innocence Foundation Fund";
}
