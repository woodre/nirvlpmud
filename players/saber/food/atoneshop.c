#define TPM this_player()->query_money()
#define tp this_player()->query_name()

id(str) {return str == "merchant";}
query_weight() {return 0;}
query_value() {return 1;}

short()  { return "A merchant selling Potions of Atonement"; }
long(){
write("A cheerful merchant selling Potions of Atonement.\n"+
      "cost for said potion is 7000 coins\n"+
    "You may <buy> a <potion>.\n");
        }

init() {
    add_action("buy","buy");
    add_action("kill","kill");
}

kill(str)  {
if(str == "merchant")  {
  write("The city guard will not let you.\n");
say(tp+" tries to attack the merchant, but is stopped by the city guard.\n");
  return 1;
        }
        }

buy(str) {
int cost, value;
object thing;

if (!str){
 write("Buy what?\n");
 return 1;
}
 if (str == "potion")  {
   write("You buy a potion of atonement.\n");
   value = 7000;
if(TPM < value) {write("That costs "+value+" golden coins, which you don't have.\n"); return 1; }
thing = clone_object("/players/saber/food/atone.c");
}
else {
write("The merchant says: What do you want to buy?\n");
 return 1;
}

if (call_other(this_player(), "query_money", 0) < value) {
  write("That costs "+value+" gold coins, which you don't have.\n");
  return 1;
}
if(!this_player()->add_weight(thing->query_weight())) {
  write("You can not carry that item.\nNO SALE\n");
  destruct(thing);
return 1; }
cost = value;
 write("You play "+cost+" coins for a "+str+".\n");
 say(call_other(this_player(), "query_name", 0) + " buys a "+str+".\n");
 move_object(thing,this_player());
  call_other(this_player(), "add_money", - cost);
 return 1;
}
