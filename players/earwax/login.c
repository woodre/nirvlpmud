/*
 *      File:                   /daemons/login.c
 *      Function:               Miscellaneous login-related functions
 *      Author(s):              Earwax@Nirvana
 *      Copyright:              Copyright (c) 2007 David Halek (Earwax)
 *                                      All Rights Reserved.
 *      Source:                 11/01/07
 *      Notes:                  
 *      Change History:
 */

#include <ansi.h>
#include <security.h>

int level;

/* 
 * Function name:  check_siteban
 * Description:    Checks if the user is sitebanned.
 * Arguments:      Login passes it query_ip_number() (numeric ip address)
 * Returns:        1 if they are or 0 if they aren't
 */

int check_siteban(string ipaddy)
{
  string junk, reason;
  
  /* No sitebans right now */
  /*
  if (sscanf(query_ip_number(), "66.189%s", junk))
  {
    reason = "Being a major pain in the ass.\n";
  } 
  */ 

  if (reason)
  {
    printf("You are sitebanned for: %s\n", reason);
    write("If you feel this is in error, email to nirvana@nirvana.beanos.com\n");
    return 1;
  }

  return 0;
}

/* 
 * Function name: valid_name
 * Description:   Checks if str is a valid name for login purposes
 * Arguments:     string str
 * Returns:       0 for no, 1 for valid
 */
  
int valid_name(str) {
  int i, length;
  
  if (str == "logon") 
  {
    write("Invalid name.\n");
    return 0;
  }
  
  length = strlen(str);
  i = -1;
  
  if (length > 11) 
  {
    write("Too long name.\n");
    return 0;
  }
  
  while(i++ < length) 
  {
    if (str[i] < 'a' || str[i] > 'z') 
    {
      write("Invalid characters in name:" + str + "\n");
      write("Character number was " + i + ".\n");
      return 0;
    }
  }
  
  if (restore_object("banish/" + str)) 
  {
    write("That name is reserved.\n");
    write("Please use another if you wish to create a new character.\n");
    return 0;
  }

  if (restore_object("pfiles/dumbasses/" + str)) 
  {
    write("That character has been deemed to be a blithering idiot.  Pick another.\n");
    return 0;
  }

  if (restore_object("pfiles/"+str[0]+"/"+str) && level > 999)
  {
    if(!"/obj/daemons/closed/ipcheck"->check(query_ip_number(), str)) 
    {
      write("God and level 1000 access not allowed from your address.\n");
      return 0;
    }
  }

  /* Put checks for handling inactive status here */
      
  return 1;
}

/* 
 * Function name:
 * Description:
 * Arguments:
 * Returns:
 */
