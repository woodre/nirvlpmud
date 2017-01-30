#include "../DEFS.h"
#include DEFS_ALEVELS
#include DEFS_OFFICES

#define HPAD 19


/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Grand Master Dune the CyberNinja (neutral)
Guild Status: Guild Owner with Divine honor
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Level     : 19+12               Experience    : 189696507
Guild Lv  : 10 (Thoughtloop)    Guild Xp      :    800000
Belt      : black, degree 10    Free Guild Xp :         0
Coins     : 79080               Hit Points    : <<618/618>>
Credits   : 40000               Energy        : <<618/618>>

  Intox[104%]  Soak[0%]  Stuff[0%]  Capacity[0%]  FluxCharges[6]

Ninja Wep : Naginata            Weapon State : NONE
Ninja Wep : Naginata            Weapon State : wielded, like new
Fighting  : Brave               Attack Mode  : NONE
Quest Pts : 15                  Age: 9 days 15 hours 22 seconds
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/


int get_my_weight(object ob)
{
  int total;
  object one;
  if (!ob) return 1;
  one = first_inventory(ob);
  while(one)
  {
    total += (int)one->query_weight();
    one = next_inventory(one);
  }
  return total;
}


string rightAdjust(int num, int slotLength)
{
  int digits, spaces, i;
  string adjustedStr;

  digits = strlen(num + "");
  spaces = slotLength - digits;
  if (spaces < 0) adjustedStr = "" + num;
  else
  {
    adjustedStr = "";
    for (i = 0; i < spaces; i++)
    {
      adjustedStr += " ";
    }
    adjustedStr += num;
  }
  return adjustedStr;
}


status main(string str)
{
  int plev, xlev, ptox, ptuf, psok, car, myweight, preg;
  int gbal, honor, glev, gxp, alev, degree, lowxp, freexp, amode;
  string shortDesc, role, guildStatus, brand, expStr, gexpStr, fexpStr, 
         beltColor, amodeStr, wepState, wepStr;
  object wep;

  write(LINE);
  shortDesc = (string)TP->short();
  if (!shortDesc) write("(Hiding in Shadows)\n");
  else            write(shortDesc+"\n");
  guildStatus = "Guild Status: ";
  if (role = (string)call_other(OFFICED, "findRole", TP));
  else role = 0;
  if (TRN == OWNER1 || TRN == OWNER2) guildStatus += "Guild Owner";
  else if(role)                       guildStatus += capitalize(role);
  else                                guildStatus += "Standard Member";
  honor = (int)IPTP->query_honor();
  guildStatus += 
    " with " + (string)call_other(HLEVELD, "honorTitle", honor) + " honor";
  write(guildStatus + "\n");
  write(LINE);

/******************************/

  plev = (int)TP->query_level();
  xlev = (int)TP->query_extra_level();
  if (plev == 19) write("Level     : " + pad(plev + "+" + xlev, HPAD) + " ");
  else            write("Level     : " + pad(plev, HPAD) + " ");

  expStr = rightAdjust((int)TP->query_exp(), 9);
  write("Experience    : " + expStr + "\n");

/******************************/

  brand  = capitalize((string)IPTP->query_brand());
  glev   = (int)IPTP->guild_lev();
  write("Guild Lv  : " + pad(glev + " (" + brand + ")", HPAD) + " ");

  gxp     = (int)IPTP->guild_exp();
  gexpStr = rightAdjust(gxp, 9);
  write("Guild Xp      : " + gexpStr + "\n");

/******************************/

  alev   = (int)IPTP->query_art_level();
  degree = alev - BLACK_BELT;
  if (degree < 0) degree = 0;
  beltColor = (string)call_other(ALEVELD, "findBeltColor", alev);
  if (degree > 0) 
    write("Belt      : " + pad(beltColor + ", degree " + degree, HPAD) + " ");
  else 
    write("Belt      : " + pad(beltColor, HPAD) + " ");

  lowxp  = (int)call_other(GLEVELD, "low_exp", glev);
  freexp = gxp - lowxp;
  fexpStr = rightAdjust(freexp, 9);
  write("Free Guild Xp : " + fexpStr + "\n");

/******************************/

  write("Coins     : " + pad((int)TP->query_money(), HPAD) + " ");

  write("Hit Points    : <<" +
    (int)TP->query_hp() + "/" + (int)TP->query_mhp() + ">>\n");

/******************************/

  gbal = (int)IPTP->balance();
  write("Credits   : " + pad(gbal, HPAD) + " ");

  write("Energy        : <<" +
    (int)TP->query_sp() + "/" + (int)TP->query_msp() + ">>\n");

/******************************/

  ptox = (int)TP->query_intoxination();
  ptuf = (int)TP->query_stuffed();
  psok = (int)TP->query_soaked();

  TP->recalc_carry();
  car = plev;
  car += 6;
  car += (int)TP->query_attrib("str") / 5;
  myweight= get_my_weight(TP);

  write("\n  Intox["   + (ptox*100)/((int)this_player()->query_max_intox()) + "%]  " +
        "Soak["        + (psok*100)/((int)this_player()->query_max_soak()) + "%]  " +
        "Stuff["       + (ptuf*100)/((int)this_player()->query_max_stuff()) + "%]  " +
        "Capacity["    + (myweight*100/car)  + "%]  " +
        "FluxCharges[" + (int)IPTP->query_flux_charges() + "]\n\n");

/******************************/

  wepStr = (string)IPTP->query_weapon();
  if (wepStr && wepStr != "" && wepStr != "0")
  {
    write("Ninja Wep : " + pad(capitalize(wepStr), HPAD) + " ");
  }
  else
  {
    write("Ninja Wep : " + pad("NONE", HPAD) + " ");
  }

  if (present(WEAPON_ID, TP))
  {
    wep = present(WEAPON_ID, TP);
    if (wep->query_wielded())
      wepState = "wielded";
    else
      wepState = "not in use";
    wepState += ", " + (string)wep->query_wear_desc();
  }
  else
  {
    wepState = "NONE";
  }
  write("Weapon State : " + wepState + "\n");

/******************************/

  if ((status)TP->query_wimpy())
    write("Fighting  : " + pad("Wimpy", HPAD) + " ");
  else
    write("Fighting  : " + pad("Brave", HPAD) + " ");

  amode  = (int)IPTP->query_attack_mode();
  if (!amode)     amodeStr = upper_case(ATTACK_MODE0);
  if (amode == 1) amodeStr = upper_case(ATTACK_MODE1);
  if (amode == 2) amodeStr = upper_case(ATTACK_MODE2);
  write("Attack Mode  : " + amodeStr + "\n");

/******************************/

  write("Quest Pts : " + 
    pad((int)TP->query_quest_point(), HPAD) + " ");

  (string)TP->show_age();

/******************************/

  if ((int)TP->query_pregnancy())
  {
    preg = (int)TP->query_age() - (int)TP->query_pregnancy();
    if (preg > 4000)
      write("Pregnancy: " + (preg*100/16300) + "%\n"); 
  }

/******************************/

  write(LINE);

  return 1;
}



