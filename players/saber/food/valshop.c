#define TPM this_player()->query_money()
#define tp this_player()->query_name()

id(str) {return str == "merchant";}
query_weight() {return 0;}
query_value() {return 1;}

short()  { return "A merchant selling Valentines"; }
long(){
write("A cheerful merchant selling Valentines.\n"+
    "You may <buy> a <valentine>, a <bear> or a <rose> for 100 coins.\n");
        }

init() {
  add_action("buy","buy");
  add_action("kill","kill");
}

kill(str)  {
if(str == "merchant")  {
  write("You can't fight the power of love!\n");
say(tp+" tries to attack the merchant, but can't fight the power of love.\n");
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
 if (str == "valentine")  {
   write("You buy a valentine.\n");
   value = 100;
if(TPM < value) {write("That costs "+value+" golden coins, which you don't have.\n"); return 1; }
thing = clone_object("/players/saber/stuff/valentine.c");
}
else if (str == "rose")  {
  write("You buy a red rose.\n");
  value = 100;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
thing = clone_object("/players/saber/stuff/rose.c");
}
else if (str == "bear")  {
  write("You buy a teddy bear.\n");
  value = 100;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
thing = clone_object("/players/saber/stuff/bear.c");
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
 write("You play "+cost+" coins for a number "+str+".\n");
 say(call_other(this_player(), "query_name", 0) + " buys a "+str+".\n");
  call_other(this_player(), "add_money", - cost);
  move_object(thing,this_player());
 return 1;
}
