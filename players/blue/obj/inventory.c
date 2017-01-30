#include "/players/blue/closed/lib/color.h"

id(str) { return str=="object"; }
short() { return "An inventory object"; }
long() { return write("This object will help you with your inventory. Type e"+
         "q to see you new inventory,\nand dest_invn to destroy it, should"+
         "have any problems.\n");
       }
query_value() { return 0; }
query_weight() { return 0; }
query_get() { return 1; }
drop() { return 1; }

init() {
   add_action("new_inventory","inv");
   add_action("dest_invin","dest_invn");

   }

new_inventory() {
   object ob;
   int w;
   string strength;
   strength=this_player()->query_attrib("str");
   ob=first_inventory(this_player());
      if(!ob) {
         write("You have nothing.\n");
         return 1;
      }
   while(ob) {
         if(ob->query_wc()) write(CYA);
         if(ob->query_ac()) write(YEL);
         write(ob->query_weight());
         write(ob->query_short());
         write(WHI+"\n");
      ob = next_inventory(ob);
   }
  write("-------------------------------------------------------------------");
  write("------------\n");
  write("Total carry: "+ w + "/");
  if(this_player()->query_level()==1) {
     write((this_player()->query_level() + 6 + strength/2)+"\n");
     return 1;
   }
  write((this_player()->query_level()+6+strength/5)+"\n");
  return 1;
}

dest_invn() {
   destruct(this_object());
   write("Object destructed.\n");
   return 1;
}
