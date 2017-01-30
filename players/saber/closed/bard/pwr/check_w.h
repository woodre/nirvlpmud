/*
 *  A bit 'o cade that returns a string for how tough a weapon is.
 *  For the Storm Bards of Ryllian
 *  v3.0 by Saber / Geoffrey Z.
 *
 */

check_wc(str)  {

string PASS;

  if(!str)  {  str == 0;  }

       if(str <  3)             PASS = "wait...you call _that_ a weapon?";
  else if(str >  2 && str < 5)  PASS = "pitiful";
  else if(str >  4 && str < 7)  PASS = "feeble";
  else if(str >  6 && str < 9)  PASS = "weak";
  else if(str >  8 && str < 11) PASS = "poor";
  else if(str > 10 && str < 13) PASS = "average";
  else if(str > 12 && str < 15) PASS = "good";
  else if(str > 14 && str < 17) PASS = "excellent";
  else if(str > 16 && str < 19) PASS = "deadly";
  else if(str > 18 && str < 21) PASS = "superb";
  else if(str > 20 && str < 23) PASS = "exquisit";
  else if(str > 22 && str < 25) PASS = "godlike";
  else if(str > 24)             PASS = "godlike.  Wield this weapon!";

  return PASS;
  
        }
