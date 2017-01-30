#include "/players/maledicta/ansi.h"
inherit "room/room";


long(str) {
    int i;
    if ((set_light(0) <= 0) && !present("dark_sight_object", this_player())) {
       write("It is dark.\n");
       return;
    }
	write(HIW+" ["+capitalize(short_desc)+NORM+"]\n\n"+long_desc+"\n\n");
}
init(){
 ::init();
  if(this_player()) /* added by verte */
  this_player()->set_fight_area();
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
