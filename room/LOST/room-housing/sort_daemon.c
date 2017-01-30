/* ***************************************************************************
 * File:           /players/earwax/housing/sort_daemon.c    
 * Function:       Sorts information for the land daemon and realties
 * Author:         Earwax
 * Copyright:      Copyright (c) 2004 Earwax.  All rights reserved.
 * Source:         5/26/04
 * Notes:          Just makes working with land daemon a little easier
 * Change History:
 * **************************************************************************/

#include <ansi.h>

#pragma weak_types
#pragma combine_strings

#include "defs.h"
#define LSHORT Info[index][0]
#define LCREATOR Info[index][1]
#define REALM Info[index][2]
#define LOTSIZE Info[index][3]
#define LOWNER Info[index][4]
#define LCOST Info[index][5]
#define ECONFLAG Info[index][6]
#define AVAILABLE Info[index][7]
#define OFFERTIME Info[index][8]
#define DEVELOPED Info[index][9]

/* Global Variables */

static string  *SortList;   /* For the sort functions                       */
static mapping  FilterList; /* For the filter functions                     */
static mixed   *Info;       /* Mirror of the one in land daemon             */
static string   Creator;    /* For filter function                          */

/* ***************************************************************************
 * Function Name: 
 * Description:   
 * Arguements:    
 * Returns:       
 * **************************************************************************/
string
comma_number(string num)
{
  int i;

  num += "";  
  i = strlen(num);

  switch(i)
  {
    case 9  : return (num[0..2]+","+num[3..5]+","+num[6..8]);
    case 8  : return (num[0..1]+","+num[2..4]+","+num[5..7]);
    case 7  : return (num[0..0]+","+num[1..3]+","+num[4..6]);
    case 6  : return (num[0..2]+","+num[3..5]);
    case 5  : return (num[0..1]+","+num[2..4]);
    case 4  : return (num[0..0]+","+num[1..3]);
    default : return num;
  }
}
/* ***************************************************************************
 * Function Name: 
 * Description:   
 * Arguements:    
 * Returns:       
 * **************************************************************************/
/* ***************************************************************************
 * Function Name: 
 * Description:   
 * Arguements:    
 * Returns:       
 * **************************************************************************/

status 
sort_ascending(int a, int b)
{
  int i, index, siz;
  string temp, temp2;
  int t, t2;
  string *sorts;

  siz = sizeof(SortList);

  for (i = 0; i < siz; i++)  
  {
    if (SortList[i] == "creator")
    {
      index = a; temp = LCREATOR;
      index = b; temp2 = LCREATOR;
      if (temp != temp2) return (temp < temp2);
    }
    if (SortList[i] == "realm")
    {
      index = a; temp = REALM;
      index = b; temp2 = REALM;
      if (temp != temp2) return (temp < temp2);
    }
    if (SortList[i] == "lotsize")
    {
      index = a; temp  = ""+LOTSIZE;
      index = b; temp2 = ""+LOTSIZE;
      t = strlen(temp); t2 = strlen(temp2);
      if (t != t2) return (t < t2);
      if (temp != temp2) return (temp < temp2);
    }
    if (SortList[i] == "cost")
    {
      index = a; temp = LCOST+"";
      index = b; temp2 = LCOST+"";
      t = strlen(temp); t2 = strlen(temp2);
      if (t != t2) return (t < t2);
      if (temp != temp2) return (temp < temp2);
    }
    if (SortList[i] == "development")
    {
      index = a; temp = DEVELOPED+"";
      index = b; temp2 = DEVELOPED+"";
      t = strlen(temp); t2 = strlen(temp2);
      if (t != t2) return (t < t2);
      if (temp != temp2) return (temp < temp2);
    }
  }

  index = a; temp = LSHORT;
  index = b; temp2 = LSHORT;
  return (a < b);
}

status sort_descending(int a, int b) { return (sort_ascending(a, b) ? 0 : 1); }

/* **************************************************************************
 * Various Filters
 * *************************************************************************/
status filter_unavailable(int index) { return (AVAILABLE ? 0 : 1) ; }
status filter_available(int index) { return AVAILABLE; }
status filter_large(int index) { return LOTSIZE < 1; }
status filter_medium(int index) { return (LOTSIZE < 10 && LOTSIZE > 3); }
status filter_small(int index) { return (LOTSIZE > 0 && LOTSIZE < 4); }
status filter_developed(int index) { return DEVELOPED; }
status filter_undeveloped(int index) { return (DEVELOPED ? 0 : 1); }
status filter_creator(int index) { return (LCREATOR == Creator); }

string *
generate_output(string verb, mixed *info, string arg)
{
  string *output, *args;
  string temp; 
  int i, siz, size, flag_sort, index;
  object me;
  int *indices;
    
  me = this_object();
  SortList = ({ });
  Info = info;  
  flag_sort = 0;
  indices = allocate(i = sizeof(Info)); while(i--) indices[i] = i;
  
  /*
   * Issues with types not being passed correctly
   */
  
   siz = sizeof(Info);
   for (index = 0; index < siz; index++)
     if (stringp(LOTSIZE))
       sscanf(LOTSIZE, ""+"%d", LOTSIZE);
       
  /*
   * First, parse the args for filter lists and sort fields/order
   */
  if (!arg || arg == "all")
    arg = "bycreator realm lotsize cost";
    
   siz = sizeof(args = explode(arg, " "));
 
   for (i = 0; i < siz; i++) /* For loop to preserve the order */
   {
     switch(args[i])
     {
       case "available"   : indices = filter_array(indices, "filter_available", me); 
                            break;
       case "unavailable" : indices = filter_array(indices, "filter_unavailable", me);
                            break;
       case "large"       : indices = filter_array(indices, "filter_large", me); 
                            break;
       case "medium"      : indices = filter_array(indices, "filter_medium", me);
                            break;
       case "small"       : indices = filter_array(indices, "filter_small", me);
                            break;
       case "developed"   : indices = filter_array(indices, "filter_developed", me); 
                            break;
       case "undeveloped" : indices = filter_array(indices, "filter_undeveloped", me);
                            break;
       case "creator"     : if ((i + 1) < siz) Creator = args[(i+1)];
                            indices = filter_array(indices, "filter_creator", me);
                            break;
       case "bycreator"   : SortList += ({ "creator" }); flag_sort++; break;
       case "realm"       : SortList += ({ "realm" }); flag_sort++; break;
       case "lotsize"     : SortList += ({ "lotsize" }); break;
       case "cost"        : SortList += ({ "cost" }); break;
       case "development" : SortList += ({ "development" }); break;
     }
   }
   
   indices = sort_array(indices, (verb == "dlist" ? "sort_descending" : "sort_ascending"), me);
   flag_sort = ((flag_sort > 1 || arg == "all" || !siz) ? 1 : 0);
   temp = "";
   output = ({ HIK +"===============================================================================\n"+NORM+NORM
          + "Land listing: "+arg+"\n" });
   if (flag_sort)
     output += ({ HIW+"Index Dev/Max Cost        Location\n"+NORM+NORM });
   else
     output += ({ HIW+"Index Dev/Max Cost        Creator      Location\n"+NORM+NORM });
          
   output += ({ HIK +"===============================================================================\n"+NORM+NORM });
     
   siz = sizeof(indices);
      
   for (i = 0; i < siz; i++)
   {
     index = indices[i];
         
     if (flag_sort)
     {
       if (REALM != temp)
       {
         temp = REALM;
         output += ({ HIY+capitalize(LCREATOR) + ": "+REALM+"\n"+NORM+NORM });
       }

      if (stringp(LOTSIZE))
        sscanf(LOTSIZE+"", "%d"+"", size);
      else
        size = LOTSIZE;

      LOTSIZE = size;
      size = (LOTSIZE < 0 ? 999 : LOTSIZE);
      output += ({ (AVAILABLE ? "" : HIK)
        + pad(" "+index,4)
        + (string)WAXFUNS->ralign(DEVELOPED, 4)
        + "/"
        + pad(size, 4)
        + (string)WAXFUNS->ralign((AVAILABLE ? (string)UTILITYD->comma_number(LCOST) : capitalize(LOWNER))+"  ", 14)
        + LSHORT
        + "\n" +NORM + NORM});
    }
    else
    {
      if (stringp(LOTSIZE))
        sscanf(LOTSIZE+"", "%d"+"", size);
      else
        size = LOTSIZE;

      LOTSIZE = size;
      size = (LOTSIZE < 0 ? 999 : LOTSIZE);
      output += ({ (AVAILABLE ? "" : HIK)
        + pad(" "+index,4)
        + (string)WAXFUNS->ralign(DEVELOPED, 4)
        + "/"
        + pad(size, 4)
        + (string)WAXFUNS->ralign((AVAILABLE ? (string)UTILITYD->comma_number(LCOST) : capitalize(LOWNER))+"  ", 14) 
        + pad(capitalize(LCREATOR)+": ", 13)
        + LSHORT
        + "\n" +NORM+NORM});
    }      
  }
  
 output += ({ HIK +"===============================================================================\n"+NORM+NORM
        + "Land displayed: "+siz+"\n"
        + HIK +"===============================================================================\n"+NORM+NORM });
  return output;
}
        
        
        
        
