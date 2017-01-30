inherit "room/room";
object mike, don, leo, ralph, splinter;

reset(arg){  
/** Replacing TMNT with updated mobs that roam Nirvana - Gnar
        if(!present("mike")){
           mike=clone_object("players/airwoman/MONSTER/mike");
           move_object(mike, this_object());
          }
        if(!present("leo")){
           leo=clone_object("players/airwoman/MONSTER/leo");
           move_object(leo, this_object());
          }
        if(!present("ralph")){
           ralph=clone_object("players/airwoman/MONSTER/ralph");
           move_object(ralph, this_object());
           }
        if(!present("don")){
           don=clone_object("players/airwoman/MONSTER/don");
           move_object(don, this_object());
           }
**/
      if(!present("splinter")){
           splinter = clone_object("/players/wicket/ninja_turtles/mobs/splinter.c");
           move_object(splinter, this_object());
}
        if(!arg){
        set_light(1);
        short_desc="sewage room 3--TMNT";
        long_desc=
        "ACK!  You have discovered the Teenage Mutant Ninja\n"+
        "Turtles' Hideout!  Kill these dirty filthy mutants!\n";
        dest_dir = ({"players/airwoman/sewage/room2", "west"});
        }
}
