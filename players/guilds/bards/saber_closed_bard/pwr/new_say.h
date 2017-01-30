/*
 *  New emotions and speach for the Bards.
 *  A new say.  Note that it uses :, so that player do not HAVE to use this.
 *  This is not for wiz pts, I just don't like the way that say looks now.
 *  v3.0 by Saber / Geoffrey Z.
 *
 */


new_say(str)  {
string message;

  if(!str || sscanf(str, "%s", message) != 1)  {
    write("What would you like to say?\n");
    return 1;
        }
        
  else if(sscanf(str, "%s!!!", message))  {
    write("You yell \""+str+"\"\n");
    say(tp+" yells \""+str+"\"\n");
    return 1;
        }
        
  else if(sscanf(str, "%s!", message))  {
    write("You exclaim \""+str+"\"\n");
    say(tp+" exclaims \""+str+"\"\n");
    return 1;
        }
        
  else if(sscanf(str, "%s???", message))  {
    write("You wonder \""+str+"\"\n");
    say(tp+" wonders \""+str+"\"\n");
    return 1;
        }
        
  else if(sscanf(str, "%s?", message))  {
    write("You ask \""+str+"\"\n");
    say(tp+" asks \""+str+"\"\n");
    return 1;
        }
        
  else if(sscanf(str, "%s", message))  {
    write("You say \""+str+"\"\n");
    say(tp+" says \""+str+"\"\n");
    return 1;
        }
        
  else  {
    write("ERROR - TELL SABER\n");
    return 1;
        }
        }
