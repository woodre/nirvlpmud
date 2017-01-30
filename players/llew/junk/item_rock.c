id(str) {return str == "rock";}
query_weight() {return 0;}
query_value() {return 1;}

short()  { return "A large rock";
        }
long(){
write("A large rock in the shape of a sphere with a flat surface\n"+
      "cut away on top.  Carved on the front is a \"list\" of items.\n");
        }

list()  {
write("The rocks menu reads:\n"+
 pad("",5)+" "+pad("1) A tension sheet",25)+" :  100 golden coins\n"+
 pad("",5)+" "+pad("2) A large firework",25)+" :  500 golden coins\n"+
/*
 pad("",5)+" "+pad("3) A rose spell",25)+" :  1000 golden coins\n"+
*/
 pad("",5)+" "+pad("3) A chaos teller",25)+" :  1500 golden coins\n"+
 "\n   Think of an item and it will appear.\n"+
 "\n");
     return 1;
}

init() {
   add_action("think","think");
   add_action("list","list");
}


think(str) {
   object bought;
   int cost;
   string item,path;
   if (!str){
      write("Think what?\n");
      return 1;
   }
   switch(str) {
      case "1": 
         item="a tension sheet";
         cost=100;
         path="/players/llew/junk/tension.c";
         break;
      case "2":
         item="a large firework";
         cost=500;
         path="/players/llew/junk/firework.c";
         break;
/*
      case "3":
         item="a rose spell";
         cost=1000;
         path="/players/llew/junk/rosefall.c";
         break;
*/
      case "3":
         item="a chaos teller";
         cost=1500;
         path="/players/llew/junk/chtell.c";
         break;
   }
   if(item==0) {
      write("Please think of a number.\n");
      return 1;
   }
   if(this_player()->query_money() < cost) {
      write("The rock doesn't respond as you don't have enough money.\n"); 
      return 1;
   }
   bought=clone_object(path);
   this_player()->recalc_carry();
#ifndef __LDMUD__
   if(transfer(bought,this_player()) == 1) {
#else
   if (funcall(symbol_function('transfer), bought, this_player()) == 1) {
#endif
      write("The rock doesn't think you'll be able to carry that.\n");
      destruct(bought);
      return 1;
   }
   this_player()->add_money(-cost);
   this_player()->add_weight(bought->query_weight());
   say(this_player()->query_name()+" concentrates and "+item+" appears.\n");
   write("You think of "+item+" and it materializes in front of you.\n");
   return 1;
}

reset(arg) {
 if(arg) return;
}

