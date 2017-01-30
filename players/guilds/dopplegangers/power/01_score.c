/*
 * Score
 * Updated Doppleganger score command
 */

#include <ansi.h>

int query_mail() {
  string messages, name;
  int new_mail;

  name = (string)this_player()->query_real_name();
  if (!restore_object("post/dir/" + name) || messages == "")
    return 0;
  if (new_mail)
    return 1;
  return 0;
}

status main(string str) {
  object badge;

  if (str) return 0;

  badge = present("V-GUILD", this_player());

  this_player()->score();
  write(RED);
  write("Guild Level: " + this_player()->query_guild_rank() +
        "     Amount swapped: " + this_player()->query_guild_exp() + "\n");
  write("Current morph:    " +
        capitalize((string)badge->query_morph()) + "\n");
  write("Current time:     " + ctime(time()) + "\n");
  write("Next rescue time: " +
        ((int)badge->query_res_time() > time() ?
              ctime((int)badge->query_res_time())
                                               : "Now") + "\n");
  write((badge->query_allowem() ? "" : "NOT ") +
         "Allowing summons and steps.\n");
  write("Drain set for:    " + (badge->query_which_drain() ?
        "Spell Points" : "Hit Points") + "\n");
  write("Fang set at: " + badge->query_fang_hit());
  if (badge->query_faction("barbarian"))
    write(HIB + "   HP Stored: " + badge->query_hp_stored());
  if (badge->query_faction("mystic"))
    write(CYAN + "   SP Stored: " + badge->query_sp_stored());
  write(NORM + "\n");
  if (query_mail())
    write(BLINK + RED + "You have New mail at the post office." + NORM + "\n");
  return 1;
}
