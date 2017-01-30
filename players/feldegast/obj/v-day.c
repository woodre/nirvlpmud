/*
File: v-day.c
Author: feldegast
Date: 2-14-01
Description:
  Dispenser for valentine's day stuf.
*/
#include "/players/feldegast/defines.h"

reset(arg) {
  if(arg) return;
  move_object(this_object(),"/room/vill_green");
}

short() {
  return "Valentine's Day Dispenser";
}

id(str) {
  return str=="dispenser";
}

long() {
  write("You may 'buy' the following items from the dispenser:\n"+
        "  Box of Chocolates..............150\n"+
        "  Flowers........................200\n"+
        "  Rose(a Traff product)..........250\n"+
        "  Valentine(a Saber product)......75\n");
}

is_castle() { return 1; }

void init() {
  add_action("cmd_buy", "buy");
}

int cmd_buy(string str) {
  object ob;
  string file;
  int value;
  if(!str) {
    notify_fail("Buy what?\n");
    return 0;
  }
  switch(str) {
    case "box": case "chocolates":
      file="/players/feldegast/heals/chocolates";
      value=150;
      break;
    case "flowers":
      file="/players/feldegast/obj/flowers.c";
      value=200;
      break;
    case "rose":
      file="/players/traff/misc/redrose";
      value=500;
      break;
    case "valentine":
      file="/players/saber/stuff/valentine";
      break;
    default:
      notify_fail("That is not sold here.\n");
      return 0;
  }
  ob=clone_object(file);
  if(!ob) {
    write("That item is not currently available.\n");
    return 1;
  }
  if(this_player()->query_money() < value) {
    write("You do not have enough money.\n");
    return 1;
  }
  if(!this_player()->add_weight(ob->query_weight())) {
    write("It is too heavy.\n");
    return 1;
  }
  this_player()->add_money(-value);
  move_object(ob,this_player());
  write("You have purchased a "+ob->short()+".\n");
  say(TPN+" purchased a "+ob->short()+".\n");
  return 1;
}
