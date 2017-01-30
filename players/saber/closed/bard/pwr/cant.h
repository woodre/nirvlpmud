/*
 *  Sign language for the Bardic Guild or Ryllian.
 *  v3.0 by Saber / Geoffrey Z.
 *
 */


cant(str)  {

object PLAYER;

  if(!str)  {
    write("What would you like to sign?\n"+
          "Syntax: < cant > < message >\n");
    return 1;
        }
  
  PLAYER = first_inventory(ENV);
  
  while(PLAYER)  {
    if(living(PLAYER))  {
      if(present("instrument", PLAYER))  {
        if(PLAYER->query_name() != tp)  {
          tell_object(PLAYER, tp+" signs '"+str+"' in bardic cant.\n");
          }
          }
       if(!present("instrument", PLAYER))  {
         tell_object(PLAYER, tp+" makes a series of unusual facial and hand gestures.\n");
          }
          }
   PLAYER = next_inventory(PLAYER);
          }
          
   write("You sign '"+str+"' in bardic cant.\n");
   return 1;
          }
