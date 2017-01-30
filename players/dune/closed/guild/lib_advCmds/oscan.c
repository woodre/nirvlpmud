#include "../DEFS.h"
#include DEFS_ALEVELS
#include DEFS_OFFICES
#include DEFS_GLEVELS


int guild_lev, guild_exp, artlevel, honor, bal, attack_mode, nohonor;
string brand, stone, weapon, sphere;
status suspend;


status main(string pName)
{
/* Advanced sc command for a member, showing guild info */
  int degree, lowxp, freexp;
  string role, capName;

  if (IPTP->guild_lev() < MAX_QUALITY_LEVEL) return 0;

  if (!pName)
  {
    write("Which ninja do you want to scan?\n");
    return 1;
  }

  pName = lower_case(pName);
  capName = capitalize(pName);

  if (!restore_object(SAVEDIR + "/" + pName))
  {
    write("No guild record exists for " + capName + ".\n");
    return 1;
  }

  degree = artlevel - BLACK_BELT;
  if (degree < 0) degree = 0;

  brand  = capitalize(brand);
  lowxp  = (int)call_other(GLEVELD, "low_exp", guild_lev);
  freexp = guild_exp - lowxp;

  if (role = (string)call_other(OFFICED, "findRoleGivenStone", stone)) {}
  else role = 0;
  if (!stone) stone = NOSTONE;

  write(LINE+BOLD+YELLOW);
  write(capName + "'s guild info......\n");
  write(OFF+LINE);

  if (suspend)
  {
    write("[[[" + capName + " is SUSPENDED from the guild.]]]\n");
  }

  if (capName == OWNER1 || capName == OWNER2)
  {
    write(capName + " is a Guild Owner.\n");
  }
  else if (stone && stone == "adamantium")
  {
    write(capName + " is " + 
      (string)call_other(OFFICED, "getSphereTitle", pName, sphere) + "\n");
  }
  else if (role)
  {
    write(capName + " holds the title of " + capitalize(role) + ".\n");
  }
  else
  {
    write(capName + "'s vision trodes are made of " + stone + ".\n");
  }

  if (nohonor > 0)
    write("Honor: RENEGADE\n");
  else
    write("Honor: " + (int)call_other(HLEVELD, "honorTitle", honor) + "\n");


  write("Neural Chip: " + brand     + ", type " + guild_lev + "\n");
  write("Guild Xp: "    + guild_exp + "\n");
  write("Free Xp: "     + freexp    + "\n");

  write("Belt: " + (string)call_other(ALEVELD, "findBeltColor", artlevel));
  if (degree > 0) write(", degree " + degree + "\n");
  else write("\n");

  write("Choice of Weapon: " + weapon + "\n");

  write("Attack Mode: ");
  if (!attack_mode)     write(upper_case(ATTACK_MODE0)+"\n");
  if (attack_mode == 1) write(upper_case(ATTACK_MODE1)+"\n");
  if (attack_mode == 2) write(upper_case(ATTACK_MODE2)+"\n");

  write("Credit Balance: " + bal + "\n");
  write(LINE);

  return 1;
}

