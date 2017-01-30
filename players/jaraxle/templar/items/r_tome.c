#include "/players/jaraxle/define.h"
inherit "/obj/treasure";

int NUMBER, rscroll;
reset(arg)  {
   if(arg) return;
   NUMBER = 1;
   
   set_weight(1);
   set_value(450);
}
id(str){ return str == "tome" || str == "tome of recall" || str == "recall tome"; }
query_save_flag(){ return 1; }

short(){ return "Tome of "+HIY+"Recall "+HIM+"["+HIG+NUMBER+HIM+"]"+NORM+""; }
long(){
   write("A Tome used to keep multiple volumes of scrolls of "+HIY+"Recall"+NORM+".\nYou can "+HIY+"<"+HIR+"add recall to tome"+HIY+">"+NORM+" to add to the book.\nJust type "+HIY+"<"+HIR+"recall"+HIY+">"+NORM+" to use a page in the tome.\nYou have "+HIY+"["+HIR+NUMBER+HIY+"]"+NORM+" scrolls left in the tome.\n"); return 1; }

init(){

   ::init();
   add_action("add_it","add");
   add_action("accept","invoke");
}

add_it(str){
   rscroll = present("recall_scroll",environment(this_object()));
   if(!rscroll){ write("You do not have the proper scroll to put into the book.\n"); return 1; }
   
  if(str == "recall to tome"){
   NUMBER +=1;
   write("You carefully add the scroll to the book.\n"+
      "You now have "+HIY+"["+HIR+NUMBER+HIY+"]"+NORM+" volumes.\n");
   say(TPN+" adds a volume of recall to their tome.\n");
   destruct(rscroll);
   return 1; }
notify_fail(HIY+"<"+HIR+"add recall to tome"+HIY+">"+NORM+"\n"); return 1; }
accept(str){
     if(!str){
          write("Invoke what?\n");
          return 1;
     }
   if(str != "scroll" && str != "tome"){
      write("Invoke what?\n");
      return 1;
}
  if(NUMBER <= 0){
    write("You have no more scrolls in the tome.\n");
    return 1;
}

  write("You read the scroll out loud.\n");
  if(call_other(environment(this_player()), "realm", 0 == "NT")) {
    write("You cannot teleport from here. The scroll crumbles.\n");
    destruct(this_object());
    return 1;
   }
  tell_room(environment(this_player()), this_player()->query_name() + 
  " vanishes in a bright "+HIY+"flash"+NORM+" of "+HIW+"light"+NORM+".\n");
move_object(this_player(), "/players/jaraxle/templar/rooms/library.c");
command("look",TP);
  tell_room(environment(this_player()), this_player()->query_name() + " arrives in a "+HIY+"flash"+NORM+" of "+HIW+"light"+NORM+".\n");
NUMBER -=1;
write("You have "+HIY+"["+HIR+NUMBER+HIY+"]"+NORM+" scrolls left in the tome.\n");
  return 1;
}
