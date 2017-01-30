/*
 *  Instruments for the Storm Bards of Ryllian.
 *  v3.0 by Saber / Geoffrey Z.
 *
 */


bard_instr(str)  {
string instr;

  if(!str || sscanf(str, "%d", instr) !=1)  {

  write(
   "  1)     Harp          2)     Flute\n"+
   "  3)     Fiddle        4)     Lyre\n"+
   "  5)     Horn          6)     Mandolin\n"+
   "  7)     Lute          8)     Violin\n"+
   "  9)     Bagpipes      10)    Recorder\n"+
   "  11)    Guitar        12)    Drum\n"+
   "  13)    Pan Pipes     14)    Trumpet\n"+
   "  15)    Harpsicord    16)    Saxophone\n"+
   "  17)    Cello         18)    Accordian\n"+
   "  19)    Kazoo         20)    Grand Piano\n"+
   "  21)    Harmonica     22)    Storm Lyre\n");

  write("\nSyntax: < instrument > < # >\n");
  return 1;
        }

switch(str)  {
  case "0" : write("That is not a valid choice.\n");  break;
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
  case "22": instr = "Storm Lyre"; break;
  
  default: notify_fail("You must enter a number.  Syntax: < bard_instrument > < # >\n");
        }
        
  INSTR->set_instrument_string(instr);
  write("You switch instruments.\n");
  return 1;
        }
