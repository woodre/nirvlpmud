inherit "room/room";
 
reset(arg){
 
  if(!present("grok")) move_object(clone_object("/players/snow/MONSTERS/mol_tender"),
      this_object());
 
 if(!arg){
 
 set_light(1);
  short_desc="The Molehill Bar";
 long_desc=
"This is the Molehill Bar & Grill. As you look around this cramped,\n"+
"somewhat shabby room, you see that there is a sign hanging above \n"+
"you. It seems to have prices written on it. Perhaps after you have\n"+
"read the sign, you could order a meal.\n"+
"The only visible exit is: out.\n";
 
items=({
 "sign", "This is a sign listing prices. You should read it",
 "bar","This is the Molehill Bar" });
 
  }   }
 
init() {
 
add_action("read","read");
add_action("order","order");
add_action("move_out","out");
   }
 
move_out() {
move_object(this_player(),"/players/snow/newbie/newbie+7.c");
write("You climb up into the sunlight.\n");
say(this_player()->query_name()+" climbs up into the sunlight.\n");
return 1;
}
read(arg) {
 
if(!arg) {
  write("Read what?\n");
    }
else
if(arg == "sign") {
  write(
"<**DRINK*****************************PRICE********>\n"+
"<**                                             **>\n"+
"<**BrownWater (sobering)             5 coins    **>\n"+
"<**OJ                                35 coins   **>\n"+
"<**Milk                              50 coins   **>\n"+
"<**EggNog (alcoholic)                60 coins   **>\n"+
"<**Screwdriver (alcoholic)           80 coins   **>\n"+
"<**SparkleWater                      500 coins  **>\n"+
"<**                                             **>\n"+
"<**FOOD******************************PRICE********>\n"+
"<**                                             **>\n"+
"<**Pretzels                          5 coins    **>\n"+
"<**Fries                             100 coins  **>\n"+
"<**Burger                            250 coins  **>\n"+
"<**Chicken (whole)                   400 coins  **>\n"+
"<**Ribs                              1000 coins **>\n"+
"<**                                             **>\n"+
"<*************************************************>\n");
return 1;
  }
}
 
order() {
 if(!present("bartender",environment(this_player()))) {
    write("There is no bartender to order from.\n");
return 1;
  }
}
 
