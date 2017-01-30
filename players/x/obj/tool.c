#include "../x.h"

#define VBIN "/players/vertebraker/closed/hat/cmds/"

string short()
{
 return "The scepter of creation";
}

status drop()
{
 return 1;
}

status get()
{
 return 1;
}

void long()
{
 write("\
With this scepter, you hold aloft the power of\n\
the immortals.  Wield it with responsibility.\n\
Remember Uncle Ben's credo.\n");
}

void init()
{
 if(TP && !IS_WIZARD(TP))
 {
  TELL_ME(HIR+CAP(TPRN)+NORM+", a player, tried to snatch a wiztool.\n");
  destruct(TO);
  return;
 }
 add_action("cmd_hook"); add_xverb("");
}


/* Copied from obj|user|cmd_hook.c */
int cmd_hook(string str)
{
 string command, arg, cmd_ob_file;
 if (!str || str == "" || (strlen(str) >= 2 && (str[0..1] == "..")))
  return 0;
 if (sscanf(str, "%s %s", command, arg) != 2)
  command = str;
/*
 cmd_ob_file = (VBIN+command);
 if(!IS_FILE(cmd_ob_file))
*/
  cmd_ob_file = (BINDIR+"_"+command);
/*
else
  return (int)call_other(cmd_ob_file, "main", arg);
*/
 if(IS_FILE(cmd_ob_file))
 return (int)call_other(cmd_ob_file, "cmd_"+command, arg);
}

status id(string str)
{
 return (str=="scepter" || str=="scepter of creation");
}
