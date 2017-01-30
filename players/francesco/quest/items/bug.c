#include "/players/francesco/univ/ansi.h"
inherit "/obj/treasure.c";

id(str) { return str == "bug" ; }

reset(arg) {
   if (arg) return;
   }

long() { write("The graduation certificate is a simple paper which entitles you to 'obtain' \n"+
               "a special item from the University.  It is possible to see the available\n"+
               "items by typing 'list'.\n"); }



init() {
    add_action("obtain","obtain");
    add_action("list","list");
    return 1;
}


list() {
     write("The following items are now available as a reward for graduating:\n"+
           "                      University cloak   (misc)\n"+
           "                      University pin     (amulet)\n"+
           "                      University gloves  (ring)\n"+
           "                      University scarf   (shield)\n"+
           "                      University cap     (helmet)\n");
     return 1;}


obtain(arg) {
    object item;
    object ob;
    object dummy;
    if(!present("graduation certificate",this_player())) {notify_fail("You must get the Graduation certificate first.\n");return 0;}
    if(!arg) {notify_fail("Obtain what?\n"); return 0; }
    if(!present("hope",environment(this_player())))
     {notify_fail("Hmmm..... Hope is not here.\n"); return 0;}

    if(arg=="cloak") {
      item = clone_object("/players/francesco/quest/items/cloak.c");      
      move_object(item,this_player()); 
      write_file("/players/francesco/quest/log/cloak"+this_player()->query_real_name(),".\n");
      return 1;}
     
    if(arg=="pin") {
      item = clone_object("/players/francesco/quest/items/pin.c");      
      move_object(item,this_player()); 
      write_file("/players/francesco/quest/log/pin"+this_player()->query_real_name(),".\n");
      return 1;}

    if(arg=="gloves") {
      item = clone_object("/players/francesco/quest/items/gloves.c");      
      move_object(item,this_player()); 
      write_file("/players/francesco/quest/log/gloves"+this_player()->query_real_name(),".\n");
      return 1;}

    if(arg=="scarf") {
      item = clone_object("/players/francesco/quest/items/scarf.c");      
      move_object(item,this_player()); 
      write_file("/players/francesco/quest/log/scarf"+this_player()->query_real_name(),".\n");
      return 1;}

    if(arg=="cap") {
      item = clone_object("/players/francesco/quest/items/cap.c");      
      move_object(item,this_player()); 
      write_file("/players/francesco/quest/log/cap"+this_player()->query_real_name(),".\n");
      return 1;}

   notify_fail("Obtain what?\n");
 return 0;   
}

get() { return 1; }

query_weight() { return 1; }

query_value() { return (150); }

query_save_flag() { return 1; } 
