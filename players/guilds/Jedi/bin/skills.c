#include "../defs.h"
#include <ansi.h>
/******************************************************************************
 * Program: skills.c - Jedi guild
 * Path: /players/guilds/Jedi/bin
 * Type: Command Daemon for Skills
 * Created: Nov 12th, 2015 by Dragnar
 * Description: Shows the skill levels for the player.
 * History:
 *          11/22/2015 - Dragnar
 ******************************************************************************/
main(string str, object caster, object gob) {
  int x, lev;
  string type, header;

  header = gob->query_wep_color_ansi() + implode(explode(pad("",40,'='),""),"-")+NORM+"\n";
  write( header );
  for( x=0; x < sizeof(SKILL_TYPES); x++ ) {
    type = SKILL_TYPES[x];
    lev = gob->query_skill( type );
    write( pad(type,12) + ": " + lev +"\n");
  }
  write( header );
  return 1;
}
