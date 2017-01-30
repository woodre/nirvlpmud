#include "/players/maledicta/ansi.h"
inherit "room/room";
string rtype;

long(str) {
    int i;
    if ((set_light(0) <= 0) && !present("dark_sight_object", this_player())) {
       write("It is dark.\n");
       return;
    }
        write(HIW+" [ "+HIW+"Far Below Hirandea"+NORM+" ]\n\n"+long_desc+"\n\n");
}
init(){
 ::init();
add_action("keys", "key");

  if(this_player()) /* added by verte */
  this_player()->set_fight_area();
}


exit(ob)
{
     if(ob && ob->is_player())
       ob->clear_fight_area();
     else
        ::exit(ob);
}


keys(){
write("Key to the Underground of Hirandea:\n\n"+
      YEL+"#"+NORM+"      -    Solid Rock\n"+
      BLU+"~"+NORM+"      -    Water/sea(impassable)\n"+
      HIW+"- + |"+NORM+"  -    Underground Tunnel\n"+
      "Note: All areas are Pk.\n\n");
return 1;
}
