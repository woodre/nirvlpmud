/* Ansi Preferences Manipulator (c) verte 2002 */
#include <ansi.h>
#define colors ({ HIK, HIR, HIG, HIY, HIB, HIM, HIC, HIW, \
                  BLK, RED, GRN, YEL, BLU, MAG, CYN, WHT, BOLD })

mapping valid_color;
string c, beef;
int ind;

reset(x) {
   if(!x)
   {
     valid_color = ([
       "hi-black" : HIK,
       "hi-red"   : HIR,
       "hi-green" : HIG,
       "hi-yellow" : HIY,
       "hi-blue":    HIB,
       "hi-magenta": HIM,
       "hi-cyan":    HIC,
       "hi-white":   HIW,
       "black":      BLK,
       "red":        RED,
       "green":      GRN,
       "yellow":     YEL,
       "blue":       BLU,
       "magenta":    MAG,
       "cyan":       CYN,
       "white":      WHT,
       "bold":       BOLD, ]);
   }
}

string
ans_convert(string arg)
{
    string x;
    switch(arg)
    {
      case HIK: x = "Hi-Black";     break;
      case HIR: x = "Hi-Red";       break;
      case HIG: x = "Hi-Green";     break;
      case HIY: x = "Hi-Yellow";    break;
      case HIB: x = "Hi-Blue";      break;
      case HIM: x = "Hi-Magenta";   break;
      case HIC: x = "Hi-Cyan";      break;
      case HIW: x = "Hi-White";     break;
      case BLK: x = "Black";        break;
      case RED: x = "Red";          break;
      case GRN: x = "Green";        break;
      case YEL: x = "Yellow";       break;
      case BLU: x = "Blue";         break;
      case MAG: x = "Magenta";      break;
      case CYN: x = "Cyan";         break;
      case WHT: x = "White";        break;
    }
    return x;
}     

status
cmd_ansipref()
{
    string *ap;
    int i, x;
    write("\n\t\tANSI Preferences\n\n");
    ap=(string *)this_player()->query_ansi_prefs();
    if(!ap || !sizeof(ap))
    {
      return (write("You have no ANSI Preferences.  Relog if you want\n" +
                    "to enable them.\n"), 1);
      destruct(this_object());
      return 1;
    }
    x=sizeof(ap);
    for(i=0; i<x; i+=2)
      write("   "+pad(ap[i], 14) + (!ap[i+1] ? "None" : (ap[i+1]+ans_convert(ap[i+1])+NORM)) + "\n");
    write("\n");
    write("Would you like to adjust these values? <y/n> ");
    return (input_to("adjVal"), 1);
}

int
adjVal(string arg)
{
    if(arg == "y" || arg == "Y" || arg == "yes" || arg == "YES")
    {
      write("Which would you like to manipulate? (i.e. gossip) [~q to abort]: \n");
      return (input_to("adjVal2"), 1);
    }
    else return (destruct(this_object()), 1);
}

int
adjVal2(string arg)
{
    string *x;
    int z;
    if(!arg)
      return adjVal("y");
    if(arg == "~q") return (destruct(this_object()), 1);
    x=(string*)this_player()->query_ansi_prefs();
    beef = arg;
    if((z=member_array(arg, x)) == -1)
    {
      write("That is not a valid value you can manipulate.\n");
      return adjVal("y");
    }
    ind=z;
    write("What color would you like to use?\n" +
          "Type '?' for a list of colors.\n");
    return (input_to("pickColor"), 1);
}

int
pickColor(string arg)
{
    string col;
    if(!arg)
      return adjVal2(beef);
    if(arg == "?" || arg == "'?'")
    {
      write("\n" +
""+HIK+"Hi-Black    "+HIY+"Hi-Yellow     "+HIR+"Hi-Red     "+HIG+"Hi-Green     "+HIB+"Hi-Blue\n"+
""+HIM+"Hi-Magenta  "+HIW+"Hi-White      "+NORM+BLK+"Black      "+YEL+"Yellow       "+RED+"Red\n"+
""+GRN+"Green       "+BLU+"Blue          "+MAG+"Magenta    "+WHT+"White        "+BOLD+"Bold"+NORM+"\n"+CYN+"Cyan"+NORM+"        "+HIC+"Hi-Cyan"+NORM+"\n\n");
      write("Use \"off\" to turn the color off.\n");
      return adjVal2(beef);
    }
    if(arg == "~q") return (destruct(this_object()), 1);
    if(arg == "off")
    {
      this_player()->change_ansi_pref(beef, 0);
      write("Your " + capitalize(beef) + " color is now toggled OFF.\n");
      return cmd_ansipref();
    }
    col = valid_color[lower_case(arg)];
    if(!col)
    {
      write("That is not a valid color.\n");
      return pickColor("?");
    }
    this_player()->change_ansi_pref(beef, col);
    write("Your " + capitalize(beef) + " color is now set to: " +
          col + ans_convert(col) + NORM + ".\n");
    return cmd_ansipref();
}
