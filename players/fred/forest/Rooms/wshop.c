#include "/players/fred/ansi.h"
inherit "room/room";

object owner;
string what;
int cost;
object item;


reset(arg) {
if(!present("brenner")){
        owner = clone_object("/players/fred/forest/Mon/wowner.c");
        move_object(owner, this_object());
        }
  if(arg) return;
set_light(1);
short_desc = BOLD+BLK+"LoOpy ViLLaGe ShOp"+NORM;
long_desc =
"  This is the local weapons shop.  There are a few assorted\n"+
"weapons displayed proudly on shelves behind the counter. To\n"+
"view the selection simply type 'list'. A door leads north\n"+
"back to the village road.\n";
items = ({
  "shelves",
  "Finely crafted wooden shelves that hold the various weapons",
  "counter",
  "A large counter with a small metal box and a piece of chalk on it",
  "box",
  "A crude looking metal boxed used to hold store money",
  "chalk",
  "A small piece of white chalk to add up totals", });
    
dest_dir = ({
  "/players/fred/forest/Rooms/vill_6.c","north",
});
}

query_no_fight(){
  return 1;
}

init(){
    ::init();
    add_action("buy_it","buy");
    add_action("list_it", "list"); }


list_it(){
write(
      "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n"+  
      "~~~~Item~~~~~~~~~~~~~~~~~~~~Cost\n"+
      "~1. "+GRN+"A Pointy Stick"+NORM+".........."+BOLD+"600"+NORM+"\n"+
      "~2. "+RED+"Croquet Mallet"+NORM+"........."+BOLD+"1500"+NORM+"\n"+
      "~3. "+YEL+"Swiss Army knife"+NORM+"......."+BOLD+"2000"+NORM+"\n"+
      "~4. "+HIB+"Quade Staff"+NORM+".........."+BOLD+"10000"+NORM+"\n"+
      "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+
      " Please '"+GRN+"Buy #"+NORM+"'\n\n");
      return 1;
      }
buy_it(string str){
    int buy;
    buy = str;
    if(!present("brenner", this_object())){
    write("You don't see the weaponsmith here.\n");
    return 1;
    }
  if(!buy){ write("Please Buy 1-4.\n"); return 1; }
     if(buy == "1"){
     cost = 600;
     item = clone_object("/players/fred/forest/Obj/pstick.c");
     what = "stick";
     }
   else if(buy == "2"){
     cost = 1500;
     item = clone_object("/players/fred/forest/Obj/cmallet.c");
     what = "mallet";
     }
   else if(buy == "3"){
     cost = 2000;
     item = clone_object("/players/fred/forest/Obj/sknife2.c");
     what = "knife";
     }
   else if(buy == "4"){
     cost = 10000;
     item = clone_object("/players/fred/forest/Obj/qstaff.c");
     what = "staff";
     }
   else{
     write("Brenner says: I'm sorry, we don't carry that.\n");
     return 1;
     }
if (call_other(this_player(), "query_money", 0) < cost) {
    write("Brenner says: I'm sorry, but you don't have enough for that.\n");
    return 1;
     }          
 if(!this_player()->add_weight(item->query_weight())) {
    write("Brenner says: It doesn't look like you can carry that.\n");
    destruct(item);
    return 1; }                 
 write("You pay Brenner "+cost+" coins and receive a "+what+".\n");
 say(this_player()->query_name() + " purchases a "+what+".\n");
 move_object(item,this_player());
 this_player()->add_money(-(cost));
 return 1;
 }   
