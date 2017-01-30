#include "/players/fred/ansi.h"
inherit "room/room";

string what;
int cost;
object item, eddie;


reset(arg) {
if(!present("eddie")){
   eddie = clone_object("/players/fred/forest/Mon/eddie.c");
   move_object(eddie, this_object());
   }
if(arg) return;
set_light(1);

short_desc = BOLD+BLK+"LoOpy ViLLaGe ShOp"+NORM;
long_desc =
"  This is the armor shop of the small village.  There \n"+
"are odd pieces of armor laying strewn out on a counter\n"+
"and over the floor. To view the selection just type 'list'.\n"+
"A door leads you back onto the main road to the north.\n";
items = ({
  "armor",
  "Random pieces of armor that could protect you",
  "floor",
  "A floor made entirely of wood covered with dust and armor",
  "door",
  "An old door hanging by only one hinge",
  });

dest_dir = ({
  "/players/fred/forest/Rooms/vill_3.c","north",
});
}

query_no_fight(){
  return 1;
}

init(){
    ::init();
    add_action("buy_it","buy");
    add_action("list_it", "list");
   }

list_it(){
write(
      "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"+
      "@ 1."+GRN+" Football Helmet"+NORM+BOLD+"        100"+NORM+"\n"+
      "@ 2."+RED+" Fuzzy Mittens"+NORM+BOLD+"           50"+NORM+"\n"+
      "@ 3."+YEL+" Sandals"+NORM+BOLD+"                 75"+NORM+"\n"+
      "@ 4."+HIB+" Wetsuit"+NORM+BOLD+"                800"+NORM+"\n"+
      "@ 5."+MAG+" Bow Tie"+NORM+BOLD+"                 50"+NORM+"\n"+
      "@ 6."+HIC+" Light Shield"+NORM+BOLD+"           200"+NORM+"\n"+
      "@ 7."+BOLD+BLK+" A Flowing Scarf"+NORM+BOLD+"        450"+NORM+"\n"+
      "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n"+
      "   You may '"+GRN+"buy #"+NORM+"'\n\n");
      return 1;
      } 
buy_it(string str){
        int buy;
        buy = str;
        if(!present("eddie", this_object())){
        write("You don't see the store owner here.\n"); 
        return 1;
        }   
        if(!buy){ write("Please use: buy 1-6.\n"); return 1; }
        if(buy == "1"){
          cost = 100;
          item = clone_object("/players/fred/forest/Obj/fhelmet.c");
          what = "helmet";
          }
        else if(buy == "2"){
          cost = 50;
          item = clone_object("/players/fred/forest/Obj/fmits.c");
          what = "pair of mittens";
          }
        else if(buy == "3"){
          cost = 75;
          item = clone_object("/players/fred/forest/Obj/sndls.c");
          what = "pair of sandals";
          }
        else if(buy == "4"){
          cost = 800;
          item = clone_object("/players/fred/forest/Obj/wsuit.c");
          what = "wetsuit";
          }
        else if(buy == "5"){
          cost = 50;
          item = clone_object("/players/fred/forest/Obj/tie.c");
          what = "bow tie";
          }
        else if(buy == "6"){
          cost = 200;
          item = clone_object("/players/fred/forest/Obj/lshield1.c");
          what = "shield";
          }
         else if(buy == "7"){
           cost = 450;
           item = clone_object("/players/fred/forest/Obj/scarf.c");
           what = "scarf";
           }
        else{
          write("Sorry we don't have that.\n");
          return 1;
        }       
 if (call_other(this_player(), "query_money", 0) < cost) {
    write("Eddie informs you: You do not have enough money for that.\n");
    destruct(item);
    return 1;
     }          
 if(!this_player()->add_weight(item->query_weight())) {
    write("Eddie informs you: You can't carry that much.\n");
    destruct(item);
    return 1; }  
 write("You give Eddie "+cost+" coins and receive a "+what+".\n");                
 say(this_player()->query_name() + " buys a "+what+".\n");
 move_object(item,this_player());
 this_player()->add_money(-(cost));
 return 1;
 }   
