/*****************************************************************************
 *      File:                   gear_funcs.c
 *      Function:               functions for bwo objects
 *      Author(s):              Sparrow@Nirvana
 *      Copyright:              Copyright (c) 2006 Sparrow 
 *                              All Rights Reserved.
 *      Source:                 03/25/2006
 *      Notes:                  
 *      Change History:         03/28/06 Sparrow: Development suspended until
 *                              changes to armor are completed
 *                              04/07/06 Sparrow: Began recode of armor gener-
 *                              ation to follow new proposed standards.
 *															Accessories will be generated seperate from
 *                              armor.
 *															04/07/06 Sparrow added generate_accessory
 *                              04/12/06 Sparrow: Gutted generate_accessory
 *                              and seperated into seperate functions.   
 ****************************************************************************/
#include <ansi.h>

string
gimmie_short(string dtype)
{
  switch(dtype)
  {
  case "other|dark":
    return HIW+"S"+HIK+"hadows"+NORM;
    break;
  case "other|light":
    return HIY+"B"+NORM+"rilliance";
    break;
  case "other|water":
    return HIB+"M"+CYAN+"ist"+NORM;
    break;
  case "other|fire":
    return RED+"F"+HIR+"lame"+NORM;
    break;
  case "other|wind":
    return "Wind";
    break;
  case "other|earth":
    return HIK+"S"+NORM+YEL+"tone"+NORM;
    break;
  case "other|ice":
    return HIC+"F"+NORM+"rost";
    break;
  case "other|electric":
    return HIY+"Sparks"+NORM;
    break;
  case "other|laser":
    return HIM+"E"+HIC+"ne"+HIM+"rg"+HIC+"y"+NORM;
    break;
  case "other|evil":
    return HIR+"D"+HIK+"evestation"+NORM;
    break;
  case "other|good":
    return HIR+"Love"+NORM;
    break;
  case "other|poison":
    return HIG+"V"+NORM+GRN+"enom"+NORM;
    break;
  case "other|sonic":
    return MAG+"W"+BLU+"ailing"+NORM;
    break;
  case "other|mental":
    return CYAN+"I"+HIW+"ll"+HIB+"us"+HIM+"ion"+NORM;
    break;
  case "magical":
    return "Magic";
    break;
  default:
    return "Warding";
  } 
}

/* 
 * Function name: calc_acc_power()
 * Description:   This function calculates the power of the accessory
 * Arguments:     int mob_pow
 * Returns:       array power
 */

int
*calc_acc_power(int mob_pow)
{
  int *power;
  int *resist;
  int resist_lev;
  switch(mob_pow)
  {
    case 1:
      resist = ({0,0,0,1,1,1,1,2,2,3});
      break;
    case 2:
      resist = ({0,1,1,2,2,2,2,3,3,4});
      break;
    case 3:
      resist = ({1,1,2,2,3,3,3,4,4,4});
      break;
    default:
      resist = ({0,0,0,1,1,1,1,2,2,3});
      break;
  }
  resist_lev = resist[random(10)];
  switch(resist_lev)
  {
    case 0:
      /* no resistance bonus */
      power = ({0});
      break;
    case 1:
      /* 90% chance of minor single resistance, 10% double */
      if(random(10)==0)
      {
        power = ({random(4)+5,random(4)+5});
      }
      else
      {
        power = ({random(4)+5});
      }
      break;
    case 2:
      /* 50% chance of moderate single resistance, 40% moderate double, 
      10% Minor Elemental */
      switch(random(10))
      {
        case 0:case 1:case 2:case 3:case 4:
          power = ({random(5)+7});
        case 5:case 6:case 7:case 8:
          power = ({random(5)+7,random(5)+7});
          break;
        default:
          power = ({random(4)+5,random(4)+5,random(4)+5,random(4)+5,random(4)+5,
          random(4)+5});
      }
      break;
    case 3:
      /* 50% chance of major single resistance, 40% chance major double
      10% moderate elemental */
      switch(random(10))
      {
        case 0:case 1:case 2:case 3:case 4:
          power = ({random(5)+10});
          break;
        case 5:case 6:case 7:case 8:
          power = ({random(5)+10,random(5)+10});
          break;
        default:
          power = ({random(5)+7,random(5)+7,random(5)+7,random(5)+7,
          random(5)+7,random(5)+7});
        }
      break;
    case 4:
      /* 50% chance of godly single resistance, 40% chance godly double
      10% major elemental */
      switch(random(10))
      {
        case 0:case 1:case 2:case 3:case 4:
          power = ({random(11)+15});
          break;
        case 5:case 6:case 7:case 8:
          power = ({random(6)+13,random(6)+13});
          break;
        default:
          power = ({random(5)+10,random(5)+10,random(5)+10,random(5)+10,
          random(5)+10,random(5)+10});
      }
      break;
    default:
      /* no resistance bonus */
      power = ({0});
      break;
  }
  return power;
}

/* 
 * Function name: calc_acc_dtype()
 * Description:   This function calculates the dtype(s) of the accessory
 * Arguments:     array - power
 * Returns:       array - dtype
 */
string
*calc_acc_dtype(int *power)
{
  string *dtype;
  string *dlist;
  int pow_size;
  int i;
  dlist = allocate(15);
  dlist = ({"other|dark","other|light","other|water","other|fire",
  "other|wind","other|earth","other|ice","other|electric","other|laser",
  "other|evil","other|good","other|poison","other|sonic","other|mental",
  "magical"});
  pow_size = sizeof(power);
  switch(pow_size)
  {
    case 1:
      dtype = allocate(1);
      if(power[0] == 0)
      {
        dtype[0] = "none";
      }
      else
      {
        dtype[0] = dlist[random(15)];
      }
      break;
    case 2:
      dtype = allocate(2);
      dtype[0] = dlist[random(15)];
      dtype[1] = dlist[random(15)];
      while(dtype[0]==dtype[1])
      {
        dtype[1] = dlist[random(15)];
      }
      break;
    case 6:
      dtype = allocate(6);
      dtype = ({"other|water","other|fire","other|wind","other|earth",
      "other|ice","other|electric"});
      break;
  }
  return dtype;
}

/* Function name: gen_acc_short()
 * Description:   This function builds the short description of the acc
 *                based on resistance type and power
 * Arguments:     array - dtype
 *                array - power
 *                string - slot
 * Returns:       string
 */
string
gen_acc_short(string *dtype, int *power, string slot)
{
  string short_string;
  short_string = capitalize(slot)+" "+NORM;
  if(slot=="chest")
  {
  short_string = "Chestguard "+NORM;
  }
  if(sizeof(dtype) > 2)
  {
    short_string += "["+YEL+"El"+CYAN+"e"+BLUE+"m"+RED+"e"+BLUE+
    "n"+CYAN+"t"+YEL+"al"+NORM+"]";
  }
  if(sizeof(dtype)==2)
  {
    short_string += "["+gimmie_short(dtype[0])+"] ["+gimmie_short(dtype[1])+"]"; 
  }
  if(sizeof(dtype)==1)
  {
    if(dtype[0]=="none")
    {
      short_string = HIK+"Common "+short_string;
    }
    else
    {
      short_string += "["+gimmie_short(dtype[0])+"]";
    }
  }
    if(power[0] < 9 && power[0] > 0) 
    { 
      short_string = HIW+"Titanium "+short_string;
    }
    if(power[0] > 8 && power[0] < 13)
    {
      short_string = HIK+"Mithril "+short_string;
    }
    if(power[0] > 12 && power[0] < 19)
    {
      short_string = GRN+"Adamantite "+short_string;  
    }
    if(power[0] > 18)
    {
      short_string = CYAN+"Runite "+short_string;  
    }
  return short_string;
} 
 
/* 
 * Function name: generate_accessory()
 * Description:   This function will generate an accessory
 * Arguments:     string - slot
 *                int - mob_pow
 * Returns:       object
 */
object
generate_accessory(string slot, int mob_pow)
{
  object armob;
  string *dtype;
  int *power;
  int q, value, t;
  string short_string;
  power = calc_acc_power(mob_pow);
  dtype = calc_acc_dtype(power);
  short_string = gen_acc_short(dtype, power, slot);
  /* Calculate the value of the item */
  value = 100;
  q=0;
  while(q<sizeof(power))
  {
    value += (power[q]*87);
    q++; 
  }
  t = random(mob_pow);
  value += t*250;
  armob = clone_object("obj/armor");
  armob->set_name(slot);
  armob->set_short(short_string);
  armob->set_alias("accessory");
  armob->set_long("\n");
  armob->set_type(slot);
  armob->set_ac(0);
  armob->set_weight(random(2)+1);
  armob->set_value(value);
  if(dtype[0]=="none")
  {
    return armob;
  }
  q=0;
  while(q<sizeof(dtype))
  {
    armob->set_params(dtype[q],t,power[q],0);
    q++;
  }
  return armob;
}
