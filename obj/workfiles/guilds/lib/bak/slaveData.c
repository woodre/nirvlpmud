static string MAINSAVE;
static string CMDDIR;
static string GUILDNAME;
static string OBJPATH;
static string MASTER;

void reset(status arg)
{
  if(arg) return;
  if(MAINSAVE) return;
  MAINSAVE = "";
  CMDDIR = "";
  GUILDNAME = "";
  OBJPATH = "";
  MASTER = "";
}
