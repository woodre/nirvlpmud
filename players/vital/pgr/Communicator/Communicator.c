/************************************************************************
*  The Power Ranger Guild Base Functions                                *
*  Created by Beck/Russ Warren for Nirvana                              * 
*  Updated by vital/keith for the Rangers                               *
*  Last changed 2005.10.13                                              *
*************************************************************************/
#pragma strict_types

#include <ansi.h>
#include "../RangerDefs.h"

string OldPretitle;           /* Pre-Morph Pretitle                     */
string OldTitle;              /* Pre-Morph Title                        */
string RangerColor;           /* Morph Color Name                       */
string RangerDino;            /* Dinosaur Zord Type                     */
string RangerAnimal;          /* Animal Zord Type                       */
string RangerWeapon;          /* Power Weapon Type                      */
string RangerNumber;          /* Zeo Ranger Number                      */
string RangerAnsi;            /* Morph Color Ansi Sequence              */
string RangerAlign;           /* Regular or Dark Ranger Type            */
static string RangerTactic;   /* Ranger Combat Tactics                  */
static int Morphed;           /* True/False Flag for Morphed            */
static int Ninja;             /* True/False Flag for Ninja Morph        */
static int Muffles;           /* True/False Flag for Muffle 'rt'        */
static int RandomNumber;      /* Login Session Number                   */
static string NotArmor;       /* Allowable Types of Armor               */
static string PlayerShort;    /* Morphed Ranger Short Desc              */
static string *ID;            /* Array of id's for Ranger               */

void
SOldTitle(string str){ OldTitle = str; }     /* Set Pre-Morph Title    */
string
QOldTitle(){ return OldTitle; }              /* Query Pre-Morph Title  */
void
SOldPretitle(string str){ OldPretitle = str; } /* Set Pre-Morph Title  */
string
QOldPretitle(){ return OldPretitle; }        /* Query Pre-Morph Title  */
void
SRangerColor(string str){ RangerColor = str; } /* Set Morph Color Name */
string
QRangerColor(){ return RangerColor; }        /* Query Morph Color Name */
void
SRangerDino(string str){ RangerDino = str; } /* Set Dinosaur Zord Type */
string
QRangerDino(){ return RangerDino; }       /* Query Dinosaur Zord Type  */
void
SRangerAnimal(string str){ RangerAnimal = str; } /*Set Animal Zord Type*/
string
QRangerAnimal(){ return RangerAnimal; }   /* Query Animal Zord Type    */
void
SRangerWeapon(string str){ RangerWeapon = str; }/*Set Power Weapon Type*/
string
QRangerWeapon(){ return RangerWeapon; }   /* Query Power Weapon Type   */
void
SRangerNumber(string str){ RangerNumber = str; }/*Set Zeo Ranger Number*/
string
QRangerNumber(){ return RangerNumber; }   /* Query Zeo Ranger Number   */
void
SRangerAnsi(string str){ RangerAnsi = str; } /* Set Morph Ansi Sequence*/
string
QRangerAnsi(){ return RangerAnsi; }       /* Query Morph Ansi Sequence */
int
QRandomNumber(){ return RandomNumber; }   /* Query Login Session Number*/
string
QRangerTactic(){ return RangerTactic; }   /* Query Combat Tactic       */
void
SRangerTactic(string str) { RangerTactic = str; }/* Set Ranger Tactics */
status
QMorphed(){ return Morphed; }             /* Query Morph State         */
status
QNinja() { return Ninja; }                /* Query Ninja State         */
status
QMuffles(){ return Muffles; }             /* Query Guild Channel State */
string
QRangerAlign(){ return RangerAlign; }     /* Query Ranger Type         */
void
SPlayerShort(string str) { PlayerShort = str; }/*Set Morphed Short Desc*/

varargs mixed
QID(string str)
{
  if (str)
    return (member_array(str, ID) + 1);
  else
    return ID;
}                      /* Query What Ranger Is Called*/

void
SMorphed()
{
  if(!Morphed)
    Morphed = 1;
  else
  {
    Morphed = 0;
  }
}

void
SNinja()
{
  if(!Ninja)
    Ninja = 1;
  else
  {
    Ninja = 0;
  }
}

status
RangerInvis()
{
  if(!environment())
  {
    remove_call_out("RangerInvis");
    destruct(this_object());
    return 1;
  }
  if(!QNinja())
  {
    remove_call_out("RangerInvis");
    environment(this_object())->unset_invis_sp();
    return 1;
  }
  environment(this_object())->set_invs_sp();
  remove_call_out("RangerInvis");
  call_out("RangerInvis", 2);
  return 1;
}

status
Muffles()
{
  if(Muffles == 1)
  {
    Muffles = 0;
    CHANNEL->add_channel(RangerAlign, this_object());
    write("Your guild channel muffle is OFF.\n");
    return 1;
  }
  Muffles = 1;
  CHANNEL->remove_channel(RangerAlign,this_object());
  write("Your guild channel muffle is ON.\n");
  return 1;
}

void
NotArmor(status arg)
{
  if(arg == 0){ NotArmor = "allowed"; }
  else if(arg == 1){ NotArmor = "notarmor"; }
  else NotArmor = "notarmor";
}

void
AID(string str)
{
  if(!ID)
     ID = ({});
  if(member_array(str, ID) == -1)
     ID += ({ str });
}

void
RID(string str)
{
  if(!ID)
     ID = ({});
  if(member_array(str, ID) != -1)
     ID -= ({ str });
}

int
id(string str)
{ 
  int i;
  if(!this_object()->QID()) ID = ({});
  i = member_array(str, ID);
  if(i != -1) return str == ID[i];
  return str == "communicator" ||
         str == "RangerCommunicator" ||
         str == "pro_object" ||
         str == "guild_object" ||
         str == "no_spell" ||
         str == "ranger_object" ||
         str == "channel_object" ||
         str == "notweapon" ||
         str == "GI" ||
         str == NotArmor; 
}

void
kill_check(object ob)
{
  int team;
  team = (int) this_object()->QuerySkillLevel("team");
  "/players/guilds/Rangers/Master/KillCheck.c"->kill_check(ob,
     this_object(), team);
  return;
}
  