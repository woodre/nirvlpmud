/*The Money is high but it will give goals to achieve if a Legend so desires.*/

#include "/players/jareel/define.h"
inherit "obj/treasure.c";

      reset(arg){
        if(arg) return;
      
      set_short(BOLD+"A small sign"+NORM);
      set_alias("sign");
      set_long("\n"+BOLD+
       "     "+NORM+RED+"------ "+NORM+BOLD+"RULES "+NORM+RED+"------"+NORM+BOLD+"\n"+
       "  1: All deposits are final.\n"+
       "  2: No refunds will be given.\n"+
       "\n"+
       "      "+NORM+RED+"------ "+NORM+BOLD+"STEPS "+NORM+RED+"------"+NORM+BOLD+"\n"+
       "  1: 100,000 coins    (Describe your room).\n"+
       "  2: 500,000 coins    (A statue of yourself in your room).\n"+
       "  3: 1,000,000 coins  (Help: Create a mob and item modeled after yourself).\n"+
       "  4: 2,500,000 coins  (A message center for you).\n"+
       "  5: 5,000,000 coins  (Viewscreen, to see who has killed your image.)\n"+
       "  6: 10,000,000 coins (Viewscreen, to see who your image has killed.)\n"+
       "\n"+
       "     "+NORM+RED+"------ "+NORM+BOLD+"COMMANDS "+NORM+RED+"------"+NORM+BOLD+"\n"+
       "  1: To deposit into your account -  deposit <COINS> ONLY LEGENDS CAN DEPOSIT!!.\n"+
       "  2: To see Legends Balance  -  deposit_list.\n"+
       "  3: To see personal Balance - inquire.\n"+
       "\n"+
       "\n"+
       "\n\n"+NORM);
      
      set_read("\n"+BOLD+
       "      "+NORM+RED+"------ "+NORM+BOLD+"RULES "+NORM+RED+"------"+NORM+BOLD+"\n"+
       "  1: All deposits are final.\n"+
       "  2: No refunds will be given.\n"+
       "\n"+
       "      "+NORM+RED+"------ "+NORM+BOLD+"STEPS "+NORM+RED+"------"+NORM+BOLD+"\n"+
       "  1: 100,000 coins    (Describe your room).\n"+
       "  2: 500,000 coins    (A statue of yourself in your room).\n"+
       "  3: 1,000,000 coins  (Help: Create a mob and item modeled after yourself).\n"+
       "  4: 2,500,000 coins  (A message center for you).\n"+       
       "  5: 5,000,000 coins  (Viewscreen, to see who has killed your image.)\n"+
       "  6: 10,000,000 coins (Viewscreen, to see who your image has killed.)\n"+
       "\n"+
       "     "+NORM+RED+"------ "+NORM+BOLD+"COMMANDS "+NORM+RED+"------"+NORM+BOLD+"\n"+
       "  1: To deposit into your account -  deposit <COINS> ONLY LEGENDS CAN DEPOSIT!.\n"+
       "  2: To see legends_balance  -  deposit_list.\n"+
       "  3: To see personal Balance - inquire.\n"+
       "\n"+
       "\n"+
       "\n\n"+NORM);
     }


get() { return 0;
}
