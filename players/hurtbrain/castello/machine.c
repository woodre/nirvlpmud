
int potion_qty;

reset(arg) {
        potion_qty++;
        if(arg) return;
        potion_qty = 3;
}

long() {
        write("This is a vending machine. You can buy some cool objects here.\n" +
               "Type 'objects' to list and 'buy <number>' to buy.\n");
        return 1;
}

short() {
   return "Hurtbrain's vending machine";
}

id(str) {
        if( str == "machine" ) return 1;
        return 0;
}

init() {
        add_action( "buy", "buy" );
        add_action( "list", "objects");
        return 1;
}

query_weight()
{   return 150;
}

list()
  { cat("/players/hurtbrain/helpdir/machine");
    return 1;
  }

buy(str)
{  int value,choice;
   object cosa;
   string name;
   if((!str) || ((sscanf(str,"%d",choice) !=1)))
     { tell_object(this_player(),"Buy what?!?\n");
       return 1;
     }
   if(choice==1)
   { 
     value=4000;
     cosa=clone_object("players/hurtbrain/obj/boomerang");
     name="a boomerang"; 
   }
   else if(choice==2)
   {
     value = 2000;
     cosa=clone_object("players/hurtbrain/obj/potion");
     name="a potion"; 
   }
   else if(choice==3)
   {
     value=500; 
     cosa=clone_object("players/hurtbrain/obj/stone");
     name="a stone"; 
   }
   else if(choice==4)
   { 
     value=200; 
     cosa=clone_object("players/hurtbrain/obj/pigeon");
     name="a pigeon"; 
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
/*


   log_file("hurtbrain.mac",call_other(this_player(),"query_name")+", level "+call_other(this_player(),"query_level")+", buys "+name+".\n");
*/
   return 1;
}

get() {
        return 0;
}

drop() {
        return 1;
}
