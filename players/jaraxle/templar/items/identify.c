#include "/players/jaraxle/define.h"

id(str) { return str == "scroll" || str == "identify" || str == "scroll of identify" || str == "identify_scroll"; }

short() { return "A Scroll of "+HIC+"Identify"+NORM+""; }

long() {
write("A rolled up scroll with a "+HIC+"cyan ribbon"+NORM+" tied around it.\nAll you need to do is "+HIC+"<"+HIW+"identify"+HIC+">"+NORM+" an "+HIC+"<"+HIW+"item"+HIC+">"+NORM+".\n");
}
query_weight() { return 1; }
query_value()  { return 100; }
get() { return 1; }
 take() { return 1; }
 drop(){
    write("As you drop the scroll is explodes in a puff of smoke!\n");
  destruct(this_object());
return 1; }

init() { add_action("identify"); add_verb("identify"); }

identify(str)
{

   object ob;
   int ac, wc, wt, va;
    if(!str) {
      say(TPN+" recites words from a scroll...\n");
      write("You recite the words of identify incorrectly!\n"+
            "The scroll explodes in a puff of smoke!\n");
      destruct(this_object());
      return 1;
    }

   ob = present(str,this_player());
   if(!ob) {
      say(TPN+" recites words from a scroll...\n");
      write("You recite the words of identify incorrectly!\n"+
            "The scroll explodes in a puff of smoke!\n");
      destruct(this_object());
      return 1;
   }  
      say(TPN+" recites words from a scroll...\n");
      write("\nYou recite the words of identify for "+str+"...\n\n");
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
if(!ac){ write(HIW+"This item is "+HIR+"not"+HIW+" armor.\n"+NORM); }
if(!wc){ write(HIW+"This item is "+HIR+"not"+HIW+" a weapon.\n"+NORM); }
if(!va){ write(HIW+"This item is "+HIR+"not"+HIW+" worth anything.\n"+NORM); }
if(!wt){ write(HIW+"This item has "+HIR+"no"+HIW+" weight.\n"+NORM); }
write("\nThe scroll explodes into a puff of smoke!\n\n");
say(TPN+"'s scroll explodes in a puff of smoke!\n");
destruct(this_object());

return 1; }
query_save_flag() { return 1; }



