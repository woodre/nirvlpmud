/* Help from Maledicta's Shop code */
#include "/open/ansi.h"
#define TP this_player()
#define tp this_player()
#define TPN this_player()->query_name()
inherit "room/room";
object item;
int cost, VSHAKE, CSHAKE, BPIE, BLPIE, VLSHAKE;
int soldout;
string what;

reset(arg) {
   VSHAKE = 0;
   CSHAKE = 20;
   BPIE = 20;
   BLPIE = 20;
   VLSHAKE = 20;
   if(arg) return;
   
/*
if (!present("counter")) {
  move_object(clone_object("/players/pestilence/amity/room/counter2.c"),
        this_object()); }
*/

   short_desc = ""+HIY+"Texas Hot's"+NORM+"  "+BLINK+HIR+"Menu has Changed"+NORM+"";
   long_desc =
""+BLINK+HIR+"    Menu has Changed"+NORM+"\n"+
   "    This is the famous restaurant named Texas Hot's.  Many different\n"+
   "items can be purchased here.  There is a long bar that goes the length\n"+
   "of the building with a menu on the wall behind the bar.  On the other\n"+
   "side of the building there are twelve booths.\n";
   set_light(1);
   
   items = ({
         "bar","A long bar with stools every three feet extends the length of the building",
         "booths","There are twelve four-person booths along the other side of the building",
         "wall","On the wall there is a large menu telling what can be sold",
         "menu","->To see all available items please type 'list' or for info just type 'info_heals'",
});
   
   dest_dir = ({
         "/players/pestilence/amity/room/nmain3.c","west",
});
}

init(){
   ::init();   
   add_action("buy_it", "buy");
   add_action("info_heals","info_heals");
   add_action("list","list");
}

info_heals(){
   write("FOOD                     HEAL       TOX      COST\n"+
      "hamburger                50/50       F     1800 coins.\n"+
      "Pepsi                    50/50       S     1800 coins.\n"+
      "vanilla milkshake        50/50      F/S    1800 coins.\n"+
      "chocolate milkshake      50/50      F/S    2100 coins.\n"+
      "french fries             50/50       F     2100 coins.\n"+
      "hotdog                   50/50       F     2100 coins.\n"+
      "black berry pie           0/50      F/S    1200 coins.\n"+
      "lowfat vanilla milkshake 50/50      F/S    3300 coins.\n"+
      "blueberry pie            50/50      F/S    1200 coins.\n"+
	  "Chrono Blast (evil)      50/50      F/S    2000 coins.\n"+
	  "Fruit Smoothie           0/50 5serv F/S    1200 coins.\n"+
	  "Lowfat Fruit smoothie    0/50 5serv F/S    2700 coins.\n");
   return 1;}

list(){
   write("1. hamburger____________________________1800 coins.\n"+
      "2. Pepsi________________________________1800 coins.\n"+
      "3. Vanilla milkshake____________________1800 coins.\n"+
      "4. chocolate milkshake__________________2100 coins.\n"+
      "5. french fries_________________________2100 coins.\n"+
      "6. hotdog_______________________________2100 coins.\n"+
      "7. black berry pie______________________1200 coins.\n"+
      "8. lowfat vanilla milkshake_____________3300 coins.\n"+
      "9. blueberry pie________________________1200 coins.\n"+
	  "10.Chrono Blast_________________________2000 coins.\n"+
	  "11.Fruit smoothie_______________________1200 coins.\n"+
	  "12.Lowfat Fruit smoothie________________2700 coins.\n");
   return 1;}

buy_it(string str){
   if(!str){ write("Buy 1-9"); return 1; }
   if(str == "1"){
      cost = 1800;
      item = clone_object("/players/pestilence/amity/obj/hamburger.c");
      what = "hamburger";
   }
   else if(str == "2"){
      cost = 1800;
      item = clone_object("/players/pestilence/amity/obj/pepsi.c");
      what = "pepsi";
   }
   else if(str == "3"){
      cost = 1800;
      item = clone_object("/players/pestilence/amity/obj/vshake.c");
      soldout = VSHAKE += 1;
      what = "vanilla milkshake";
   }
   else if(str == "4"){
      cost = 2100;
      item = clone_object("/players/pestilence/amity/obj/cshake.c");
      soldout = VSHAKE += 1;
      what = "chocolate milkshake";
   }
   else if(str == "5"){
      cost = 2100;
      item = clone_object("/players/pestilence/amity/obj/fries.c");
      what = "french fries";
   }
   else if(str == "6"){
      cost = 2100;
      item = clone_object("/players/pestilence/amity/obj/hotdog.c");
      what = "hotdog";
   }
   else if(str == "7"){
      cost = 1200;
      item = clone_object("/players/pestilence/amity/obj/bpie.c");
      soldout = VSHAKE += 1;
      what = "blackberry pie";
   }
   else if(str == "8"){
      cost = 3300;
      item = clone_object("/players/pestilence/amity/obj/lvshake.c");
/*
      soldout = VSHAKE += 1;
*/
      what = "lowfat vanilla milkshake";
   }
   else if(str == "9"){
      cost = 1200;
      item = clone_object("/players/pestilence/amity/obj/bluepie.c");
      soldout = VSHAKE += 1;
      what = "blueberry pie";
   }
      else if(str == "10"){
      cost = 2000;
      item = clone_object("/players/pestilence/amity/obj/cblast.c");
      soldout = VSHAKE += 1;
      what = "Chrono Blast";
   }
      else if(str == "11"){
      cost = 1200;
      item = clone_object("/players/pestilence/amity/obj/fsmoothie.c");
      soldout = VSHAKE += 1;
      what = "Fruit Smoothie";
   }
      else if(str == "12"){
      cost = 2700;
      item = clone_object("/players/pestilence/amity/obj/lfsmoothie.c");
      soldout = VSHAKE += 1;
      what = "Lowfat Fruit Smoothie";
   }
   else{
      write("The choices are 1-12.\n");
      return 1;
   }     
   if (call_other(this_player(), "query_money", 0) < cost) {
      write("I'm sorry, but you don't have enough coins for that.\n");
      return 1;
   } 
/*         
if(VSHAKE > 35){ write("They are all sold out right now.\n"); return 1;}
*/
   if(!this_player()->add_weight(item->query_weight())) {
      write("It doesn't look like you can carry that.\n");
      destruct(item);
      return 1; }                 
   write("You pay "+cost+" coins for a "+what+".\n");
   say(tp->query_name() + " purchases a "+what+".\n");
      soldout;
   move_object(item,this_player());
   tp->add_money(-cost);
   return 1;
}
