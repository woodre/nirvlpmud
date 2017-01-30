#include "../defs.h"

status main(string arg)
{
  if (!arg) {
    write("What is it you wanted to say?  Valid syntax:\n"
      +"mtalk on\nmtalk off\nmtalk list\nmtalk history\n");
  return 1;
  }

  if (arg == "list") return (int)call_other(BIN+"masons", "main", arg);

 if (arg == "ON_OFF_SILENT") {
    present(MGOB_ID, this_player())->ghetto_channel_fix();
    return 1;
  }

  if (arg == "on" || arg == "off") {
    present(MGOB_ID, this_player())->set_muffle((arg == "on" ? 0 : 1));
    return 1;
  }

  if (arg == "history") 
    return (int)CHANNELD->query_history(CHAN);

  CHANNELD->channel_message(CHAN, "<Masons> "+(string)this_player()->query_name()+": "+arg+"\n");
  return 1;
}
