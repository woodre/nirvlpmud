/*
 *  A bit 'o cade that returns a string for how tough a monsters weapon class is.
 *  For the Storm Bards of Ryllian
 *  v2.0 by Saber / Geoffrey Z.
 *
 */

check_mwc(str)  {

string PASS;

  if(!str)  {  str == 0;  }

       if(str <  3)             PASS = "pitiful.  Party naked!  It still won't hit.";
  else if(str >  2 && str < 5)  PASS = "pitiful";
  else if(str >  4 && str < 7)  PASS = "feeble";
  else if(str >  6 && str < 9)  PASS = "weak";
  else if(str >  8 && str < 11) PASS = "poor";
  else if(str > 10 && str < 13) PASS = "below average";
  else if(str > 12 && str < 15) PASS = "average";
  else if(str > 14 && str < 17) PASS = "good";
  else if(str > 16 && str < 19) PASS = "strong";
  else if(str > 18 && str < 21) PASS = "excellent";
  else if(str > 20 && str < 23) PASS = "deadly";
  else if(str > 22 && str < 25) PASS = "exceptional";
  else if(str > 24 && str < 27) PASS = "superb";
  else if(str > 26 && str < 29) PASS = "amazing";
  else if(str > 28 && str < 31) PASS = "exquisit";
  else if(str > 30 && str < 33) PASS = "lethal";
  else if(str > 32 && str < 37) PASS = "godlike";
  else if(str > 36)             PASS = "godlike.  Run while you still can!";

  return PASS;
  
        }
