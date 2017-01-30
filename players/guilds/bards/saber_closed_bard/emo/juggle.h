/* Emotions for Bards */

juggle()  {

  if(COLOR)  {
  
    write("You conjure four balls of "+HIM+"pastel "+HIC+"colored "+HIY+"light"+NORM+" and deftly\n"+
        "juggle them between your hands.\n");
  say(tp+" conjures four balls of "+HIM+"pastel "+HIC+"colored "+HIY+"light"+NORM+" and proceeds\n"+
      "to deftly juggle them between "+POSS+" hands.\n");

  }  else  {

  write("You conjure four balls of pastel colored light and deftly\n"+
        "juggle them between your hands.\n");
  say(tp+" conjures four balls of pastel colored light and proceeds\n"+
      "to deftly juggle them between "+POSS+" hands.\n");
      
      }

  return 1;

        }
