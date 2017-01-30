
#include "/players/vertebraker/define.h"

string *betas;
inherit ROOM;

reset(x) {
   if(x) return;
   betas = ({ "aubergine", "pegasas", "lacar", "handy" });
   set_light(1);
   short_desc = "Stable Yard "+GRN+"["+NORM+BOLD+"Knights"+
" Templar"+NORM+GRN+"]"+NORM;
   long_desc =
   "     A tall wooden fence surrounds the hoof trodden ground on\n"+
   "which you walk.  Stalls line the wall of the stable to the east,\n"+
   "and a wide double door stands open in the center.  An old rusty\n"+
   "horse shoe is nailed above the doorway.\n";
   
   items = ({
         "fence",  "A privacy fence built of sturdy wooden slats six inches\n"+
         "wide and almost ten feet tall.  It is very sturdy",
         "ground", "Brown dirt mixed with horse-dung, straw, and sawdust",
         "door",   "The stable door is open on both sides and tied off with\n"+
         "a piece of rope",
       "shoe",   "An old horse shoe that has seen many years of rain and"+
" sun", });
   add_exit("/players/jaraxle/templar/rooms/courtyard.c","north");
add_exit("/players/jaraxle/templar/rooms/s2.c","enter");
   add_object("/players/maledicta/hope/mobs/templar_guard2");
   add_object("/players/maledicta/hope/mobs/templar_guard2");
}

init()
{
    ::init();
   add_action("enter","enter");
   add_action("other_syntax","stable");
   add_action("other_syntax","in");
   add_action("other_syntax","stables");
   this_player()->set_fight_area();
   }

exit(){    if(this_player()) this_player()->clear_fight_area();     }



other_syntax()
{
   if(!TP) return;
   command("enter",TP);
   return 1;
}

enter()
{
   if(present("templar_guard",TO) && !present("KnightTemplar",TP) &&
TP->query_level() < 21)
      {
      write("The guard steps forward and says, 'You are not invited, please"+
" leave.'\n");
      return 1;
   }
   write("  You walk through the yard to the stable....\n\n");
}

realm() { return "LA"; }



