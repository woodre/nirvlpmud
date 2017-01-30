#define TPM this_player()->query_money()
#define tp this_player()->query_name()

id(str) {return str == "sign";}
query_weight() {return 0;}
query_value() {return 1;}

short() { return "A shop sign"; }
long(){
write("You may buy:\n"+
 "           An emoter                :  50 golden coins\n"+
 "           A red rose               :  50 golden coins\n"+
 "           A silver mirror          :  50 golden coins\n"+
 "           Leather jacket           :  50 golden coins\n"+
 "           A leather sack           :  50 golden coins\n"+
 "           A corpse                 : 100 golden coins\n"+
 "           An eternal torch         : 500 golden coins\n"+
 "           A scroll of identify       : 150 golden coins\n"+
 "           Short Sword              : 200 golden coins\n"+
 "           A bottle of wine         : 300 golden coins\n"+
 "           Ring Mail                : 300 golden coins\n"+
 "           A rod corpse processor   : 350 golden coins\n"+
 "           Battle Axe               : 500 golden coins\n"+
 "           A bottle of white wine   :2500 golden coins\n"+
 "           A coin of sustenance     :2500 golden coins\n"+
 "\n");
}

init() {
  add_action("buy","buy");
}

buy(str) {
int cost, value;
object thing;
if (!str){
 write("Buy what?\n");
 return 1;
}
 if (str == "emoter")  {
   write("You buy an emoter\n");
   value = 50;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
thing = clone_object("/players/saber/stuff/emoter.c");
}
else if (str == "red rose" || str == "rose")  {
   write("You buy a red rose\n");
   value = 50;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
thing = clone_object("/players/saber/stuff/rose.c");
}
else if (str == "mirror" || str == "silver mirror")  {
   write("You buy a silver mirror\n");
   value = 50;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
thing = clone_object("/players/saber/stuff/mirror.c");
}
else if (str == "leather jacket" || str == "jacket")  {
   write("You buy a leather jacket.\n");
   value = 50;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
thing = clone_object("/players/saber/armor/ljacket.c");
}
else if (str == "sack" || str == "leather sack")  {
   write("You buy a leather sack.\n");
   value = 50;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
thing = clone_object("/players/saber/stuff/sack.c");
}
else if (str == "corpse")  {
   write("You buy a corpse.\n");
   value = 100;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
thing = clone_object("/players/saber/stuff/corpse2.c");
}
else if (str == "torch" || str == "eternal torch")  {
  write("You buy an eternal torch.\n");
   value = 500;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
thing = clone_object("/players/saber/stuff/etorch.c");
}
else if (str == "scroll" || str == "identify" || str == "scroll of identify") {
  write("You buy a scroll of identify.\n");
  value = 150;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
thing = clone_object("/players/vertebraker/misc/mage/items/id");
}
else if (str == "short sword" || str == "sword")  {
   write("You buy a short sword.\n");
   value = 200;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
thing = clone_object("/players/saber/weapons/ssword.c");
}
else if (str == "wine" || str == "bottle of fine" || str == "bottle")  {
   write("You buy a bottle of wine.\n");
   value = 300;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
thing = clone_object("/players/saber/food/wine.c");
}
else if (str == "ring mail" || str == "mail")  {
   write("You buy a suit of ring mail.\n");
   value = 300;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
thing = clone_object("/players/saber/armor/ringmail.c");
}
else if (str == "rod" || str == "processor")  {
  write("You buy a rod of processing.\n");
  value = 350;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
thing = clone_object("/players/saber/stuff/process.c");
}
else if (str == "battle axe" || str == "axe")  {
   write("You buy a battle axe.\n");
   value = 500;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
thing = clone_object("/players/saber/weapons/battleaxe.c");
}
else if (str == "white" || str == "white wine")  {
   write("You buy a bottle of white wine.\n");
   value = 2500;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
thing = clone_object("/players/saber/food/bigwine.c");
}
else if (str == "coin" || str == "coin of sustenance")  {
   write("You buy a coin of sustenance.\n");
   value = 2500;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
thing = clone_object("/players/saber/food/icoin.c");
}
else {
write("A vioce booms out: What do you want to buy?\n");
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
 write("You pay "+cost+" coins for a "+str+".\n");
 say(call_other(this_player(), "query_name", 0) + " buys a "+str+".\n");
 move_object(thing,this_player());
  call_other(this_player(), "add_money", - cost);
 return 1;
}
