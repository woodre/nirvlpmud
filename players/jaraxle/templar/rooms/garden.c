#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room.c";

reset(arg) {
  if(arg) return;
set_light(1);
short_desc = ""+GRN+"["+HIW+"Templar Gardens"+NORM+GRN+"]"+NORM+"";
long_desc =
  "  A lovely garden, filled with a great assortment of flowers. Patches\n"+
  "of flowers are growing on both sides of a stepping stone walk. The\n"+
  "stones make pathways to the north, west and east into more sections\n"+
  "of the garden. Gerber daisy grow heavily to the left, while a group of\n"+
  "chrysanthemum flowers grow on the right side of the walk. A small\n"+
  "donation dish is placed at the base of the flowers. An archway leads\n"+
  "out into the tower.\n";
items = ({
  "garden","A lush garden of gerber daisy, and chrysanthemum flowers.\nYou can "+HIW+"pick"+NORM+" either of these flowers for "+HIY+"10"+NORM+" coins",
  "dish","A small, stone donation dish with coins sitting in it",
  "patches","Small gatherings of flowers",
  "flowers","Which flowers would you like to look at?\nYou can look at the gerber flowers, or the chrysanthemum flowers",
  "walk","A walk way made of circular stepping stones",
  "gerber","A small flower with a brown center, surrounded by large yellow petals",
  "daisy","A small flower with a brown center, surrounded by large yellow leaves",
  "chrysanthemum","A full flower with a bright yellow center, surrounded by thin, pointed, red petals",
  "stone walk","A walk way made of circular stepping stones",
  "stones","Small circular stones set on the soft grass",
  "grass","Soft, neatly kept grass",
  "pathway","A path of stepping stones to the north, east and west",
  "archway","A stone archway leading out to the tower",
});

MOCO("/players/jaraxle/templar/mon/aster.c"), TO);
dest_dir = ({
  "/players/jaraxle/templar/rooms/garden2.c","north",
  "/players/jaraxle/templar/rooms/courtyard.c","out",
  "/players/jaraxle/templar/rooms/garden4.c","west",
  "/players/jaraxle/templar/rooms/church.c","enter",
});

}

init(){
        ::init();

this_player()->set_fight_area();
add_action("pick_it","pick");
}
pick_it(arg) {
    if(TP->query_money() < 10){
  write("You do not have enough coins to donate to the garden to pick its flowers.\n");
    return 1; }

    if(!TP->add_weight(1)){ write("You cannot carry this flower.\n"); return 1; }

if(arg == "daisy" || arg == "gerber" || arg == "gerber daisy") {
  TP->add_money(-10);
   write("You place 10 coins in the dish and pick a gerber daisy from the garden.\n");
   MOCO("/players/jaraxle/templar/flowers/gerber.c"),TP);
   say(TPN+" picks a flower from the garden.\n");
return 1; }                          
if(arg == "chrysanthemum"  || arg =="chrys"){
  TP->add_money(-10);
   write("You place 10 coins in the dish and pick a chrysanthemum from the garden.\n");
   MOCO("/players/jaraxle/templar/flowers/chrys.c"),TP);
   say(TPN+" picks a flower from the garden.\n");
return 1; }
  write("That is not a flower you can pick here.\n"); 
return 1; }


exit(){    if(this_player()) this_player()->clear_fight_area();     }
