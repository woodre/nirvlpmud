inherit "room/room";
 
reset(arg) {
    object dealer;
    if(arg) return;
    set_light(1);
 long_desc = "This is the toilet of the EclYpsE, the walls are covered with a lot of vulgar\n" +
             "phrases and drawings. There's a strange smell in the air and you see a strange\n" +
        "fog in the room, wasn't smoking the pot illegal? However, why don't you try \n"+
        "asking him for the 'list'.\n";
   short_desc = "A toilet";
    dest_dir = ({ "/players/trix/castle/disco/grid20.c","north"});
   dealer=clone_object("/players/trix/castle/dismonst/dealer");
   move_object(dealer,this_object());
}
init() {
        ::init();
        add_action( "buy", "buy" );
        add_action("list","list");
        add_action( "err", "kill" );
        return 1;
}

err(arg)
     {
       notify_fail("Drug dealer says: AHAHA, and who you would dare to attack ?\n"); return 1; }
list()
  { cat("/players/trix/castle/dismonst/machine/druglist");
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
   if (choice<1 || choice>5)
    { tell_object(this_player(),"You can only choose drugs from 1 to 5.\n");
      return 1;
    }  
   if(!this_player()->add_weight(1))
     {
       notify_fail("Drug dealer says: You can't carry that much.\n"); return 1; }
   if (choice==1)
   { value=1800;
     if (this_player()->query_money() < value)
     {
       notify_fail("Drug dealer says: You don't have enough money.\n");
       return 1;
      } 
     cosa=clone_object("players/trix/castle/dismonst/machine/marija.c");
     name="a joint of marijuana"; 
   }

   if (choice==2)
   { value=2400; 
     if (this_player()->query_money() < value)
     {
       notify_fail("Drug dealer says: You don't have enough money.\n");
       return 1;
     } 
     cosa=clone_object("players/trix/castle/dismonst/machine/hashish.c");
     name="a joint of hashish"; 
   }

   if (choice==3)
   { value=4800; 
     if (this_player()->query_money() < value)
     {
       notify_fail("Drug dealer says: You don't have enough money.\n");
       return 1;
     } 
     cosa=clone_object("players/trix/castle/dismonst/machine/xtc.c");
     name="an ecstasy"; 
   }

   if (choice==4)
   { value=6000; 
     if (this_player()->query_money() < value)
     {
       notify_fail("Drug dealer says: You don't have enough money.\n");
       return 1;
     }
     cosa=clone_object("players/trix/castle/dismonst/machine/acid.c");
     name="a dragon acid"; 
   }

   if (choice==5)
   { value=10000; 
    if (this_player()->query_money() < value)
     {
       notify_fail("Drug dealer says: You don't have enough money.\n");
       return 1;
     } 
     cosa=clone_object("players/trix/castle/dismonst/machine/cocaine.c");
     name="1 gram of cocaine"; 
   }
   if (choice==5)
   { value=11000; 
     if (this_player()->query_money() < value)
     {
       notify_fail("Drug dealer says: You don't have enough money.\n");
       return 1;
     } 
     cosa=clone_object("players/trix/castle/dismonst/machine/cocaine.c");
     name="1 gram of cocaine"; 
   }
   move_object(cosa,this_player());
   tell_object(this_player(),"You buy  "+name+" from your trustable drug dealer.\n");
   call_other(this_player(), "add_money", - value);
   return 1;
}
