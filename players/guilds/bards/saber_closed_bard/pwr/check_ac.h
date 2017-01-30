/*
 *  A bit 'o cade that returns a string for how good armor is.
 *  For the Storm Bards of Ryllian
 *  v3.0 by Saber / Geoffrey Z.
 *
 */

check_ac(str)  {

string PASS;

  if(!str)  {  str == 0;  }

       if(str <  1)  PASS = "pitiful.  You call this armor?";
  else if(str == 1)  PASS = "average";
  else if(str == 2)  PASS = "superb";
  else if(str >  2)  PASS = "exquisit";

  return PASS;
  
        }
