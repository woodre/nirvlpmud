/* Added a 'south' exit to make navigation possible. -Snow 1/00 */
inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset(int arg){
 if(arg) return;
  set_light(0);
  short_desc="Jungle Path";
  long_desc="This is an extremely dark and gloomy part of the jungle and what\n" +
            "makes it worse is the howling you hear to the south and the bones\n" +
            "scattered all around. The path continues both east and west while\n" +
            "to the south you see a rockslide\n" +
            "\n";
  items=({"jungle","The jungle is extremly gloomy with large trees to the north",
          "sky","You cannot see the sky as the jungle canopy blocks your view",
          "bones","They look like bones some of them are perhaps human but you\n" +
                  "are not sure",
          "rockslide","You think that if you dared search long enough you might\n" +
                      "find a path leading south through it",
          "path","The path is very rough and heads both east and west",
          "howling","You can not see the howling but you can hear it and it\n" +
                    "sounds very ominous",
          "trees","The trees are big and very dark, black may not be the word\n" +
                  "but it is close",
        });
  dest_dir=({"players/persephone/rooms/junpatc","west",
             "players/persephone/rooms/junpat2","east",
           });
}
init(){
 ::init();
  add_action("search1","search");
  add_action("search1","find");
  add_action("search1","move");
  add_action("enter1","enter");
  add_action("enter1","in");
  add_action("enter1","picks");
  add_action("south","south");
}
search1(str){
 if(str=="rockslide" || str=="rocks" || str=="slide"){
  write("After much searching you find a path that leads into the rockslide\n" +
        "but you think it looks very dangerous.\n");
  say(CAPTPLNM + " carefully searches the rockslide trying to find an entrance\n" +
                 "into the slide.\n");
  return 1;
 }
}
enter1(str){
 if(str=="path" || str=="rocklide" || str=="slide"){
  write("Foolishly you head south through the rockslide.\n");
  TPL->move_player("entering the rockslide#"+"players/persephone/rooms/wwden");
  return 1;
 }
}

south() {
  write("Foolishly you head south through the rockslide.\n");
  TPL->move_player("entering the rockslide#"+"players/persephone/rooms/wwden");
  return 1; }
