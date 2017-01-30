#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */
inherit "/players/wocket/std/wiztell.c";

reset(arg){
  if(arg) return;
  owner = "angel";
   cap_owner = "Angel";
  color = HIC;
  extra_look = "Angel is learning new things";
}
