#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room.c";

reset(arg) {
  if(arg) return;
set_light(1);
short_desc = ""+GRN+"["+HIW+"Templar Gardens"+NORM+GRN+"]"+NORM+"";
long_desc =
  "  The stepping stone walk leads to the west edge of the garden. This\n"+
  "part of the garden is swarmed with snapdragon growing around the\n"+
  "base of a large statue.  Delphinium flowers line the walkway of the\n"+
  "stepping stones, on both sides. Thick bush has grown into a wall,\n"+
  "boxing in the garden to the north, south, and west. King Protea\n"+
  "flowers grow from within the walls, dotting white patches along the\n"+
  "stones.\n";
items = ({
  "flowers","Which flowers would you like to look at?\nYou can look at snapdraggon, delphinium, or king protea flowers",
  "wall","A thick wall of bush, covered with King Protea flowers",
  "north wall","A thick wall of bush, covered with King Protea flowers",
  "south wall","A thick wall of bush, covered with King Protea flowers",
  "west wall","A thick wall of bush, covered with King Protea flowers",
  "garden","A beautiful garden of snapdraggon, and delphinium flowers.\nYou can "+HIW+"pick"+NORM+" either of these flowers for "+HIY+"10"+NORM+" coins",
  "bush","A thick wall of bush, covered with King Protea flowers",
  "stone walk","A walk way made of circular stepping stones leading to the south",
  "walkway","A walk way made of circular stepping stones leading to the east",
  "walk","A walk way made of circular stepping stones leading to the south",
  "stepping stone walk","A walk way made of circular stepping stones leading to the south",
  "stones","Small circular stones set on the soft grass",
  "grass","Soft, neatly kept grass",
  "bowl","A small stone bowl used to collect donations for the garden",
  "donation bowl","A small stone bowl used to collect donations for the garden",
  "statue","A large statue of a female knight.  She is wearing a platemail\nchestplate, with angelic wings spreading wide apart from the\nback.  In one hand she wields a mighty broadsword, which is\npointed to the ground. Her other hand is outstretched, with\na cross clenched tightly in her fist",
  "knight","A large statue of a female knight.  She is wearing a platemail\nchestplate, with angelic wings spreading wide apart from the\nback.  In one hand she wields a mighty broadsword, which is\npointed to the ground. Her other hand is outstretched, with\na cross clenched tightly in her fist",
  "breastplate","A large plate of armor, with a cross over the chest",
  "platemail","A large plate of armor, with a cross over the chest",
  "platemail breastplate","A large plate of armor, with a cross over the chest",
  "wings","LArge wings about four feet in length each",
  "angelic wings","LArge wings about four feet in length each",
  "broadsword","A simple broadsword, with a long hilt",
  "hilt","The long hilt of a broadsword",
  "cross","A thin cross, held tightly in the statue's hand",
  "snapdragon","A long green stem, with multiple bulbs of white flowers",
  "delphinium","Tall stems with purple flowers, which grow in groups",
  "king protea","Large pink petals with a white center growing in a small bulb shape",
  "protea","Large pink petals with a white center growing in a small bulb shape",
  "base","The marble base of the statue",
});
dest_dir = ({
  "/players/jaraxle/templar/rooms/garden.c","east",
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

if(arg == "king" || arg == "king protea" || arg == "protea"){
  TP->add_money(-10);
   write("You place 10 coins in the bowl and pick a king protea from the wall.\n");
   MOCO("/players/jaraxle/templar/flowers/king_pro.c"),TP);
   say(TPN+" picks a flower from the wall.\n");
return 1; }                          
if(arg == "snapdragon" || arg == "snap" || arg == "dragon" || arg == "snap dragon"){
  TP->add_money(-10);
   write("You place 10 coins in the bowl and pick a snapdragon from the garden.\n");
  MOCO("/players/jaraxle/templar/flowers/snap.c"),TP);
   say(TPN+" picks a flower from the garden.\n");
return 1; }
if(arg == "delph" || arg == "delphinium"){
  TP->add_money(-10);
   write("You place 10 coins in the bowl and pick a delphinium from the garden.\n");
   MOCO("/players/jaraxle/templar/flowers/delph.c"),TP);
   say(TPN+" picks a flower from the garden.\n");
return 1; }
  write("That is not a flower you can pick here.\n"); 
return 1; }


exit(){    if(this_player()) this_player()->clear_fight_area();     }
