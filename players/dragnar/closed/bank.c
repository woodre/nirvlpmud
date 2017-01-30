inherit "obj/treasure";
#include "/players/dragnar/closed/color.h"
#define JJ capitalize(this_player()->query_real_name())
int money;

id(str) { return str == "bank"; }
reset(arg) {
if(!arg) money = 0;
set_light(1);
}
short() {
	return "A" + BLINK+ " Newbie" +NOSTYLE+ " Bank";
}
long() {
	write("This is a newbie bank newbies can get money from.  Anyone\n" +
"can deposit money but only players level 5 and under can withdraw money.\n" +
"'Deposit <amount>' will put the amount into the bank and 'withdraw\n" +
"<amount>' will take out out the amount.  Please be thoughtful and not\n" +
"abuse it.\n" +
"It looks like the balance is "+money+" coins.\n");
write("\n");
}
init() {
	::init();
	add_action("deposit","deposit");
	add_action("withdraw","withdraw");
	}
deposit(str) {
	int amt;
	if(!str) {
	write("Deposit how much?\n");
	return 1;
	}
	sscanf(str, "%d", amt);
	if(this_player()->query_level() > 19) {
	write("Wizzes can't deposit into the bank!\n");
	return 1;
	}
	if(this_player()->query_money() < amt) {
	write("You do not have " +amt+ " coins!\n");
	return 1;
	}
	if(amt < 1) {
	write("You must deposit a positive number of coins!\n");
	return 1;
	}
	this_player()->add_money(-amt);
	write("You deposit " +amt+ " coins into the bank.\n" +
"All of the newbies cheer your name.\n");
	say(capitalize(this_player()->query_name()) + " deposits " +amt+ " coins.\n");
	money = money + amt;
	return 1;
}
withdraw(str) {
	int amt;
	if(!str) {
	write("How many coins to you wish to withdraw?\n");
	return 1;
	}
   if(this_player()->query_real_name() == "guest") {
   write("Sorry as guest you may not do that.\n");
  return 1; }
	sscanf(str, "%d", amt);
	if(amt < 0) {
	write("You must withdraw a positive amount.\n");
	this_player()->add_spell_point(-20);
	return 1;
	}
	if(this_player()->query_level() > 5) {
	write("You scum...you would steal the newbies money?\n");
   command("deposit "+this_player()->query_money(),this_player());
	return 1;
	}
	if(this_player()->query_money() > 10000) {
	write("You want to withdraw money when you have that much already?\n");
	command("deposit 1000",this_player());
	this_player()->add_spell_point(-20);
	return 1;
	}
	if(money < amt) {
	write("There are not enough coins in the bank!\n");
	write("The most you can withdraw is " +money+ " coins.\n");
	return 1;
	}
	if(amt > 5000) {
	write("You really shouldn't be that sellfish!\n");
	write("Withdraw a smaller amount.\n");
	return 1;
	}
	this_player()->add_money(amt);
	write("You withdraw " +amt+ " coins from the bank.  Good luck =)\n");
	say(capitalize(this_player()->query_name()) + " withdraws " +amt+ " coins.\n");
	money = money - amt;
	return 1;
}
get() { return 0; }
drop() { return 1; }
query_weight() { return 0; }
query_value() { return 1; }
