/*
 *     Fayawyn Fairy Dealer  
 *     faydealer       
 *     Cloud 2009
 */


#include "/obj/ansi.h"
#define CO clone_object

inherit "room/room";

object Bottle;
int Cost;
string What;
     
reset(arg)
 {

     if(!present("azlyn"))
  {
    move_object(clone_object("/players/cloud/Fayawyn/mobs/azlyn"),
      this_object());
  }

  if(!arg)
  { 

  set_light(1);
  
  short_desc = HIM+"Fayawyn Fairy Dealer"+NORM;

  long_desc=
	""+HIC+"The run-down hut appears to be some sort of twisted shop."+NORM+"\n" +  
	""+HIC+"Small, clear bottles clutter the entire area, while a large"+NORM+"\n" + 
	""+HIC+"cage full of screaming fairies sits behind the long counter."+NORM+"\n" +
	""+HIC+"A sign is suspended from the roof by strong, tan twine."+NORM+"\n"; 
  items=({
     "sign",
       	"A rectangular piece of wood that you can read",
     "bottles",
     	"Small and clear, the bottles make it hard for you to maneuver around the shop",
     "cage",
     	"The large wooden cage is full of fairies. A small, square door is on the front",
     "fairies",
     	"The poor things are trapped inside the cage and ready to be sold",
     "counter",
     	"The thick wooden counter takes up the entire width of the hut providing a large work area",
     "roof",
     	"The roof is rotten and caving in. Shingles probably could have prevented this",
     "twine",
     	"One end of the twine is nailed to the sign, the other nailed the remaining roof",
     "door",
     	"A small door with a tiny brass knob for a handle allowing access to inside the cage",
     "knob",
     	"It is very tarnished and weathered",
      "handle",
     	"It is very tarnished and weathered",
  
   });

   dest_dir=({
        "/players/cloud/Fayawyn/rooms/fay3.c",  "out",
   });} 



   
}
  init() {
     ::init();
  add_action("read_sign","read");
  add_action("cmd_buy","buy");
  }

read_sign(str) {
  if(!str) {
    notify_fail("Read what?\n");
    return 0;
  }
  else if(str == "sign") {
  write(
" _______________________________________________ \n" +  
"|        _____                                  | \n" +
"|       `.___,'                                 | \n" +
"|        (___)                                  | \n" +
"|        <   >                                  | \n" +
"|        ,   ,            Three Fairies         | \n" + 
"|       ,     ,            1600 Coins           | \n" +
"|      ,       ,     Guaranteed Satisfaction    | \n" +
"|     ,         ,          all you have         | \n" +
"|     :         :            to do              | \n" +
"|     |"+HIW+"E A T M E"+NORM+"|             is                | \n" +
"|     :         ;   "+HIW+"       buy bottle"+NORM+"           | \n" +
"|     '        '                                | \n" +
"|       `.___.'                                 | \n" +
"|_______________________________________________| \n\n");

   say(capitalize(this_player()->query_name())+" reads the sign.\n");

   return 1; }
}

cmd_buy(string str)
{
  if(!present("azlyn", this_object()))
  {
    write("Azlyn is not here to help you.\n");
      return 1;
  }

  if(!str){ write("Azlyn says, \"I don't have all day.\"\n"); return 1; }
  if(str == "bottle" || str == "fairies")
  {
    Cost = 1600;
    Bottle = CO("/players/cloud/Fayawyn/obj/fheal.c");
    What = ""+HIC+"Fairy Bottle"+NORM+"";
  }

  else
  {
    write("Azlyn says, \"I only sell delicious fairies.\"\n");
      return 1;
  }     

  if (call_other(this_player(), "query_money", 0) < Cost) 
  {
    write("Azlyn says, \"You're broke. Come back when you have more money.\"\n");
      return 1;
  }             

  if(!this_player()->add_weight(Bottle->query_weight())) 
  {
    write("Azlyn says, \"Lighten your load, then we can talk.\"\n");
    destruct(Bottle);
      return 1; 
  }                     
  write("You give Azlyn "+Cost+" coins for the "+What+".\n");
  say(this_player()->query_name() + " buys a "+What+".\n");
  move_object(Bottle,this_player());
  this_player()->add_money(-Cost);
    return 1;
}
