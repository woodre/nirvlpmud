#define tp this_player()->query_name()

id(str) {return str == "sign";}
query_weight() {return 0;}
query_value() {return 1;}

long(){
write("You may order:\n"+
 "           Spiced Ale             :  10 golden coins\n"+
 "           Honey Mead             :  80 golden coins\n"+
 "           Brandy (warmed)        : 240 golden coins\n"+
 "           Suicide                : 400 golden coins\n"+
"\n");
}

init() {
  add_action("order","order");
}
order(str) {
string name, short_desc, mess;
int value, cost, strength, heal;

if (!str){
write("The comely barmaid asks: What do you want?\n");
say(tp+" hails the comely barmaid for a drink.\n");
 return 1;
}
if (str == "spiced ale" || str == "ale") {
say("The comely barmaid brings "+tp+" a "+str+".\n");
write("The comely barmaid brings you a "+str+".\n");
   mess = "That tasted great";
   heal = 1;
   value = 10;
   strength = 3;
}
else if (str == "honey mead" || str == "mead") {
write("The comely barmaid brings you a "+str+".\n");
say("The comely barmaid brings "+tp+" a "+str+".\n");
   mess = "A wave of pleasure rushes through your body";
   heal = 5;
   value = 80;
   strength = 8;
}
else if (str == "brandy") {
say("The comely barmaid brings "+tp+" a "+str+".\n");
write("The comely barmaid brings you a "+str+".\n");
   mess = "The brandy refreshes your mind and invigorates your body";
   heal = 20;
   value = 240;
   strength = 12;
}
else if (str == "suicide") {
say("The comely barmaid brings "+tp+" a "+str+".\n");
write("The comely barmaid brings you a "+str+".\n");
   mess = "You feel invincible!  You could fight all night";
   heal = 40;
   value = 400;
   strength = 14;
}

else {
 write("The comely barmaid says: You want a "+str+"?\n");
say(tp+" asks the comely barmaid for a strange drink.\n");
say("The comely barmaid says: I'm sorry, but we don't serve that here.\n");
write("The comely barmaid says: I'm sorry, but we don't serve that here.\n");
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
