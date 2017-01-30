/* This is help for bardic cantrips */

help(str)  {

string file;

/*
  file = "players/saber/closed/bard/cantrip/d/" + str;
  
  if(!restore_object(file))  {
  write("There is no "+str+" cantrip.\n");
 
   }  else   {
   
*/

  write("\n");
  cat("/players/saber/closed/bard/cantrip/d/"+str);
  write("\n");

  return 1;
        }
