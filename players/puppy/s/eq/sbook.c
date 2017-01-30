#include "/players/puppy/define.h"
inherit "obj/treasure";

reset(arg)  {
   if(arg) return;
   
   set_id("book");
   set_short("A spell book");
   set_long(
      "An old book with torn corners that Papa Smurf uses as a\n"+
      "guide for the spells he creates.  Many of the pages have\n"+
      "worn letters and are hard to read.\n");
   set_weight(1);
   set_value(150);
}

init()
{  add_action("book", "read");   }

book(str)  {
   if(!str){ notify_fail("read what?\n"); return 0; }
   if(str == "book")  {
      
      write("You can not understand what is written in this book.\n");
      
      return 1;   }
   notify_fail("read what?\n"); return 0; }
