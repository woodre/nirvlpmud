#define ME capitalize(this_player()->query_real_name())
inherit "obj/treasure";
   int money;
reset(arg) {
 if(arg) return;
  set_short("Monk Welfare Machine");
    set_alias("welfare");
     set_long("This welfare machine is to benefit the less fortunate in the\n" +
"guild. If you have a little extra money, why not make a deposit?\n" +
"The commands for the machine are: Deposit(amt), Withdraw(amt) or Balance.\n");
   set_weight(678);
    set_value(2);
   money = 1000;
}
 id(str) { return str == "welfare" || str == "machine"; }

init() {
 ::init();
add_action("deposit","deposit");
add_action("withdraw","withdraw");
add_action("balance","balance");
}


deposit(str) {
  int much, mymon, oldmon, newmon,level;
   object ob, ob1, obj;
  if(!str) {
  write("Donate how much?\n");
     return 1;
       }
   sscanf(str, "%d", much);
level = this_player()->query_level();
  if(level > 19) {
  write("I'm sorry but wizards can not deposit!\n");
    return 1;
}

   mymon = this_player()->query_money();
         if(much > mymon) {
    write("You do not have that much money to donate.\n");
            return 1;
              }
      if(much < 1) {
    write("You must deposit a positive number of coins!\n"+
          "Your attempt to cheat the guild is frowned upon.\n");
   say(ME+" just tried to cheat the Guild!\n");
      this_player()->heal_self(-10);
          return 1;
             }
    this_player()->add_money(-much);
     money = money + much;
   write("You open the Monk Welfare Machine and deposit "+much+" coins.\n"+
     "You feel a little bit better, knowing you did a good deed for\n"+
     "the Guild.\n");
 write("The welfare machine now holds "+money+" gold coins.\n");
  say(ME+" just deposited some money into the Welfare Machine!\n");
 this_player()->add_guild_exp(much/10);
    return 1;
}

withdraw(str) {
    int much,level,mym;
   if(!str) {
 write("How much would you like to withdraw?\n");
       return 1;
          }
    sscanf(str, "%d", much);

level = this_player()->query_level();
  if(level > 19) {
   write("I'm sorry but wizards can not withdraw!\n");
return 1;
}
mym = this_player()->query_money();
if(mym > 30000) {
  write("You want to withdraw and you have all that money already?\n"+
    "Come back when you are in need.\n");
return 1;
}
    if(much < 1) {
  write("You must withdraw an amount greater than Zero.\n");
        return 1;
           }
   if(much > money) {
  write("There is not that many coins present in the welfare machine.\n"+
     "The greatest amount you can withdraw is "+money+" coins.\n");
          return 1;
           }
    this_player()->add_money(much);
       money = money + (-much);
    write("You withdraw "+much+" coins from the machine.\n"+
    "Be sure to thank your fellow guild members for their generous\n"+
    "donations.\n");
    say(ME+" withdraws "+much+" coins from the welfare machine.\n");
         return 1;
 }

balance() {
  write("The Current Balance of the Welfare Machine is "+
      money+" coins.\n");
   return 1;
}
