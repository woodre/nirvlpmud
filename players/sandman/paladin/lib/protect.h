
/*
 * PROTECTION FROM EVIL (5/20/94)
 * Reduces damage done by evil monsters
 */

/* Minimum spell points */
#define MIN_SP 50

/* Maximum spell points */
#define MAX_SP 250

protection(str, prot_evil_time) {
   object shield;
   int cost;

   if(!str || sscanf(str, "from evil %d", cost) != 1)
     notify_fail("Usage:  protection from evil <spell points>");
   if(cost < MIN_SP)
     notify_fail("You must specify at least "+MIN_SP+" spell points.");
   if(cost > MAX_SP)
     notify_fail("The max spell points you can spend is "+MAX_SP+".");
   if(this_player()->query_protected_from_evil()) 
     notify_fail("You are already protected from evil!");
   if(!verify_use("spell",0,cost))
     return 1;
   shield = clone_object("players/sandman/paladin/obj/pr_evil");
   shield->start_protection_from_evil(this_player(),cost);
   TELL(capitalize(this_player()->query_name())+
       " is enveloped by a blue glow.\n");
   write("You are now protected from evil.\n");
   previous_object()->set_prot_evil_time(time());  
   return 1;
}
