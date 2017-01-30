#include "/open/ansi.h"
#define tp this_player()
#define TP this_player()
inherit "/players/vertebraker/closed/std/room";

object item;
int cost, strength;
string what;
reset(arg) {
  if(arg) return;

short_desc = ""+HIG+"Mustaine's Irish Pub"+NORM+"";
long_desc =
  "    A long bar stretches out for twenty feet.  There are green bar\n"+
  "stools every two feet.  There are several tables out on the floor.\n"+
  "Also there is a small area for dancing.  Behind the dancing area,\n"+
  "there is a caged area for a band to play.  There is a small sign on\n"+
  "the bar.\n";


set_light(1);


items = ({
  "bar","A long bar that stretches from one wall to almost the other",
  "area","A small cleared out area in the bar, made for dancing",
  "dancing area","A small cleared out area in the bar, made for dancing",
  "caged area","A little stage with a cage front to prevent items from hitting the band",
  "cage","A metal chicken wire fence to protect the band from flying objects",
  "stools","Small green bar stools that are at every two feet",
  "sign","The sign reads: Please type list to see your choices",
  "rack","A long rack of liqours",
  "jar","An empty jar for the bartender's tips",
});

dest_dir = ({
"/players/pestilence/amity/room/nmain3.c","east",
});
}

init(){
    ::init();   
   add_action("buy_it", "buy");
/*
  add_action("list"); add_verb("list");
*/
  add_action("list","list");

}

list(){
     write("Usage buy 1-8.\n"+
           "1. "+RED+"Bud"+HIW+"wei"+BLU+"ser"+NORM+" ____________________________ 500 coins.\n"+
           "2. Murphy's Lager _______________________ 500 coins.\n"+
           "3. "+BLU+"Labatts ice"+NORM+" __________________________ 500 coins.\n"+
           "4. "+HIG+"Heineken"+NORM+" _____________________________ 500 coins.\n"+
           "5. "+HIK+"Jack Daniels"+NORM+" _________________________ 500 coins.\n"+
           "6. Everclear ____________________________ 500 coins.\n"+
           "7. "+HIR+"Pe"+HIB+"p"+HIW+"si"+NORM+" ________________________________ 500 coins.\n"+
           "8. "+HIG+"Mountain Dew"+NORM+" _________________________ 500 coins.\n");
     return 1;}

buy_it(string str){
 if (call_other(this_player(), "query_money", 0) < cost) {
    write("I'm sorry, but you don't have enough coins for that.\n");

     return 1;
}

        if(str == "1"){
if (!call_other(this_player(), "drink_alcohol", 17)) {
  write("You appear to be too drunk to have anymore.\n");
  say(call_other(this_player(),"query_name", 0) + " orders a "+what+" but is too drunk to drink it.\n");
  return 1;
}
          cost = 500;
          what = ""+RED+"Bud"+HIW+"wei"+BLU+"ser"+NORM+"";
     this_player()->heal_self(50);
     this_player()->add_money(-500);
}
        else if(str == "2"){
if (!call_other(this_player(), "drink_alcohol", 17)) {
  write("You appear to be too drunk to have anymore.\n");
  say(call_other(this_player(),"query_name", 0) + " orders a "+what+" but is too drunk to drink it.\n");
  return 1;
}
          cost = 500;
          what = "Murphy's Lager";
     this_player()->heal_self(50);
     this_player()->add_money(-500);
}

        else if(str == "3"){
if (!call_other(this_player(), "drink_alcohol", 17)) {
  write("You appear to be too drunk to have anymore.\n");
  say(call_other(this_player(),"query_name", 0) + " orders a "+what+" but is too drunk to drink it.\n");
  return 1;
}
          cost = 500;
          what = ""+BLU+"Labatts ice"+NORM+"";
     this_player()->heal_self(50);
     this_player()->add_money(-500);
}
        else if(str == "4"){
if (!call_other(this_player(), "drink_alcohol", 17)) {
  write("You appear to be too drunk to have anymore.\n");
  say(call_other(this_player(),"query_name", 0) + " orders a "+what+" but is too drunk to drink it.\n");
  return 1;
}
          cost = 500;
          what = ""+HIG+"Heineken"+NORM+"";
     this_player()->heal_self(50);
     this_player()->add_money(-500);
} 
       else if(str == "5"){
if (!call_other(this_player(), "drink_alcohol", 17)) {
  write("You appear to be too drunk to have anymore.\n");
  say(call_other(this_player(),"query_name", 0) + " orders a "+what+" but is too drunk to drink it.\n");
  return 1;
}
          cost = 500;
          what = ""+HIK+"Jack Daniels"+NORM+"";
     this_player()->heal_self(50);
     this_player()->add_money(-500);
}
        else if(str == "6"){
if (!call_other(this_player(), "drink_alcohol", 17)) {
  write("You appear to be too drunk to have anymore.\n");
  say(call_other(this_player(),"query_name", 0) + " orders a "+what+" but is too drunk to drink it.\n");
  return 1;
} 
         cost = 500;
          what = "Everclear";
     this_player()->heal_self(50);
     this_player()->add_money(-500);
}
        else if(str == "7"){
if (!call_other(this_player(), "drink_soft", 7)) {
  write("You appear to have to have drunk too much soda.\n");
  say(call_other(this_player(),"query_name", 0) + " orders a "+what+" but has had too much already.\n");
  return 1;
}
if (!call_other(this_player(), "eat_food", 7)) {
  write("You appear to have to have drunk too much soda.\n");
  say(call_other(this_player(),"query_name", 0) + " orders a "+what+" but has had too much already.\n");
  return 1;}          
          cost = 500;
          what = ""+HIR+"Pe"+HIB+"p"+HIW+"si"+NORM+"";
     this_player()->heal_self(50);
     this_player()->add_money(-500);
}
        else if(str == "8"){
if (!call_other(this_player(), "drink_soft", 7)) {
  write("You appear to have to have drunk too much soda.\n");
  say(call_other(this_player(),"query_name", 0) + " orders a "+what+" but has had too much already.\n");
  return 1;
}
if (!call_other(this_player(), "eat_food", 7)) {
  write("You appear to have to have drunk too much soda.\n");
  say(call_other(this_player(),"query_name", 0) + " orders a "+what+" but has had too much already.\n");
  return 1;}    
          cost = 500;
          what = ""+HIG+"Mountain Dew"+NORM+"";
     this_player()->heal_self(50);
     this_player()->add_money(-500);
}

        else{
          write("Buy what?\n");
          return 1;
}
write("You pay "+cost+" coins for a "+what+".\n"+
        "You drink a "+what+" until it's gone.\n");
 say(tp->query_name() + " purchases a "+what+".\n"+
       ""+tp->query_name()+" drinks a "+what+" until it's gone.\n");
 return 1;


}
