#include "/players/fakir/color.h"
#define tp this_player()
inherit "obj/treasure";

reset(arg)  {
  if(arg) return;

   set_id("bartowel");
   set_alias("towel");
   set_short("A wet bartowel");
   set_long("A damp bartowel used for cleaning. You can also 'snap' it. \n");
   set_weight(1);
   set_value(25);
}

init()
{  add_action("snap_bartowel", "snap");   }


snap_bartowel(str)  {

if(str=="bartowel")  {

  write("You snap the bartowel.\n "+MAGENTA+" ZZZZzzz....******`~SNAP~`******"+OFF+"\n");
  say(tp->query_name()+" snaps a bartowel.\n "+MAGENTA+" ZZZZzzz....******`~SNAP~`******"+OFF+"\n");
  return 1;   }
        }
