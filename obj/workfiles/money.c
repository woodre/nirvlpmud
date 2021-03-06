#include "/obj/clean.c"
#include <ansi.h>
#define MAXCOINS 80000
int money;
static string descr;
static int last_descr_money;
static int oldwt, olderwt;

reset(arg) {
    if (arg)
	return;
    money = 1;
}

/*
query_weight() { return 0; }
*/
query_weight() {
  if(money > 749) {
    if(money && money / 750 != oldwt)
    set_oldwt(money/750);
    return money / 750;
  }
  else 
  {
    if(money && 1 != oldwt) set_oldwt(1);
    return 1;
  }
}

/* suggested by Zeus at some point
  added by illarion 5 dec 2004
*/
update_descr() {
  if (!money) return; /* Rumplemintz 7-15-2011 */
  last_descr_money=money;
	switch(money) {
  	case 1: descr="A single gold coin"; break;
  	case 2..20: descr="A tiny stack of gold coins"; break;
  	case 21..50: descr="A small stack of gold coins"; break;
  	case 51..199: descr="A large stack of gold coins"; break;
  	case 200..499: descr="Several stacks of gold coins"; break;
  	case 500..999: descr="Several large stacks of gold coins"; break;
  	case 1000..1999: descr="Many large stacks of gold coins"; break;
  	case 2000..2999: descr="A small pile of gold coins"; break;
  	case 3000..4999: descr="A pile of gold coins"; break;
  	case 5000..5999: descr="A large pile of gold coins"; break;
  	case 6000..7999: descr="A huge pile of gold coins"; break;
  	case 8000..9999: descr="A gigantic pile of gold coins"; break;
  	default: descr="A veritable dragon horde of gold coins"; break;
	}
}

short() {
  if(!descr || money != last_descr_money)
    update_descr();
  if (money <= 0)
	  return 0;
	return descr+" ["+HIY+money+NORM+"]";
}
string wt_descr() {
  switch(query_weight()) {
    case 0..1: return "very light";
    case 2..3: return "not very heavy";
    case 4..6: return "fairly heavy";
    case 7..9: return "quite heavy";
    case 10..12: return "very heavy";
    default: return "extremely heavy";
  }
  return 0; /* Rumplemintz */
}

/* Added because Mizan pointed out coins have no
long
*/
long() {
  if(money < 0)
    return;
  if(money==1) {
    write("A single piece of Nirvana's main currency: the gold coin.\n"+
    "It's very light.\n");
    return;
  }
  write(money+" pieces of Nirvana's main currency: the gold coin.\n"+
        "They are "+wt_descr()+"\n");
}

get() {
  int cashola,diff;
    if(this_player()) {
      cashola = this_player()->query_money();
      if(cashola > MAXCOINS - 1) {
        write("You have the maximum amount of coins.\n");
        write("You pick up the coins and place them in your inventory.\n");
        return 1;
      }
      if(cashola + money > MAXCOINS) {
        diff = MAXCOINS - cashola;
        call_other(this_player(), "add_money", diff);
        write("You max your coins and place the remainder in your inventory.\n");
        money=money-diff;
        return 1;
      }
      call_other(this_player(), "add_money", money);
    }
    money = 0;
    set_heart_beat(1);
    return 1;
}

set_money(m) {
    money = m;
}

int query_goldamt() { return money; }

id(str) {
     if (str == "coins" && money > 1)
	return 1;
    if (str == "money")
	return 1;
    if (str == "moneyXX")
       return 1;
    if (str == "coin" && money == 1)
      return 1;
}

heart_beat() {
    if (money == 0)
	destruct(this_object());
}

check_loc(){ 
  object blah;
  blah=environment(this_object());
  if(blah)
    if(blah->query_npc() && blah->query_money()+money < blah->query_maxcoins())
    {
      blah->add_money(money);
/* LD doesn't like desting it so fast... -Bp 
      call_out("asplode",3);
*/
      destruct(this_object());
    }
return;
}
init() {
  check_loc();
  add_action("split","splitmoney");
}
is_money() {return 1;}

restore_thing(str){
      restore_object(str);
      return 1;
   }
save_thing(str){
      save_object(str);
      return 1;
   }
locker_arg() {  
    return money;
}
locker_init(str) {
    int x;
    if(sscanf(str,"%d",x)==1) money = x;
    else money = 0;
    return 1;
}

query_save_flag() { 
  if(money > 3000) return 1;
  return 0;
}
split(arg) {
  int spl;
  object splob;
  if(!arg || sscanf(arg,"%d",spl) != 1) {
    write("USAGE: splitmoney <# of coins>\n");
    return 1;
  }
  if (spl > money - 1 || spl < 0) {
    write("Number must be less than the total number of coins.\n");
    return 1;
  }
  splob = clone_object("obj/money");
  money = money - spl;
  splob->set_money(spl);
  move_object(splob,environment(this_object()));
  write("You split up the group of coins.\n");
  say(this_player()->query_name()+" splits up a group of coins.\n");
  return 1;
}

set_oldwt(arg) { 
  olderwt = oldwt;
  oldwt = arg;
}
query_oldwt() {
  return oldwt;
}
query_olderwt() { return olderwt; }
clear_olderwt() { olderwt = 0;}

query_descr() { return descr; }
asplode() {
  destruct(this_object());
}
