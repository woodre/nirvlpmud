#define TPM this_player()->query_money()
#define tp this_player()->query_name()

id(str) {return str == "guy";}
query_weight() {return 0;}
query_value() {return 1;}

short()  { return "A guy wearing a large cloak"; }
long(){
write("A guy wearing a large cloak.  You think you see strange metal \n"+
        "objects glinting from under its concealing cover.\n"+
        "\nGuy says: Pssst.  Want to <order> a paintball <clip>?\n"+
        "\nGuy says: Pssst.  Want to <order> a paintball <gun>?\n");
        }

init() {
  add_action("order","order");
  add_action("kill","kill");
}

kill(str)  {
if(str == "guy")  {
  write("The city guard will not let you.\n");
say(tp+" tries to attack the guy, but is stopped by the city guard.\n");
  return 1;
        }
        }

order(str) {
int cost, value;
object thing;
if (!str){
 write("Buy what?\n");
 return 1;
}
 if (str == "gun")  {
    write("You order a fully automatic paintball gun.\n");
   value = 300;
if(TPM < value) {write("That costs "+value+" golden coins, which you don't have.\n"); return 1; }
thing = clone_object("/players/saber/stuff/tag_gun.c");
}
  else if(str == "clip")  {
    write("You order a paintball clip.\n");
    value = 100;
if(TPM < value) {write("That costs "+value+" golden coins, which you don't have.\n"); return 1; }
thing = clone_object("/players/saber/stuff/clip.c");
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
