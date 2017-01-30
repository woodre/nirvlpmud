inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset (int arg){
 if (arg) return;
  set_light(0);
  short_desc="Jungle Path";
  long_desc="The jungle has started to take over the path here and you see large\n" +
            "creeping vines all around you except to the west. There is no\n" +
            "possible way of proceeding either east or south as thick vegetation\n" +
            "blocks your way. However, you think that you might be able to find  \n" +
            "something in the vines.\n";
  items=({"path","The path appears to be extremely over grown with different\n" +
                 "kinds of vegetation",
          "vegitation","You know plants only these grow on the ground",
          "trees","The trees are extremely big and some of them have jungle orchids\n" +
                  "growing out of them",
          "orchids","These are extremely beautiful but very parasitic and oportunistic\n" +
                    "towards other plants but they are in flower",
          "flower","The flowers are beautiful mainly violet but some are also yellow\n" +
                   "black",
          "vines","They are tangled up in the trees making the passage both\n" +
                  "east and north impossible but there might be a way south if\n" +
                  "you choose the right path",
         });
  dest_dir=({"players/persephone/rooms/junpatd","west",
           });
}
init(){
 ::init();
  add_action("choose1","choose");
  add_action("choose1","search");
  add_action("crawl1","crawl");
  add_action("crawl1","slash");
  add_action("crawl1","south");
}
choose1(str){
 if (str=="path" || str=="way"){
  write("You find a path that you could crawl south on but it looks very\n" +
        "unwholesome and dangerous.\n");
  say(CAPTPLNM + " is searching for a way south.\n");
  return 1;
 }
}
crawl1(str){
/* Removed to make navigation easier. -Snow 1/00
 if(str=="path" || str=="way"){
*/
  write("You crawl south on a dirty and disused path\n");
  TPL->move_player("south crawling along a path#"+"players/persephone/rooms/junpat3");
  return 1;
 }
/*
 write("You crawl like a baby. Perhaps you should try the path.\n");
 say(CAPTPLNM + " crawls around like a baby.\n");
 return 1;
}
*/
