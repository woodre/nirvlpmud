#define MAX 5000
inherit "obj/treasure";

int coins;

reset(arg) {
  restore_object("players/feldegast/obj/dbox");
  set_id("box");
  set_short("Donation Box");
  set_long(
"This is a battered wooden box hung on the wall.  Players who\n"+
"have excess money can put coins in the box.  Conversely,\n"+
"players who are down on their luck can get coins from the\n"+
"box if they need them.\n"+
"Commands: donate #, withdraw #.\n");
  set_weight(100);
}
long() {
  write(long_desc);
  write("There are "+coins+" coins in it.\n");
}
get() { return 0; }
init() {
  add_action("cmd_donate","donate");
  add_action("cmd_withdraw","withdraw");
}

cmd_donate(str) {
  int num;
  sscanf(str,"%d",num);
  if(num<0) {
    write("You cannot deposit a negative number of coins.\n");
    return 1;
  }
  if(this_player()->query_money()<num) {
    write("You don't have that much money.\n");
    return 1;
  }
  if(num+coins>MAX) {
    write("You fill up the donation box.\n");
    this_player()->add_money(coins-MAX);
    coins=MAX;
    save_object("players/feldegast/obj/dbox");
    return 1;
  }
  write("You put "+num+" coins into the donation box one at a time.\n");
  say(this_player()->query_name()+" puts "+num+" coins into the donation box one at a time.\n");
  this_player()->add_money(-num);
  if(this_player()->query_alignment()<1500) {
    this_player()->add_alignment(num/10);}
  coins+=num;
  save_object("players/feldegast/obj/dbox");
  return 1;
}
cmd_withdraw(str) {
  int num;
  sscanf(str,"%d",num);
  if(num<0) {
    write("You may not donate a negative number of coins.\n");
    return 1;
  }
  if(num>coins) {
    write("The donation box doesn't have that many coins.\n");
    return 1;
  }
  if(this_player()->query_money()>5000) {
    write("You already have plenty of money.\n");
    return 1;
  }
  coins-=num;
  this_player()->add_money(num);
  write("You take "+num+" coins out of the donation box.\n");
  say(this_player()->query_name()+" takes "+num+" coins out of the donation bin.\n");
  save_object("players/feldegast/obj/dbox");
  return 1;
}
