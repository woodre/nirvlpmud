#include "../lib/attribs.h"

/* Paths */
#define ROOTDIR       "/players/vertebraker/classic/undead/"
#define LOGDIR        (ROOTDIR + "log/")
#define CMDDIR        (ROOTDIR + "cmds/")
#define NPCDIR        (ROOTDIR + "npc/")
#define DAEMONS       (ROOTDIR + "daemon/")
#define HELPDIR       (ROOTDIR + "help/")
#define WIZHELP       (HELPDIR + "wiz/")
#define OBJDIR        (ROOTDIR + "obj/")
#define WEPDIR        (ROOTDIR + "wep/")
#define ARMDIR        (ROOTDIR + "arm/")
#define LIBDIR        (ROOTDIR + "lib/")
#define ROOMDIR       (ROOTDIR + "room/")
#define SPELLS        (ROOTDIR + "spells/")
#define STDDIR        (ROOTDIR + "std/")
#define PERSONAL_LOGS "/players/vertebraker/classic/undead/log/personal/"

#define MAINSAVE      "players/vertebraker/classic/undead/save/"
#define BACKUPDIR     "players/vertebraker/classic/undead/save/backup/"

mixed query_path(string str)
{
  switch(str)
  {
    case "root":         return ROOTDIR;
    case "log":          return LOGDIR;
    case "cmds":         return CMDDIR;
    case "npc":          return NPCDIR;
    case "daemons":      return DAEMONS;
    case "help":         return HELPDIR;
    case "wizhelp":      return WIZHELP;
    case "obj":          return OBJDIR;
    case "wep":          return WEPDIR;
    case "arm":          return ARMDIR;
    case "lib":          return LIBDIR;
    case "rooms":        return ROOMDIR;
    case "spells":       return SPELLS;
    case "std":          return STDDIR;
    case "personal":     return PERSONAL_LOGS;
    case "mainsave":     return MAINSAVE;
    case "backupdir":    return BACKUPDIR;
    case "guildname":    return GUILDNAME;
    case "objpath":      return OBJPATH;
    case "master":       return MASTER;
    case "gwiz":         return GWIZ;
    case "wiztool":      return WIZTOOL;
  }
  return str;
}
    
