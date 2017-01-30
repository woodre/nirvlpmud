inherit "room/room";
 
reset(arg) {
    object waiter;
    if(arg) return;
    set_light(1);
 long_desc = "You are near the desk of the chief waiter, in the restaurant under the EclYpsE,\n" +
             "looking around you notice the elegance of the place and the quiet that makes a\n" +
             "strong contrast with the messy and noisy place you know it is upstairs.\n";
   short_desc = "EclYpse's Restaurant";
    dest_dir = ({ "/players/trix/castle/disco/d7.c","west",
                  "/players/trix/castle/disco/d9.c","east"});
   waiter=clone_object("/players/trix/castle/dismonst/waiter");
   move_object(waiter,this_object());
}
init() {
        ::init();
        add_action( "buy", "buy" );
        add_action( "err", "kill" );
        return 1;
}

err(arg) { write("The waiter says: No killing allowed here, sir!\n"); return 1; }

buy(str)
{  int value,choice;
   object cosa;
   string name;
   if((!str) || ((sscanf(str,"%d",choice) !=1)))
     { tell_object(this_player(),"Buy what?!?\n");
       return 1;
     }
   if (choice<1 || choice>6)
    { tell_object(this_player(),"The waiter says: You can only choose dishes from 1 to 5.\n");
      return 1;
    }  

   if(!this_player()->add_weight(1)) { write("The waiter says: You can't carry that much.\n"); return 1; }
   if (choice==1)
   { value=500; 
     if(call_other(this_player(),"query_money",)<value) { write("Bartender says: You don't have enough money.\n"); return 1; } 
     cosa=clone_object("players/trix/castle/dismonst/machine/lobster.c");
     name="a boiled red lobster"; 
   }
   if (choice==2)
   { value=400; 
     if(call_other(this_player(),"query_money",)<value) { write("The waiter says: You don't have enough money.\n"); return 1; } 
     cosa=clone_object("players/trix/castle/dismonst/machine/spaghetti.c");
     name="a plate of spaghetti"; 
   }
   if (choice==3)
   { value=300; 
     if(call_other(this_player(),"query_money",)<value) { write("The waiter says: You don't have enough money.\n"); return 1; } 
     cosa=clone_object("players/trix/castle/dismonst/machine/steak.c");
     name="a t-bone steak"; 
   }
   if (choice==4)
   { value=200; 
     if(call_other(this_player(),"query_money",)<value) { write("The waiter says: You don't have enough money.\n"); return 1; } 
     cosa=clone_object("players/trix/castle/dismonst/machine/soup.c");
     name="a vegetal soup"; 
   }  
if (choice==5)
   { value=150; 
     if(call_other(this_player(),"query_money",)<value) { write("The waiter says: You don't have enough money.\n"); return 1; } 
     cosa=clone_object("players/trix/castle/dismonst/machine/panna.c");
     name="a portion of Panna Elena"; 
   }
   if (choice==6)
   { value=140; 
     if(call_other(this_player(),"query_money",)<value) { write("The waiter says: You don't have enough money.\n"); return 1; } 
     cosa=clone_object("players/trix/castle/dismonst/machine/salad.c");
     name="a fresh salad"; 
   }
   move_object(cosa,this_player());
   tell_object(this_player(),"You order and the waiter serves you "+name+".\n");
   call_other(this_player(), "add_money", - value);
   return 1;
}
