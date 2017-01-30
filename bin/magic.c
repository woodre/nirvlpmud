#pragma strong_types

#include <grammar.h>
#include <kernel.h>
#include <message.h>
#include <global_commands.h>  // added global_, Coogan, 02-May-2001
#include <server.h>

inherit ACCESS;
inherit "basic/create";
inherit "basic/daemon";
inherit "basic/parser";

void
create() {
  set_privilege("@magic");
  add_rule("cast "G_WORDS" on "G_INDIRECT" with "G_OBJECT, "targetcomponent",
                                                        COMMANDS_MAGIC);
  add_rule("cast "G_WORDS" on "G_ALL" with "G_OBJECT,      "multicomponent",
                                                        COMMANDS_MAGIC);
  add_rule("cast "G_WORDS" at "G_INDIRECT" with "G_OBJECT, "targetcomponent",
                                                        COMMANDS_MAGIC);
  add_rule("cast "G_WORDS" at "G_ALL" with "G_OBJECT,      "multicomponent",
                                                        COMMANDS_MAGIC);
  add_rule("cast "G_WORDS" with "G_OBJECT" at "G_INDIRECT, "targetcomponent",
                                                        COMMANDS_MAGIC);
  add_rule("cast "G_WORDS" with "G_OBJECT" at "G_ALL,      "multicomponent",
                                                        COMMANDS_MAGIC);
  add_rule("cast "G_WORDS" with "G_OBJECT" on "G_INDIRECT, "targetcomponent",
                                                        COMMANDS_MAGIC);
  add_rule("cast "G_WORDS" with "G_OBJECT" on "G_ALL,      "multicomponent",
                                                        COMMANDS_MAGIC);
  add_rule("cast "G_WORDS" with "G_OBJECT, "component", COMMANDS_MAGIC);
  add_rule("cast "G_WORDS" at "G_INDIRECT, "target",    COMMANDS_MAGIC);
  add_rule("cast "G_WORDS" at "G_ALL,      "multi",     COMMANDS_MAGIC);
  add_rule("cast "G_WORDS" on "G_INDIRECT, "target",    COMMANDS_MAGIC);
  add_rule("cast "G_WORDS" on "G_ALL,      "multi",     COMMANDS_MAGIC);
  add_rule("cast "G_WORDS" "G_INDIRECT,    "target",    COMMANDS_MAGIC);
  add_rule("cast "G_WORDS" "G_ALL,         "multi",     COMMANDS_MAGIC);
  add_rule("cast "G_WORDS,                 "",          COMMANDS_MAGIC);

  add_rule("spell add "G_TEXT,     "add",     "bin/magic");
  add_rule("spell approve "G_TEXT, "approve", "bin/magic");
  add_rule("spell remove "G_WORDS, "remove",  "bin/magic");
  add_rule("spell list "G_LIVING,  "listl",   "bin/magic");
  add_rule("spell list "G_WORDS,   "listw",   "bin/magic");
  add_rule("spell list",           "lista",   "bin/magic");
  add_rule("spell info "G_WORDS,   "info",    "bin/magic");
  add_rule("spell "G_WORDS,        "info",    "bin/magic");
  add_rule("spell",                "help",    "bin/magic");

  add_rule("let "G_LIVING" forget "G_TEXT,             "fl",    "bin/magic");
  add_rule("teach "G_WORD" to "G_LIVING" at "G_NUMBER, "tlto",  "bin/magic");
  add_rule("teach "G_WORD" at "G_NUMBER" to "G_LIVING, "tlto",  "bin/magic");
  add_rule("teach "G_WORDS" to "G_LIVING,              "tl",    "bin/magic");
  add_rule("teach "G_WORDS,                            "thelp", "bin/magic");
  add_rule("teach",                                    "thelp", "bin/magic");

  filter(query_rule_verbs(),
               lambda(({ 'verb }), 
                      ({ #'add_command, "parse_cmd", 'verb })));
}

status parse_cmd(string arg, string verb) {
  return parse_sentence(arg ? verb + " " + arg : verb);
}

private string expand_file(string file, object who) {
  if (!file)
    return 0;
  if (strlen(file) < 3)
    file += ".c";
  if (file[<2..]!=".c")
    file += ".c";
  return file;
}

status do_action(string verb, mapping args) {
  string fullname;
  mixed tmp;

  switch (verb) {
    case "add":
      if (!is_wizard(this_player()))
        return 0;
      if (!(fullname = expand_file(args[G_TEXT], this_player())))
        return notify_fail("There is no such file.\n", -1), 0;
      return SE_MAGIC->add_spell(fullname);

    case "remove":
      if (!is_wizard(this_player()))
        return 0;
      return SE_MAGIC->remove_spell(args[G_WORDS]);

    case "approve":
      if (!is_wizard(this_player()))
        return 0;
      if (!(fullname = expand_file(args[G_TEXT], this_player())))
        return notify_fail("There is no such file.\n",-1), 0;
      return SE_MAGIC->add_spell(fullname, 1);

    case "listl":
      if (!is_wizard(this_player()) && args[G_LIVING] != this_player())
        return notify_fail("You can only list your own spells!\n"), 0;

      tmp = m_indices(args[G_LIVING]->query_spells());
      if (!tmp || !sizeof(tmp)) {
        send_message(({ M_WRITE, M_THE, args[G_LIVING], M_VERB, "do",
                        args[G_LIVING], " not know any spells at all." }));
        return 1;
      }
      tmp = sort_array(tmp, #'>);
      send_message(({ M_WRITE, M_THE, args[G_LIVING], M_VERB, "know",
                      args[G_LIVING], " these spells: ", tmp, "." }));
      return 1;

    case "lista":
      if (!is_wizard(this_player()))
        tmp = m_indices(this_player()->query_spells());
      else
        tmp = SE_MAGIC->query_spells();
      if (!tmp || !sizeof(tmp)) {
        message("You don't know any spells at all.\n");
        return 1;
      }
      tmp = sort_array (tmp, #'>);
      if (!is_wizard(this_player()))
        send_message(({ M_WRITE, "You know these spells: ", tmp, "." }));
      else
        send_message(({ M_WRITE, "There are these spells: ", tmp, "." }));
      return 1;

    case "listw":
      if (!is_wizard(this_player()))
        tmp = SE_MAGIC->identify_spell(args[G_WORDS], this_player());
      else
        tmp = SE_MAGIC->identify_spell(args[G_WORDS]);
      if (!tmp || !sizeof(tmp)) {
        message("There are no matching spells.\n");
        return 1;
      }
      tmp = sort_array (tmp, #'>);
      if (!is_wizard(this_player()))
        send_message(({ M_WRITE, "The following spells you know match: ",
                        tmp, "." }));
      else
        send_message(({ M_WRITE, "The following spells match: ", tmp, "." }));
      return 1;

    case "info":
      if (!is_wizard(this_player()))
        return SE_MAGIC->spell_info(args[G_WORDS], this_player());
      else
        return SE_MAGIC->spell_info(args[G_WORDS]);

    case "tlto":
      if (!is_wizard(this_player()))
        return 0;
      return SE_MAGIC->learn_magic(args[G_LIVING],
                                   args[G_WORD], args[G_NUMBER]);

    case "tl":
      if (!is_wizard(this_player()))
        return notify_fail("Sorry, this is impossible _yet_.", -1), 0;
      if (SE_MAGIC->query_magic(args[G_WORDS]))
        return SE_MAGIC->learn_magic(args[G_LIVING], args[G_WORDS]);
      else
        return SE_MAGIC->learn_spell(args[G_LIVING], args[G_WORDS]);

    case "fl":
      if (!is_wizard(this_player()))
        return 0;
      return SE_MAGIC->forget_spell(args[G_LIVING], args[G_TEXT]);

    case "thelp":
      if (!is_wizard(this_player())) {
        notify_fail("You can't teach other players magic and spells yet.\n");
        return 0;
      }
     if (check_privilege("@magic"))
       message(({({ M_WRITE, "teach <magic> to <player> [for <points>]\n"
                    "Teach the player a magical art or lore. If 'points' "
                    "is given, the player receives 'points' skill points "
                    "for that lore or art.\n" }),
                 ({ M_WRITE, "teach <spellname> to <player>\n"
                    "Teach the player the specified spell.\n" }),
                 ({ M_WRITE, "let <player> forget <spellname>\n"
                    "Takes all of player's memory of that spell." })}));
     else
       message(({({ M_WRITE, "teach <magic> to <player> [for <points>]\n"
                    "Teach the player a magical art or lore. If 'points' "
                    "is given, the player receives 'points' skill points "
                    "for that lore or art.\n"
                    "You may only teach testplayers or other wizards, but "
                    "not regular players.\n" }),
                 ({ M_WRITE, "teach <spellname> to <player>\n"
                    "Teach the player the specified spell.\n"
                    "You may only teach testplayers or other wizards, but "
                    "not regular players." }),
                 ({ M_WRITE, "let <player> forget <spellname>\n"
                    "Takes all of player's memory of that spell. "
                    "You may use this only for testplayers, but not for "
                    "regular players or wizards." })}));
     return 1;

    case "help":
    default:
      if (check_privilege("@magic"))
        message(({({ M_WRITE, "spell add <file>\n"
                     "Adds the given file to the database. Players cannot "
                     "use this spell.\n" }),
                  ({ M_WRITE, "spell remove <spellname>\n"
                     "Removes the given spell from the database. If you "
                     "remove spells of other wizards for any reason, make "
                     "sure they are notified.\n" }),
                  ({ M_WRITE, "spell approve <file>\n"
                     "Approve the given spell and permamently store it in "
                     "the database.\n"
                     "Players will be able to learn and use this spell.\n" }),
                  }));
      else if (is_wizard(this_player()))
        message(({({ M_WRITE, "spell add <file>\n"
                     "Adds the given file to the database. Only testplayers, "
                     "wizards and monsters can use this spell. To make a "
                     "spell available to learning for players, contact an "
                     "Magic admin and ask for approval.\n" }),
                  ({ M_WRITE, "spell remove [spellname]\n"
                     "Removes the given spell from the database. Of course "
                     "you can only delete spells of your own.\n" }),
                  }));
      if (!is_wizard(this_player()))
        send_message(({ M_WRITE, "spell list [pattern]\n"
                        "Lists all spells you know. If you specify a pattern, "
                        "only the matching spells are shown.\n" }));
      else
        send_message(({ M_WRITE, "spell list [living|pattern]\n"
                        "Lists all spells known to the given living (or "
                        "known to you, if omitted) or matching to the "
                        "given pattern.\n" }));
      send_message(({ M_WRITE, "spell info <spellname>\n"
                      "Prints some infos about the given spell." }));
      return 1;
  }
  return 0;  // Coogan, 26-Mar-2011
}

