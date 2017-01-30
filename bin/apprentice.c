/*
 * This file is a daemon for each wizard. It defines the apprentice wizards
 * commands (formerly in /obj/player.c).
 *
 * Coogan, 23-Apr-1998
 *
 */

#include <prop/player.h>
#include <grammar.h>
#include <message.h>
#include <is_wizard.h>
#include <fingerd.h>

inherit "basic/create";
inherit "basic/daemon";
static functions inherit "basic/parser";

void create() {
  if (clonep()) {
    add_rule("zap "G_LIVING,    "zap");
    add_error_message("zap",    "Zap whom?\n");
    add_rule("stat "G_LIVING,   "stat");  // Coogan, 28-Apr-1998
    add_rule("stat "G_ANY_LIVING, "stat");
    add_rule("stat "G_TEXT,     "stat");
    add_error_message("stat",   "There is no such person.\n");
    add_rule("heal "G_LIVING,   "heal");  // Coogan, 28-Apr-1998
    add_rule("heal "G_ANY_LIVING, "heal");
    add_error_message("heal",   "There is no such person.\n");
    add_rule("title "G_TEXT,    "title");
    add_rule("title",           "title");
    add_rule("remove title",    "notitle");
    add_rule("align "G_TEXT,    "align");
    add_rule("align",           "align");
    add_rule("remove align",    "noalign");
    add_rule("pretitle "G_TEXT, "pretitle");
    add_rule("pretitle",        "pretitle");
    add_rule("remove pretitle", "nopretitle");
    add_rule("setmin "G_TEXT,   "setmin");
    add_error_message("setmin", "Give a message.\n");
    add_rule("setmmin "G_TEXT,  "setmmin");
    add_error_message("setmmin", "Give a message.\n");
    add_rule("setmout "G_TEXT,  "setmout");
    add_error_message("setmout", "Give a message.\n");
    add_rule("setmmout "G_TEXT, "setmmout");
    add_error_message("setmmout", "Give a message.\n");
    add_rule("setmclone "G_TEXT,"setmclone");
    add_error_message("setmclone", "Give a message.\n");
    add_rule("setmdestruct "G_TEXT, "setmdestruct");
    add_error_message("setmdestruct", "Give a message.\n");
    add_rule("review",          "review");
    add_rule("invis "G_NUMBER,  "invis");
    add_rule("invis",           "invis");
    add_rule("vis",             "vis");
    add_rule("wizlist "G_TEXT,  "wizlist");
    add_rule("wizlist",         "wizlist");
  }
  set_auto_clone();
  add_command("parse_cmd", "zap");
  add_command("parse_cmd", "stat");
  add_command("parse_cmd", "heal");
  add_command("parse_cmd", "title");
  add_command("parse_cmd", "align");
  add_command("parse_cmd", "pretitle");
  add_command("parse_cmd", "remove");
  add_command("parse_cmd", "setmmin");
  add_command("parse_cmd", "setmmout");
  add_command("parse_cmd", "setmin");
  add_command("parse_cmd", "setmout");
  add_command("parse_cmd", "setmclone");
  add_command("parse_cmd", "setmdestruct");
  add_command("parse_cmd", "review");
  add_command("parse_cmd", "invis");
  add_command("parse_cmd", "vis");
  add_command("parse_cmd", "wizlist");
}

static status parse_cmd(string arg, string verb) {
  return parse_sentence(arg ? verb + " " + arg : verb);
}

static status do_action(string verb, mapping args) {
  object ob;
  mixed h;
  mixed h1, h2;

  if (query_once_interactive(this_player()) &&
      !is_wizard(this_player(), IW_TOOLUSER) &&  // Coogan, 28-Aug-2002
      !is_wizard(this_player(), IW_APPRENTICE))
    raise_error("Illegal daemon added for player\n");

  switch (verb) {
  case "zap":
    if (!args[G_LIVING])
      return 0;
    send_message(({ M_PL_THE, M_PL_VERB, "summon", " a flash from the sky." }));
    // added this_player() in next call, because bin/apprentice is an own
    // clone for the attacked. Coogan, 25-Jun-2006
    this_player()->add_exp(args[G_LIVING]->hit_player(1000000, this_player()));
    write("There is a big clap of thunder.\n");
    return 1;
  case "heal":
    args[G_LIVING] || (args[G_LIVING] = args[G_ANY_LIVING]);
    args[G_LIVING]->heal_self(100000);
#if 1  // Alfe 1998-Jun-19
    send_message(({ M_TARGETS,({ args[G_LIVING],this_player() }),
                    M_THE,args[G_LIVING],M_VERB,"are",args[G_LIVING],
                    " healed by ",M_OBJECT }) +
                 (environment(this_player()) == environment(args[G_LIVING])?
                  ({ M_PL_THE }) : ({ M_PL })) +
                 ({ "." }));
#else
    tell_object((args[G_LIVING] || args[G_ANY_LIVING]),
                "You are healed by " + this_player()->query_vis_name() + ".\n");
    write("Ok.\n");
#endif
    return 1;
  case "stat":
    ob = args[G_LIVING] || args[G_ANY_LIVING];
    if (!ob) {
      if (!args[G_TEXT])
        return 0;
      ob = FINGERD->load_player(lower_case(args[G_TEXT]));
      if (!ob)
        return 0;
    }
    ob->show_stats();
    return 1;
  case "notitle":
    this_player()->set_title(0);
    // fall through
  case "title":
    if (args[G_TEXT])
      this_player()->set_title(args[G_TEXT]);
    if (h = this_player()->query_title())
      message("Your (visible) title is " + h + ".\n");
    else
      message("You have no (visible) title.\n");
    return 1;
  case "nopretitle":
    this_player()->set_pretitle(0);
    // fall through
  case "pretitle":
    if (args[G_TEXT])
      this_player()->set_pretitle(args[G_TEXT]);
    if (h = this_player()->query_pretitle())
      message("Your (visible) pretitle is " + h + ".\n");
    else
      message("You have no (visible) pretitle.\n");
    return 1;
  case "noalign":
    this_player()->set_al_title(0); // Surak, 19-Nov-1999
    // fall through
  case "align":
    if (args[G_TEXT])
      this_player()->set_al_title(args[G_TEXT]);
    if (h = this_player()->query_al_title())
      message("Your (visible) alignment is " + h + ".\n");
    else
      write("You have no (visible) alignment description.\n");
    return 1;
  case "setmclone":     // Coogan, 12-Nov-2003
    this_player()->set_mclone(args[G_TEXT]);
    return 1;
  case "setmdestruct":  // Coogan, 12-Nov-2003
    this_player()->set_mdestruct(args[G_TEXT]);
    return 1;
  case "setmin":
    this_player()->set_msgin(args[G_TEXT]);  // changed functions, Coogan,
    return 1;                                // 06-Jan-1999
  case "setmmin":
    this_player()->set_mmsgin(args[G_TEXT]);
    return 1;
  case "setmout":
    this_player()->set_msgout(args[G_TEXT]);
    return 1;
  case "setmmout":
    this_player()->set_mmsgout(args[G_TEXT]);
    return 1;
  case "review":
    h1 = this_player()->query_property(P_MSGCLONE);
    h2 = this_player()->query_property(P_MSGDESTRUCT);
    h = break_string("mout:      "
              + (h = this_player()->query_msgout(), stringp(h)
                     ? "\"" + h + "\""
                     : implode(LIB_MESSAGE->message2macros(h), ", "))
              + "\n", 0, 11, -1)
      + break_string("min:       "
              + (h = this_player()->query_msgin(), stringp(h)
                     ? "\"" + h + "\""
                     : implode(LIB_MESSAGE->message2macros(h), ", "))
              + "\n", 0, 11, -1)
      + break_string("mmout:     "
              + (h = this_player()->query_mmsgout(), stringp(h)
                     ? "\"" + h + "\""
                     : implode(LIB_MESSAGE->message2macros(h), ", "))
              + "\n", 0, 11, -1)
      + break_string("mmin:      "
              + (h = this_player()->query_mmsgin(), stringp(h)
                     ? "\"" + h + "\""
                     : implode(LIB_MESSAGE->message2macros(h), ", "))
              + "\n", 0, 11, -1);
    if (stringp(h1) || pointerp(h1))
      h = h + break_string("mclone:    "
            + (stringp(h1) ? "\"" + h1 + "\""
               : implode(LIB_MESSAGE->message2macros(h1), ", "))
            + "\n", 0, 11, -1);
    if (stringp(h2) || pointerp(h2))
      h = h + break_string("mdestruct: "
            + (stringp(h2) ? "\"" + h2 + "\""
               : implode(LIB_MESSAGE->message2macros(h2), ", "))
            + "\n", 0, 11, -1);
    write(h);
    return 1;
  case "vis":
    if (this_player()->short()) {
      write("You are not invisible.\n");
      return 1;
    }
    this_player()->vis(0);
    return 1;
  case "invis":
    if (args[G_NUMBER]) {
      if (args[G_NUMBER] < 0)
        args[G_NUMBER] = 0;
    }
    if (!this_player()->short()) {
      if (member(args, G_NUMBER) && args[G_NUMBER] > 0)
        write("You will be invisible for "+ args[G_NUMBER] +" more seconds.\n");
    }
    else if (member(args, G_NUMBER) && args[G_NUMBER] > 0)
      write("You will be invisible for " + args[G_NUMBER] + " seconds.\n");
    this_player()->invis(args[G_NUMBER]);
    return 1;
  case "wizlist":
    if (args[G_TEXT])
      wizlist(args[G_TEXT]);
    else
      wizlist("");
    return 1;
  }
  return 0;
}

