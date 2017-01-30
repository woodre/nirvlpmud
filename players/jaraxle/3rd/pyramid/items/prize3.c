#include "/players/jaraxle/define.h"
inherit "/obj/treasure";

int LONG, OPEN, OPEN2, BODY, SHORT, MIST;
reset(arg)  {
   switch(random(4)){
      case 0:
      LONG = "Jackal's";
      break;
      case 1:
      LONG = "Human's";
      break;
      case 2:
      LONG = "Baboon's";
      break;
      case 3:
      LONG = "Falcon's";
      break;
   }
   
   OPEN = 0;
   SHORT = "A "+HIW+"closed"+NORM+"";
   OPEN2 = ""+HIW+"["+NORM+"closed"+HIW+"]"+NORM+"";
   BODY = 0;
   MIST = 0;
   if(arg) return;
   
   set_alias("canopic jar");
   set_weight(1);
   set_value(150+random(51));
}
id(str){ return str == "jar" || str == "canopic jar"; }
short(){ return ""+SHORT+" canopic jar"; }
long(){ write("A jar made of limestone, used to hold mummy organs.\nIt has a "+HIW+""+LONG+""+NORM+" head carved into the lid.\nThese jars are very fragile, and can be easily broken.\nThe jar is "+OPEN2+".\n"); }
query_save_flag() { return 1; }

init(){
   ::init();
   add_action("open","open");
   add_action("close","close");
   add_action("brk","break");
}

open(arg){
   if(OPEN == 1){ write("The jar is already open.\n"); return 1; }
   if(arg == "jar" || arg == "lid"){
      write("You open the lid of the jar.\n");
      OPEN2 = ""+HIW+"["+NORM+"open"+HIW+"]"+NORM+"";
      SHORT = "An "+HIW+"open"+NORM+"";
      OPEN +=1;
      if(BODY == 0){
         call_other(this_player(),"drink_alcohol",-5-random(6));
         call_other(this_player(),"drink_soft",-4-random(8));
         call_other(this_player(),"eat_food",-4-random(8));
         write(YEL+"A stench mist escapes from the canopic jar.\n"+NORM);
         say(TPN+" inhales a "+YEL+"stench mist"+NORM+".\n"+NORM);
         BODY +=1;
         MIST +=1;
         return 1; }
      return 1; }
   write("Open what?\n");
   return 1; }
close(arg){
   if(OPEN == 0){ write("The jar is already closed.\n"); return 1; }
   if(arg == "jar" || arg == "lid"){
      write("You close the lid of the jar.\n");
      OPEN2 = ""+HIW+"["+NORM+"closed"+HIW+"]"+NORM+"";
      SHORT = "A "+HIW+"closed"+NORM+"";
      OPEN -=1;
      return 1; }
   write("Close what?\n");
   return 1; }

brk(arg){
object mummy;
mummy = present("jar_mummy",environment(this_player()));
   if(arg == "jar" || arg == "canopic jar"){
      write("With a heavy swing, you throw the jar onto the ground!\nThe jar shatters into pieces!\n");
      say(TPN+" smashes a canopic jar on the ground!\n");
      
      
      if(MIST == 0){
         write(GRN+"A mist escapes from the jar.\n"+NORM);
         say(GRN+"A mist escapes from the jar.\n"+NORM);
}
else{ write("[nothing happens]\n"); }
      if(MIST == 0){
if(mummy){
         write(HIG+"The mist swirls around the mummy!\n"+NORM);
         say(HIG+"The mist swirls around the mummy!\n"+NORM);
mummy->hit_player(51+random(50));
}
else{
      write("[nothing happens]\n");
 }
}
      destruct(this_object());
      return 1; }                     
   write("Break what?\n");
   return 1; }

