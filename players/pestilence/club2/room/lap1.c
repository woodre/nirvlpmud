#include "/open/ansi.h"
#define TP this_player()
#define TO this_object()
#define tp this_player()
#define TPN this_player()->query_name()
inherit "/players/vertebraker/closed/std/room";
object item;
int cost,DESIRE,JESSICA,KIRSTEN;
string what;

reset(arg) {
  cost = 500;
  KIRSTEN = 0;
  DESIRE = 0;
  JESSICA = 0;
  if(arg) return;

short_desc = ""+HIK+"Lap Dance Room ("+HIW+"Occupied"+NORM+""+HIK+")"+NORM+"";
long_desc =
  "    Beads hang down from the doorway of this lap dance room.  A\n"+
  "long blue couch sits against the west wall.  The strippers often\n"+
  "use this couch to give their customers a close and personal dance\n"+
  "that they will never forget.  Black lights in the corners set the\n"+
  "mood for intimacy.  On the wall there is a list of dancers you can\n"+
  "choose from.\n";
/*
add_property("NT");
add_property("PK");
*/
add_property("NT");
set_light(1);

items = ({
  "couch","A well wore blue couch, that has seen many a pussy in it's day",
  "beads","Blue, red and purple beads hand from the doorway",
  "wall","A white wall with lots of finger prints on it",
  "list","A list of names of strippers that will dance for you.  Type list to see the names",
  "lights","Blacks lights flash, to make you strain to see that nice pussy shot",
  "black lights","Black lights flash, to make you strain to see that nice pussy shot",
});

dest_dir = ({
"/players/pestilence/club2/room/pervert.c","east",
});

}

init() {
  ::init();

add_action("stop","quit");
   add_action("buy_it", "buy");
   add_action("list","list");
}
stop() {
if(TP->query_ghost() == 1) { return 0; }
else{
write("You can't quit from here.\n");
return 1; }
}

list(){
     write("Usage buy name.\n"+
           "1. Dance with Busty_____________________500 coins.\n"+
           "2. Dance with Kitty_____________________500 coins.\n"+
           "3. Dance with Cheryl____________________500 coins.\n");
     return 1;}

buy_it(string str){
        if(!str){ write("Pick a girl"); return 1; }
 if (call_other(this_player(), "query_money", 0) < cost) {
    write("I'm sorry, but you don't have enough coins for that.\n");
     return 1;
     }
        if(str == "busty"){
          if(DESIRE == 1){ write("Busty has already danced.\n"); return 1; }
          move_object(clone_object("players/pestilence/club/mob/busty.c"),TO);
          what = "Busty";
          DESIRE +=1;
          }
        else if(str == "kitty"){
          if(KIRSTEN == 1){ write("Kitty has already danced.\n"); return 1; }
          move_object(clone_object("players/pestilence/club/mob/kitty.c"),TO);
          what = "Kitty";
                    KIRSTEN +=1;
          }
        else if(str == "cheryl"){
          if(JESSICA == 1){ write("Cheryl has already danced.\n"); return 1; }
          move_object(clone_object("players/pestilence/club/mob/cheryl.c"),TO);
          what = "Cheryl";
                    JESSICA +=1;
          }

        else{
          write("Type list to see choices again.\n");
          return 1;
        }     
/*
 if (call_other(this_player(), "query_money", 0) < cost) {
    write("I'm sorry, but you don't have enough coins for that.\n");
     return 1;
     }          
*/
 write("You pay "+cost+" coins for a dance with "+what+".\n");
 say(tp->query_name() + " purchases a dance with "+what+".\n");
 tp->add_money(-cost);
 return 1;
}
