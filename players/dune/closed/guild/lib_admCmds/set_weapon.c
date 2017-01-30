#include "../DEFS.h"


status main(string str)
{
  object ob;
  string who, weapon, currentweapon;
  int alev;

  if (!IPTP->guild_manager()) return 0;

  if (!str || !sscanf(str, "%s %s", who, weapon) ||
     !find_player(who) || !present(GUILD_ID, find_player(who)))
  {
    write("Usage: set_weapon <player> <weapon>\n");
    return 1; 
  }

  ob = present(GUILD_ID, find_player(who));
  alev = (int)ob->query_art_level();

  if (((int)call_other(WEAPOND, "findWeaponCost", alev, weapon)) < 0)
    write("Not a valid weapon. \nWeapon will be set anyway.\n");

  currentweapon = (string)ob->query_weapon();
  if(weapon == currentweapon)
  {
    write(capitalize(who)+" is already using that weapon.\n");
    return 1;
  }

  tell_object(environment(ob), 
    "Your weapon has been changed to "+weapon+" by "+TPN+".\n");
  write_file(LOGDIR + "/WEPS",
    TRN+" set "+capitalize(who)+"'s weapon from "+currentweapon+" to "+
    weapon+". ("+ctime()+")\n");

  ob->set_weapon(weapon);
  ob->save_me();
  move_object(ob, find_player(who)); /* force init */
  return 1;
}
