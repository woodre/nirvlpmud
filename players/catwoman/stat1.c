inherit "obj/treasure";
#include "/players/persephone/rooms.h"
reset(int arg){
 set_id("statue");
 set_short("Emerald Statue");
 set_long("A stunning emerald statue that stands 20 feet tall and depicts\n" +
          "an angelic woman of insurmountable beauty and grace, who bears\n" +
          "a striking resemblance to Athena Victory. Yes as you wonder\n" +
          "who this beautious figure you realize it is none other than\n"+ 
          "Catwoman. She stands here watching over her area as a guardian\n" +
          "angel. On the base of the Statue is a small plaque\n\n");


 set_weight(100);
 set_value(250000);
}
get(){
 return 0;
}
init(){
 ::init();
/*
  add_action("read1","read");
}
read1(str){
 if(str=="plaque" || str=="notice"){
  write("            Oh Catwoman you brought us\n" +
        "            much joy and happiness. It\n" +
        "            is tragic to lose one with\n" +
        "            such a cheerful nature and\n" +
        "            love of life. I always    \n" +
        "            respected you as did every\n" +
        "            person here. Please look\n" +
        "            down on us and protect us.\n" +
        "            \n" +
        "            Persephone and the rest of\n" +
        "            of your friends and admirers\n\n");
  say(CAPTPLNM + " reads the golden plaque.\n");
  return 1;
*/
 }
