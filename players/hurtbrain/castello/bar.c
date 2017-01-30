#include "std_old.h"

#undef EXTRA_INIT
#define EXTRA_INIT\
   add_action("buy", "buy"); \
   add_action("list", "list");

ONE_EXIT("/players/hurtbrain/castello/entrance", "west",
         "The healing-shop",
         "You are in Hurtbrain's healing-shop. You can buy some\n" +
         "good healing here. Commands are: 'buy item' and  'list'.\n" +
         "To the west you see a strange looking machine.\n", 1)

list()
  { cat("/players/hurtbrain/castello/heal_list");
    return 1;
  }

buy(str)
{  int value,choice;
   object cosa;
   string name;
   if((!str) || ((sscanf(str,"%d",choice) !=1)))
     { tell_object(this_player(),"What do you want to buy?\n");
       return 1;
     }
   if (choice<1 || choice>11)
    { tell_object(this_player(),"You can only choose items from 1 to 11.\n");
      return 1;
    }  
   if (choice==1)
   { value=900;
     if(call_other(this_player(),"query_money",)<value) { write("You don't have enough money.\n"); return 1; } 
     cosa=clone_object("players/hurtbrain/castello/potion.c");
     name="a Roman's potion"; 
   }

   if (choice==2)
   { value=1200; 
     if(call_other(this_player(),"query_money",)<value) { write("You don't have enough money.\n"); return 1; } 
     cosa=clone_object("players/hurtbrain/castello/paper.c");
     name="a parchment paper"; 
   }

   if (choice==3)
   { value=2400; 
     if(call_other(this_player(),"query_money",)<value) { write("You don't have enough money.\n"); return 1; } 
     cosa=clone_object("players/hurtbrain/castello/object.c");
     name="a red glowing object"; 
   }

   if (choice==4)
   { value=3000; 
     if(call_other(this_player(),"query_money",)<value) { write("You don't have enough money.\n"); return 1; } 
     cosa=clone_object("players/hurtbrain/castello/dust.c");
     name="a bag of dust"; 
   }

   if (choice==5)
   { value=10000; 
     if(call_other(this_player(),"query_money",)<value) { write("You don't have enough money.\n"); return 1; } 
     cosa=clone_object("players/hurtbrain/castello/pillow.c");
     name="a strange pill"; 
   }
   if (choice==6)
   { value=150; 
     if(call_other(this_player(),"query_money",)<value) { write("You don't have enough money.\n"); return 1; } 
     cosa=clone_object("players/hurtbrain/castello/wine.c");
     name="a bottle of wine"; 
   }
   if (choice==7)
   { value=300; 
     if(call_other(this_player(),"query_money",)<value) { write("You don't have enough money.\n"); return 1; } 
     cosa=clone_object("players/hurtbrain/castello/cognac.c");
     name="a bottle of cognac"; 
   }
   if (choice==8)
   { value=450; 
     if(call_other(this_player(),"query_money",)<value) { write("You don't have enough money.\n"); return 1; } 
     cosa=clone_object("players/hurtbrain/castello/brandy.c");
     name="a bottle of brandy"; 
   }
   if (choice==9)
   { value=600; 
     if(call_other(this_player(),"query_money",)<value) { write("You don't have enough money.\n"); return 1; } 
     cosa=clone_object("players/hurtbrain/castello/rum.c");
     name="a bottle of rum"; 
   }
   if (choice==10)
   { value=750; 
     if(call_other(this_player(),"query_money",)<value) { write("You don't have enough money.\n"); return 1; } 
     cosa=clone_object("players/hurtbrain/castello/vodka.c");
     name="a bottle of vodka"; 
   }
   if (choice==11)
   { value=200; 
     if(call_other(this_player(),"query_money",)<value) { write("You don't have enough money.\n"); return 1; } 
     cosa=clone_object("players/hurtbrain/castello/spotion.c");
     name="a sobering potion"; 
   }
   move_object(cosa,this_player());
   tell_object(this_player(),"You push button number "+choice+" and "+name+" falls in your hand.\n");
   call_other(this_player(), "add_money", - value);
   return 1;
}

