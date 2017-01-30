inherit "obj/treasure";
#include "/players/persephone/rooms.h"
reset(int arg){
 set_id("scroll");
 set_short("A Velum Scroll");
 set_long("An important looking velum scroll indeed you seem to think\n" +
          "some players would pay a considerable sum for it. It is rolled\n" +
          "with a large red seal on it\n\n");
 set_weight(1);
 set_value(250);
}
get(){
 return 1;
}
init(){
 ::init();
  add_action("read1","read");
}
read1(str){
 if(str=="scroll"){
  write("When you you look at it more closely you see the seal is\n" +
        "official signed by the mayor of Stormhold and dare not\n" +
        "open it.\n\n");
  return 1;
 }
 write("What are you trying to read\n\n");
return 1;
}
