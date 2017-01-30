/*
 * cglass.c - a glass for sipping non-intox champagne
 * Illarion 4/00
 */

#include "/players/illarion/dfns.h"
inherit "/obj/treasure";

int amount;

void reset(status arg) {
  if(arg) return;
  
  set_id("glass");
  set_alias("champagne glass");
  set_short("A delicate champagne glass");
  set_long("A perfectly clear champagne glass, with an impossibly thin stem,\n"+
           "and a wide, graceful bowl.\n");
  set_weight(1);
}
void show_amount() {
  switch(amount) {
    case 5: write("It is full of champagne.\n"); return;
    case 4: write("It is nearly full of champagne.\n"); return;
    case 2..3: write("It is about half-full of champagne.\n"); return;
    case 1: write("It is nearly empty.\n"); return;
    default: write("It is empty.\n"); return;
  }
}
void long() {
  ::long();
  show_amount();
  if(amount)
    write("You could "+BLD("sip")+" from the glass.\n");
}
int top_off(int amt) {
  int amt_needed;
  amt_needed=5-amount;
  if(amt_needed>amt) {
    amount+=amt;
    return 0;
  } else {
    amount=5;
    return amt-amt_needed;
  }
}
  
void init() {
  ::init();
  add_action("cmd_sip","sip");
}
status cmd_sip(string str) {
  if(!str || present(str,TP) != this_object())
    FAIL("Sip what?\n");
  if(!amount) {
    write("The glass is empty.\n");
    return 1;
  }
  write("You take a sip of the champagne.  The bubbles tickle your mouth\n"+
        "and throat.\n");
  say(TPN+" takes a sip of champagne.\n");
  amount--;
  return 1;
}
