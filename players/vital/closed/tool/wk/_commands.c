#include "/players/vital/closed/headers/vital.h"
#include <ansi.h>

main() {
  string *commands;
  string help, command;
  int x, y, z;
  commands = get_dir("/players/vital/closed/tool/wk/_*.c");
  x = sizeof(commands);
  write(pad("Tool Commands", -42)+"\n");
  write(pad("     ", 20, '-') + pad("", 15, '=') + "(+)" + pad("", 15,
            '=') + pad("     ", -20, '-') + "\n");
  OUT(pad("There are currently " + x + " commands loaded.\n", -55));
  FOREACH(commands, y)
  {
    if(sscanf(commands[y],"_%s.c",command))
    {
      write(pad(command, 20));
      if(help = ("/players/vital/closed/tool/wk/" + commands[y])->get_help())
      {
        write(help + "\n");
      }
      else
      {
        write("[no help listed yet]\n");
      }
    }
  }
  return 1;
}

get_help()
{
  string help;
  help = "This listing of commands and help";
  return help;
}