#include "/players/jaraxle/define.h"
inherit "/obj/treasure";

int NUMBER, iscroll;
reset(arg)  {
   if(arg) return;
   NUMBER = 1;
   
   set_weight(1);
   set_value(450);
}
id(str){ return str == "tome" || str == "tome of identify" || str == "identify tome"; }
query_save_flag(){ return 1; }

short(){ return "Tome of "+HIC+"Identify"+NORM+" "+HIM+"["+HIG+NUMBER+HIM+"]"+NORM+""; }
long(){
   write("A Tome used to keep multiple volumes of scrolls of "+HIC+"identify"+NORM+"\n"+HIW+"<"+HIC+"Identify"+HIW+"> <"+HIC+"item"+HIW+">"+NORM+" to use the pages in the tome.\nYou can "+HIC+"<"+HIW+"add identify to tome"+HIC+">"+NORM+" to add to the book.\nYou have "+HIC+"["+HIW+NUMBER+HIC+"]"+NORM+" scrolls left in the tome.\n"); return 1; }


init(){
   ::init();
   add_action("add_it","add");
   add_action("identify_it","identify");
}

add_it(str){
   iscroll = present("identify_scroll",environment(this_object()));
   if(!iscroll){ write("You do not have the proper scroll to put into the book.\n"); return 1; }
   if(str == "identify to tome"){
   
   NUMBER +=1;
   write("You carefully add the scroll to the book.\n"+
      "You now have "+HIC+"["+HIW+NUMBER+HIC+"]"+NORM+" volumes.\n");
   say(TPN+" adds a volume of identify to their tome.\n");
   destruct(iscroll);
   return 1; }
notify_fail(HIC+"<"+HIW+"add identify to tome"+HIC+">"+NORM+"\n"); return 1; }
identify_it(str){
   
   object ob;
   int ac, wc, wt, va;
   if(NUMBER <= 0){ write("You do not have any pages left!\n"); return 1; }
   if(!str) {
      say(TPN+" recites words from a tome...\n");
      write("You recite the words of identify incorrectly!\n"+
         "The page explodes in a puff of smoke!\n");
      destruct(this_object());
      return 1;
   }
   
   ob = present(str,this_player());
   if(!ob) {
      say(TPN+" recites words from a tome...\n");
      write("You recite the words of identify incorrectly!\n"+
         "The page explodes in a puff of smoke!\n");
      destruct(this_object());
      return 1;
   }  
   write("\nYou recite the words of identify for "+str+"...\n\n");
   say(TPN+" recites words from a tome...\n");
if(ob->query_save_flag()){ write(""+HIW+"This item is "+HIR+"not"+HIW+" saveable"+NORM+".\n");
}
else{
write(HIW+"This item is "+HIC+"saveable"+NORM+".\n");    }
   ac = call_other(ob,"armor_class");
   wc = call_other(ob,"weapon_class");              
   wt = call_other(ob,"query_weight");     
   va = call_other(ob,"query_value");     
   if(wc) {
      string class;
      if(wc >= 20)
         class = "god-like";
      else
         if(wc >= 18)
         class = "excellent";
      else
         if(wc >= 17)
         class = "great";
      else
         if(wc >= 15)
         class = "good";
      else
         if(wc >= 14)
         class = "moderate";
      else
         if(wc >= 12)
         class = "fair";
      else
         if(wc >= 10)
         class = "below average";
      else
         class = "useless";
      write("This weapon is "+class+" in your hands.\n");
   }
   if(ac) {
      string arm;
      if (ac >= 6)
         arm = "god-like";
      else
         if(ac == 5)
         arm = "astonishing";
      else
         if(ac == 4)
         arm = "excellent";
      else
         if(ac == 3)
         arm = "good";
      else
         if(ac == 2)
         arm = "adequite";
      else
         if(ac == 1)
         arm = "fair";
      else
         arm = "useless";
      
      write("This is "+arm+" armor, if worn.\n");
   }
   if(wt) {
      string weight;
      if (wt >= 6)
         weight = "as heavy as lead";
      else
         if(wt >= 5)
         weight = "extremely heavy";
      else
         if(wt >= 4)
         weight = "moderately heavy";
      else
         if(wt >= 3)
         weight = "evenly weighted";
      else
         if(wt >= 2)
         weight = "moderate in weight";
      else
         if(wt >= 1)
         weight = "as light as a feather";
      else
         weight = "weightless";
      
      write("This is "+weight+".\n");
   }
   if(va) {
      string value;
      if (va >= 4499)
         value = " unsurmountable wealth";
      else
         if (va >= 3499)
         value = " your weight in gold";
      else
         if (va >= 2499)
         value = " a lot of coins";
      else
         if(va >= 1499)
         value = " a good amount of coins";
      else
         if(va >= 999)
         value = " a fair amount of coins";
      else
         if(va >= 500)
         value = " a small amount of coins";
      
      else
         if(va >= 250)
         value = " next to nothing";
      else
         if(va >= 1)
         value = " almost nothing";
      else
         value = "less";
      
      write("This item is worth"+value+".\n");
   }
   if(!ac){ write(HIW+"This item is not armor.\n"+NORM); }
   if(!wc){ write(HIW+"This item is not a weapon.\n"+NORM); }
   if(!va){ write(HIW+"This item is not worth anything.\n"+NORM); }
   if(!wt){ write(HIW+"This item has no weight.\n"+NORM); }
   write("\nThe page explodes into a puff of smoke!\n\n");
   say("A page from "+TPN+"'s tome explodes in a puff of smoke!\n");
   NUMBER -=1;
   
    write("You have "+HIC+"["+HIW+NUMBER+HIC+"]"+NORM+" scrolls left in the tome.\n");
   return 1; }


