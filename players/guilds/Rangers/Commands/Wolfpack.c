#pragma strict_types
#include <ansi.h>
#include "../RangerDefs.h"

string *Rangers;
object Enemy;

int
QMax() { return 20; }

status
QTactic(string person)
{ 
   if(member_array(person, Rangers) != -1)
      {
      return 1; 
   }
   else
      return 0;
}

status
RangerPower(string str, string Type)
{
  object prev_obj;

  prev_obj = previous_object();

   if(!Rangers) Rangers = ({});
   if(!(prev_obj->QMorphed()) && !(prev_obj->QNinja()))
      {
      if(member_array(this_player()->query_real_name(), Rangers) != -1) Rangers -= ({ this_player()->query_real_name() });
      tell_object(this_player(),
         "Zordon tells you: \"You can only use Wolfpack when Morphed.\"\n");
      return 1;
   }
   if(member_array(this_player()->query_real_name(), Rangers) < 0)
      {
      write("You turn on Wolfpack Team Tactics.\n");
      prev_obj->SRangerTactic("Wolfpack");
      Rangers += ({this_player()->query_real_name()});
      return 1;
   }
   write("You turn Off Wolfpack Team Tactics.\n");
   prev_obj->SRangerTactic(0);
   Rangers -= ({ this_player()->query_real_name() });
   return 1;
}

status
QRangerInfo() { return 1; }

status
RangerInfo()
{
   write("\
      Wolfpack Tactics give you the ability to sneak up on an enemy \n\
      And hit them better.  Be careful because this will leave you \n\
      more vulnerable to hits. You can only use this if you are not the \n\
      leader in battle.\n");
   return 1;
}

int
OffSkill(int level)
{
  object prev_obj;

  prev_obj = previous_object();

   if(!Rangers) Rangers = ({});
   level = (int) prev_obj->QuerySkillLevel("team");
   if(member_array(environment(prev_obj)->query_real_name(),
            Rangers) >= 0)
   {
      if(!prev_obj->QMorphed() ||
            (string) prev_obj->QRangerTactic() != "Wolfpack")
      {
         tell_object(environment(prev_obj), 
            "You turn off Wolfpack Team Tactics.\n");
         Rangers -= ({ environment(prev_obj)->query_real_name() });
         return 0;
      }
Enemy = (object) environment(prev_obj)->query_attack();
if( (object) Enemy->query_attack() == environment(prev_obj)){
return -15;
}
      tell_object(environment(prev_obj), "[ " + BOLD + RED +
         "TACTIC" + OFF + " ] " + "You use Wolfpack Team Tactics\n");
      return random((level*5)/3);
   }
   else
      return 1;
}

status
DefSkill(int level)
{
  object prev_obj;

  prev_obj = previous_object();

   if(!Rangers) Rangers = ({});
   level = (int) prev_obj->QuerySkillLevel("team");
Enemy = (object) environment(prev_obj)->query_attack();
  /* Added following if(Enemy) to fix child birth error -Bp */
   if(Enemy)
   if(member_array(environment(prev_obj)->query_real_name(),
Rangers) >=0 && (object) Enemy->query_attack() == environment(prev_obj))
   {
      tell_object(environment(prev_obj),
         "You turn off Wolfpack Team Tactics.\n");
      if((string) prev_obj->QRangerTactic() == "Wolfpack")
         prev_obj->SRangerTactic(0);
      Rangers -= ({ environment(prev_obj)->query_real_name() });
      return -random((level*5)/3);
   }   
   else
      return 1;
}
