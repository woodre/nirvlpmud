#include <ansi.h>

inherit "/obj/user/one_chan.c";

main(str)
{
  object player;
  string *dir, file, who;
  int i, so;
  if(sscanf(str,"%s %s", who, file) != 2)
  {
    notify_fail(get_help() + "\n");
    return 0;
  }
  if(!(player = find_player(who)))
  {
    notify_fail("No such player.\n");
    return 0;
  }
  if(!(file = read_file("/doc/helpdir/" + file)))
  {
    notify_fail("No file.\n");
    return 0;
  }
  tell_object(player, file);
  tell_object(player, file);
  tell_object(player, file);
  if(!interactive(player))
  {
    write("SPPAAAMMMEEDD!!\n");
    chan_msg("You see "+player->query_name()+"'s sorry butt fly streaking across the mud, covered in spam.\n", "junk");
  }
  write("Ok.\n");
  return 1;
}

get_help()
{
  string help;
  help = "Spam someone with help files. Syntax: spam <who> <helpfile>";
  return help;
}
