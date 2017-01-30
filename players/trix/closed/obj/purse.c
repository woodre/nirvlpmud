int money;
reset(arg) {
  if(arg) return;
 }
    query_auto_load() {
    return "/players/trix/closed/obj/purse.c:";}
 
long() {
       write("This is your virtual purse, it contains "+money+" coin(s).\n");
       return 1;
 }

short() {
        return "A virtual purse";
        }

id(str) {
        if( str == "purse" ) return 1;
        return 0;
}

init() {
        add_action("help","help");
        add_action("deposit","dep");
        add_action("deposit","deposit");
        add_action("draw","draw");
        add_action("amt","amt");
        add_action("info","info");
        return 1;
       }

deposit(arg)
 {int amount,qmoney;     
  if((!arg) || ((sscanf(arg,"%d",amount) !=1))) { write("$$$> Wrong Syntax, dep <amount> to save money.\n"); return 1; }
  qmoney=call_other(this_player(),"query_money",0);
  if(amount>qmoney) { write("$$$> You can do that, you have only "+qmoney+" coin(s).\n"); return 1; }
  money=money+amount;
  call_other(this_player(),"add_money",-amount);
  write("$$$> You now have "+money+" coin(s) in your purse and "+(qmoney-amount)+" coin(s) in your pocket.\n");
  return 1;
 }

draw(arg)
 {int amount,qmoney,over,swap;   
  if((!arg) || ((sscanf(arg,"%d",amount) !=1))) { write("$$$> Wrong Syntax, draw <amount> to pickup money.\n"); return 1; }
  qmoney=call_other(this_player(),"query_money",0);
  if(amount>money) 
    { 
      if(amount+qmoney>60000) 
       { over=amount+qmoney-60000; }
      if(money<(amount-over))
       { swap=money;
         write("$$$> Your purse contains only "+money+" coin(s).\n");
       }
      else 
       { swap=amount-over;
         write("$$$> You can't draw "+amount+", you would override 60000 losing "+over+" coin(s).\n");
       }
      write("$$$> You draw only "+swap+" coin(s).\n");
      call_other(this_player(),"add_money",swap);
      money=money-swap;
      return 1;                        
    }  
  if(amount+qmoney>60000)
       { over=amount+qmoney-60000;
         swap=amount-over;
         write("$$$> You would override 60000 losing "+over+" coin(s).\n");
         write("$$$> You draw only "+swap+" coin(s).\n");
         money=money-swap;
         call_other(this_player(),"add_money",swap);
         return 1;
       }
   write("$$$> You draw "+amount+" coin(s).\n");
   call_other(this_player(),"add_money",amount);
   money=money-amount;
   return 1;
 }   

amt() 
 { int amount;
   amount=call_other(this_player(),"query_money",0);
   write("$$$> You have "+money+" coin(s) in your purse and "+amount+" coin(s) in your pocket.\n");   
   return 1;
 }
help(arg) { 
  if(arg=="purse") { cat("/players/trix/helpdir/pursehelp"); return 1; }
  return 0;
 }

info(arg) { 
 if(arg=="purse") 
  { write("                              Virtual Purse 1.0\n");
    write("This purse can store an illimitate number of coins; it autoloads, this means\n"+
          "that you don't have to get one every time you log on.\n"+
          "It doesn't save money from disconnections and logouts, so , make sure that you\n"+
          "swap all your money out of it before quitting.\n");
    return 1;
  }
 return 0;
}
get() {
        return 1;
}

drop() {
        return 1;

}
