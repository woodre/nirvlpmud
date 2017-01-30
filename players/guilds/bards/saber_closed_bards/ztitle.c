bard_title(str)  {
int a, b, c, CLVL;
string titl;
if(!str || sscanf(str, "%d", CLVL) !=1)  {
  write("You must enter a number.  See bard_title_list.\n");
  return 1;        }
b = str;
a = CLVL;
c = BLVL;
if(a > c)  {
  write("You have not yet achieved that title.\n");
  return 1;        }
switch(b)  {
case "0" : write("That is not a valid choice.\n");
        break;
case "1" : titl = "the Apprentice"; break;
case "2" : titl = "the Lyrist"; break;
case "3" : titl = "the Journeyman"; break;
case "4" : titl = "the Minstrel"; break;
case "5" : titl = "the Troubadour"; break;
case "6" : titl = "the Bard"; break;
case "7" : titl = "the Guardian of Secrets"; break;
case "8" : titl = "the Master of Riddles"; break;
case "9" : titl = "the Master Bard"; break;
case "10": titl = "the Song Master"; break;
case "11": titl = "the Keeper of Lore"; break;
default: notify_fail("You must enter a number.  See bard_title_list.\n");
        }
call_other(TP, "set_title", titl);
write("Your title has been changed.\n");
return 1;
        }

bard_title_list()  {
"\n"+
write(
"  Bard Level       Actual Level     Guild Title\n"+
"_______________________________________________________\n\n"+
"      1                 1           Apprentice\n"+
"      2                 3           Lyrist\n"+
"      3                 5           Journeyman\n"+
"      4                 8           Minstrel\n"+
"      5                 10          Troubadour\n"+
"      6                 12          Bard\n"+
"      7                 14          Guardian of Secrets\n"+
"      8                 16          Master of Riddles\n"+
"      9                 18          Master Bard\n"+
"      10                18          Song Master\n"+
"      11                GC          Keeper of Lore\n\n"+
 "\nType bard_title <level #> to change your title.\n");
  return 1;
        }

bard_instrument_list()  {
write("  1)     Harp\n"+
 "  2)     Flute\n"+
 "  3)     Fiddle\n"+
 "  4)     Lyre\n"+
 "  5)     Horn\n"+
 "  6)     Mandolin\n"+
 "  7)     Lute\n"+
 "  8)     Violin\n"+
 "  9)     Bagpipes\n"+
 "  10)    Recorder\n"+
 "  11)    Guitar\n"+
 "  12)    Drum\n"+
 "  13)    Pan Pipes\n"+
 "  14)    Trumpet\n"+
 "  15)    Harpsicord\n"+
 "  16)    Saxophone\n"+
 "  17)    Cello\n"+
 "  18)    Accordian\n"+
 "  19)    Kazoo\n"+
 "  20)    Grand Piano\n"+
 "  21)    Harmonica\n"+
 "\nType instrument_name <#> to switch instruments.\n");
 return 1;
       }

bard_instrument_name(str)  {
int a, b, c, CLVL;
string instr;
if(!str || sscanf(str, "%d", CLVL) !=1)  {
  write("You must enter a number.  See instrument_list.\n");
  return 1;
        }
a = str;
c = BLVL;
b = CLVL;
switch(a)  {
case "0" : write("That is not a valid choice.\n");
           break;
case "1" : instr = "Harp"; break;
case "2" : instr = "Flute"; break;
case "3" : instr = "Fiddle"; break;
case "4" : instr = "Lyre"; break;
case "5" : instr = "Horn"; break;
case "6" : instr = "Mandolin"; break;
case "7" : instr = "Lute"; break;
case "8" : instr = "Violin"; break;
case "9" : instr = "Bagpipes"; break;
case "10": instr = "Recorder"; break;
case "11": instr = "Guitar"; break;
case "12": instr = "Drum"; break;
case "13": instr = "Pan Pipes"; break;
case "14": instr = "Trumpet"; break;
case "15": instr = "Harpsicord"; break;
case "16": instr = "Saxophone"; break;
case "17": instr = "Cello"; break;
case "18": instr = "Accordian"; break;
case "19": instr = "Kazoo"; break;
case "20": instr = "Grand Piano"; break;
case "21": instr = "Harmonica"; break;
default: notify_fail("You must enter a number.  See instrument_list.\n");
        }
set_instrument_string(instr);
write("You switch instruments.\n");
  return 1;
        }

special_bard_title()  {
  object ob;
  string titl;

  if(TPQ == "saber")  titl = "the Bardic One";
  else if(TPQ == "lanfear")  titl = "the Amyrlin Seat";
  else if(TPQ == "zog")  titl = "the Master of Music";
  else if(TPQ == "senoj")  titl = "the Master Gleeman";
  else if(TPQ == "reflex")  titl = "the Bard of Passion and Mirth";
  else if(TPQ == "spawn")  titl = "the Jester's Jester";
  else if(TPQ == "mythos")  titl = "the Prophet";
  else if(TPQ == "devon")  titl = "the Chaos Bard";
  else if(TPQ == "fury") titl = "the Master of the Night Sky";
  else if(TPQ == "hollie") titl = "the Irish Songstress";
  else if(TPQ == "llew") titl = "the Forest Lord";
  else  {
    write("You have not earned a special bardic title.\n");
    return 1;
        }

  call_other(TP, "set_title", titl);
  write("You now have your special bardic title!\n");
  return 1;
       }
