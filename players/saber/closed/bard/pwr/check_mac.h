/*
 *  A bit 'o cade that returns a string for how tough a monster's armor is.
 *  For the Storm Bards of Ryllian
 *  v2.0 by Saber / Geoffrey Z.
 *
 */

check_mac(str)  {

string PASS;

  if(!str)  {  str == 0;  }

       if(str <  3)   PASS = "pitiful.  Close your eyes and swing.  You'll still hit";
  else if(str >  2 && str < 5)  PASS = "pitiful";
  else if(str >  4 && str < 7)  PASS = "poor";
  else if(str >  6 && str < 9)  PASS = "average";
  else if(str >  8 && str < 11) PASS = "good";
  else if(str > 10 && str < 13) PASS = "strong";
  else if(str > 12 && str < 15) PASS = "excellent";
  else if(str > 14 && str < 17) PASS = "exceptional";
  else if(str > 16 && str < 19) PASS = "superb";
  else if(str > 18 && str < 21) PASS = "amazing";
  else if(str > 20 && str < 23) PASS = "exquisit";
  else if(str > 22 && str < 27) PASS = "godlike";
  else if(str > 26)             PASS = "godlike.  Face it.  You're not going to hit.";

  return PASS;
  
        }
