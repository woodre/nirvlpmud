#include <ansi.h>

void init() {
  if((int)this_player()->query_level() >= 21)
    add_action("file_it", "file");
}

status file_it(string arg) {
  if(!arg)
  {
    tail("/log/WR/dune_workreport");
    return 1;
  }
  arg=ctime()[4..15]+" :: "+arg+"\n";
  write_file("/log/WR/dune_workreport", arg);
  write("Ok, you wrote into your log.\n");
  return 1;
}

status drop() { return 1; }

status id(string str) {
  return (str=="filer"||str=="dune_filer"||str=="dune's filer");
}

string short()
{
  return "Dune's Filer";
}
