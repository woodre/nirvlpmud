#pragma strict_types
#include <ansi.h>
#include "../RangerDefs.h"

mapping MartialArts;

void MartialArtsDef();
string *UseMartialArts(string skill);

int
QMax(){ return 100; }

status
QRangerInfo(){ return 1;}

status
RangerInfo()
{
  write("\
Combat is the one of the Power Rangers most powerful abilities.\n\
Combat directly relates to offensive and defensive power.\n\
Rankings:\n\n\
    White               3-9\n\
    Yellow              10-19\n\
    Orange              20-29\n\
    Red                 30-39\n\
    Green               40-49\n\
    Blue                50-59\n\
    Purple              60-69\n\
    Brown               70-79\n\
    Black               80-89\n\
    Black (1st Degree)  90-91\n\
    Black (2nd Degree)  92-93\n\
    Black (3rd Degree)  94-95\n\
    Black (4th Degree)  96\n\
    Black (5th Degree)  97\n\
    Black (6th Degree)  98\n\
    Black (7th Degree)  99\n\
    Black (8th Degree)  100\n\n");
  return 1;
}


int
OffSkill(int level)
{
  int damage;
  string *skills;
  string msg;
  int enemyhp;
  int enemymhp;
  int enemyper;
  string name;
  string attacker;
  name = (string) environment(previous_object())->query_name();
  attacker = (string) 
    (environment(previous_object())->query_attack())->query_name();
  level = (int) previous_object()->QuerySkillLevel("combat");
  if(level > random(50))
  {
    damage += ( (int) previous_object()->QuerySkillLevel("combat") / 20);
    if(level > random(200))
    {
      skills = (array) this_object()->UseMartialArts("off");
      damage += ( (int) previous_object()->QuerySkillLevel("combat") / 20);
      msg = name+skills[1]+attacker+skills[2];
      tell_object(environment(previous_object()), "[ " + RED + "OFFENSE" +
                  OFF + " ] " + msg + "\n");
      if(level > random(300))
      {
        skills = (array) this_object()->UseMartialArts("off");
        damage += ( (int) previous_object()->QuerySkillLevel("combat") / 10);
        msg = name+skills[1]+attacker+skills[2];
        tell_object(environment(previous_object()), "[ " + RED + "OFFENSE" +
                    OFF + " ] " + msg + "\n");
        if(level > random(500))
        {
          skills = (array) this_object()->UseMartialArts("off");
          damage += ( (int) previous_object()->QuerySkillLevel("combat") / 5);
          msg = name+skills[1]+attacker+skills[2];
          tell_object(environment(previous_object()), "[ " + RED + "OFFENSE" +
                      OFF + " ] " + msg + "\n");
          if(level > random(1000))
          {
            enemyhp = (int) (  
              environment(previous_object())->query_attack())->query_hp();
            enemymhp = (int) ( 
              environment(previous_object())->query_attack())->query_mhp();
            enemyper = (enemyhp * 100)/enemymhp;
            if(enemyper < 15 && enemyhp < 100)
            {
              damage += enemyhp;
              tell_object(environment(previous_object()), "[ " + BOLD+RED +
                          "FATAL" + OFF + " ] You finish " + attacker +
                          " off with a deadly blow\n");
            }
            else {damage -=2; }
          }
        }
      }
    }
  }
  return damage;
}

int
DefSkill(int level)
{
  int prot;
  string *skills;
  string msg;
  string name;
  string attack;
  level = (int) previous_object()->QuerySkillLevel("combat");
  name = (string) environment(previous_object())->query_name();
  if(environment(previous_object())->query_attack())
    attack = (string)
      (environment(previous_object())->query_attack())->query_name();
  else
    attack = "Unknown";
  if(level > random(100))
  {
    prot += ( (int) previous_object()->QuerySkillLevel("combat") / 50);
    if(level > random(500))
    {
      skills = (array) this_object()->UseMartialArts("def");
      prot += ( (int) previous_object()->QuerySkillLevel("combat") / 50);
      msg = name+skills[1]+attack+skills[2];
      tell_object(environment(previous_object()), "[ "+BOLD+BLUE+"DEFENSE"+OFF+" ] "+msg+"\n");
      if(level > random(1000))
      {
        skills = (array) this_object()->UseMartialArts("def");
        prot +=( (int) previous_object()->QuerySkillLevel("combat") / 25);
        msg = name+skills[1]+attack+skills[2];
        tell_object(environment(previous_object()), "[ "+BOLD+BLUE+"DEFENSE"+OFF+" ] "+msg+"\n");
      }
    }
  }

  return prot;
}

string *
UseMartialArts(string skill)
{
  int num;

  if(!MartialArts)
    MartialArtsDef();
  if(skill == "off")
    num = random(11)+100;
  else if(skill == "def")
    num = random(17);

  return MartialArts[num];
}

void
MartialArtsDef()
{

  MartialArts =
    ([1: ({ 1," does a backflip and dodges ","." }),
    2:({ 1," blocks the attack of "," with a defensive chop." }),
    3:({  1," grabs " ,"'s arm and throws them using shiho-nage."  }),
    4:({ 1," moves toward " ," and throws them with irimi-nage."  }),
    5:({1," gives " ," a rotary kaiten-nage throw."  }),
    6:({  1," grabs " ,"'s wrist and applies kote-gaeshi." }),
    7:({  1," pins " ,"'s arm with ikkyo technique." }),
    8:({  1," turns " ,"'s wrist inward with nikyo." }),
    9:({  1," twists " ,"'s wrist with sankyo." }),
    10:({  1," pins ","'s wrist with yonkyo technique."  }),
    11:({ 2," gives " ," a hip throw using koshi-nage." }),
    12:({  2," applies a tenchi-nage, heaven and earth throw to ","." }),
    13:({  2," entangles and throws " ," with juji-garami." }),
    14:({  2," gives " ," an aiki drop using aiki-otoshi." }),
    15:({  2," gives " ," a corner drop with applied sumi-otoshi." }),
    16:({  2," gives " ," an elegant breath throw using your kokyu-nage." }),
    0:({  2," gives " ," an aiki throw using aiki-nage." }),
    101:({1," gives "," a chop to the head."}),
    102:({3," does an artistic butterfly kick to ","."}),
    103:({1," laughs in ","'s face...as cocky as they are."}),
    104:({4," reaches out with one finger, and lightly deliver the DEATH TOUCH to ","!"}),
    105:({1," slaps "," in the face."}),
    106:({1," scratches ","'s face with their nails."}),
    107:({2," grabs "," and throws them to the floor."}),
    108:({3," raises "," up in a gorilla press, and drops them to the ground."}),
    109:({2," turns and bashes "," with the side of the elbow."}),
    100:({1," gives "," a solid punch to the chest."}),
    110:({2," raises their foot and crashes it down on the shoulder of ","."}),
  ]);
}
