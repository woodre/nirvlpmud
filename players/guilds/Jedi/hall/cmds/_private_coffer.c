#include "../defs.h"
#include "../ansi.h"

main(string str)
{
   
   int amt, cur_balance;
   if(!C_OBJ)
      {
      write("Error! Missing clan object.\n");
      return 1;
   }
   
   if(!str || str == "balance")
      {
      write("Current private coffer balance: "  + YEL + C_OBJ->query_private_coffer() + NORM + " coins.\n");
      return 1;
   }
   
   if(sscanf(str,"%s %d",str,amt) != 2)
      {
      write("Syntax: private_coffer [balance || deposit || transfer] [amount].\n");
      return 1;
   }
   
   if(str != "deposit" && str != "transfer")
      {
      write("Syntax: private_coffer [balance || deposit || transfer] [amount].\n");
      return 1;
   }
   
   if(str == "transfer")
      {
      if((int)TP->query_bank_balance() == 0)
         {
         write("Your bank account is empty.\n");
         return 1;
      }
      
      if(amt < 1 || amt > (int)TP->query_bank_balance())
         {
         write("Pick a number between 1 and " + TP->query_bank_balance()+ " to transfer.\n");
         return 1;
      }
      
      TP->add_bank_balance(-amt);
      C_OBJ->add_private_coffer(amt);
      write("You transfer " + YEL + amt + NORM + " coins from your bank account to the private coffers.\n");
      return 1;
   }
   
   if((int)TP->query_money() == 0)
      {
      write("You are flat broke! How are you going to deposit anything?\n");
      return 1;
   }
   
   if(amt < 1 || amt > (int)TP->query_money())
      {
      write("Pick a number between 1 and " + TP->query_money()+ " to deposit.\n");
      return 1;
   }
   
   TP->add_money(-amt);
   C_OBJ->add_private_coffer(amt);
   write("You deposit " + YEL + amt + NORM + " coins into the private coffers.\n");
   return 1;
}
