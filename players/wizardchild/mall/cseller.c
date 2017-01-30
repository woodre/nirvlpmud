short() { return "The Candy seller"; }
id(str) { return str == "seller" || str == "cseller" || str =="candy seller"; }
long() {
write("This young individual seems to sell candy here.\n");
write("Type \"list candy\" for a list of candy types, or \"buy <candy>\".\n");
}
init() { add_action("list", "list"); add_action("buy", "buy"); }
list(str) {
  if(str != "candy" && str != "candies") return 0;
write("[Name]        [Cost]\n");
write("Rock Candy      210\n");
write("Gumballs        400\n");
write("Sugar Daddys    800\n");
write("Jelly beans    1400\n");
write("Chocolates     3000\n");
write("Variety pack   6000\n");
return 1;
}
buy(str) {
object candy; int cost;
if(!str) return 0;
if(str == "rock candy" || str == "rock") {
candy = clone_object("players/wizardchild/mall/heals/rcandy");
cost = 210;
}else if(str == "gumballs" || str == "gum") {
candy = clone_object("players/wizardchild/mall/heals/gumballs");
cost = 400;
}else if(str == "sugar daddys" || str == "sugar daddies" || str == "sugar") {
candy = clone_object("players/wizardchild/mall/heals/sdaddy");
cost  = 800;
}else if(str == "jelly beans" || str == "jelly" || str == "beans") {
candy = clone_object("players/wizardchild/mall/heals/jbeans");
cost = 1400;
}else if(str == "chocolates" || str == "box of chocolates") {
candy = clone_object("players/wizardchild/mall/heals/boxchoc");
cost = 3000;
} else if(str == "variety pack" || str == "variety" || str == "pack") {
candy = clone_object("players/wizardchild/mall/heals/variety");
cost = 6000;
} else {
 write("The seller says: We don't have that.\n");
return 1;
}
if(this_player()->query_money() < cost) {
write("The seller says: You don't have enough money.\n");
return 1;
}
if(!this_player()->add_weight(candy->query_weight())) {
write("The seller says: You cannot carry that much.\n");
return 1;
}
move_object(candy, this_player());
write("You buy "+str+".\n");
say(this_player()->query_name()+" buys "+str+".\n");
this_player()->add_money(-cost);
return 1;
}

