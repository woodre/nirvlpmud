#include <ansi.h>
#include <security.h>

/* Metapsychics 2001 - 2004 */
/* 3 years in development   */
/*Should only need to change this dir to move guild file locations */
#define ROOTDIR "/players/vital/closed/meta/"

/* Save directory is for player and object related save files ***/
#define SAVE ROOTDIR + "save/"
/* Backup directory is for roll back versions of guild files *****/
#define BACKUP ROOTDIR + "bak/"
/* Guild related objects files **********************************/
#define OBJDIR ROOTDIR + "object/"
/* Commands for members and wizards reside here *****************/
#define CMDDIR ROOTDIR + "cmd/"
/* All documentation and help files are located here ************/
#define DOCDIR ROOTDIR + "doc/"
/* Base directory for guild daemon files ************************/
#define DAEMONS ROOTDIR + "daemons/"
/* Log files directory for tracking and reporting ***************/
#define LOGDIR ROOTDIR + "log/"
/* Lib files that can be inherited by objects */
#define LIBDIR ROOTDIR + "lib/"

#define CHANNELD    DAEMONS + "channeld"
#define MAND        DAEMONS + "mand"
#define COLORD      (string)DAEMONS+"colourd"
#define FUND        DAEMONS + "fund"

#define SPELL       OBJDIR + "spell.c"

/* Miscellaneous guild information that needs to be universal ***/
/* This is the current versioning of the guild object ***********/
#define TEXT_VERSION    "Pre-Alpha"
#define NUMERIC_VERSION "0.1a"
#define GUILDNAME "metapsychics"
#define GWIZ ({ "vertebraker", "vital" })
#define GUILD_ID "meta_object"
#define ALT_GID  "guild_object"

#define GOBJ present(GUILD_ID, this_player())

#define BEEP ""

/* Quick guild level references *********************************/
#define LATENT      0
#define OPERANT     6
#undef  APPRENTICE          /* Undefined from the <security.h> */
#define APPRENTICE  6
#define JOURNEYMAN  16
#define ADEPT       21
#define MASTER      31
#define GRAND       51
#define MAGNATE     66
#define PARAMOUNT   76
#define PGM        100

