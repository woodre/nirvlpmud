/*
 * bin/intermud - a daemon providing a unique syntax for intermud communication
 * independly wether the target mud supports intermud vers. 2 or 3
 * Coogan, Feb-May 2002
 *
 * player commands:
 *
 * command  |  prio
 * ---------+-------
 * tell     | i2, i3            // defined by /bin/secure
 * feelings | i3, i2            // defined by /bin/soul
 * who      | i2, i3 done.
 * finger   | i2, i3 done.
 * locate   | i2, i3 todo.
 * mudinfo  | i2, i3 todo.
 * mudlist  | i2, i3 done.      // also done in /bin/remote, /bin/imud3
 *
 */

#pragma strong_types

#include <grammar.h>
#include <udp.h>
#include <imud3.h>
#include <intermud.h>
#include <server.h>

inherit "basic/parser";
inherit "basic/daemon";
inherit "basic/create";

void create() {
  create::create();
  add_rule("who "G_TEXT" "G_MUD_NAME,           "who");
  add_rule("who "G_MUD_NAME,                    "who");

  add_rule("locate "G_WORD,                     "locate");

  add_rule("finger "G_REMOTE_RESOURCE,          "finger");
  add_error_message("finger", "Usage: finger player@mud\n");

  add_rule("mudinfo "G_MUD_NAME" "G_WORD,       "mudinfo");
  add_rule("mudinfo "G_MUD_NAME,                "mudinfo");

  add_rule("to "G_REMOTE_RESOURCE" emote "G_TEXT, "emote");

  add_rule("mudlist "G_WORD,                    "mudlist");
  add_rule("mudlist",                           "mudlist");

  filter(query_rule_verbs(),
               lambda(({ 'v }), ({ #'add_command, "parse_cmd", 'v })));
}

static status parse_cmd(string arg, string verb) {
  return parse_sentence(arg ? verb + " " + arg : verb);
}

int do_action(string action, mapping args) {
  int protocol, *mud_status_2, *mud_status_3;
  mixed* mud_info;
  string mud_name, data;
  int result;
  mixed res;

  switch (action) {
  case "who":
    SE_INTERMUD->send_request("who", args[G_MUD_NAME],
                              args[G_TEXT]);
    return 1;

  case "locate":
//    DEBUG_POINT_TP("coogan", ({ args }));
    break;

  case "finger":
    SE_INTERMUD->send_request("finger", args[G_REMOTE_RESOURCE],
                              args[G_REMOTE_RESOURCE,1]);
    return 1;

  case "mudinfo":
//    DEBUG_POINT_TP("coogan", ({ args }));
    break;

  case "emote":
    SE_INTERMUD->send_request("emoteto", args[G_REMOTE_RESOURCE],
                              ({ args[G_REMOTE_RESOURCE,1], args[G_TEXT] }));
    return 1;

  case "tell":
//    DEBUG_POINT_TP("coogan", ({ args }));
    if (args[G_WORDS])
      SE_INTERMUD->send_request("tell", args[G_REMOTE_RESOURCE],
                                ({ args[G_REMOTE_RESOURCE,1], args[G_TEXT],
                                   args[G_WORDS] }));
    else
      SE_INTERMUD->send_request("tell", args[G_REMOTE_RESOURCE],
                                ({ args[G_REMOTE_RESOURCE,1], args[G_TEXT] }));
    break;

  case "mudlist":
//    DEBUG_POINT_TP("coogan", ({ args }));
    if (args[G_WORD])
      if (args[G_WORD] != "intermud2" && args[G_WORD] != "intermud3")
        return notify_fail("Usage: mudlist [intermud2 | intermud3]\n"), 0;
    this_player()->view_text(
      SE_INTERMUD->get_mud_list(args[G_WORD] &&
                                (args[G_WORD] == "intermud2"
                                 ? INTERMUD_2 : INTERMUD_3)));
    this_player()->start_view();
    return 1;

  }
  return 0;  // Coogan, 26-Mar-2011
}

#if 0
int remote(string str) {
  mixed h;
  object note;
  string *args, text;
  int emote_type;
  mapping udp_map;
  string name,mud,channel,keyword;
  status emote,ask;
  if (!str)
    str = "";
  str = unguarded(1,#'call_other,({ this_player(),"alias_substitution",str }));
  if (!str)
    str = "";
  args = explode(str," ");
  switch (args[0]) {
  case "locate":  // Alfe 1996-Feb-26
    if (sizeof(args) != 2)
      return notify_fail("Usage: remote locate <player name>\n",-1), 0;
    note = clone_object("etc/udp_note");
    move_object(note,this_player());
    note->set_title("Locate request of "+args[1]);
    h = INETD->do_send_udp(0,([ REQUEST: "locate",
                                SENDER: note,
                                DATA: args[1] ]),1);
    if (h)
      write(h);
    write("Locate request for \""+args[1]+"\" sent to all known muds.\n"
          "A note appears in your hands.\n");
    return 1;
  case "query":
    if (!is_wizard(this_player(),IW_TOOLUSER))
      return 0;
    if (sizeof(args) == 2)
      args += ({ "list" });
    else if (sizeof(args) != 3)
      return notify_fail("Usage: remote query <mud> [<type>]\n"), 0;
    write(INETD->do_send_udp(args[1],
                             ([ REQUEST: "query",
                                DATA: args[2],
                                SENDER: this_player()->query_vis_name() ]),1) ||
          "Query-" + args[2] + " request sent to mud \"" + args[1] + "\".\n");
    return 1;
  default:
    if (args[0][0..2]!="wiz" || !is_wizard(this_player(),IW_APPRENTICE))
      return notify_fail("Usage: remote who <mud name>\n"
                         "       remote muds\n"
                         "       remote locate <player name>\n"+
                          "       remote man <keyword>\n"
                          "       remote man <keyword>@<mud>\n"
                          "       remote query <mud> [<type>]\n" : 
                          ""),-1), 0;
    channel = args[0][3..];
    h = explode(channel,"@");
    channel = h[0];
    mud = (sizeof(h) > 1) && h[1];
    if (mud && !strlen(mud))
      return notify_fail("Give a mud.\n",-1), 0;
    if (sizeof(h) > 2)
      return notify_fail("Usage: remote wiz<channel>@<mud> <text>\n"
                         "       remote wiz:<channel>@<mud> <text>\n"
                         "       remote wiz?<channel>@<mud>\n",-1), 0;
    if (channel[0] == ':') {
      emote = 1;
      channel = channel[1..];
    }
    else if (channel[0] == '?') {
      ask = 1;
      channel = channel[1..];
    }
    if (ask) {
      if (!mud) {  // no '@' found ==> ask all muds
        note = clone_object("etc/udp_note");
        move_object(note,this_player());
        note->set_title("Channel-list request for " + channel);
        write("Channel-list request for \"" + channel +
              "\" sent to all known muds.\n"
              "A note appears in your hands.\n");
        h = INETD->do_send_udp(0,([ REQUEST: "channel",
                                    SENDER: note,
                                    "CHANNEL": channel,
                                    "CMD": "list" ]),1);
      }
      else  // a mud was given
        h = INETD->do_send_udp(mud,([ REQUEST: "channel",
                                      SENDER: this_player()->query_vis_name(),
#if 0  // Alfe 1997-May-16
                                      "CHANNEL": mud,
#else
                                      "CHANNEL": channel,
#endif
                                      "CMD": "list" ]),1);
      if (h)
        write(h);
      return 1;
    }
    if (!strlen(channel))
      return notify_fail("Give a channel.\n",-1), 0;
    if (member(this_player()->query_channels(1),channel)<0)
      return notify_fail("You are not listening to intermud transmissions on"
                         " channel "+channel+".\n",-1), 0;
    if (sizeof(args)<2)
      return notify_fail("Give a message.\n",-1), 0;
    unguarded(1,#'call_other,
              ({ this_player(),"set_last_command",
                 "remote wiz"+(emote? ":" : "")+channel+" %s" }));
    text = implode(args[1..], " "); // added gemote-feature, Coogan, 13-Jul-2001
    if (emote) {
      emote_type = emote;
      if (text[0..2] == "'s ") {
        text = text[3..];
        emote_type = 2;
      }
    }
    udp_map = ([ REQUEST  : "channel",
                 SENDER   : this_player()->query_vis_name(),
                 "CHANNEL": channel,
                 "CMD"    : emote ? "emote" : 0,
                 DATA     : text ]);
    if (emote)
      udp_map += ([ "EMOTE" : emote_type ]);

    h = INETD->do_send_udp(mud, udp_map);
    if (h)
      message(h);
    return 1;
  }
}

#endif

