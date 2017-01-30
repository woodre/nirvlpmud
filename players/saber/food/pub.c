#define tp this_player()->query_name()

id(str) {return str == "sign";}
query_weight() {return 0;}
query_value() {return 1;}

long(){
write("You may order:\n"+
 "           Hot Chocolate          :  30 golden coins\n"+
 "           Spiced Ale             :  10 golden coins\n"+
 "           Honey Mead             :  80 golden coins\n"+
 "           Brandy (warmed)        : 240 golden coins\n");
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
if (str == "chocolate" || str == "hot chocolate") {
  mess = "The chocolate warms you to your tummy";
   heal = 0;
   value = 30;
   strength = -3;
}
else if (str == "melody chocolate") {
  str = "chocolate for Melody";
  mess = "You order melody a cup of chocolate";
  heal = 0;
  value = 30;
}
else if (str == "spiced ale" || str == "ale") {
   mess = "That tasted great";
   heal = 1;
   value = 10;
   strength = 3;
}
else if (str == "honey mead" || str == "mead") {
   mess = "A wave of pleasure rushes through your body";
   heal = 5;
   value = 80;
   strength = 8;
}
else if (str == "brandy") {
   mess = "The brandy refreshes your mind and invigorates your body";
   heal = 20;
   value = 240;
   strength = 12;
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
