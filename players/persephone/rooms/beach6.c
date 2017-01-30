inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
int t;
reset (int arg){
 if(!present("troll")){
  for(t=0;t<4;t++){
   move_object(clone_object("players/persephone/monster/stroll"), TOB);
  }
 }
 if (!arg) {
  set_light(2);
  short_desc="Sandy Beach";
  long_desc="This is a sandy beach much like the others you have recently walked\n" +
            "along. To the West you see the waves breaking against some cliffs\n" +
            "while back to the East all you see is the beach which looks\n" +
            "impassible as the sand absorbs all. As you look around\n" +
            "this area you notice a pile of wood near some grass to the south.\n";
  items=({"sand","Just normal pure white sand",
          "cliffs","They look extremely steep but there is a path\n" +
                   "running up them",
          "waves","There seem to be horses riding on the waves",
          "beach","The beach looks extremely desolate",
          "wood","The wood seems almost out of place here perhaps you\n" +
                 "should move it",
          });
  dest_dir=({"players/persephone/rooms/cliffb","west",
             
  });
 }
}
realm(){ return "NT";}
init(){
 ::init();
  add_action("move1","move");
  add_action("move1","shift");
  add_action("enter","enter");
  add_action("enter","in");
}
move1(str){
 if(str=="wood" || str=="logs" || str=="pile"){
  write("With a great deal of strain and effort you manage to\n" +
        "to move the pile of wood to reveal a cave entrance\n" +
        "which you seem to be drawn to and feel like entering\n\n");
  say(CAPTPLNM + " moves the pile of wood to reveal the entrance\n" +
      "to a cave.\n\n");
  return 1;
 }
 write ("No matter how hard you try you cannot move the air!\n\n");
 say(CAPTPLNM + " futilely tries to move the air that surrounds you\n\n");
 return 1;
}
enter(){
 write("You enter the cave looking for fun and excitement\n\n");
 TPL->move_player("enter searching for fun and excitement#"+"players/persephone/rooms/lair_ent2.c");
 return 1;
}

