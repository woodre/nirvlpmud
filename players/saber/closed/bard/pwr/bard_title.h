/*
 *  Titles for the guild.
 *  v3.0 by Saber / Geoffrey Z.
 *
 */

bard_title(str)  {

int b, CLVL;
string titl;

  if(!str || sscanf(str, "%d", CLVL) !=1)  {

  write("\n"+
    "  Title #      Bard Level       Actual Level     Guild Title\n"+
    "___________________________________________________________________\n\n"+
    "    1              1                 4           Apprentice\n"+
    "                   2                 5           Apprentice\n"+
    "                   3                 6           Apprentice\n"+
    "    2              4                 7           Journeyman\n"+
    "                   5                 8           Journeyman\n"+
    "    3              6                 9           Lyrist\n"+
    "    4              7                 10          Minstrel\n"+
    "                   8                 11          Minstrel\n"+
    "    5              9                 12          Troubadour\n"+
    "    6              10                13          Bard\n"+
    "                   11                14          Bard\n"+
    "    7              12                15          Storm Bard\n"+
    "    8              13                16          High Bard\n"+
    "                   14                17          High Bard\n");

    if(BLVL > 14)  {
    write("    9              15+               18+         Master Bard\n");    
        }
    if(BLVL > 17)  {
    write("    10             15+               18+         Master of Riddles\n");    
        }
    if(BLVL > 20)  {
    write("    11             15+               18+         Master of Storms\n");    
        }
    if(BLVL > 23)  {
    write("    12             15+               18+         Guardian of Rain\n");    
        }
    if(BLVL > 26)  {
    write("    13             15+               18+         Guardian of Thunder\n");    
        }
    if(BLVL > 29)  {
    write("    14             15+               18+         Guardian of Lightning\n");    
        }
    if(BLVL > 32)  {
    write("    15             15+               18+         Guardian of Secrets\n");    
        }
    if(BLVL > 35)  {
    write("    16             15+               18+         Initiate of the Innter Mysteries\n");    
       }
    if(BLVL > 38)  {
    write("    17             15+               18+         Keeper of Lore\n");    
        }
    if(BLVL > 41)  {
    write("    18             15+               18+         Bardic Avatar\n");    
        }

    write("\nSyntax: < bard_title > < # >\n");
      return 1;
        }

       if(CLVL <  2)  b = 1;   else if(CLVL == 2)  b = 4;
  else if(CLVL == 3)  b = 6;   else if(CLVL == 4)  b = 7;
  else if(CLVL == 5)  b = 9;   else if(CLVL == 6)  b = 10;
  else if(CLVL == 7)  b = 12;  else if(CLVL == 8)  b = 13;
  else if(CLVL == 9)  b = 15;  else if(CLVL == 10) b = 18;
  else if(CLVL == 11) b = 21;  else if(CLVL == 12) b = 24;
  else if(CLVL == 13) b = 27;  else if(CLVL == 14) b = 30;
  else if(CLVL == 15) b = 33;  else if(CLVL == 16) b = 36;
  else if(CLVL == 17) b = 39;  else if(CLVL == 18) b = 42;
  
  if(b > (BLVL+1))  {
    write("You have not yet achieved this title.\n");
    return 1;        
        }

switch(str)  {

  case "0"  : write("That is not a valid choice.\n");  break;
  case "1"  : titl = "the Apprentice"; break;
  case "2"  : titl = "the Journeyman"; break;
  case "3"  : titl = "the Lyrist"; break;
  case "4"  : titl = "the Minstrel"; break;
  case "5"  : titl = "the Troubadour"; break;
  case "6"  : titl = "the Bard"; break;
  case "7"  : titl = "the Storm Bard"; break;
  case "8"  : titl = "the High Bard"; break;
  case "9"  : titl = "the Master Bard"; break;
  case "10" : titl = "the Master of Riddles"; break;
  case "11" : titl = "the Master of Storms"; break;
  case "12" : titl = "the Guardian of Rain"; break;
  case "13" : titl = "the Guardian of Thunder"; break;
  case "14" : titl = "the Guardian of Lightning"; break;
  case "15" : titl = "the Guardian of Secrets"; break;
  case "16" : titl = "the Initiate of the Innter Mysteries"; break;
  case "17" : titl = "the Keeper of Lore"; break;
  case "18" : titl = "the Bardic Avatar"; break;
  default: notify_fail("You must enter a number.  Syntax: < bard_title > < # >\n");
        }

  call_other(TP, "set_title", titl);
  write("Your title has been changed.\n");

  return 1;
        }
