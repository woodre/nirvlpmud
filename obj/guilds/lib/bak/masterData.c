static string ROOTDIR;
static string LOGDIR;
static string CMDDIR;
static string NPCDIR;
static string DAEMONS;
static string HELPDIR;
static string WIZHELP;
static string OBJDIR;
static string WEPDIR;
static string ARMDIR;
static string LIBDIR;
static string ROOMDIR;
static string SPELLS;
static string STDDIR;
static string PERSONAL_LOGS;
static string MAINSAVE;
static string BACKUPDIR;
static string GUILDNAME;
static string *GWIZ;
static string OBJPATH;
static string MASTER;
static string WIZTOOL;

inherit "/obj/clean";

void reset(status x)
{
 if(x) return;
 if(ROOTDIR) return;
 set_no_clean(1);
ROOTDIR = "";
LOGDIR = "";
CMDDIR = "";
NPCDIR = "";
DAEMONS = "";
HELPDIR = "";
WIZHELP = "";
OBJDIR = "";
WEPDIR = "";
ARMDIR = "";
LIBDIR = "";
ROOMDIR = "";
SPELLS = "";
STDDIR = "";
PERSONAL_LOGS = "";
MAINSAVE = "";
BACKUPDIR = "";
GUILDNAME = "";
GWIZ = ({});
OBJPATH = "";
MASTER = "";
WIZTOOL = "";
}
