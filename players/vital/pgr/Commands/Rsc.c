#pragma strict_types
#include <ansi.h>
#include "../RangerDefs.h"

status
QRangerInfo(){ return 1; }

status
RangerInfo()
{
  write("\
The \'rsc\' command gives you a more detailed score information, direct from \
Zordon, the Supercomputer in the command center.");
  return 1;
}

/* New command to show a more detailed Score */
status
RangerPower(string str, string rtype)
{
  string karate;
  string type;
  int power, intox, stuff, soak, infuse;
  write("\n");
  write(this_player()->short()+"\n");
  /* pulls the type and belt from one place */
  karate = (string) previous_object()->query_ranger_belt();
  type = (string) previous_object()->query_ranger_type();
  write("Ranger Type: " + type + "\t\tKarate Belt: " + karate + "\n");
  write("Level: " + this_player()->query_level() +
        "\t\t\t\tAlignment: " + this_player()->query_al_title() + "\n");
  if(this_player()->query_extra_level() > 0)
     write("Extra Level: " + this_player()->query_extra_level() + "\n");
  write("Hit Points: " + this_player()->query_hp() + "/" + 
        this_player()->query_mhp() + "\t\t" + "Spell Points: " +
        this_player()->query_sp() + "/" + this_player()->query_msp() + "\n");
  write("Coins: " + this_player()->query_money() + "\t\t\t" + "Experience: " +
        BOLD + GREEN + this_player()->query_exp() + OFF +"\n");
  intox = ( (int) this_player()->query_intoxication() * 100) /
    ( (int) this_player()->query_level() + 3);
  stuff = ( (int) this_player()->query_stuffed()) * 100 /
    ( (int) this_player()->query_level() * 8);
  soak = ( (int) this_player()->query_soaked()) * 100 /
    ( (int) this_player()->query_level() * 8);
  infuse = ( (int) this_player()->query_infuse()) * 100 / 
        ( (int) this_player()->query_level()*8);
  write("Intox: " + intox + "%\t");
  write("Stuffed: " + stuff + "%\t");
  write("Soaked: " + soak + "%\t");
  write("Infused: " + infuse +"%");
  write("\n");
  write("Unused Skill Points: " + previous_object()->QSkillPoints() + "  ");
  write("Build Points: " + previous_object()->QBuildPoints() + "  ");
  write("Next Skill Point: " + previous_object()->QNextSkillCost() + "\n");
  MASTER->CheckPower(rtype);
  if(this_player()->query_fight_area())
     write(BOLD + RED + "You are in a PK area." + OFF + "\n");
  if(previous_object()->QSpam())
     write("Your Weapon messages are turned OFF.\n");
  if(previous_object()->QAutoGen())
     write("Auto Generate set to " + previous_object()->QAutoGenAmount() +
           " PP, when over " + previous_object()->QAutoGenLimit() +
           " Spell Points.\n");
  if(previous_object()->QRangerTactic())
     write("Current Ranger Team Tactic: " +
           capitalize( (string) previous_object()->QRangerTactic()) + "\n");
 if("/players/guilds/Rangers/Commands/Pweapon.c"->QSkill(
    this_player()->query_real_name()))
   write("You have Power Weapon enabled.\n");
  if("/players/guilds/Rangers/Commands/Marmor.c"->QSkill(
    this_player()->query_real_name()))
    write("You have Metallic Armor enabled.\n");
  this_player()->show_age();
  return 1;
}

