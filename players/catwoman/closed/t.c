money(str) {
int val;
   if(!str) {
   write("Useage: money <amount>\n");
   return 1;
   }
   if (sscanf(str, "%d", val) !=1) {
   write("Useage: money <amount>\n");
   return 1;
   }
   call_other(this_player(), "add_money", val);
write("What?\n");
   return 1;
}
