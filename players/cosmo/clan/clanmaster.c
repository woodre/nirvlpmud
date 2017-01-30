/*  The Clan Object Master  Version 1.0      */
/*  Created by Cosmo        May 2000         */

#include "/players/cosmo/closed/ansi.h"
#define CLANOB "/players/cosmo/clan/clanob.c"
#define ROSTER "/players/cosmo/clan/clanroster.c"
#define CLANCHAN(x) BOLD+"|>. "+NORM+x+BOLD+" .<|"+NORM

mapping Clans;
string ClanName;

#include "/players/cosmo/clan/master/status.h"
#include "/players/cosmo/clan/master/start.h"
#include "/players/cosmo/clan/master/info.h"
#include "/players/cosmo/clan/master/who.h"
#include "/players/cosmo/clan/master/speak.h"
#include "/players/cosmo/clan/master/leave.h"
#include "/players/cosmo/clan/master/add.h"
#include "/players/cosmo/clan/master/remove.h"
#include "/players/cosmo/clan/master/modrank.h"
#include "/players/cosmo/clan/master/quit.h"

