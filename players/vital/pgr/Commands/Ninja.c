#pragma strict_types
#include <ansi.h>
#include "../RangerDefs.h"

string *Rangers;

status
QSkill(string person)
{ 
  if(!Rangers) Rangers = ({});
  if(member_array(person, Rangers) != -1)
    return 1;
  else
    return 0;
}

status
QRangerInfo() { return 1; }

status
RangerInfo()
{
  write(
"  The Ninja Ranger morph is a special skill granted to those with\n\
the greatest devotion to the concepts of protecting Good and\n\
defending the Universe against Evil.\n\n\
The Ninja Ranger Morph differs from the Morph command in a few\n\
key areas:\n\
  Ninja Rangers cannot call a Zord.\n\
  Ninja Rangers have different morph types.\n\
  Ninja Rangers cannot use additional armors.\n\
  Ninja Rangers must have PK set to morph.\n\
  Ninja Morphs have a lower cost to morph.\n\
  Ninja Morphs can see in the dark. [no Lamp command]\n\
  Ninja Morphs cannot access the Ranger Pack.\n\n\
Additionally, Ninja Rangers can gain new advantages based on their\n\
trained skills in other areas.\n\
  Invisible             11 Communication\n\
  See in Dark           14 Communication\n\
  Stealth Movement      80 Combat\n\n");
  return 1;
}

status
RangerPower(string str, string type)
{
  int cost, i;
  string msg, title;
  if(!(environment(previous_object())->query_pl_k()))
  {
    tell_object(this_player(),
      "Zordon tells you: \"Only Power Rangers who are prepared to attack \
other players can use the Ninja Morph.\"\n");
    return 1;
  }
  if(previous_object()->QMorphed() || previous_object()->QNinja())
  {
    tell_object(this_player(),
      "Zordon tells you: \"You are already Morphed.\"\n");
    return 1;
  }
  if(!previous_object()->QMorphed() && !previous_object()->QNinja())
  {
    cost = (5 * ((int) previous_object()->QuerySkillLevel("morph")));
    msg = "";
    if(MASTER->QPowerPoints(type) < cost)
    {
      tell_object(this_player(),
        "Zordon tells you: \"There is not enough power for you to morph.\"\n");
      return 1;
    }
/*     MASTER->APowerPoints(-cost, type); */
    switch(previous_object()->QuerySkillLevel("morph"))
    {
      case 30..129:  msg = " Ninja Power!\n" + OFF; break;
      case 130..400: msg = " Ninja Storm!\n" + OFF; break;
      default: msg + "";
    }
    previous_object()->SOldTitle(this_player()->query_title());
    previous_object()->SOldPretitle(this_player()->query_title());
    title = "The " + previous_object()->COLOR + " Ninja";
    if(this_player()->is_player() && environment(this_player()))
    {
      tell_room(environment(this_player()), this_player()->query_name() +
        " yells: " + previous_object()->QRangerAnsi() + previous_object()->COLOR + msg);
      tell_room(environment(this_player()), this_player()->query_name() +
        " yells: Ninja Karate Belt " + previous_object()->query_ranger_belt() + "\n");
      this_player()->add_player_id("the "+lower_case( (string) previous_object()->COLOR)+" ninja");
      this_player()->add_player_id(lower_case( (string) previous_object()->COLOR)+" ninja");
      this_player()->add_player_id("ninja");
      present("soul",this_player())->setmin(title+" arrives");
      present("soul",this_player())->setmout(title+" leaves");
      previous_object()->SPlayerShort(title);
      previous_object()->AID("player_short_object");
      if(previous_object()->QuerySkillLevel("combat") > 79)
        previous_object()->AID("silent_move_object");
      if(previous_object()->QuerySkillLevel("communication") > 10)
        title = "";
      if(previous_object()->QuerySkillLevel("commmunication") > 13)
        previous_object()->AID("dark_sight_object");
      if(previous_object()->QuerySkillLevel("communication") > 11)
        previous_object()->RangerInvis();
      title = BS;
      for(i=0; i < strlen( (string) environment(previous_object())->query_name()); i++)
      {
        title += BS;
      }
    }
    Rangers += ({ environment(previous_object())->query_real_name() });
    previous_object()->SNinja();
    return 1;
  }
  return 0;
}

int
DefSkill(int level)
{
  if(!Rangers) Rangers = ({});
  level = (int) previous_object()->QuerySkillLevel("combat");
  if(member_array(environment(previous_object())->query_real_name(),
    Rangers) >= 0)
  {
    if(!previous_object()->QNinja())
    {
      Rangers -= ({ environment(previous_object())->query_real_name() });
      return 0;
    }
    return (level/15);
  }
  return 0;
}

int
OffSkill(int level)
{
  if(!Rangers) Rangers = ({});
  level = (int) previous_object()->QuerySkillLevel("morph");
  if(member_array(environment(previous_object())->query_real_name(), Rangers) >= 0)
  {
    if(!previous_object()->QNinja())
    {
      Rangers -= ({ environment(previous_object())->query_real_name() });
      return 0;
    }
    return (level/30);
  }
  return 0;
}
