#define tp this_player()->query_name()

id(str) {return str == "sign";}
query_weight() {return 0;}
query_value() {return 1;}

long(){
write("You may order:\n"+
 "           Tomato Juice           :  20 golden coins\n"+
 "           Drunken Nymph          :  80 golden coins\n"+
 "           Grasshopper            : 140 golden coins\n"+
 "           Fire and Ice           : 200 golden coins\n"+
 "           Umashu                 : 240 golden coins\n"+
 "           307 Ale                : 400 golden coins\n"+
 "           Dragon Death           : 650 golden coins\n"+
"\n");
}

init() {
  add_action("order","order");
}
order(str) {
string name, short_desc, mess;
int value, cost, strength, heal;

if (!str){
 write("Order what?\n");
 return 1;
}
if (str == "juice" || str == "tomato juice") {
   mess = "The tomato juice brings you back to your senses";
   heal = 0;
   value = 20;
   strength = -2;
}
else if (str == "drunken nymph" || str == "nymph") {
   mess = "The drunken nymph runs her hands down your body";
   heal = 5;
   value = 80;
   strength = 8;
}
else if (str == "grasshopper") {
   mess = "The grasshopper bounces down your throat";
   heal = 10;
   value = 140;
   strength = 10;
}
else if (str == "fire and ice" || str == "fire" || str == "ice") {
   mess = "You feel your head torn apart by two conflicting forces";
   heal = 17;
   value = 200;
   strength = 12;
}
else if (str == "umashu") {
   mess = "You blink as the sour then sweet taste washes across your body";
   heal = 20;
   value = 240;
   strength = 12;
}
 else if (str == "dragon" || str == "dragon death") {
   mess = "You feel the flames of a dying dragon rage through your innards";
   heal = 65;
   value = 650;
   strength = 15;
}
else if (str == "ale" || str == "307 ale") {
   mess = "Your heart skips a beat as the ale rages down your throat";
   heal = 40;
   value = 400;
   strength = 14;
}

else {
write("The bartender says: What do you want?\n");
 return 1;
}

if (call_other(this_player(), "query_money", 0) < value) {
  write("That costs "+value+" gold coins, which you don't have.\n");
  return 1;
}
cost = value;
if (strength > (call_other(this_player(), "query_level") +2)){if(strength >(call_other(this_player(), "query_level") + 5)) {
say(call_other(this_player(), "query_name", 0) + " orders a "+str+", and immediatly throws it up.\n");
 write("You order a "+str+", try to drink it, and throw up.\n");
}
else
{
say(call_other(this_player(), "query_name", 0) +" orders a "+str+", and spews it all over the room.\n");
 write("You order a "+str+", try to drink it, and sputter it all over the room!\n");
}
 call_other(this_player(), "add_money", - cost);
  return 1;
}

if (!call_other(this_player(), "drink_alcohol", strength)) {
  write("The bartender says: I think you've had enough.\n");
  say(call_other(this_player(),"query_name", 0) + " asks for a "+str+" but the bartender refuses.\n");
   return 1;
}
 write("You play "+cost+" coins for a "+str+".\n");
 say(call_other(this_player(), "query_name", 0) + " orders a "+str+".\n");
  call_other(this_player(), "add_money", - cost);
  call_other(this_player(), "heal_self", heal);
  write(mess + ".\n");
 return 1;
}
