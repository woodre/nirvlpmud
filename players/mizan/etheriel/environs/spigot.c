#include "std.h"
id(str) { return str == "spigot"; }
string kick;
int x, y;
short() { return "A spigot"; }
long() {
   cat("/players/mizan/etheriel/environs/SPIGOT");
   return 1;
}
init() {
   add_action("pour","pour");
}
pour(str) {
   object thingo;
   if(!str) return 0;
   sscanf(str, "%d", x);
   y=x*15;
   if(call_other(this_player(), "query_money", 0) < y) {
      write("You only have ["+(this_player()->query_money())+
         "] gold! It would cost ["+y+"] gold\n"+
         "to add ["+x+"] units of healing to the thermos.\n");
      return 1; }
   if(x>1000) {
      write("That number is too high.\n");
      log_file("mizan.jug", (this_player()->query_name())+" attempted to overfill the thermos "+x+"\n");
      return 1;
   }
   if(x<1) {
      write("You can't do that.\n");
      log_file("mizan.jug", (this_player()->query_name())+" attempted to underfill the thermos "+x+"\n");
      return 1;
   }
   
   thingo= present("MI-thermos", this_player());
   if(!thingo) return 0;
   thingo->add_charge(x);
   call_other(this_player(), "add_money", 0-y);
   return 1; }
