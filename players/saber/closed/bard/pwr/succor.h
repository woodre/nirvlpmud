/*
 *  A go-to-guild-spell for the Bardic Guild or Ryllian.
 *  v3.0 by Saber / Geoffrey Z.
 *
 */


succor(str)  {

object BARD, MIRROR;
int TEL_FLAG;

  if(spell(-50,1,35) == -1) return 0;
  
  if(REALM !="NT")  {
    MIRROR = present("mirror", ENV);
    if(MIRROR)  {
      write("You glance into the mirror.\n");
      say(tp+" glances into the mirror.\n\n");
      say("The "+BOLD+"runes"+NORM+" on "+tp+"'s "+INST+" glow a bright "+BOLD+
          "silver."+NORM+"\n"+
          tp+" slowly fades from view.\n\n");
      say("In the distance, you hear a crash of thunder.\n"+
          "The mirror "+HIB+"gleams"+NORM+".\n");
      TEL_FLAG = 1;
        
        }  else  {
        
      write("You glance up at the sky.\n");
      say(tp+" glances up at sky.\n");
      say("The "+BOLD+"runes"+NORM+" on "+tp+"'s "+INST+" glow a bright "+BOLD+
          "silver"+NORM+".\n\n");
      if(COLOR)  {
        say("There is a sudden "+HIB+"gust of wind"+NORM+", and "+tp+" is gone.\n\n");
          }  else  {
        say("There is a sudden gust of wind, and "+tp+" is gone.\n\n");
          }
      say("In the distance, you hear a crash of thunder.\n");
      if(file_name(environment(this_player())) == "room/church") TEL_FLAG = 1;
        }
   
  if(COLOR)  {
   write("\nYou rise upward in a sudden "+HIB+"gust of wind"+NORM+".\n\n"+
         "High in the sky, you speed towards the City of Ryllian.\n\n"+
         "You suddenly drop towards Orin's Inn...\n\n");
         }  else  {
   write("\nYou rise upward in a sudden gust of wind.\n\n"+
         "High in the sky, you speed towards the City of Ryllian.\n\n"+
         "You suddenly drop towards Orin's Inn...\n\n");
        
         } 
   
   move_object(TP, "/players/saber/closed/bard/r/summon.c");
   say("\nThere is a sudden gust of wind.\n"+tp+" has arrived.\n");
   write("The runes on your "+BOLD+INST+NORM+" glow brightly.\n"+
         "You are now in the Guild Hall of the Bards.\n");
   
   if(TEL_FLAG)  {  
     write("You were not drained any mana.\n");
     return 1;
         }
         
   call_other(TP, "add_spell_point", -40);
   return 1;
         }
         
   write("You cannot succor from here.\n");
   return 1;
         }
