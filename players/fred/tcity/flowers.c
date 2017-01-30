#include "/players/fred/ansi.h"
#include "/players/fred/defines.h"
inherit "/obj/treasure.c";

reset (arg) {

 set_id("flowers");
 set_short(RED+"A bouquet of flowers"+NORM);
 set_long(
 "  A beautiful bouquet of fresh cut flowers. Small droplets of\n"+
 "water glisten in the sunlight as they cling to the soft petals.\n"+ 
 "They are so beautiful you almost want to '"+BOLD+YEL+"send"+NORM+"' them to someone else.\n");
 set_weight(1);
 set_value(75);
}

init(){
 ::init();
   add_action("flowers_good", "send");
 }

flowers_good(str){
  int monies;
  string what, name;
  object ob, person;
  monies = 10+random(15);
  if(!str) { write("Send what?\n"); return 1; }
  if(!(sscanf(str, "flowers to %s", name))){
    write("Use 'send flowers to <name>.\n");
    return 0; }
  person = find_player(name);
  if(!person) { write(str+" can't be found.\n"); return 1; }
  ob = TO;
  if(call_other(TP, "query_money", 0) < monies){
    write("You don't have enough money to do that.\n");
    return 1; }
  write("You let out a really loud whistle...\n"+
        "A small halfling child rushes into the room.\n"+
        "He takes the flowers and a few coins from you and rushes out of the room.\n");
  TP->add_money(-monies); 
  move_object(ob, person);
  tell_object(person,
  BOLD+BLK+"A small halfing child runs into the room...\n"+
           "He hands you a bouquet of flowers from "+capitalize(TPN)+NORM+".\n");
  return 1; 
  } 




   

    

