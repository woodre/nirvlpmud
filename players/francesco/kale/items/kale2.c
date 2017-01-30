#include "/players/francesco/univ/ansi.h"
inherit "/obj/treasure.c";

id(str) { return str == "kaleidoscope" || str == "kale"; }

reset(arg) {
   if (arg) return;
   }

long() { write("This kaleidoscope is just a toy which both adults and childrens\n"+
               "like to play with.  It has a tubular shape with a peephole at one\n"+
               "end, and is all colored in "+HIB+"blue"+NORM+".  By returning it to the proper\n"+
               "person, it is possible to 'obtain money' or, alternatively, \n"+
               "'obtain heals'.\n"); }

short() { return ""+HIB+"BLUE "+HIR+"Ka"+NORM+YEL+"le"+HIY+"id"+HIG+"os"+HIB+"co"+HIM+"pe"+NORM+""; }

init() {
    add_action("obtain","obtain");
    return 1;
}

obtain(arg) {
    object item;
    object ob;
    object dummy;
    if(!present("kaleidoscope",this_player())) {notify_fail("You must get the "+HIR+"Ka"+NORM+YEL+"le"+HIY+"id"+HIG+"os"+HIB+"co"+HIM+"pe"+NORM+" first.\n");return 0;}
    if(!arg) {notify_fail("Obtain what?\n"); return 0; }
    if(!present("hope",environment(this_player())))
     {notify_fail("Hmmm..... Hope is not here.\n"); return 0;}
    if(arg=="heals")
     {
      item = clone_object("/players/francesco/univ/items/panino.c");      
      move_object(item,this_player());      
      item = clone_object("/players/francesco/univ/items/tea.c");      
      move_object(item,this_player());
      write("Hope says: Well done, "+call_other(this_player(),"query_name")+", enjoy this full set of heals.\n");
      write_file("/players/francesco/kale/log/"+this_player()->query_name()+"",ctime(time())+" blue  2\n");
      destruct(this_object());
      this_player()-> recalc_carry();
      return 1;
     }
    if (arg=="money") 
     { 
      call_other(this_player(),"add_money",(2015+random(2900))); 
      write("Hope says: Well done, "+call_other(this_player(),"query_name")+", these coins will help you in your further mud life.\n");
      write_file("/players/francesco/kale/log/"+this_player()->query_name()+"",ctime(time())+" blue  2\n");
      destruct(this_object());
      this_player()-> recalc_carry();
      return 1; 
     }
   notify_fail("Obtain what?\n");
 return 0;   
}

get() { return 1; }

query_weight() { return 1; }

query_value() { return (150); }

query_save_flag() { return 1; } 
