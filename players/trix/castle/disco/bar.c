inherit "room/room";
 
reset(arg) {
    object bartender;
    if(arg) return;
    set_light(1);
 long_desc = "Your at the bar of the EclYpse, many people is sipping coloured cocktails from\n" +
             "big cups, or gulping down all at once superalcoholics. Tom, the bartender\n" +
        "smiles at you so brightly that you almost feel forced to order something.\n";
   short_desc = "EclYpse's bar";
    dest_dir = ({ "/players/trix/castle/disco/grid16.c","north"});
   bartender=clone_object("/players/trix/castle/dismonst/bartender");
   move_object(bartender,this_object());
}
init() {
        ::init();
        add_action( "buy", "buy" );
        add_action( "err", "kill" );
        return 1;
}

err(arg) { write("Bartender says: I hate violence, please stop it, sir.\n"); return 1; }

buy(str)
{  int value,choice;
   object cosa;
   string name;
   if((!str) || ((sscanf(str,"%d",choice) !=1)))
     { tell_object(this_player(),"Buy what?!?\n");
       return 1;
     }
   if (choice<1 || choice>6)
    { tell_object(this_player(),"Bartender says: You can only choose drinks from 1 to 6.\n");
      return 1;
    }  

   if(!this_player()->add_weight(1)) { write("Bartender says: You can't carry that much.\n"); return 1; }
   if (choice==1)
   { value=180; 
    if (this_player()->query_money() < value)
    {
      notify_fail("Bartender says, \"You don't have enough money.\"\n");
      return 0;
    }
     cosa=clone_object("players/trix/castle/dismonst/machine/coffee.c");
     name="a cup of coffee"; 
   }
   if (choice==2)
   { value=300; 
    if (this_player()->query_money() < value)
    {
      notify_fail("Bartender says, \"You don't have enough money.\"\n");
      return 0;
    }
     cosa=clone_object("players/trix/castle/dismonst/machine/chianti.c");
     name="a bottle of Chianti"; 
   }
   if (choice==3)
   { value=320; 
    if (this_player()->query_money() < value)
    {
     notify_fail("Bartender says, \"You don't have enough money.\"\n");
      return 0;
    }
     cosa=clone_object("players/trix/castle/dismonst/machine/baileys.c");
     name="a bottle of Baileys.";
   }
   if (choice==4)
   { value=360; 
    if (this_player()->query_money() < value)
    {
     notify_fail("Bartender says, \"You don't have enough money.\"\n");
      return 0;
    }
     cosa=clone_object("players/trix/castle/dismonst/machine/vodka.c");
     name="a bottle of Vodka Smirnov"; 
   }
   if (choice==5)
   { value=440; 
    if (this_player()->query_money() < value)
    {
      notify_fail("Bartender says: \"You don't have enough money.\"\n");
      return 0;
    }
     cosa=clone_object("players/trix/castle/dismonst/machine/whiskey.c");
     name="a bottle of Jack Daniels Whiskey"; 
   }
   if (choice==6)
   { value=500; 
    if (this_player()->query_money() < value)
    {
     notify_fail("Bartender says, \"You don't have enough money.\"\n");
      return 0;
    }
     cosa=clone_object("players/trix/castle/dismonst/machine/alcohol.c");
     name="a bottle of pure alcohol"; 
   }
   move_object(cosa,this_player());
   tell_object(this_player(),"You order and the barternder serves you "+name+".\n");
   call_other(this_player(), "add_money", - value);
   return 1;
}
query_no_fight(){ return 1; }
