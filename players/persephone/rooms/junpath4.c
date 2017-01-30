inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
object pills, mirr;
int t;
reset(int arg){
if(!present("huorn")) {
  for(t=0;t<2;t++){
   move_object(clone_object("players/persephone/monster/huorn"), TOB);
  }
 }
 if(!present("fanghorn")) {
  move_object(clone_object("players/persephone/monster/treeb"), TOB);
 }
 if(!arg){
  set_light(1);
  short_desc="Bright Clearing";
  long_desc="You have swung into very pleasant little clearing in the jungle.\n" +
            "In the north of this clearing you see a lovely looking glass\n" +
            "with a piece of paper on it. All around you is jungle and you\n" +
            "think that you can possibly head south into the jungle\n" +
            "\n";
  items=({"clearing","This clearing would make a lovely little picnic spot and\n" +
                     "the grass that covers it so beautiful",
          "grass","The grass is a lovely shade of blue. Yes blue!" ,
          "sky","Ah finally to see green sky and the two suns of Nirvana",
          "suns","Like sol for the planet earth but these are alpha and beta\n" +
                 "Kitten",
          "glass","Silly a looking glass is just a mirror but there is something\n" +
                  "strange about this looking glass perhaps you should examine it",
          "jungle","You cannot be sure but jungle seems to be almost alive",
          "paper","There is some writing on this piece of paper maybe you should\n" +
                  "read the note",
        });
  dest_dir=({"players/persephone/rooms/junpatc","south",
           });
 }
}
init(){
 ::init();
  add_action("read1","read");
  add_action("polish1","polish");
  add_action("polish1","clean");
  add_action("leep","dive");
  add_action("fang","fang");
  add_action("flame","flame");
}
read1(str){
 if(str=="bush" || str=="paper"){
  write("\n"+
        "                     To dearest Alyss your own\n" +
        "                     looking glass be careful\n" +
        "                     when cleaning it strange\n" +
        "                     things may happen. \n" +
        "                     Have Fun!!!!!\n" +
        "\n");
  say(CAPTPLNM +" reads a note");
  return 1;
  }
}
polish1(str){
 if(str=="mirror" || str=="glass"){
  write("You see a small girl in a wonderous land who seems to be crying\n" +
        "perhaps you can dive through the mirror and help her\n");
  say(CAPTPLNM + " polishes the mirror.\n");
  if(present("mogodon",TPL)){mirr = TPL; return 1;}
  return 1;
 }
}
leep(){
 if(mirr==TPL){
  write("You dive north through the mirror to help Alis.\n");
  this_player()->move_player("diving north through the mirror#"+"players/persephone/rooms/wland");
  return 1;
 }
 write("You hit your head trying to dive into the mirror. Ouch!!\n");
 say(CAPTPLNM+" hits his head trying to dive through the mirror. What a jerk!!\n");
 return 1;
}
