/*
 *  Corpse healing selection for the Bardic Guild
 *  v3.0 by Saber / Geoffrey Z.
 *
 */


t_healing(str)  {

string T_NAME;
  
  if(!str)  {
    write("\nYou may choose to bury a corpse in the following ways:\n\n"+
          "  You may bury it                           <bury>\n"+
          "  You may bury it and place a headstone     <grave>\n"+
          "  You may build a pyre and burn the corpse  <pyre>\n\n"+
          "To select a method, type < bury_type > < method (bury-grave-pyre) > \n\n");
    return 1;
        }
 
   if(str == "bury")        INSTR->set_bury_type("bury");
   else if(str == "grave")  INSTR->set_bury_type("grave");
   else if(str == "pyre")   INSTR->set_bury_type("pyre");
   else {  write("\nThat is not a valid selection.\n"); 
           command("bury_type", this_player());             }
  
   write("You set your bury_type to "+BOLD+str+NORM+".\n");
   return 1;
 
        }
