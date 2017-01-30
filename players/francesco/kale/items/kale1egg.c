#include "/players/francesco/univ/ansi.h"
inherit "/obj/treasure.c";

id(str) { return str == "egg" || str == "easter egg" ; }

reset(arg) {
   if (arg) return;
   }

long() { write("The Easter eggs has been acknowledged as a symbol of continuing life and \n"+
               "resurrection since pre-Christian spring celebrations.  Given as gifts by \n"+
               "the ancient Greeks, Persians, and Chinese at their spring festivals, the \n"+
               "egg also appears in pagan mythology, where we read of the Sun-Bird being \n"+
               "hatched from the World Egg.   In the Middle Age, the eggs were colored to\n"+
               "be given as gifts at Easter.  They are part of the feasting and gifts for \n"+
               "family, friends and servants.  In modern times, they are made by gaily \n"+
               "colored cardboard or by rich chocolate and always carry a surprise inside.\n"+
               "This egg is all colored in "+HIW+"white"+NORM+".  By returning it to the proper person,\n"+
               "it is possible to 'obtain money' or, alternatively, 'obtain heals'.\n"); }

short() { return ""+HIW+"WHITE "+HIR+"Ea"+NORM+YEL+"st"+HIY+"er"+HIG+" e"+HIB+"gg"+HIM+""+NORM+""; }

init() {
    add_action("obtain","obtain");
    return 1;
}

obtain(arg) {
    object item;
    object ob;
    object dummy;
    if(!present("egg",this_player())) {notify_fail("You must get the "+HIR+"Ea"+NORM+YEL+"st"+HIY+"er"+HIG+" e"+HIB+"gg"+HIM+""+NORM+" first.\n");return 0;}
    if(!arg) {notify_fail("Obtain what?\n"); return 0; }
    if(!present("hope",environment(this_player())))
     {notify_fail("Hmmm..... Hope is not here.\n"); return 0;}
    if(arg=="heals")
     {
      item = clone_object("/players/francesco/univ/items/panino.c");      
      move_object(item,this_player());      
      item = clone_object("/players/francesco/univ/items/barbera.c");      
      move_object(item,this_player());
      item = clone_object("/players/francesco/univ/items/tea.c");      
      move_object(item,this_player());
      write("Hope says: Well done, "+call_other(this_player(),"query_name")+", enjoy this full set of heals.\n");
      destruct(this_object());
      this_player()-> recalc_carry();
      return 1;
     }
    if (arg=="money") 
     { 
      call_other(this_player(),"add_money",(2615+random(4000))); 
      write("Hope says: Well done, "+call_other(this_player(),"query_name")+", these coins will help you in your further mud life.\n");
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
