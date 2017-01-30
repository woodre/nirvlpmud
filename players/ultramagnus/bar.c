inherit "room/room";
 
reset(arg) {
        object bed;
    if(arg) return;
    set_light(1);
long_desc = "Welcome to Gondor's one and ONLY Black Dragon Saloon.  You\n"+
"can find anything you need here, as long as you have the dough.\n";
	"	Here's a long list of Middle Earth brews:\n"+
               "              .---------------------------------------------------.\n"+
               "              | # |   item      |level|intox|heal pts|    cost    |\n"+
               "              .---------------------------------------------------.\n"+
                "              | 1 | Java        | any | -15 |   --   | 180   coins|\n"+
                "              | 2 | Mocha       | any |  -5 |   --   |  75   coins|\n"+
               "              | 3 | Beer        | any |   5 |   15   | 250   coins|\n"+
               "              | 4 | Wine Coolers| >=5 |  10 |   25   | 310   coins|\n"+
               "              | 5 | Scotch      | >=10|  15 |   30   | 350   coins|\n"+
               "              | 6 | Jack Daniels| >=12|  17 |   45   | 500   coins|\n"+
               "              | 6 | pure alcohol| >=10|  14 |   50   | 500   coins|\n"+
               "              | 7 | Fruit Punch | >=10|  20 |   60   | 700   coins|\n"+
               "              | 8 | Ever Clear  | >=15|  40 |  100   | 100000coins|\n"+
               "              `---------------------------------------------------'\n                    ";
short_desc = "Black Dragon Saloon";
dest_dir = ({"/players/ultramagnus/ins_gondor.c", "east"});
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
       return 0;
     }
   if (choice<1 || choice>6)
    { tell_object(this_player(),"You can only choose drinks from 1 to 6.\n");
      return 0;
    }  
   if(!this_player()->add_weight(1)) { write("You can't carry that much.\n"); return 1; }
   if (choice==1)
   { value=180; 
     if(call_other(this_player(),"query_money",)<value) { write("You don't have enough money.\n"); return 1; } 
     cosa=clone_object("players/trix/castle/dismonst/machine/coffee.c");
     name="a cup of coffee"; 
   }
   if (choice==2)
   { value=300; 
     if(call_other(this_player(),"query_money",)<value) { write("You don't have enough money.\n"); return 1; } 
     cosa=clone_object("players/trix/castle/dismonst/machine/chianti.c");
     name="a bottle of Chianti"; 
   }
   if (choice==3)
   { value=320; 
     if(call_other(this_player(),"query_money",)<value) { write("You don't have enough money.\n"); return 1; } 
     cosa=clone_object("players/trix/castle/dismonst/machine/baileys.c");
     name="a bottle of Baileys"; 
   }
   if (choice==4)
   { value=360; 
     if(call_other(this_player(),"query_money",)<value) { write("You don't have enough money.\n"); return 1; } 
     cosa=clone_object("players/trix/castle/dismonst/machine/vodka.c");
     name="a bottle of Vodka Smirnov"; 
   }
   if (choice==5)
   { value=440; 
     if(call_other(this_player(),"query_money",)<value) { write("You don't have enough money.\n"); return 1; } 
     cosa=clone_object("players/trix/castle/dismonst/machine/whiskey.c");
     name="a bottle of Jack Daniels Whiskey"; 
   }
   if (choice==6)
   { value=500; 
     if(call_other(this_player(),"query_money",)<value) { write("You don't have enough money.\n"); return 1; } 
     cosa=clone_object("players/trix/castle/dismonst/machine/alcohol.c");
     name="a bottle of pure alcohol"; 
   }
   move_object(cosa,this_player());
   tell_object(this_player(),"You buy "+name+".\n");
   call_other(this_player(), "add_money", - value);
   return 1;
}
