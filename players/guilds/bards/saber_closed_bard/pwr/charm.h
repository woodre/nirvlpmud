/*
 *  A charm spell for the Bards Guild of Ryllian.
 *  v3.0 by Saber / Geoffrey Z.
 *
 */
 

charm(str)  {

object MARK, MARK1;
string CHARMED, TOCHARM;

if(!str)  {                 /* charm every monster in the room */

  if(spell(-50,3,40) == -1) return 0;
  
  MARK = first_inventory(ENV);
  
  while(MARK)  {
  
    MARK->stop_fight();          MARK->stop_fight();
    MARK->stop_fight();
    MARK->stop_hunter();         MARK->stop_hunter();
    MARK = next_inventory(MARK);
    
        }
        
if(COLOR)  {
  write("\nYou raise your "+INST+" and play a "+HIM+"soothing tune"+NORM+".\n"+
        "The fighting stops as your "+HIM+"music"+NORM+" fills the area.\n\n");

  say("\n"+tp+" raises "+POSS+" "+INST+" and plays a "+HIM+"soothing tune."+NORM+"\n"+
      "The fighting stops as "+tp+"'s "+NORM+"music"+NORM+" fills the area.\n\n"+
      "You have a strong urge to listen to "+tp+".\n");

        }  else  {

  write("\nYou raise your "+INST+" and play a soothing tune.\n"+
        "The fighting stops as your music fills the area.\n\n");

  say("\n"+tp+" raises "+POSS+" "+INST+" and plays a soothing tune.\n"+
      "The fighting stops as "+tp+"'s music fills the area.\n\n"+
      "You have a strong urge to listen to "+tp+".\n");

        }

  call_other(TP, "add_spell_point", -40);
  return 1;
        }


  /* stops a single monster from attacking the bard */
  
 if(sscanf(str, "%s %s", CHARMED, TOCHARM) < 2)  {

 if(spell(-50,5,30) == -1) return 0;
 
  MARK = present(str, ENV);
  
  if(!MARK)  { 
   write("You must see "+CAP+" before you can charm.\n");
   write("Syntax: charm < opponent > or < charm >\n");
   return 1;
        }
        
  MARK->stop_fight();    MARK->stop_fight();    MARK->stop_fight();
  TP->stop_fight();      TP->stop_fight();      TP->stop_fight();
  MARK->stop_hunter();   TP->stop_hunter();     MARK->stop_hunter();
  
  call_other(TP, "add_spell_point", -30);
  
if(COLOR)  {

  write("You play a "+HIM+"soothing melody"+NORM+" on your "+
         INST+" as you gaze into "+CAP+"'s eyes.\n"+
         CAP+" gets a dazed look on "+POSS+" face and stops fighting.\n");

  say(tp+" plays a "+HIM+"soothing melody"+NORM+" on "+
      POSS+" "+INST+" as "+PRO+" gazes at "+CAP+".\n"+
      CAP+" gets a dazed look in "+POSS+" face and stops fighting.\n");

        }  else  {
  
   write("You play a soothing melody on your "+INST+" as you gaze into "+CAP+"'s eyes.\n"+
          CAP+" gets a dazed look on "+POSS+" face and stops fighting.\n");

  say(tp+" plays a soothing melody on "+POSS+" "+INST+" as "+PRO+" gazes at "+CAP+".\n"+
      CAP+" gets a dazed look in "+POSS+" face and stops fighting.\n");

        }

  tell_object(MARK, "You feel very peaceful...\n");
  
  return 1;
        }


/* Lets the Bard remove other people from combat */

 if(spell(-50,7,30) == -1) return 0;
  
  if(!(MARK = present(TOCHARM, ENV)))  { 
   write("You must see "+capitalize(MARK)+" before you can charm.\n");
   write("Syntax: charm < target > < target >\n");
   return 1;
        }
  
  if(!(MARK1 = present(CHARMED, ENV)))  { 
   write("You must see "+capitalize(MARK1)+" before you can charm.\n");
   write("Syntax: charm < target > < target >\n");
   return 1;
        }

  
  MARK->stop_fight();    MARK->stop_fight();    MARK->stop_fight();
  MARK1->stop_fight();   MARK1->stop_fight();   MARK1->stop_fight();
  MARK->stop_hunter();   MARK1->stop_hunter();     
  MARK->stop_hunter();   MARK1->stop_hunter();
  
  call_other(TP, "add_spell_point", -30);
  
if(COLOR)  {

  write("Playing a "+HIM+"soothing melody"+NORM+" on your "+
         INST+", you gaze from "+capitalize(TOCHARM)+" to "+capitalize(CHARMED)+".\n"+
         capitalize(TOCHARM)+" and "+capitalize(CHARMED)+" stop fighting.\n");

  say("Playing a "+HIM+"soothing melody"+NORM+" on "+POSS+" "+INST+", "+
      tp+" gazes from "+capitalize(TOCHARM)+" to "+capitalize(CHARMED)+".\n"+
      capitalize(TOCHARM)+" and "+capitalize(CHARMED)+" stop fighting.\n");

        }  else  {
  
  write("Playing a soothing melody on your "+INST+", you gaze from "+
         capitalize(TOCHARM)+" to "+capitalize(CHARMED)+".\n"+
         capitalize(TOCHARM)+" and "+capitalize(CHARMED)+" stop fighting.\n");

  say("Playing a soothing melody on "+POSS+" "+INST+", "+
      tp+" gazes from "+capitalize(TOCHARM)+" to "+capitalize(CHARMED)+".\n"+
      capitalize(TOCHARM)+" and "+capitalize(CHARMED)+" stop fighting.\n");

        }

  tell_object(MARK,  "You feel very peaceful...\n");
  tell_object(MARK1, "You feel very peaceful...\n");
  
  return 1;
        }
