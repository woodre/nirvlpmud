#include <ansi.h>

inherit "room/room";

string rtype;

void long(string str)
{
  if ((set_light(0) <= 0) && !present("dark_sight_object", this_player())) {
       write("It is dark.\n");
       return;
    }
  write(HIC+" [ "+HIW+capitalize(short_desc)+" "+NORM+CYN+"<<"+HIW+"FrostGard"+NORM+CYN+">> "+HIC+"]"+NORM+"\n\n"+long_desc+"\n\n");
}

init(){
 ::init();
add_action("keys", "key");

  if(this_player()) /* added by verte */
if(rtype != "road"){
  this_player()->set_fight_area();
  }
if(rtype == "forest" && !random(10) &&
   !present("cont_mob", this_object())){
   move_object(clone_object("/players/maledicta/cont/mobs/forest1.c"), this_object());
   }
else if(rtype == "hills" && !random(10) &&
   !present("cont_mob", this_object())){
   move_object(clone_object("/players/maledicta/cont/mobs/foot1.c"), this_object());
   }
else if(rtype == "plain" && !random(10) &&
   !present("cont_mob", this_object())){
   move_object(clone_object("/players/maledicta/cont/mobs/plain1.c"), this_object());
   }

}

/*
Bad Form, old chap.  [verte]

exit(){ if(this_player()) this_player()->clear_fight_area(); }
*/

exit(ob)
{
     if(ob && ob->is_player())
       ob->clear_fight_area();
     else
        ::exit(ob);
}


keys(){
write("Key to the Continent of Frostgard:\n\n"+
      GRN+"#"+NORM+"      -    Glacier\n"+
      HIG+"@"+NORM+"      -    Ice sheet\n"+
      BOLD+"M"+NORM+"      -    Snow-peaked mountain(impassable)\n"+
      YEL+"n"+NORM+"      -    Icy Hills\n"+
      BLU+"~"+NORM+"      -    Water/sea(impassable)\n"+
      HIR+"- + |"+NORM+"  -    Roads(Non-pk)\n"+
      "Note: All terrains are Pk EXCEPT roads.\n\n");
return 1;
}
