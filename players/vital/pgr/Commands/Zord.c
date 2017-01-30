#pragma strict_types
#include <ansi.h>
#include "../RangerDefs.h"

string *Owners;

int reset_ownership(int OwnerNumber);
string query_zord_call(object owner);
string query_zord_msg(object owner);


status
RangerPower(string str, string type)
{
  string msg, shortmsg, rtype;
  object pet;
  if(!previous_object()->QMorphed())
  {
    if(previous_object()->QNinja())
    {
      tell_object(this_player(),
        "Zordon tells you: \"You cannot use a Zord as a Ninja.\"\n");
      return 1;
    }
    tell_object(this_player(),
      "Zordon tells you: \"You must be morphed to summon your Battlezord.\"\n");
    return 1;
  }
  if(!Owners)  Owners = ({});
  if(member_array(this_player()->query_real_name() +
    previous_object()->QRandomNumber(), Owners) != -1)
  {
    tell_object(this_player(),
      "Zordon tells you: \"You already have summoned your Battlezord.\"\n");
    return 1;
  }
  if(!present("ViewingGlobe",environment(this_player())))
  {
    if(MASTER->QPowerPoints(type) <
      ( 200 + (60 * ((int)previous_object()->QuerySkillLevel("machine")) ) ) )
    {
      tell_object(this_player(),
        "Zordon tells you: \"There is not enough Power to use.\"\n");
      return 1;
    }
  }
  if(MASTER->QPowerPoints(type) <
    (100 + (30 * ((int)previous_object()->QuerySkillLevel("machine")) ) ) )
  {
    tell_object(this_player(),
      "Zordon tells you: \"There is not enough Power to use.\"\n");
    return 1;
  }
  rtype = (string) previous_object()->query_ranger_type();
  msg = query_zord_call(previous_object());
  shortmsg = query_zord_msg(previous_object());
  tell_room(environment(this_player()), this_player()->query_name() + 
    " yells: "+msg+"\n");
  pet = clone_object("/players/guilds/Rangers/RangerZord.c");
  pet->set_level(previous_object()->QuerySkillLevel("machine"));
  pet->set_hp(1 + (20 * ((int) previous_object()->QuerySkillLevel("machine"))));
  pet->set_short("A " + shortmsg);
  pet->set_Owner(this_player());
  pet->set_OwnerName(this_player()->query_real_name());
  pet->set_OwnerNumber(this_player()->query_real_name() +
    previous_object()->QRandomNumber());
  if(this_player()->RangerNPC())
  {
    pet->set_OwnerName(environment(this_object())->query_name());
  }
  pet->set_wc(previous_object()->QuerySkillLevel("machine"));
  pet->set_ac(2 +
    (random((int)previous_object()->QuerySkillLevel("machine") / 2)));
  pet->set_alt_name(previous_object()->COLOR + "Zord");
  pet->set_message(shortmsg);
  move_object(pet, environment(this_player()));
  MASTER->APowerPoints( - (100 + 30 * 
    ((int)previous_object()->QuerySkillLevel("machine"))), type);
  if(!present("ViewingGlobe",environment(this_player())))
  {
    MASTER->APowerPoints( - (100 + 30 * 
      ((int)previous_object()->QuerySkillLevel("machine"))), type);
  }
  Owners += ({ this_player()->query_real_name() +
    previous_object()->QRandomNumber() });
  tell_room(environment(this_player()),"A " + shortmsg + " arrives.\n");
  return 1;
}

status
QRangerInfo() { return 1; }

status
RangerInfo(string str)
{
  write("\
  Your Zord is your most trusted companion.  The Zord assists you\n\
in combat automatically.  Statistics (Hp, Ac, Wc) and  cost of \n\
calling your Zord depend on your skill level in Machine.\n\n");
  return 1;
}


int
reset_ownership(int OwnerNumber)
{
  if(!Owners) return 0;
  if(member_array(OwnerNumber, Owners) != -1)
  {
    Owners -= ({ OwnerNumber });
    return 1;
  }
}

string
query_zord_call(object owner)
{
  string rtype, temp_msg, temp_dino, temp_animal;
  rtype = (string) owner->query_ranger_type();
  temp_dino = (string) owner->DINO;
  temp_animal = (string) owner->ANIMAL;
  switch(owner->QuerySkillLevel("morph"))
  {
    case 0..9:
      temp_msg = "Zord Power";
      break;
    case 10..19:
      temp_msg = temp_dino + " " + rtype + "zord Power";
      break;
    case 20..49:
      temp_msg = temp_animal + " " + rtype + "Thunderzord Power";
      break;
    case 50..149:
      temp_msg = temp_animal + " " + rtype + "-zord Power";
      break;
    case 150..169:
      temp_msg = temp_dino + " " + rtype + "-zord Power";
      break;
    case 170..200:
      temp_msg = temp_animal + " " + rtype + "-zord Power";
      break;
    default: temp_msg = "Zord Power";
  }
  return temp_msg;
}

string
query_zord_msg(object owner)
{
  string rtype, temp_msg, temp_dino, temp_animal;
  rtype = (string) owner->query_ranger_type();
  temp_dino = (string) owner->DINO;
  temp_animal = (string) owner->ANIMAL;
  switch(owner->QuerySkillLevel("morph"))
  {
    case 0..9:
      temp_msg = "Zord ";
      break;
    case 10..19:
      temp_msg = temp_dino + " " + rtype + "zord";
      break;
    case 20..49:
      temp_msg = temp_animal + " " + rtype + "Thunderzord";
      break;
    case 50..149:
      temp_msg = temp_animal + " " + rtype + "-zord";
      break;
    case 150..169:
      temp_msg = temp_dino + " " + rtype + "-zord";
      break;
    case 170..200:
      temp_msg = temp_animal + " " + rtype + "-zord";
      break;
    default: temp_msg = "Zord";
  }
  return temp_msg;
}
