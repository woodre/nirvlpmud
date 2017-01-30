#include <ansi.h>
int potion_qty;

reset(arg) {
        potion_qty++;
        if(arg) return;
        potion_qty = 3;
}

long() {
        write("This is a vending machine. You can buy some cool objects here.\n" +
               "Type 'list' to list and 'buy <number>' to buy.\n");
        return 1;
}

short() {
   return ""+BOLD+HIR+"V"+HIR+"ending"+NORM+" machine";
}

id(str) {
        if( str == "machine" ) return 1;
        return 0;
}

init() {
        add_action( "bbuy", "buy" );
        add_action( "llist", "list");
        return 1;
}

query_weight()
{   return 150;
}

llist(){
   write("1.Mechanical Vortex______________________15000 coins.\n");
   return 1;}

bbuy(str)
{  int value,choice;
   object cosa;
   string name;
   if((!str) || ((sscanf(str,"%d",choice) !=1)))
     { tell_object(this_player(),"Buy what?!?\n");
       return 1;
     }
   if(choice==1)
   { 
     value=15000;
     cosa=clone_object("players/sami/misc/Dtorch");
     name="vortex"; 
   }
   
   else
   { 
      tell_object(this_player(),"Out of range. You can only choose items from 1 to 4.\n");
      return 1;
   }  
   if(call_other(this_player(), "query_money", 0) < value)
   {
     write("You don't have enough money.\n");
     destruct(cosa);
     return 1;
   }
   if(!this_player()->add_weight(cosa->query_weight()))
   {
     write("You can't carry that much.\n");
     destruct(cosa);
     return 1;
   }  
   tell_object(this_player(),"You push button number "+choice+" and "+name+" falls in your hand.\n");
   tell_room(environment(this_object()),
     this_player()->query_name()+" pushes button number "+choice+" and "+name+" falls into "+this_player()->query_possessive()+" hands.\n", ({ this_player() }));
   move_object(cosa,this_player());
   call_other(this_player(), "add_money", - value);
   return 1;
}

get() {
        return 0;
}

drop() {
        return 1;
}
