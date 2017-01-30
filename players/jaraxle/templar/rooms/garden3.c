#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room.c";

reset(arg) {
  if(arg) return;
set_light(1);
short_desc = ""+GRN+"["+HIW+"Templar Gardens"+NORM+GRN+"]"+NORM+"";
long_desc =
  ""+GRN+"  A shallow, curved pond at the end of the walkway takes up\n"+
  "the center of the east garden.  In the middle of the pond a\n"+
  "large sundial reflects the time. Around the pond grows thick\n"+
  "gardenia in small bunches.  Rose bushes surround the garden\n"+
  "like a wall, enclosing it in a thick hedge.  The castle can\n"+
  "be seen over the rose bushes looming overhead while to the\n"+
  "west the entrance to the garden can be seen."+NORM+"\n";
items = ({
  "flowers","Which flowers would you like to look at?\nYou can look at the roses, or the gardenia",
  "gardenia","A collection of white petals wrapped around a green stem",
  "roses","Huge red blossoms on dark green stems.\nWatch out for the thorns",
  "rose","A large rose blossom on a beautiful stem",
  "rose bushes","Huge red blossoms on dark green stems.\nWatch out for the thorns",
  "walkway","A walkway made of circular stepping stones",
  "stones","Small circular stones set on the soft grass",
  "stepping stones","Small circular stones set on the soft grass",
  "grass","Soft, neatly kept grass",
  "pond","A small pond with many curves.\nThere is some change at the bottom",
  "change","Donations given to the garden for picking the flowers",
  "garden","A lush garden of roses, and gardenia.\nYou can "+HIW+"pick"+NORM+" either of these flowers for "+HIY+"10"+NORM+" coins",
  "sundial","blah",
  "bunches","A collection of white petals wrapped around a green stem",
  "castle","The castle of the Knights Templar",
  "entrance","The entrance of the Templar Gardens",
  "hedge","A large row of hedges creating a natural fence around the garden",
  "fence","A large row of hedges creating a natural fence around the garden",
  "bushes","Huge red blossoms on dark green stems.\nWatch out for the thorns",
});
dest_dir = ({
  "/players/jaraxle/templar/rooms/garden.c","west",
});

}

long(arg)
{
    if(arg == "sundial")
    {
write("The sundial shows "+ctime()+"\n");
return; }
   ::long(arg);  
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

if(arg == "rose" || arg == "roses" || arg == "rose bush") {
  TP->add_money(-10);
   write("You lightly toss 10 coins into the pond.\nThe coins drop in with light 'bloops'.\nYou pluck a rose from the rose bushes.\n");
   MOCO("/players/jaraxle/templar/flowers/rose.c"),TP);
   say(TPN+" picks a flower from the garden.\n");
return 1; }                          
if(arg == "gardenia bunch"  || arg =="gardenia"){
  TP->add_money(-10);
   write("You lightly toss 10 coins into the pond.\nThe coins drop in with light 'bloops'.\nYou pick a gardenia from about the pond.\n");
   MOCO("/players/jaraxle/templar/flowers/gardenia.c"),TP);
   say(TPN+" picks a flower from the garden.\n");
return 1; }
  write("That is not a flower you can pick here.\n"); 
return 1; }


exit(){    if(this_player()) this_player()->clear_fight_area();     }
