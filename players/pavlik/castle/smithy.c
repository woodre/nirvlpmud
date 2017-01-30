#include "std.h"
init() {
    set_light(1);
   add_action("fix","fix");
   add_action("west","west");
 }
short() { return "Smitty's Place";
   }
long() {
 write("This is Smitty's smithy.  Here Smitty will take your\n"+
 "broken, shattered, useless, piece of shit weapons and fix them\n"+
 "to be brand new, spankin, shiny, kickass weapons again.\n"+
 "Smitty is a good hard worker and can fix just about anything.\n"+
 "Just toss your weapon down on his anvil and he'll take care of it.\n"+
 " To have Smitty clean up your gear, just type: fix (weapon name).\n"+
  "Please make sure your weapon is unwielded, or Smitty won't be able\n"+
  "to do his job correctly. (kinda hard to fix a weapon when you\n"+
  "are still holding on to it!\n");
    write("The only exit is to the west.\n");
   }
west() {
 this_player()->move_player("to the shop#players/pavlik/castle/tshop.c");
    return 1;
  }
fix(str) {
int cost;
object ob;
   if (!str) return 0;
    ob=present(str,this_player());
      if(!ob) ob = present(str,this_object());
      if(!ob) {
     write("That is not here.\n");
    return 1;
     }
   if(!ob->fix_weapon()) {
     write("It is not broken.\n");
     return 1;
    }
    cost = ob->query_value()/5;
   cost = 500;
    if (this_player()->query_money() < cost) {
        ob->re_break();
        write("You do not have enough money.\n");
        return 1;
        }
    this_player()->add_money(-500);
 write("Smitty takes a good look at your weapon.\n"+
     "'Cake,' he says.  In a flash and whirl of flying sparks and\n"+
     "hammers Smitty lays into the "+str+".  After several moments\n"+
     "Smitty presents the finished product to you.  Your weapon\n"+
 "looks like new.\n");
return 1;
     }
