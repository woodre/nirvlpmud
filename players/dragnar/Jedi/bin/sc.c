#include <ansi.h>

#define HP      USER->query_hp()
#define MHP     USER->query_mhp()
#define USER    environment(previous_object())
#define CP      previous_object()->query_cp()
#define MCP     previous_object()->query_mcp()
#define XP      USER->query_exp()
#define MONEY   USER->query_money()
#define NAME    USER->short()
#define INTOX   USER->query_intoxination()*100/(USER->query_level()+3)
#define STUFF   USER->query_stuffed()*100/(USER->query_level()*8)
#define SOAK    USER->query_soaked()*100/(USER->query_level()*8)
#define INFUSE  USER->query_infuse()*100/(9*(USER->query_level()/2))
#define LVL     USER->query_level()
#define XLVL    USER->query_extra_level()
#define RACE    USER->query_race()
#define RANK    USER->query_guild_rank()
#define DARK    previous_object()->query_darkside()
#define MYCP CP*100/MCP
#define SKILL   previous_object()->query_skill_points()
#define KILL_NEUTRAL_ALIGNMENT 10
#define MSHIELD previous_object()->query_mind_shield()
#define WIMPY   USER->query_wimpy()
#define alignment USER->query_alignment()

string COLOR;
string moncolor;
string mshield;
string jedi_rank;
string str;
string my_cp;

main(){
  COLOR = previous_object()->query_mon_color();
if(RANK && DARK){
   switch(RANK){
   case 1..4:	 	
   jedi_rank = ""+HIR+"dark apprentice"+NORM+"";
   break;
   case 5..8:
   jedi_rank = ""+HIR+"jedi assassin"+NORM+"";
   break;
   case 9..12:
   jedi_rank = ""+HIR+"jedi"+NORM+"";
   break;
   case 13:
   jedi_rank = ""+HIR+"jedi master"+NORM+"";
   break;
   default:
   jedi_rank = "error";
   break;
  }
 } 

if(RANK && !DARK){
   switch(RANK){
   case 1..4:
   jedi_rank = ""+HIG+"patawan apprentice"+NORM+"";
   break;
   case 5..8:
   jedi_rank = ""+HIG+"jedi knight"+NORM+"";
   break;
   case 9..12: 
   jedi_rank = ""+HIG+"jedi"+NORM+"";
   break;
   case 13:
   jedi_rank = ""+HIG+"jedi master"+NORM+"";
   break;
   default:
   jedi_rank = "error";
   break;
  }  		
 }
switch(MSHIELD){
  case 100..5000:
  mshield = "unbreakable";
  break;
  case 80..99:
  mshield = "high";
  break;
  case 60..79:
  mshield = "good";
  break;
  case 25..59:
  mshield = "shakey";
  break;
  case 1..24:
  mshield = "nearly gone";
  break;
  default:
  mshield = "gone";
  break;
  } 
 
  my_cp = MYCP+"%";
   	 
tell_object(USER,
""+COLOR+"__________________________________"+
"["+NORM+"JEDI"+COLOR+"]___________________________________"+NORM+"\n"+
" "+NAME+COLOR+"\n"+
""+COLOR+""+
"___________________________________________________________________________"+NORM+"\n");


if(!XLVL){
tell_object(USER,
pad("  Level: "+LVL+"", 40));
}
else {         
tell_object(USER, 
pad("  Level: "+LVL+"+"+XLVL+"", 40));   
}                
tell_object(USER,
"Jedi rank: "+jedi_rank+"\n");
tell_object(USER,
pad("  Experience: "+XP+"", 40));
tell_object(USER,
"SkillPoints: "+SKILL+"\n");
tell_object(USER,
"                            [Concentration: "+my_cp+"]\n");
tell_object(USER,
"\n                               [HP: "+HP+"/"+MHP+"]\n");
tell_object(USER,
""+COLOR+""+
"___________________________________________________________________________"+NORM+"\n");
tell_object(USER,
"   Money: "+MONEY+"\n");
tell_object(USER, "   Age: ");
show_age();
tell_object(USER,
"   QuestPoints: "+USER->query_quest_point()+"\n");
tell_object(USER,
"   Mindshield: Your mindshield is "+mshield+".\n");
tell_object(USER,
"                    [I:"+COLOR+" "+INTOX+"%"+NORM+"]"+
"         [F: "+COLOR+""+STUFF+"%"+NORM+"]"+
"         [S: "+COLOR+""+SOAK+"%"+NORM+"]\n");

if(WIMPY){
tell_object(USER,
"   Wimpy on.\n");
tell_object(USER,
""+COLOR+""+
"___________________________________________________________________________"+NORM+"\n\n");
}
else{
tell_object(USER,
""+COLOR+""+
"___________________________________________________________________________"+NORM+"\n\n");
}
return 1;
}
  



show_age() {                     
  int i;                       
                      
 i= USER->query_age();                     
  if (i/43200) {               
   tell_object(USER, i/43200 + " days "); 
 i = i - (i/43200)*43200;   
   }                       
  if (i/1800)  {                
   tell_object(USER, i/1800 + " hours "); 
 i = i  - (i/1800)*1800;    
   }                       
  if (i/30)    {                  
   tell_object(USER, i/30 + " minutes "); 
 i = i - (i/30)*30;         
   }                      
   tell_object(USER, "and "+ i*2 + " seconds.\n");  
}                              



















