#include "/players/fred/ansi.h"
inherit "/players/vertebraker/closed/std/room";
#define tp this_player()
#define tpn this_player()->query_name()
int cost;
object item;
string what;

reset(int arg)
{
   if(arg) return;
   set_light(1);
   set_short(BOLD+"CRaZed FoReSt"+NORM);
   set_long(
      "  The inside of the cabin is more run down then the outside.\n"+
      "Random objects are strewn about everywhere. A small table sits\n"+ 
      "in the middle of the room.  A large barrel is pushed into the corner.\n");
   add_item("objects","Miscellaneous objects.");
   add_item("table","It is smooth and looks old and rugged");
   add_item("barrel","An old barrel with with some gooey substance running down the side");
   add_item("substance","A gooey sticky gunk. You are not sure what it is");
   add_exit("/players/fred/forest/Rooms/forest29.c","exit");
   add_object("/players/fred/forest/Mon/samson.c");
   add_property("NF");
}


init(){
    ::init();
    add_action("buy_it","buy");
    add_action("askem", "ask"); }

askem(str){
if(!str) { write("Ask who?\n"); return 1; }
if(str == "samson" || "merchant"){
write("Samson says I'm sorry I don't have much at the moment.\n"+
      "All I can offer you to buy is some:\n\n"+
      BOLD+"        Maple Syrup"+NORM+" (3300)\n"+
      BOLD+"        Liquid Cocaine"+NORM+"  (10000)\n");  
      return 1; }
      }
buy_it(string str){
    int buy;
    buy = str;
    if(!present("samson", this_object())){
    write("I'm sorry but Samson isn't here at the moment.\n");
    return 1;
    }
  if(!buy){ write("Please buy syrup.\n"); return 1; }
     if(buy == "syrup"){
     cost = 3300;
     item = clone_object("/players/fred/forest/Obj/syrup.c");
     what = "some maple syrup";
     }
  else if(buy == "liquid" || buy == "cocaine"){
     cost = 10000;
     item = clone_object("/players/fred/forest/Obj/lcocaine.c");
     what = "syringe";
     } 
  else{
     write("Samson replies: I'm sorry, I don't carry that.\n");
     return 1;
     }
if (call_other(this_player(), "query_money", 0) < cost) {
    write("Samson laughs: You'll have to make some more money first.\n");
    return 1;
     }          
 if(!this_player()->add_weight(item->query_weight())) {
    write("Samson replies: You can carry that much.\n");
    destruct(item);
    return 1; }                 
 write("You pay Samson "+cost+" coins and receive a "+what+".\n");
 say(tpn+ " purchases a "+what+".\n");
 move_object(item,this_player());
 this_player()->add_money(-(cost));
 return 1;
 }   

