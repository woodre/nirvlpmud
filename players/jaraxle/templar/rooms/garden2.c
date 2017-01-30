#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room.c";

reset(arg) {
  if(arg) return;
set_light(1);
short_desc = ""+GRN+"["+HIW+"Templar Gardens"+NORM+GRN+"]"+NORM+"";
long_desc =
    "  The north edge of the garden is filled with a beautiful bed of tulips\n"+
  "and orchids. A stepping stone walk leads south to the entrance of the\n"+
  "garden. A large water fountain with a polished stone statue has been\n"+
  "built as the centerpiece of the gardens.\n";

items = ({
  "base","A round fountain base, with a small donation dish attached",
  "lion","A large, powerful looking, male lion sits in the middle\nof the fountain.  It has a large mouth with pointed teeth.\nA huge mane surrounds the lions head",
  "edge","The north edge of the garden is boxed in with a wall of bushes",
  "bushes","Thick bushes making a wall edge for the garden",
  "wall","Thick bushes making a wall edge for the garden",
  "fountain","An impressive fountain with a large round base.\nIn the center of the fountain sits a graceful lion.\nWater pours out of the lion's mouth into the base of the fountain",
  "garden","A lush garden of orchid, and tulip flowers.\nYou can "+HIW+"pick"+NORM+" either of these flowers for "+HIY+"10"+NORM+" coins",
  "dish","A small, stone, square donation dish with coins sitting in it",
  "donation dish","A small, stone, square donation dish with coins sitting in it",
  "flowers","Which flowers would you like to look at?\nYou can look at the tulips, or the orchids",
  "walk","A walk way made of circular stepping stones to the south",
  "stone walk","A walk way made of circular stepping stones leading to the south",
  "stones","Small circular stones set on the soft grass",
  "grass","Soft, neatly kept grass",
  "orchids","A small group of white petaled flowers with a yellow center",
  "orchid","A small group of white petaled flowers with a yellow center",
  "tulip","A long stemmed tulip.  This tulip has a thick white bulb which sits on a long green stem",
  "tulips","Long stemmed tulips.  This tulip has a thick white bulb which sits on a long green stem",
});

 dest_dir = ({
  "/players/jaraxle/templar/rooms/garden.c","south",
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

if(arg == "orchid"){
  TP->add_money(-10);
   write("You place 10 coins in the dish and pick an orchid from the garden.\n");
   MOCO("/players/jaraxle/templar/flowers/orchid.c"),TP);
   say(TPN+" picks a flower from the garden.\n");
return 1; }                          
if(arg == "tulip"){
  TP->add_money(-10);
   write("You place 10 coins in the dish and pick a tulip from the garden.\n");
   MOCO("/players/jaraxle/templar/flowers/tulip.c"),TP);
   say(TPN+" picks a flower from the garden.\n");
return 1; }
  write("That is not a flower you can pick here.\n"); 
return 1; }


exit(){    if(this_player()) this_player()->clear_fight_area();     }
