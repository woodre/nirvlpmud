/*
 *  A bit 'o cade that returns a string for the monsters alignment.
 *  For the Storm Bards of Ryllian
 *  v2.0 by Saber / Geoffrey Z.
 *
 */


check_ali(str)  {

string PASS;

  if(!str)  {  str == 0;  }

       if(str < -949)                 PASS = "Diabolical";
  else if(str > -950 && str < -799)   PASS = "Obscene";
  else if(str > -801 && str < -599)   PASS = "Wicked";
  else if(str > -600 && str < -399)   PASS = "Corrupt";
  else if(str > -400 && str < -199)   PASS = "Vile";
  else if(str > -200 && str <  -50)   PASS = "Malevolent";
  else if(str > -51  && str <   51)   PASS = "Balanced";
  else if(str >   50 && str <  200)   PASS = "Benevolent";
  else if(str >  199 && str <  400)   PASS = "Virtuous";
  else if(str >  399 && str <  600)   PASS = "Pure";
  else if(str >  599 && str <  800)   PASS = "Magnanimous";
  else if(str >  799 && str <  950)   PASS = "Righteous";
  else if(str >  949)                 PASS = "Saintly";

  return PASS;
  
        }
