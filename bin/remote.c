#include <udp.h>
#include <prop/player.h>
#include <names.h>
#include <kernel.h>
#include <is_wizard.h>
#include <libs.h>
#include <intermud.h>   // Coogan, 21-May-2002

inherit ACCESS;
inherit "basic/daemon";
inherit "basic/create";

#define MUDS_BAR "\
------------------------------------------------------------------------------"
#define MUDS_LINE "%-20s %|6s %-13s %-15s %4s\n"

void create() {
  add_command("remote", "remote");
}

// int to void, Coogan, 26-Mar-2011
void list_muds() {
  mapping hosts;
  int i;
  mixed muds;
  string result;

  result = sprintf(MUDS_LINE,"Mudname","Status","Last access","Host","Port");
  result += sprintf("%'-'*s\n",strlen(result)-1,"");
  muds = sort_array(m_indices(hosts = INETD->query("hosts")),#'>);
  for(i = 0; i < sizeof(muds); i++) {
    if (hosts[muds[i]][HOST_STATUS] > 0)
      result += sprintf(MUDS_LINE,
                        hosts[muds[i]][HOST_NAME],                   // name
                        "UP",                                        // status
                        ctime(hosts[muds[i]][HOST_STATUS])[4..15],   // time
                        hosts[muds[i]][HOST_IP],                     // host
                        to_string(hosts[muds[i]][HOST_UDP_PORT]));   // port
    else if (hosts[muds[i]][HOST_STATUS] < 0)
      result += sprintf(MUDS_LINE,
                        hosts[muds[i]][HOST_NAME],                   // name
                        "DOWN",                                      // status
                        ctime(-hosts[muds[i]][HOST_STATUS])[4..15],  // time
                        hosts[muds[i]][HOST_IP],                     // host
                        to_string(hosts[muds[i]][HOST_UDP_PORT]));   // port
    else
      result += sprintf(MUDS_LINE,
                        hosts[muds[i]][HOST_NAME],                   // name
                        "UNKNOWN",                                   // status
                        "Never accessed.",                           // time
                        hosts[muds[i]][HOST_IP],                     // host
                        to_string(hosts[muds[i]][HOST_UDP_PORT]));   // port
  }
  this_player()->view_text(result,"remote muds");
  this_player()->start_view();
}

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
  case "mail":
    return notify_fail("Please use the command 'mail' instead giving an "
                       "intermud address.\n"
                       "For example 'mail chameloid@tubmud'.\n",1), 0;
                         // Chameloid, 02-Jan-1997
  case "locate":  // Alfe 1996-Feb-26
    if (sizeof(args) != 2)
      return notify_fail("Usage: remote locate <player name>\n",-1), 0;
    note = clone_object("etc/udp_note");
    move_object(note,this_player());
    note->set_title("Locate request of "+args[1]);
    h = INETD->do_send_udp(0,([ REQUEST: "locate",
                                SENDER: note,
                                "vbs": 1,
                                "user": this_player()->query_real_name(),
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
  case "who":
    if (sizeof(args) != 2)
      return notify_fail("Usage: remote who <mud name>\n"), 0;
//#define REMOTE_WHO_RESULT_ON_NOTE
#ifdef REMOTE_WHO_RESULT_ON_NOTE
    note = clone_object("etc/udp_note");
    move_object(note,this_player());
    note->set_title("Who request of "+args[1]);
    write((INETD->do_send_udp(args[1],
                              ([ REQUEST: "who",
                                 SENDER: note ]),1) ||
           "Who request sent to mud \""+args[1]+"\".\n") ||
          "A note appears in your hands.\n");
#else
    write(INETD->do_send_udp(args[1],
                            ([ REQUEST: "who",
                               SENDER: this_player()->query_vis_name() ]),1) ||
          "Who request sent to mud \""+args[1]+"\".\n");
#endif
    return 1;
  case "finger":  // Alfe 1996-Feb-29
    if (sizeof(args)<2 || sscanf(args[1],"%s@%s",name,mud)!=2)
      return notify_fail("Usage: remote finger <player>@<mud>\n",-1), 0;
    if (lower_case(mud) == (DOMAIN[0..strlen(mud)-1]) &&
        !is_wizard(this_player(),IW_WIZARD))
      return 0;  // disable remote finger into own mud
    write(INETD->do_send_udp(mud,([ REQUEST: "finger",
                                    SENDER: this_player()->query_vis_name(),
                                    DATA: name ]),1) ||
          "Finger request for \""+name+"\" sent to mud \""+mud+"\".\n");
    return 1;
  case "man":
    if (!is_wizard(this_player(),IW_TOOLUSER))
      return 0;
    if (sizeof(args)<2)
      return notify_fail("Usage: remote man <keyword>@<mud>\n"
                         "       remote man <keyword>\n",-1), 0;
    if (sscanf(args[1],"%s@%s",keyword,mud)!=2) {
      mud = 0;
      keyword = args[1];
    }
    note = clone_object("etc/udp_note");
    move_object(note,this_player());
    note->set_title("Man request for "+args[1]);
    h = INETD->do_send_udp(mud,([ REQUEST: "man",
                                  SENDER: note,
                                  DATA: keyword ]),1);
    if (h)
      write(h);
    write("Man request for \""+keyword+"\" sent to " +
          (mud? "mud \""+mud+"\"" : "all known muds") + ".\n"
          "A note appears in your hands.\n");
    return 1;
  case "won":  // Coogan, 21-May-2002
    if (!is_wizard(this_player(),IW_APPRENTICE))
      return 0;
    if (sizeof(args) != 2)
      return notify_fail("Usage: remote won <channel>\n",-1), 0;
    this_player()->switch_on_protocol_for_channel(args[1], INTERMUD_2);
    return 1;
  case "woff":
    if (!is_wizard(this_player(),IW_APPRENTICE))
      return 0;
    if (sizeof(args) != 2)
      return notify_fail("Usage: remote woff <channel>\n",-1), 0;
    this_player()->switch_off_protocol_for_channel(args[1], INTERMUD_2);
    return 1;
  case "tell":
    if (sizeof(args)<3 || sscanf(args[1],"%s@%s",name,mud)!=2)
      return notify_fail("Usage: remote tell <player>@<mud> <text>\n",-1), 0;
    if (lower_case(mud) == (DOMAIN[0..strlen(mud)-1]) &&
        !is_wizard(this_player(),IW_APPRENTICE))
      return 0;  // Alfe 1995-Mar-27  disable remote tell into own mud
    unguarded(1,#'call_other,
              ({ this_player(),"set_last_command",
                 "remote tell "+name+"@"+mud+" %s" }));
    if (!this_player()->short())  // invisible?
      return notify_fail("You cannot send remote tells to other muds while you"
                         " are invisible.\n",-1), 0;
    message(INETD->do_send_udp(mud,
                               ([ REQUEST: "tell",
                                  SENDER: this_player()->query_vis_name(),
                                  RECIPIENT: name,
                                  DATA:
#if 0  // Coogan, 19-Sep-2001: no quoting here for intermud2, as there are muds
       // not using LDMud's terminal_colour()
       LIB_CNTL_SEQUENCES->quote_for_terminal_colour(implode(args[2..]," "))
#else
                                        implode(args[2..]," ")
#endif
                               ]), 1) ||
            "Message transmitted.\n");
    return 1;
  case "muds":
    list_muds();
    return 1;
  default:
    if (args[0][0..2]!="wiz" || !is_wizard(this_player(),IW_APPRENTICE))
      return notify_fail("Usage: remote who <mud name>\n"
                         "       remote muds\n"
                         "       remote tell <player>@<mud> <text>\n"
                         "       remote finger <player>@<mud>\n"
                         "       remote locate <player name>\n"+
                         (is_wizard(this_player(),IW_APPRENTICE)?
                          "       remote wiz<channel> <text>\n"
                          "       remote wiz<channel>@<mud> <text>\n"
                          "       remote wiz:<channel> <text>\n"
                          "       remote wiz:<channel>@<mud> <text>\n"
                          "       remote wiz?<channel>\n"
                          "       remote wiz?<channel>@<mud>\n"
                          "       remote won <channel>\n"
                          "       remote woff <channel>\n"
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
    if (member(this_player()->query_channels(INTERMUD_2),channel)<0)
      return notify_fail("You are not listening to intermud2 transmissions on "
                         "channel "+channel+".\n",-1), 0;
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
  NO_WARN_MISSING_RETURN;  // Coogan, 26-Mar-2011
}

