#define tp this_player()->query_name()
id(str) {return str == "sign";}
query_weight() {return 0;}
query_value() {return 1;}

long(){
write("You may order:\n"+
 "         Tea                      :  60 golden coins\n"+
 "         Umeshu (plum wine)       :  10 golden coins\n"+
 "         Sake (rice wine)         :  120 golden coins\n"+
 "         Junmai (rich rice wine)  :  300 golden coins\n");
}

init() {
add_action("order", "order");
}
order(str) {
string name, short_desc, mess;
int value, cost, strength, heal;

if (!str){
 write("Order what?\n");
 return 1;
}
if (str == "tea") {
  mess = "The Tea relaxes you";
   heal = 0;
   value = 60;
   strength = -5;
}
else if (str == "umeshu") {
   mess = "The rich sweet taste of the plum wine feels good";
   heal = 1;
   value = 10;
   strength = 3;
}
else if (str == "sake") {
   mess = "The sake gives you a rush";
   heal = 8;
   value = 120;
   strength = 10;
}
else if (str == "junmai") {
   mess = "You take a small shot of 'Junmai'.  You feel really good";
   heal = 30;
   value = 300;
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
if (strength > (call_other(this_player(), "query_level") +2)){if(strength >(call_other(this_player(), "query_level") + 4)) {
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
 write("You pay "+cost+" coins for a "+str+".\n");
 say(call_other(this_player(), "query_name", 0) + " orders a "+str+".\n");
  call_other(this_player(), "add_money", - cost);
  call_other(this_player(), "heal_self", heal);
  write(mess + ".\n");
 return 1;
}
