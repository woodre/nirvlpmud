inherit "obj/treasure";
#include "/players/persephone/rooms.h"
reset(int arg){
 set_id("book");
 set_short("Leather Book");
 set_long("A Beautiful Leather Bound Book entitled Great Wombles\n" +
          "of Science and Their Discoveries\n\n");
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
 if(str=="book" || str=="tome"){
  write("You open up the book and try to read the cover page but you\n" +
           "notice it is not in any language you can understand\n\n");
  return 1;
 }
 write("What are you trying to read\n\n");
return 1;
}
