inherit "/players/jareel/room";
#include "/players/jareel/define.h"
#define ARENA "/players/jareel/areas/statue/arena/bone/rm1.c"

reset(arg) {

     if(!present("statue"))  {
       MOCO("/players/jareel/general_stuff/cooper_statue.c"),this_object()); }
     if(!present("board"))  {
       MOCO("/players/jareel/general_stuff/cooper_graf.c"),this_object()); }
     
     if(arg) return;
     set_light(1);
     short_desc=("The"+GRN+" Moss "+NORM+"Ranger's "+BLU+"Command Center"+NORM);
     long_desc=
       ""+BRED+BLK+"@@"+NORM+"|"+BRED+BLK+"@@"+NORM+"     \n"+
       ""+BRED+BLK+"@"+NORM+BOLD+"X"+NORM+"+"+BOLD+BLK+"M"+NORM+BLK+BRED+"@"+NORM+"     The room filled with computer consoles and strange inventions, this\n"+ 
       ""+BRED+BLK+"@"+NORM+HIB+"J"+NORM+"+"+HIK+"B"+NORM+BLK+BRED+"@"+NORM+"     is The "+GRN+"Moss"+NORM+" Ranger's "+BLU+"Command Center"+NORM+".  Flashing lights, control panels\n"+
       ""+BRED+BLK+"@"+NORM+HIB+"S"+NORM+"+"+NORM+HIR+"K"+NORM+BLK+BRED+"@"+NORM+"     and toggle switches cover the northern wall. On the western wall lie\n"+
       ""+NORM+"-"+NORM+"-+D"+BLK+BRED+"@"+NORM+"     numerous tools and diagnostic machines. A slightly open closet recedes\n"+
       ""+BRED+BLK+"@@"+NORM+"E"+BLK+BRED+"@@"+NORM+"     on the southern wall near a moss covered recliner and an end table.\n"+     
       "\n"+
       "E - Entrance/Exit : D - Depository  : "+HIB+"S"+NORM+" - Stone's Room  : "+HIR+"K"+NORM+" - Konya's Room\n"+	
       ""+HIB+"J"+NORM+" - Justin's Room : "+HIK+"B"+NORM+" - Bone's Room : "+GRN+"C"+NORM+" - Cooper's Room : "+BOLD+BLK+"M"+NORM+" - Magus's Room\n\n";
     items = ({
       "console","It seems as if one person could control the world from here",
       "consoles"," It seems as if one person could control the world from here",
       "inventions","Crazy looking items, probably used by the Power Rangers to thwart evil doers",
       "light","The panels have hundreds of thousands of little flashers",
       "lights","The panels have hundreds of thousands of little flashers",
       "tools","Covering the walls, this could be a mechanics dream",
       "machines","Some odd machine designs are here, Cooper maybe working on a new Zord design",
       "bay","This is where Coopers trusty Zord recharges and rests for repairs when not in use",
       "repair bay","This is where Coopers trusty Zord recharges and rests for repairs when not in use",
       "recliner","This recliner seems to be covered in moss, except for the outline of a person. The outline must be where Mossy lays to relax",
       "closet","After you examine the closet closer, you notice 7 moss colored spandex. He must have one for each day of the week",
       "table","A computer, piece of paper and a family picture rests on the table",
       "morpher","Could this be Mossy's personal power ranger morpher?",
       "computer","The computer flashes, beeps and hums, it must be doing various task. This computer must run Mossy's command center and keep in touch with the power ranger command center, what a busy machine",
       "tools","These are used to fix and repair the zords",
       "picture","Two small childern playing with a snake. This must be Nelia, James and slimer, Cooper's two kids his pet snake(good thing they look like their mother!)",
       "spandex","Moss colored spandex, how could someone where such a thing",
       "wall","The walls are covererd with panels of toggle switches and tools",
       "walls","The walls are covererd with panels of toggle switches and tools",
       "paper","Stuff to kill, Icingdeath...done, Vanishing tower....done, Red Dragon...done, Duncan MacCloud....done, Gordie howe....",
     });

     dest_dir = ({
       "/players/jareel/areas/statue/hall3.c","east",
     });
}

     init() {
       ::init();
         add_action("Search","search");
         add_action("Start","start");
         if(TPRN == "cooper") add_action("chair","sit on");
}

     Search(str) {
       if(!str) { write("Search what?\n"); return 1; }
         write("You search the "+str+" but find nothing special.\n");
         say(this_player()->query_name()+" searches around for something.\n");
       return 1;
}

     chair(str) {
       if(!str) { write("Sit on what?\n"); return 1; }
       write("You sit in your arm chair and kick up you feet, ahh this is the life.\n");
       say(this_player()->query_name()+" sits in his arm chair and kicks up his feet.\n");
     return 1;
}

  Start(string str){
     if(!str || str != "arena"){
       notify_fail("What do you want to do?\n");
     return 0;
   }
   if(this_player()->query_level() < 19){
     write("Not until you are level 19.\n");
   return 1;
 
   }

  if ((status)ARENA->cannot_enter())
  {
    notify_fail("There is already someone in Cooper's Arena.\n");
    return 0;
  }

  write("You start the arena.\n");
  say((string)this_player()->query_name()+" heads off to fight Cooper.\n");
  move_object(this_player(), "/players/jareel/areas/statue/arena/cooper/rm1.c");
  command("glance", this_player());
  return 1;
}


