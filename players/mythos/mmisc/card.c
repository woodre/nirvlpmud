#include "/players/mythos/closed/ansi.h"
#define tp this_player()
#define tpn tp->query_real_name()
#define SCR "/players/mythos/mmisc/credit"
#define max (tp->query_level())*4000
#define rate 15
int owe, timer, use;
static int amount;
static int ti,h,m;
id(str) {
    return str == "card" || str == "credit";
}

long() {
  write("A Credit Card.\n"+
        "To get money: credit <amount>\n"+
        "To pay back: pay_credit <amount>\n"+
        "To check credit balance: check\n"+
         "                             - Mythos\n");
}

short() {
    return "Credit Card";
}
drop() {return 1;}
get() {return 0;}

init_arg() {
  restore_object(SCR+tpn);
return 1;}

query_auto_load() {
    return "/players/mythos/mmisc/card.c:";
}

reset(arg) {
  if(arg) return;
  call_out("timing",100);
}

init() {
  restore_object(SCR+tpn);
  add_action("credit","credit");
  add_action("check","check");
  add_action("pay","pay_credit");
}

check() {
if(!restore_object(SCR+tpn)) { write("You have a credit limit of: "+max+"\n"); 
                               write("You owe nothing.\n"); return 1;}
ti = timer*200/3;
h = ti/60/60;
ti -= h*60/60;
m = ti/60;
ti -= m*60;
    write("Your credit limit: "+max+"\n"+
          "You have drawn: "+use+" <left: "+max-use+">\n"+
          "You owe: "+owe+"\n"+
          "Time left: "+h+" hours "+m+" min "+ti+" sec\n");
}

credit(str) {
  if(!str) { write("Usage: credit <amount>\n"); return 1;}
  if(sscanf(str,"%d",amount) != 1) { write("Usage: credit <amount>\n"); return 1;}
  if(amount < 1) { write("You may not do that!\n"); return 1;}
  if(restore_object(SCR+tpn)) { 
    if(amount+use > max) { write("You are going above your credit limit.\n");
                           return 1;}
    owe = amount+owe;
    } else {
    owe = amount; 
    timer = 69;}
  tp->add_money(amount);
  use = owe;
  owe = owe + (owe*rate)/100;
  save_object(SCR+tpn);
  write("You have taken "+amount+" from your credit account.\n");
  command("check",tp);
  return 1;}
  
pay(str) {
  if(!str) { write("Usage: pay <amount>\n"); return 1;}
  if(sscanf(str,"%d",amount) != 1) { write("Usage: pay <amount>\n"); return 1;}
  if(amount < 1) {  write("You may not do that!\n"); return 1;}
  if(tp->query_money() < amount) {write("You do not have that much!\n"); return 1;}
  if(restore_object(SCR+tpn)) { 
    if(owe - amount < 0) { owe = 0;}
    else { owe = owe - amount; }
  } else { write("You do not owe anything!\n"); return 1;}
  tp->add_money(-amount);
  write("You have paid "+amount+" to your credit account.\n");
  if(owe == 0) { rm(SCR+tpn+".o"); return 1;}
  else {
  save_object(SCR+tpn); }
  command("check",tp);
  return 1;}
  
timing() {
  if(restore_object(SCR+tpn)) {
  if(timer < 1 && timer > -3) { write("You owe money!\n");}
  if(timer < -2) { owe = owe + (owe*rate*2)/100; }
  if(timer < -5) { write(BOLD+"\nYOU MAY WISH TO PAY THE MONEY BACK!\n"+NORM); }
  if(timer < -7) { tp->lower_attrib(); }
  timer = timer - 1;
  save_object(SCR+tpn); 
  }
  call_out("timing",10);
  return 1;}
