#include "/players/fred/ansi.h"
inherit "room/room";

string what;
int cost;
object item, joe;


reset(arg) {
if(!present("joe")){
  joe = clone_object("/players/fred/forest/Mon/joe.c");
  move_object(joe, this_object());
  }
if(arg) return;
set_light(1);

short_desc = BOLD+BLK+"LoOpy ViLLaGe ShOp"+NORM;
long_desc =
"  You have entered the local heal shop.  There are\n"+ 
"several heals available for you to purchase.  To\n"+
"see the what the shop has to offer you might be\n"+
"able to check the 'list'.\n";
  
dest_dir = ({
  "/players/fred/forest/Rooms/vill_4.c","south",
});
}

query_no_fight(){
  return 1;
}

init(){
    ::init();
    add_action("buy_it","buy");
    add_action("list_it","list");
   }
list_it(){
write(
      "_______________________\n\n"+
      "1."+GRN+" Pixie Stix"+NORM+BOLD+"      1800"+NORM+"\n"+
      "2."+RED+" Hi-C"+NORM+BOLD+"            1800"+NORM+"\n"+
      "3."+YEL+" Splooge"+NORM+BOLD+"         1800"+NORM+"\n"+
      "4."+HIB+" Whiskey"+NORM+BOLD+"         1800"+NORM+"\n"+
      "5."+MAG+" Grape Jelly"+NORM+BOLD+"     1200"+NORM+"\n"+   
      "_______________________\n\n"+
      "Please '"+GRN+"buy #"+NORM+"'.\n\n");
      return 1; }  
buy_it(string str){
        int buy;
        buy = str;
        if(!present("joe")){
        write("I'm sorry you don't see the shopkeeper here.\n");
        return 1;
        }
        if(!buy){ write("Please use: buy 1-4.\n"); return 1; }
        if(buy == "1"){
          cost = 1800;
          item = clone_object("/players/fred/forest/Obj/stix.c");
          what = "pixie stix";
          }
        else if(buy == "2"){
          cost = 1800;
          item = clone_object("/players/fred/forest/Obj/hic.c");
          what = "jug of punch";
          }
        else if(buy == "3"){
          cost = 1800;
          item = clone_object("/players/fred/forest/Obj/splooge.c");
          what = "tube of splooge";
          }
        else if(buy == "4"){
          cost = 1800;
          item = clone_object("/players/fred/forest/Obj/whiskey.c");
          what = "bottle of whiskey";
          }
        else if(buy == "5"){
          cost = 1200;
          item = clone_object("players/fred/forest/Obj/jelly.c");
          what = "jar of grape jelly";
          }
        else{
          write("Sorry we don't have that.\n");
          return 1;
        }       
 if (call_other(this_player(), "query_money", 0) < cost) {
    write("Joe tells you: You do not have enough money for that.\n");
    return 1;
     }          
 if(!this_player()->add_weight(item->query_weight())) {
    write("Joe tells you: You can't carry that much.\n");
    destruct(item);
    return 1; }  
 write("You give Joe "+cost+" coins and receive a "+what+".\n");                
 say(this_player()->query_name() + " buys a "+what+".\n");
 move_object(item,this_player());
 this_player()->add_money(-(cost));
 return 1;
 }   