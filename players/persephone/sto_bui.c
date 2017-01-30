inherit "room/room";
#include "/players/persephone/rooms.h"
object atach;
reset(int arg){
 if(!arg) {
  set_light(1);
  short_desc="Storage Room";
  long_desc="You are inside a building with large containers stacked all\n" +
            "over the place. Hanging from the ceiling is a large hook suspended\n" +
            "by a chain. To the north is a large crank and to the east is a\n" +
            "steel security door\n" +
            "\n";
  items=({"containers","Large steel and wooden crates used to store things in, \n" +
                       "many of them seem to be locked one chest however has a\n" +
                     "distinctive look to it",
          "chest","It is just a treasure chest and it appears to be unlocked.\n" +
                      "Do you dare try to open it?",
          "ceiling","There are large beams holding up this high ceiling",
          "beams","These are definately wooden beams you can tell by the broken\n" +
                  "beam lying near the crank",
          "beam","It is just a broken beam. Hold on you think you can see large\n" +
                  "teeth marks in it. Now what could have caused that?",
          "hook","It looks like this hook was used to lift containers off the\n" +
                 "to aid in the stacking of them",
          "chain","A strong but rusted chain suspending a large hook, which you\n" +
                  "think might have been used for positioning large containers.\n" +
                  "The chain seems to connect to a spool",
          "crank","It appears that you can wind the crank but it might pay to be\n" +
                  "careful",
          "spool","There is a large rusted chain connected to this black spool",
          "floor","The wooden floor is extremely dusty and dirty and you can\n" +
                  "see many scraps scattered around",
          "scraps","Mainly food scraps but there are also some bones near the\n" +
                   "treasure chest",
        });
  dest_dir=({
             "players/persephone/rooms/road1b","out",
           });
 }
}
init(){
 ::init();
  add_action("open1","open");
  add_action("wind1","wind");
  add_action("wind1","turn");
  add_action("attach1","attach");
  add_action("attach1","connect");
}
open1(str){
 if(str=="chest"){
  write("You open the chest and to your dismay find it is empty.\n");
  say(CAPTPLNM +" opens the black treasure chest only to find it empty.\n");
  return 1;
 }
}
attach1(str){
 if(str=="box" || str=="container" || str=="containers"){
  write("You succeed in attaching the hook to on of the containers.\n");
  say(CAPTPLNM + " after much difficulty succeeds in attaching a hook to\n" +
                 "the largest container.\n");
  atach="yes";
  return 1;
 }
}
wind1(str){
 if(str=="handle" || str=="crank" || str=="lever"){
  if(atach=="yes"){
   write("As you start to turn the crank you lift a great container\n" +
         "letting loose a huge snake but luckily you fall\n" +
         "through a trapdoor\n\n");
   say(CAPTPLNM + " winds up the crank to release a huge annaconda\n");
   if(!present("anaconda")){
    move_object(clone_object("players/persephone/monster/ana"), TOB);
   }
   TPL->move_player("falling through a trapdoor#"+"players/persephone/rooms/und_gr1");
   return 1;
  }
  write("You start to wind the crank with great ease but suddenly a trap\n" +
        "door opens below your feet and you land splash.\n");
  say(CAPTPLNM + " starts to wind the crank.\n");
  TPL->move_player("falling through a trapdoor#"+"players/persephone/rooms/und_gr1");
  return 1;
 }
}

