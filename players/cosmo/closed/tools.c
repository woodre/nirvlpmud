#include "/players/cosmo/closed/ansi.h"

/*   Convert a letter to a number  */
/*   --- by Cosmo on 2/21/97 ---  */

int lnconv(string letter, int num2)  {
  switch (letter) {
    case "a": num2 = 1;  break;
    case "b": num2 = 2;  break;
    case "c": num2 = 3;  break;
    case "d": num2 = 4;  break;
    case "e": num2 = 5;  break;
    case "f": num2 = 6;  break;
    case "g": num2 = 7;  break;
    case "h": num2 = 8;  break;
    case "i": num2 = 9;  break;
    case "j": num2 = 10; break;
    case "k": num2 = 11; break;
    case "l": num2 = 12; break;
    case "m": num2 = 13; break;
    case "n": num2 = 14; break;
    case "o": num2 = 15; break;
    case "p": num2 = 16; break;
    case "q": num2 = 17; break;
    case "r": num2 = 18; break;
    case "s": num2 = 19; break;
    case "t": num2 = 20; break;
    case "u": num2 = 21; break;
    case "v": num2 = 22; break;
    case "w": num2 = 23; break;
    case "x": num2 = 24; break;
    case "y": num2 = 25; break;
    case "z": num2 = 26; break;
    default:  return 0;
  }
  return num2;
}

/*   Determine the appropriate ANSI color for a monster */
/*   --- by Cosmo on 10/19/98 ---  */

string query_color(object MON) {
string monster_color;
  if(MON->query_level() < 6)   monster_color=NORM;     /* lvl 1-5   */
  else if(MON->query_level() < 11)  monster_color=GRN; /* lvl 6-10  */
  else if(MON->query_level() < 16)  monster_color=HIY; /* lvl 11-15 */
  else if(MON->query_level() < 21)  monster_color=RED; /* lvl 16-20 */
  else monster_color=HIR;                              /* lvl 21+   */
  return monster_color;
}
