/* 
 *  The vision chamber of the Bardic Guild of Ryllian
 *  v3.0 by Geoffrey Z. / Saber
 *
 */

#define tp this_player()->query_name()

inherit "room/room";

#include "/players/saber/closed/esc2.h"
#include "/players/saber/closed/ansi.h"

string MSG1, MSG2, MSG3, MSG4, MSG5, MSG6, MSG7, MSG8, MSG9, MSG10;
string REM1, REM2, REM3, REM4, REM5, REM6, REM7, REM8, REM9, REM10;
string TEMP, TEMP2, FINAL;
int CHECK, CHECK2, MARK, SINGLE;

reset(int arg) {  
 
  if(!arg){

  set_light(1);
  short_desc="Chamber of Visions";
 
  long_desc=
 BOLD+"Chamber of Visions"+NORM+"\n"+
 "The Chamber of Visions is a shadowy room constructed from deeply polished\n"+
 "mahogany wood.   The floor has been sanded to a soft grain, and the walls\n"+
 "are unadorned.  Legend holds that this Chamber was once part of the Stark\n"+
 "Keep, deep within the heart of the Forest of Dreams.   It is said that to\n"+
 "speak a question within these halls is to receive a vision.\n"+
 "Syntax: < vision > < help >\n";

items=({
 "floor","The floor has been sanded to a soft grain, and constructed from beautiful mahogany wood",
 "chamber","You are in the "+BOLD+"Chamber of Visions"+NORM+"",
 "room","You are in the "+BOLD+"Chamber of Visions"+NORM+"",
 "wood","The chamber is constructed entirely from polished mahogany wood",
 "mahogany","The chamber is constructed entirely from polished mahogany wood",
 "wall","The walls are unadorned",
 "walls","The walls are unadorned",
 });

  dest_dir=({
 "/players/saber/closed/bard/r/lore.c","south",
           });
  }   }
  
  
init()  {
 ::init();

if(!present("instrument",this_player()) && this_player()->is_player() &&
   this_player()->query_level() < 21)  {
  
  write("You get the brief image of a "+BLU+"blue circle"+NORM+" before\n\n"+
        BOLD+" * * * * *  B O O M  * * * * *"+NORM+"\n\n"+
        "Your body flies through space.\n\nYou find yourself somewhere new.\n");
  say(tp+" bounces off the "+BLU+"Circle of Warding"+NORM+".\n");
  move_object(this_player(),"/room/void");
  tell_room(environment(this_player()), tp+" falls screaming from the sky.\nTHUD.\n");
  return 1;
        }

  add_action("search","search");
  add_action("vision","vision");
       }


search() {
 write("You find nothing.\n");
 say (tp +" searches the area.\n");
 return 1; 
       }


vision(str)  {
string WORKING;

  if(!str) str = "help";
  
  if(lower_case(str) == "help")  {
    write("\nTo receive a vision, type < vision > < question >\n"+
          "Questions must be phrased so that they may be answered with a yes or a no.\n\n");
    return 1;
        }
        
  write("You ask \""+str+"\"\n");
  say(tp+" asks \""+str+"\"\n");
  
  WORKING = str;
  
  MARK = 0;    TEMP = 0;  TEMP2 = 0;  CHECK = 0;  
  CHECK2 = 0;  MARK = 0;  FINAL = 0;  SINGLE = 0;
  
       if(lower_case(str) == MSG1) { MARK = 1; str = REM1; }
  else if(lower_case(str) == MSG2) { MARK = 1; str = REM2; }
  else if(lower_case(str) == MSG3) { MARK = 1; str = REM3; }
  else if(lower_case(str) == MSG4) { MARK = 1; str = REM4; }
  else if(lower_case(str) == MSG5) { MARK = 1; str = REM5; }
  else if(lower_case(str) == MSG6) { MARK = 1; str = REM6; }
  else if(lower_case(str) == MSG7) { MARK = 1; str = REM7; }
  else if(lower_case(str) == MSG8) { MARK = 1; str = REM8; }
  else if(lower_case(str) == MSG9) { MARK = 1; str = REM9; }
  else if(lower_case(str) == MSG10){ MARK = 1; str = REM10;}
  
 if(!MARK)  {
 
  CHECK  = random(13);
  CHECK2 = random(4);
  
  if(random(4) < 1 || CHECK < 3)  SINGLE = 1;
  
/*
  Listen (to), Learn, Seek, Believe, Question, Look (at), Investigate, Review, Affirm, Deny
  Wait, Soon, Later, 
  yourself, the answers that appear, your assumptions, the facts, 
*/
  
  if(CHECK > 2) CHECK = CHECK + 7;
  
       if(CHECK == 0 )  { TEMP = "Wait";     }
  else if(CHECK == 1 )  { TEMP = "Soon";     }
  else if(CHECK == 2 )  { TEMP = "Later";    }

  else if(CHECK == 10)  { if(!SINGLE) TEMP = "Listen to"; else TEMP = "Listen";   }
  else if(CHECK == 11)  {             TEMP = "Learn";                             }
  else if(CHECK == 12)  {             TEMP = "Seek";                              }
  else if(CHECK == 13)  {             TEMP = "Believe";                           }
  else if(CHECK == 14)  {             TEMP = "Question";                          }
  else if(CHECK == 15)  { if(!SINGLE) TEMP = "Look at"; else TEMP = "Look";       }
  else if(CHECK == 16)  {             TEMP = "Investigate";                       }
  else if(CHECK == 17)  {             TEMP = "Review";                            }
  else if(CHECK == 18)  {             TEMP = "Affirm";                            }
  else                  {             TEMP = "Deny";                              }


 if(SINGLE < 1)  {
 
       if(CHECK2 == 0 )  { TEMP2 = " yourself";                   }
  else if(CHECK2 == 1 )  { TEMP2 = " the answers that appear";    }
  else if(CHECK2 == 2 )  { TEMP2 = " your assumptions";           }
  else                   { TEMP2 = " the facts";                  }
 
  str = TEMP + TEMP2;
      
        }  else  { str = TEMP; }

        }
        

       if(MSG1  == "0") { REM1  = str;  MSG2  = 0; }
  else if(MSG2  == "0") { REM2  = str;  MSG3  = 0; }
  else if(MSG3  == "0") { REM3  = str;  MSG4  = 0; }
  else if(MSG4  == "0") { REM4  = str;  MSG5  = 0; }
  else if(MSG5  == "0") { REM5  = str;  MSG6  = 0; }
  else if(MSG6  == "0") { REM6  = str;  MSG7  = 0; }
  else if(MSG7  == "0") { REM7  = str;  MSG8  = 0; }
  else if(MSG8  == "0") { REM8  = str;  MSG9  = 0; }
  else if(MSG9  == "0") { REM9  = str;  MSG10 = 0; }
  else                  { REM10 = str;  MSG1  = 0; }
  
  
  FINAL = str;
  
  call_out("message", random(3)+1);
  return 1;
         }
         
         
message()  {
         
  tell_room(this_object(), "\nA voice whispers\n\n\t\t\""+FINAL+"\"\n\n");
  return 1;
         }
