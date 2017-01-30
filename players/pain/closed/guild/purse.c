int money;

reset(arg) {
    if (arg)
 money = 0;
	return;
}

short(){
 return "A coin pouch";
}

long(){
 if(!present("mrobe", this_player())){
   write("A musty old bag the crumples to dust in your hands.\n");
   destruct(this_object());  } else {
 write("A small pouch to hold coins in.\n");
 if(money > 1)
   write("There are "+money+" gold coins in it.\n");
 else
   write("The pouch is empty.\n");
 write("You can 'purse <x>' and 'gcoin <x>' to add/remove coins.\n");
           }
}

id(str) {
 return str == "pouch" || str == "coin pouch" || str == "purse"
        || str == "monk_obj";
}

query_value() { return 0; }

query_weight() { return 0; }

drop() { return 1; }

init(){
 add_action("purse","purse");
 add_action("get_coin","gcoin");
}

purse(str){
 int amt;
if(!str){
 write("Usage: purse <amt>.\n");
 return 1; }
sscanf(str, "%d", amt);
if(amt > 10000) {write("The purse can not hold that much.\n");return 1;}
if(amt > this_player()->query_money()){
 write("You do not have that many coins.\n");
 return 1; }
if(amt < 1){
 write("Usage: purse <amt>.\n");
 return 1; }
money = money + amt;
this_player()->add_money(-amt);
write("You put "+amt+" coins into your purse.\n");
if(money > 10000){
write("Your purse can only hold 10000 coins.  The purse is "+
"now full.\n");
money = 10000;   }
return 1;
}

get_coin(str){
 int amt;
if(!str){
 write("Usage: gcoin <amt>.\n");
 return 1; }
sscanf(str, "%d", amt);
if(amt > money){
 write("There aren't that many coins in your purse.\n");
 return 1; }
if(amt < 1){
 write("Usage: gcoin <amt>.\n");
 return 1; }
write("You take "+amt+" gold coins from your purse.\n");
money = money - amt;
this_player()->add_money(amt);
return 1;
}
