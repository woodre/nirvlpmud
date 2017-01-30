int money;
 
reset(arg) {
    if (arg)
 money = 0;
        return;
}
 
short(){
 return "A checkbook";
}
 
long(){
 if(!present("watch", this_player())){
   write("Thief!! The paper checks burn away in the midday sun.\n");
   destruct(this_object());  } else {
 write("This checkbook is so you don't have to burdened with carrying excess cash\n");
 if(money > 1)
   write("Your current balance is: "+money+" You're loaded.\n");
 else
   write("Hard times have fell upon you. You current balance is 0..ZILCH.\n");
 write("You can 'deposit <x>' and 'withdraw <x>' to add/remove coins.\n");
           }
}
 
id(str) {
 return str == "checkbk" || str == "check book" || str == "check"
        || str == "merch_chkbk";
}
 
query_value() { return 0; }
 
query_weight() { return 0; }
 
drop() { return 1; }
 
init(){
 add_action("deposit","deposit");
 add_action("withdraw","withdraw");
}
 
deposit(str){
 int amt;
if(!str){
 write("Usage: deposit <amt>.\n");
 return 1; }
sscanf(str, "%d", amt);
if(amt > 20000) {write("Currently, we are unable to cover such 'healthy' transactions.\n");return 1;}
if(amt > this_player()->query_money()){
 write("That amount and your wishes combined still = SQUAT.\n");
 return 1; }
if(amt < 1){
 write("Usage: deposit <amt>. C'mon get it together.\n");
 return 1; }
money = money + amt;
this_player()->add_money(-amt);
write("You deposit "+amt+" into your account. Saving for a rainy day.\n");
if(money > 20000){
write("Your account is only authorized to hold 20,000.  Share your excess "+
"wealth. You account is maxed.\n");
money = 20000;   }
return 1;
}
 
withdraw(str){
 int amt;
if(!str){
 write("Usage: withdraw <amt>.\n");
 return 1; }
sscanf(str, "%d", amt);
if(amt > money){
 write("Unfortunately, you cant spend what you don't have. Try again.\n");
 return 1; }
if(amt < 1){
 write("Usage: withdraw <amt>. Thank much money normally come in handy?\n");
 return 1; }
write("You write out a check for "+amt+" in gold.\n");
money = money - amt;
this_player()->add_money(amt);
return 1;
}
 
 
 
