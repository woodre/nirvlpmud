#include <ansi.h>
#define MAX_SIZE 29000

int
id(string arg)
{
      return (arg == "box" || arg == "suggestion box");
}

string
short()
{
    if(this_player() && (int)this_player()->query_level() > 10)
      return (CYN+"Suggestion Box"+NORM);
}

void
long()
{
    if(this_player() && (int)this_player()->query_level() > 10)
    write("\
A suggestion box for players of Nirvana to use.\n\
Please type \"suggest <idea>\" and the administration will read over your\n\
responses as soon as humanly possible.  Do not abuse, and thank you.\n");
}

void
init()
{
    add_action("cmd_suggest", "suggest");
}

int
cmd_suggest(string arg)
{
    if(!this_player() || !this_player()->is_player() ||
       (int)this_player()->query_level() < 10 ||
       (int)this_player()->query_level() > 20)
      return 0;
    if(!arg)
      return (notify_fail("Suggest what?\n"), 0);
    if(file_size("/ideas/sugg") > MAX_SIZE)
    {
      string str;
      str = read_bytes("/ideas/sugg", 0, file_size("/ideas/sugg")-1);
      write_file("/ideas/sugg." + ctime()[4..6] + "." + implode(explode(ctime()[8..9], " "), "-"), str);
      rm("/ideas/sugg");
    }
    write_file("/ideas/sugg", ctime()[4..15] + " " +
      capitalize((string)this_player()->query_real_name()) +
                     ": " + arg + "\n");
    return (write("Thanks for the suggestion!\n"), 1);
}
