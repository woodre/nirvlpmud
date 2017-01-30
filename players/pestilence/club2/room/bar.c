#include "/open/ansi.h"
#define tp this_player()
#define TP this_player()
inherit "/players/vertebraker/closed/std/room";

object item;
int cost;
string what;
reset(arg) {
  if(arg) return;

if (!present("bill")) {
  move_object(clone_object("/players/pestilence/club/mob/bill.c"),
        this_object()); }
short_desc = ""+HIK+"Pesty's bar"+NORM+"";
long_desc =
  "    A long bar stretches out for twenty feet.  There are red bar\n"+
  "stools every two feet along the length of the bar.  Behind the bar\n"+
  "is a long rack of many different types of liquor.  On the end of\n"+
  "the bar is a small jar for the bartender's tips.  It appears to be\n"+
  "empty.  Behind the bar on the wall there is a sign.\n";
/*
add_property("NT");
add_property("PK");
*/
add_property("NT");
set_light(1);

items = ({
  "bar","A long bar the stretches from one wall to almost the other",
  "liquor","A few bottles of hard liquor, just out of sight to be recognized",
  "stools","Small red stools that are at every two feet",
  "red stools","Small red stools that are at every two feet",
  "rack","A long rack of liqours",
  "sign","To see what is available for purchase please use 'list'",
  "jar","An empty jar for the bartender's tips",
});

dest_dir = ({
"/players/pestilence/club2/room/inside.c","east",
});
}

init(){
    ::init();   
   add_action("buy_it", "buy");
   add_action("list","list");
}

list(){
     write("1. Budweiser____________________________500 coins.\n"+
           "2. Heineken_____________________________500 coins.\n"+
           "3. Labatts Blue_________________________500 coins.\n");
     return 1;}

buy_it(str){
 if(!present("bill", this_object())){
        write("Bill isn't here to serve the drinks.\n");
        return 1;
        }
        if(str == "1"){
          cost = 500;
          item = clone_object("/players/pestilence/club/obj/bud.c");
          what = "bud";
          }

        else if(str == "2"){
          cost = 500;
          item = clone_object("/players/pestilence/club/obj/heineken.c");
          what = "Heineken";
          }

        else if(str == "3"){
          cost = 500;
          item = clone_object("/players/pestilence/club/obj/labatts.c");
          what = "Labatts Blue";
          }
        else{
          write("Buy what?\n");
          return 1;
}
 if (call_other(this_player(), "query_money", 0) < cost) {
    write("I'm sorry, but you don't have enough coins for that.\n");
     return 1;
     }          
 if(!this_player()->add_weight(item->query_weight())) {
    write("It doesn't look like you can carry that.\n");
    destruct(item);
    return 1; }                 
 write("You pay "+cost+" coins for a "+what+".\n");
 say(tp->query_name() + " purchases a "+what+".\n");
 move_object(item,this_player());
 tp->add_money(-cost);
 return 1;
}
