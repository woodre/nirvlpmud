/* Emotions for Bards */

blueli(str)  {
object ob;

 if(!str)  {
  
  if(COLOR)  {
  write("You briefly surround yourself with an aura of "+HIB+"blue magic"+NORM+".\n");
  say(tp+" surrounds "+OBJE+"self with an aura of sinister "+HIB+"blue magic"+NORM+".\n");

  }  else  {

  write("You briefly surround yourself with an aura of blue magic.\n");
  say(tp+" surrounds "+OBJE+"self with an aura of sinister blue magic.\n");
        }
  return 1;
        }

 ob = present(str,ENV);
  if(!ob)  {
    write(CAP+" is not here right now.\n");
    return 1;
        }

  if(COLOR)  {
 
  write("You point at "+CAP+", surrounding "+ob->query_objective()+" with an aura of pulsating "+HIB+"blue magic"+NORM+".\n");
  say(tp+" points at "+CAP+", surrounding "+ob->query_objective()+" with an aura of pulsating "+HIB+"blue magic"+NORM+".\n",ob);
  tell_object(ob, tp+" points at you, surrounding you with an aura of pulsating "+HIB+"blue magic"+NORM+".\n"+
     "You feel different.\n");

  }  else  {

  write("You point at "+CAP+", surrounding "+ob->query_objective()+" with an aura of pulsating blue magic.\n");
  say(tp+" points at "+CAP+", surrounding "+ob->query_objective()+" with an aura of pulsating blue magic.\n",ob);
  tell_object(ob, tp+" points at you, surrounding you with an aura of pulsating blue magic.\n"+
     "You feel different.\n");
     
     }
  
  return 1;
        }
