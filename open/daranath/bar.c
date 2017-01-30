#define tp this_player()->query_name()

id(str) {return str == "sign";}
query_weight() {return 0;}
query_value() {return 1;}

long(){
write("You may order:\n"+
 "           Stong Coffee           :  30 gold coins\n"+
 "           Daranath's Brew        :  10 gold coins\n"+
 "           Furiondian Wine        :  80 gold coins\n"+
 "           Guiness Draft          : 250 gold coins\n");
}

init() {
 add_action("order");
   add_verb("order");
}
order(str) {
string name, short_desc, mess;
int value, cost, strength, heal;

if (!present("homer")) {
write("There is no bartender present to take your order. Sorry.\n");
return 1;
}

if (!str){
 write("Homer says: What is it you would like to order?\n");
 return 1;
}
if (str == "coffee" || str == "strong coffee") {
   mess = "The strong coffee brings you back to sobriety";
   heal = 0;
   value = 30;
   strength = -3;
}
else if (str == "Daranath's brew" || str == "brew") {
   mess = "You down a mug of Daranath's personal brew.\n"+
          "It has a strong, yet unnerving taste";
   heal = 1;
   value = 10;
   strength = 3;
}
else if (str == "furiondian wine" || str == "wine") {
   mess = "The wine has a warming and soothing effect on your body";
   heal = 5;
   value = 80;
   strength = 8;
}
else if (str == "draft" || str == "guiness draft") {
   mess = "The perfect pint";
   heal = 20;
   value = 250;
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
  write("Homer says: I think you've had enough.\n");
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
