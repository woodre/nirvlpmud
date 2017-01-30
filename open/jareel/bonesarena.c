inherit "/players/jareel/room";
#include "/players/jareel/define.h"

reset(arg) {

     if(arg) return;
     set_light(-3);
     short_desc=(BOLD+"Legends Arena"+NORM);
     long_desc=
       ""+BRED+BLK+"@@@@@"+NORM+"\n"+
       ""+BRED+BLK+"@@@@@"+NORM+"\n"+
       ""+BRED+BLK+"@@"+NORM+"X"+BRED+BLK+"@@"+NORM+"   The Legends Arena.   [exit]"+NORM+"\n"+     
       ""+BRED+BLK+"@@@@@"+NORM+"\n"+
       ""+BRED+BLK+"@@@@@"+NORM+"\n";
     items = ({
       "","",
       "","",
});
}
      init(){
        ::init();
      add_action("exit_cmd", "exit");
}
      exit(){    if(TP) TP->clear_fight_area();   }  
        realm(){   return "NT";   }

      exit_cmd(){
        TP->move_player("leaves the arena.#players/jareel/areas/statue/enter.c");
      return 1; }



status
cannot_enter()
{
  object ob;

  ob = first_inventory(this_object());

  while(ob)
  {
    if ((status)ob->is_player())
      return 1;

    ob = next_inventory(ob);
  }

  return 0;
}
