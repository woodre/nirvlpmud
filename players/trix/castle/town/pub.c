inherit "room/room";
 
reset(arg) {
        object bed;
    if(arg) return;
    set_light(1);
   long_desc = 
"You are in Trixtown Pub, you can order a drink by typing \"buy <number>\".\n"+
               "                          Here is a list of the drinks:\n"+
               "              .---------------------------------------------------.\n"+
               "              | # |   item      |level|intox|heal pts|    cost    |\n"+
               "              .---------------------------------------------------.\n"+
               "              | 1 | coffee      | any | -10 |   --   | 180   coins|\n"+
               "              | 2 | chianti     | any |   7 |   15   | 300   coins|\n"+
               "              | 3 | baileys     | >=5 |   8 |   20   | 320   coins|\n"+
               "              | 4 | vodka       | >=10|  12 |   30   | 360   coins|\n"+
               "              | 5 | whiskey     | >=10|  13 |   40   | 440   coins|\n"+
               "              | 6 | pure alcohol| >=10|  14 |   50   | 500   coins|\n"+
               "              `---------------------------------------------------'\n                    ";
   short_desc = "Trixtown Pub";
    dest_dir = ({ "/players/trix/castle/town/2str1s.c", "east"});
}


init(){
 ::init();
     add_action("buy","buy");
}

buy(str)
{  int value,choice;
   object cosa;
   string name;
   if((!str) || ((sscanf(str,"%d",choice) !=1)))
     { tell_object(this_player(),"Buy what?!?\n");
       return 1;
     }
   if (choice<1 || choice>6)
    { tell_object(this_player(),"You can only choose drinks from 1 to 6.\n");
      return 1;
    }  
   if(!this_player()->add_weight(1)) { write("You can't carry that much.\n"); return 1; }
   if (choice==1)
   { value=180; 
     if(this_player()->query_money() < value) { write("You don't have enough money.\n"); return 1; }
     cosa=clone_object("players/trix/castle/dismonst/machine/coffee.c");
     name="a cup of coffee"; 
   }
   if (choice==2)
   { value=300; 
     if(this_player()->query_money() < value) { write("You don't have enough money.\n"); return 1; }
     cosa=clone_object("players/trix/castle/dismonst/machine/chianti.c");
     name="a bottle of Chianti"; 
   }
   if (choice==3)
   { value=320; 
     if(this_player()->query_money() < value) { write("You don't have enough money.\n"); return 1; }
     cosa=clone_object("players/trix/castle/dismonst/machine/baileys.c");
     name="a bottle of Baileys"; 
   }
   if (choice==4)
   { value=360; 
     if(this_player()->query_money() < value) { write("You don't have enough money.\n"); return 1; }
     cosa=clone_object("players/trix/castle/dismonst/machine/vodka.c");
     name="a bottle of Vodka Smirnov"; 
   }
   if (choice==5)
   { value=440; 
     if(this_player()->query_money() < value) { write("You don't have enough money.\n"); return 1; }
     cosa=clone_object("players/trix/castle/dismonst/machine/whiskey.c");
     name="a bottle of Jack Daniels Whiskey"; 
   }
   if (choice==6)
   { value=500; 
     if(this_player()->query_money() < value) { write("You don't have enough money.\n"); return 1; }
     cosa=clone_object("players/trix/castle/dismonst/machine/alcohol.c");
     name="a bottle of pure alcohol"; 
   }
   move_object(cosa,this_player());
   tell_object(this_player(),"You buy "+name+".\n");
   call_other(this_player(), "add_money", - value);
   return 1;
}
