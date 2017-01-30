reset(arg) {
        if(arg) return;
        /* Initialization code goes here */

}
long() {
        write("This is a heals vending machine , the drugs sold are NOT intoxicating , type\n" +
               "'heals' to see the list.\n");
        return 1;
}

short() {
   return "A vending machine";
}

id(str) {
        if( str == "machine" ) return 1;
        return 0;
}

init() {
        add_action( "buy", "buy" );
        add_action( "list", "heals");
        add_action( "drugs", "drugs");
        add_action( "drugs", "wines");
        return 1;
}

query_weight()
{   return 50;
}

list()
  { cat("/players/trix/castle/dismonst/machine/druglist");
    return 1;
  }

drugs()
 { write("Type 'heals' to have the list.\n");
   return 1;
 }
buy(str)
{  int value,choice;
   object cosa;
   string name;
   if((!str) || ((sscanf(str,"%d",choice) !=1)))
     { tell_object(this_player(),"Buy what?!?\n");
       return 0;
     }
   if (choice<1 || choice>11)
    { tell_object(this_player(),"You can only choose items from 1 to 11.\n");
      return 0;
    }  
   if (choice==1)
   { value=1800;
     if(call_other(this_player(),"query_money",)<value) { write("You don't have enough money.\n"); return 1; } 
     cosa=clone_object("players/trix/castle/dismonst/machine/marija.c");
     name="a joint of marijuana"; 
   }

   if (choice==2)
   { value=2400; 
     if(call_other(this_player(),"query_money",)<value) { write("You don't have enough money.\n"); return 1; } 
     cosa=clone_object("players/trix/castle/dismonst/machine/hashish.c");
     name="a joint of hashish"; 
   }

   if (choice==3)
   { value=4800; 
     if(call_other(this_player(),"query_money",)<value) { write("You don't have enough money.\n"); return 1; } 
     cosa=clone_object("players/trix/castle/dismonst/machine/xtc.c");
     name="an ecstasy"; 
   }

   if (choice==4)
   { value=6000; 
     if(call_other(this_player(),"query_money",)<value) { write("You don't have enough money.\n"); return 1; } 
     cosa=clone_object("players/trix/castle/dismonst/machine/acid.c");
     name="a dragon acid"; 
   }

   if (choice==5)
   { value=10000; 
     if(call_other(this_player(),"query_money",)<value) { write("You don't have enough money.\n"); return 1; } 
     cosa=clone_object("players/trix/castle/dismonst/machine/cocaine.c");
     name="1 gram of cocaine"; 
   }
   if (choice==5)
   { value=10000; 
     if(call_other(this_player(),"query_money",)<value) { write("You don't have enough money.\n"); return 1; } 
     cosa=clone_object("players/trix/castle/dismonst/machine/cocaine.c");
     name="1 gram of cocaine"; 
   }
   if (choice==6)
   { value=180; 
     if(call_other(this_player(),"query_money",)<value) { write("You don't have enough money.\n"); return 1; } 
     cosa=clone_object("players/trix/castle/dismonst/machine/coffee.c");
     name="a cup of coffee"; 
   }
   if (choice==7)
   { value=300; 
     if(call_other(this_player(),"query_money",)<value) { write("You don't have enough money.\n"); return 1; } 
     cosa=clone_object("players/trix/castle/dismonst/machine/chianti.c");
     name="a bottle of Chianti"; 
   }
   if (choice==8)
   { value=320; 
     if(call_other(this_player(),"query_money",)<value) { write("You don't have enough money.\n"); return 1; } 
     cosa=clone_object("players/trix/castle/dismonst/machine/baileys.c");
     name="a bottle of Baileys"; 
   }
   if (choice==9)
   { value=360; 
     if(call_other(this_player(),"query_money",)<value) { write("You don't have enough money.\n"); return 1; } 
     cosa=clone_object("players/trix/castle/dismonst/machine/vodka.c");
     name="a bottle of Vodka Smirnov"; 
   }
   if (choice==10)
   { value=440; 
     if(call_other(this_player(),"query_money",)<value) { write("You don't have enough money.\n"); return 1; } 
     cosa=clone_object("players/trix/castle/dismonst/machine/whiskey.c");
     name="a bottle of Jack Daniels Whiskey"; 
   }
   if (choice==11)
   { value=500; 
     if(call_other(this_player(),"query_money",)<value) { write("You don't have enough money.\n"); return 1; } 
     cosa=clone_object("players/trix/castle/dismonst/machine/alcohol.c");
     name="a bottle of pure alcohol"; 
   }
   move_object(cosa,this_player());
   tell_object(this_player(),"You push button number "+choice+" and "+name+" falls in your hand.\n");
   call_other(this_player(), "add_money", - value);
   return 1;
}

get() {
        return 0;
}

drop() {
        return 1;
}
