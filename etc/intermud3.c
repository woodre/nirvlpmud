/* This is an intermud 3 daemon designed for Amylaar 3.2.1 muds.  It was
 * created by Skylight and friends.  This requires the use of the Timewarp
 * erq daemon, preferably version 1.3 or newer.
 *
 * Originally adapted for Evermore by Fafnir 1998
 * Adapted for Tubmud by Fafnir 
 *
 */

#pragma strong_types

#ifdef INTERMUD3

#include <time_units.h>
#include <erq.h>
#include <imud3.h>
#include <kernel.h>
#include <message.h>  // Coogan, 23-Feb-2001
#include <intermud.h>
#include <libs.h>

inherit ACCESS;
inherit IMUD3"/imud3";
virtual inherit IMUD3"/pf-colours";  // virtual, Coogan, 23-Feb-2001
inherit IMUD3"/file";

#define TIME_OUT 600

int oob_port;
       mapping banned = ([]), muds = ([]), channels = ([]);
nosave mapping mud_names = ([]);
// mixed *routers = ({ ({ "*gjs", "198.144.203.194 9000" }) });
// *gjs is dead, long live http://dead-souls.net/router.html
// added *i4, Coogan, 30-Apr-2008
// Coogan, 18-Jun-2009: yatmin removed, and router page moved
//  	to http://lpmuds.net/intermud.html
// ({ "*yatmim", "149.152.218.102 23" }),
nosave mixed *routers = ({ ({ "*i4", "204.209.44.3 8080"      }) });
// static int *ticket, data_pos;
int password = 0, mudlist_id = -1, channellist_id = -1;
nosave mixed /* *buffer = ({}), */ data_size;
nosave string incoming_data;
// nosave status sending;

nosave mixed *socket_ticket, *tickets, *buffers, *data_sizes;
nosave int *last_used;
nosave string *incoming_datas, *originator_muds, *target_muds;
nosave status *sendings;
nosave int *data_poss, *direction;
nosave mapping oob_queue = ([]);
nosave mapping oob_unanswered = ([]);
nosave mapping auth_tokens = ([]);
nosave mapping our_auth_tokens = ([ ]);
nosave string mudmode_buffer;

void oob_connect(string where);
void oob_write_callback(int fd, mixed *data, int size);
void oob_flush(int fd);
void handle_oob_data(int fd, mixed *lpc_data);
void handle_data(mixed *lpc_data);


// #define IB_DEBUG        "coogan"
// #define OOB_DEBUG       "coogan"
// #define FULL_DEBUG

mixed* query_routers() {
  return routers;
}

mapping get_services() {
  return ([
#ifdef SERVICE_CHANNEL
            "channel" : 1,
#endif
#ifdef SERVICE_TELL
            "tell" : 1,
#endif
#ifdef SERVICE_WHO
            "who" : 1,
#endif
#ifdef SERVICE_FINGER
            "finger" : 1,
#endif
#ifdef SERVICE_LOCATE
            "locate" : 1,
#endif
#ifdef SERVICE_EMOTETO
            "emoteto" : 1,
#endif
#ifdef SERVICE_UCACHE
            "ucache" : 1,
#endif
#ifdef SERVICE_AUTH
            "auth" : 1,
#endif
#ifdef SERVICE_MAIL
            "mail" : 1,
#endif
#ifdef SERVICE_FILE
            "file" : 1,
#endif
#ifdef PORT_FTP
            "ftp" : PORT_FTP,
#endif
#ifdef PORT_HTTP
            "http" : PORT_HTTP,
#endif
#ifdef PORT_RCP
            "rcp" : PORT_RCP,
#endif
         ]);
}

#ifdef IB_DEBUG
void debug_ib(mixed lpc_data) {
  object ob;

  ob = find_player(IB_DEBUG);
  if (!ob)
    return;
  if (!sizeof(lpc_data)) {
    tell_object(ob,"IB : Unknown, buffered packet\n");
    return;
  }
  tell_object(ob, sprintf("IB : Req: %10s From: %s@%s To: %s@%s\n",
                  to_string(lpc_data[0]) || "<unknown>",
                  to_string(lpc_data[3]) || "<unset>",
                  to_string(lpc_data[2]) || "<unset>",
                  to_string(lpc_data[5]) || "<unset>",
                  to_string(lpc_data[4]) || "<unset>"));
#ifdef FULL_DEBUG
  tell_object(ob, sprintf(" %O\n", lpc_data));
#endif
}
#endif

#ifdef OOB_DEBUG
void debug_oob(string from, string to, mixed lpc_data) {
  object ob;

  ob = find_player(OOB_DEBUG);
  if (!ob)
    return;
  if (!sizeof(lpc_data)) {
    tell_object(ob, "OOB: Unknown, buffered packet\n");
    return;
  }
  tell_object(ob, sprintf("OOB: Req: %10s From: %s To: %s\n",
                  to_string(lpc_data[0]) || "<unknown>",
                  to_string(from) || "<unset>",
                  to_string(to) || "<unset>"));
#ifdef FULL_DEBUG
  tell_object(ob, sprintf(" %O\n", lpc_data));
#endif
}
#endif

// tell_object including PF code parsing
void tell_object(object ob,string text) {
#if 0  // Coogan, 23-Feb-2001
  efun::tell_object(ob, parse_text(text, ob));
#else
  if (text[<1..<1] == "\n")
    text = text[0..<2];
  send_message(({ M_TARGETS, ob, parse_text(text, 1) }));
#endif
}

void save_me() {
  unguarded(1, #'save_object, ({ SAVE_INTERMUD }));
}

#ifndef USE_RESTORE_OBJECT
mixed scan_data() {
  int a, b;

  if (sscanf(mudmode_buffer, "%d.%d%s", a, b, mudmode_buffer) == 3)
    return to_float(a + "." + b);
  if (sscanf(mudmode_buffer, "%d%s", a, mudmode_buffer) == 2)
    return a;
  if (mudmode_buffer[0] == '\"') {
    string str;
    int c, c2, cha;
    c = 1;
    str = "";
    c2 = 0;
    do {
      c2 = strstr(mudmode_buffer,"\"",c2+1);
      b = c2-1;
      while(b && mudmode_buffer[b] == '\\')
        b--;
    } while (c2 > 0 && !((c2 - b) % 2));
    if (c2 < 0)
      raise_error("Unterminated string.\n");
    str = imud3::unquote_string(mudmode_buffer[1..(c2-1)]);
    c = c2;
    mudmode_buffer = mudmode_buffer[c + 1..];
    return str;
  }
  if (mudmode_buffer[0..1] == "({") {
    mixed *arr;
    arr = ({ });
    mudmode_buffer = mudmode_buffer[2..];
    while (mudmode_buffer[0..1] != "})") {
      if (!strlen(mudmode_buffer))
        raise_error("Incomplete array.\n");
      arr += ({ scan_data() });
      mudmode_buffer = mudmode_buffer[1..]; /* assume there's a comma */
    }
    mudmode_buffer = mudmode_buffer[2..];
    return arr;
  }
  if (mudmode_buffer[0..1] == "([") {
    mapping map;
    map = ([ ]);
    mudmode_buffer = mudmode_buffer[2..];
    while (mudmode_buffer[0..1] != "])") {
      mixed key;
      if (!strlen(mudmode_buffer))
        raise_error("Incomplete mapping.\n");
      key = scan_data();
      mudmode_buffer = mudmode_buffer[1..]; /* assume there's a colon */
      map[key] = scan_data();
      mudmode_buffer = mudmode_buffer[1..]; /* assume there's a comma */
    }
    mudmode_buffer = mudmode_buffer[2..];
    return map;
  }

  // Coogan, 15-Jan-1999: added the next big if(), taken from
  // Evermore's intermud3.c
  /*
   * (/ ... /) mean classes which come close to C structs.
   * best equivalent are mappings with a defined set of keys.
   */

  if (mudmode_buffer[0..1] == "(/") {
    mapping map2;
    map2 = ([ ]);
    mudmode_buffer = mudmode_buffer[2..];
    while (mudmode_buffer[0..1] != "/)") {
      mixed key2;
      if (!strlen(mudmode_buffer))
        raise_error("Incomplete mapping.\n");
      key2 = scan_data();
      mudmode_buffer = mudmode_buffer[1..]; /* assume there's a comma */
      map2[key2] = scan_data();
      mudmode_buffer = mudmode_buffer[1..]; /* assume there's a comma */
    }
    mudmode_buffer = mudmode_buffer[2..];
    return map2;
  }

  raise_error("Error decoding mud mode data.\n");
}
#endif

mixed from_mudmode(string data) {
  mixed restored_data;
#ifdef USE_RESTORE_OBJECT
  rm("/open/mudmode.o");
  write_file("/open/mudmode.o", "x "+implode(explode(data,"\n"),"\\n") +"\n");
  return ::from_mudmode();
#else
#if 0
  mudmode_buffer = data;
  return scan_data();
#else
  // this is MUCH cheaper. Coogan, 25-Sep-2007
  return restore_value(data + "\n");
#endif
#endif
}

static void receive_auth_mud_reply(mixed *data) {
  auth_tokens[data[2]] = data[6];
#ifdef OOB_DEBUG
  debug(OOB_DEBUG,"Reply received...");
#endif
  if (member(originator_muds, data[2]) == -1 &&
      member(target_muds, data[2]) == -1)
    oob_connect(data[2]);
#ifdef OOB_DEBUG
  else
    debug(OOB_DEBUG,"Using already opened connection");
#endif
}

void receive_auth_mud_request(mixed *data) {
  int p, q;
  if ((p = member(m_values(our_auth_tokens), data[2])) != -1)
    m_delete(our_auth_tokens, m_indices(our_auth_tokens)[p]);
  q = time() ^ 0x55AA55AA; /* perhaps use something else ? */
  while (our_auth_tokens[q])
    ++q;
  our_auth_tokens[q] = data[2];
  call_out(#'m_delete, 600, our_auth_tokens, q);
  send_tcp(({ "auth-mud-reply", 5, MUDNAME, 0, data[2], 0, q }));
}

void read_callback(mixed *data, int size) {
  string text, error;
  mixed lpc_data;
  int i, pos, tmp;

  switch(data[0]) {
  case ERQ_OK:
    ticket = data[1..];
    data_pos = 0;
    incoming_data = 0;
    data_size = 0;
    sending = 0;
    buffer = ({ to_mudmode(({ "startup-req-3", 5, MUDNAME, 0, routers[0][0],
                              0, password, mudlist_id, channellist_id,
                              query_mud_port(), oob_port, PORT_UDP,
                              MUDLIB + " " + MUDLIB_VERSION,
                              MUDLIB + " " + MUDLIB_VERSION,
                              DRIVER + " " __VERSION__, "LDMud",
                              MUD_STATUS, ADMIN_EMAIL, get_services(),
                              ([ "url"   : "http://www.tubmud.de",
                                 "banner": "\
 ,-------.    ,-.        Welcome at        ,-. \n\
 `--. .--'    | |                          | |  Telnet:    mud.tubmud.de 7680\n\
    | |,-. ,-.| +--. ,---------.,-. ,-. ,--+ |             tubmud.mud.de 7680\n\
    | || | | || ,-. )| ,-. ,-. || | | |( ,-. |  \n\
    | || `-' || `-' )| | | | | || `-' |( `-' |  WWW: http://www.tubmud.de \n\
    `-'`-----'`----' `-' `-' `-'`-----' `----'  \n",
                              ]) })) }) + buffer;
    flush();
    return;
  case ERQ_STDOUT:
    data = data[1..];
#if 0
    while (sizeof(data)) {
      if (data_size) {
        if (pointerp(data_size)) {
          int tmp;
          tmp = 3 - sizeof(data_size);
          data_size += data[0..tmp];
          data_size = (data_size[0] & 0xFF) * 0x1000000 +
                      (data_size[1] & 0xFF) * 0x10000 +
                      (data_size[2] & 0xFF) * 0x100 +
                      (data_size[3] & 0xFF);
          incoming_data = "";
          data = data[tmp + 1..];
          continue;
        }
        tmp = data_size - strlen(incoming_data);
        incoming_data += to_string(data[0..tmp - 1]);
        if (strlen(incoming_data) + 1 == data_size) {
          if (error = catch(lpc_data = from_mudmode(incoming_data)))
            log_file("INTERMUD3_PACKET", error + incoming_data + "\n");
          else if(error = catch(handle_data(lpc_data)))
            log_file("INTERMUD3_PACKET", error + incoming_data + "\n");
          incoming_data = 0;
          data_size = 0;
        }
        data = data[tmp..];
        continue;
      }
      data_size = data[0..3];
      data = data[4..];
      if (sizeof(data_size) == 4) {
        data_size = (data_size[0] & 0xFF) * 0x1000000 +
                    (data_size[1] & 0xFF) * 0x10000 +
                    (data_size[2] & 0xFF) * 0x100 +
                    (data_size[3] & 0xFF);
        incoming_data = "";
      }
    }
#else
    while(sizeof(data)) {
      if(!data_size || !intp(data_size)) { // Still incomplete
        data_size = data_size || ({ });
        tmp = sizeof(data);
        if (tmp > 4)
          tmp = 4;
        tmp -= sizeof(data_size);
        data_size += data[0..(tmp-1)];
        data = data[tmp..];
        if (sizeof(data_size) == 4) {
          data_size = (data_size[0] & 0xFF) * 0x1000000 +
                      (data_size[1] & 0xFF) * 0x10000 +
                      (data_size[2] & 0xFF) * 0x100 +
                      (data_size[3] & 0xFF);
        }
      } else {
        tmp = sizeof(data);
        if (tmp > data_size)
          tmp = data_size;
        if (!incoming_data)
          incoming_data = "";
        incoming_data += to_string(data[0..(tmp-1)]);
        data = data[tmp..];
        data_size -= tmp;
        if (!data_size) {
          if (error = catch(lpc_data = from_mudmode(incoming_data)))
            log_file("INTERMUD3_PACKET", __LINE__ + " " + error + incoming_data + "\n");
          else {
#ifdef IB_DEBUG
            debug_ib(lpc_data);
#endif
            if (error = catch(handle_data(lpc_data)))
              log_file("INTERMUD3_PACKET", __LINE__ + " " + error + incoming_data + "\n");
          }
          incoming_data = 0;
          data_size = 0;
        }
      }
    }
#endif
    return;
  case ERQ_EXITED:
    ticket = 0;
    call_out("connect", 2);
    return;
  case ERQ_E_UNKNOWN: /* failed to connect, connection broken */
    ticket = 0;
    call_out("connect", 2);
    return;
  }
}
 
void connect() {
  int a, b, c, d, port;
  if (sscanf(routers[0][1], "%d.%d.%d.%d %d", a, b, c, d, port) != 5)
    raise_error("Bad router address.\n");
  send_erq(ERQ_OPEN_TCP, ({ a, b, c, d, port / 0x100, port & 0xFF }),
           #'read_callback);
}
 
void handle_data(mixed *lpc_data) {
  string *indices, ch;
  mixed *values;
  int i;

  switch(lpc_data[0]) {
  case "startup-reply":
    if (sizeof(lpc_data) != 8)
      return;
    if (!sizeof(lpc_data[6]))
      return;
    if (lpc_data[6][0][0] == routers[0][0]) {
      routers = lpc_data[6];
      password = lpc_data[7];
      save_me();
      // startup was successful. listen to channels ..
      foreach (ch : LIB_CHANNELS->query_all_channels(INTERMUD_3)) {
#ifdef IB_DEBUG
        if (find_player(IB_DEBUG))
          tell_object(find_player(IB_DEBUG), "listen on for " + ch + "\n");
#endif
        IMUD3"/channel"->send_channel_listen(ch, 1);
      }
    }
    return;
  case "mudlist":
    if (sizeof(lpc_data) != 8)
      return;
    if (lpc_data[2] != routers[0][0])
      return;
    indices = m_indices(lpc_data[7]);
    values = m_values(lpc_data[7]);
    i = sizeof(indices);
    while (i--) {
      if (values[i]) {
        muds[indices[i]] = values[i];
        mud_names[implode(explode(lower_case(indices[i])," "),".")]=indices[i];
      }
      else if (muds[indices[i]]) {
        m_delete(muds, indices[i]);
        m_delete(mud_names, implode(explode(lower_case(indices[i])," "), "."));
      }
    }
    save_me();
    return;

  // channel stuff
  case "channel-m":
    IMUD3"/channel"->receive_channel_message(lpc_data);
    return;
  case "channel-e":
    IMUD3"/channel"->receive_channel_emote(lpc_data);
    return;
  case "channel-t":
    IMUD3"/channel"->receive_channel_target_emote(lpc_data);
    return;
  case "chan-who-req":
    IMUD3"/channel"->receive_channel_who_request(lpc_data);
    return;
  case "chan-who-reply":
    IMUD3"/channel"->receive_channel_who_reply(lpc_data);
    return;
  case "chan-user-req":
    IMUD3"/channel"->receive_channel_user_request(lpc_data);
    return;
  case "chan-user-reply":
    IMUD3"/channel"->receive_channel_user_reply(lpc_data);
    return;
  case "ucache-update":
    IMUD3"/channel"->receive_ucache_update(lpc_data);
    return;
  case "chanlist-reply":
    if (lpc_data[2] != routers[0][0])
      return;
    channellist_id = lpc_data[6];
    indices = lpc_data[7];
    values = m_values(lpc_data[7]);
    channels += lpc_data[7];
    i = sizeof(indices);
    while (i--)
      if (!values[i])
	efun::m_delete(channels, indices[i]);
    channels += ([ "imud_code"   : ({ "global", 0 }),
                   "imud_gossip" : ({ "global", 0 }) ]);
    save_me();
    return;

  case "tell":
    IMUD3"/tell"->receive_tell(lpc_data);
    return;
  case "who-req":
    IMUD3"/who"->receive_who_request(lpc_data);
    return;
  case "who-reply":
    IMUD3"/who"->receive_who_reply(lpc_data);
    return;
  case "finger-reply":
    IMUD3"/finger"->receive_finger_reply(lpc_data);
    return;
  case "finger-req":
    IMUD3"/finger"->receive_finger_request(lpc_data);
    return;
  case "locate-req":
    IMUD3"/locate"->receive_locate_request(lpc_data);
    return;
  case "locate-reply":
    IMUD3"/locate"->receive_locate_reply(lpc_data);
    return;
  case "emoteto":
    IMUD3"/emoteto"->receive_emoteto(lpc_data);
    return;
  case "auth-mud-req":
    receive_auth_mud_request(lpc_data);
    return;
  case "auth-mud-reply":
    receive_auth_mud_reply(lpc_data);
    return;
  case "error":
    IMUD3"/error"->receive_error(lpc_data);
    return;
  default:
    send_tcp(({ "error", 5, MUDNAME, 0, lpc_data[2], 0, "unk-type",
      "type '" + lpc_data[0] + "' is unrecognized", lpc_data }));
  }
}
 
void notify_destruct() {
  send_tcp(({ "shutdown", 5, MUDNAME, 0, routers[0][0], 0, ONE_MONTH }));
  if (ticket)
    send_erq(ERQ_KILL, ticket, 0); /* assume the response will be ERQ_OK */
  if (socket_ticket)
    send_erq(ERQ_KILL, socket_ticket, 0); /* assume again */
}

void remove() {  // Coogan, 15-Jan-1999, was missing
  destruct(this_object());
}

void shutdown(int restart) {
  send_tcp(({ "shutdown", 5, MUDNAME, 0, routers[0][0], 0, restart }));
  call_out("remove",10); /* We do shutdown in every case */
}

mapping query_muds() {
  return muds;
}

mapping query_mud_list() {
  return mud_names;
}

mapping query_channels() {
  return channels;
}
 
string get_mud_name(string str) {
  if (member(muds,str))
    return str;
  return mud_names[implode(explode(lower_case(str), " "), ".")];
}

mixed *query_mud_info(string str) {
  mixed *ret;
  if (ret = muds[str])
    return ret + ({ });
}

status query_has_service(string where, string service) {
  return muds[where] && muds[where][I3_ML_SERVICES][service];
}

mapping query_muds_per_service(string service) {
  return
    filter_indices(muds,
                   lambda(({ 'x }),
                          ({ #'&&,
                             ({ #'mappingp,
                                ({ #'=, 'st, ({#'[, ({#'[,muds,'x }), 11 }) })
                             }),
                             ({ #'member, 'st, service }),
                          })));
}

void oob_read_callback(int fd, mixed *data, int size) {
  int tmp;
  mixed lpc_data;
  string error;

  switch(data[0]) {
  case ERQ_OK:
#ifdef OOB_DEBUG
    debug(OOB_DEBUG,"Connection established.");
#endif
    if (direction[fd] > 0)
      tickets[fd] = data[1..];
    else
      tickets[fd] = data[7..];
    incoming_datas[fd] = 0;
    data_poss[fd] = 0;
    data_sizes[fd] = 0;
    sendings[fd] = 0;
    if (target_muds[fd])
      buffers[fd] = ({ to_mudmode(({ "oob-begin", MUDNAME,
                       !!(tmp = auth_tokens[target_muds[fd]]), tmp })) });
    else
      buffers[fd] = ({ });
    oob_flush(fd);
    return;
  case ERQ_STDOUT:
    last_used[fd] = time();
    data = data[1..];
#if 0
    while (sizeof(data)) {
      if (data_sizes[fd]) {
        if (pointerp(data_sizes[fd])) {
          tmp = 3 - sizeof(data_sizes[fd]);
          data_sizes[fd] += data[0..tmp];
          data_sizes[fd] = (data_sizes[fd][0] & 0xFF) * 0x1000000 +
                           (data_sizes[fd][1] & 0xFF) * 0x10000 +
                           (data_sizes[fd][2] & 0xFF) * 0x100 +
                           (data_sizes[fd][3] & 0xFF);
          incoming_datas[fd] = "";
          data = data[tmp + 1..];
          continue;
        }
        tmp = data_sizes[fd] - strlen(incoming_datas[fd]);
        incoming_datas[fd] += to_string(data[0..tmp - 1]);
        if (strlen(incoming_datas[fd]) + 1 >= data_sizes[fd]) {
          if (error = catch(lpc_data = from_mudmode(incoming_datas[fd])))
            log_file("INTERMUD3_PACKET", error + incoming_datas[fd] + "\n");
          else if(error = catch(handle_oob_data(fd, lpc_data)))
            log_file("INTERMUD3_PACKET", error + incoming_datas[fd] + "\n");
          incoming_datas[fd] = 0;
          data_sizes[fd] = 0;
        }
        data = data[tmp..];
        continue;
      }
      data_sizes[fd] = data[0..3];
      data = data[4..];
      if (sizeof(data_sizes[fd]) == 4) {
        data_sizes[fd] = (data_sizes[fd][0] & 0xFF) * 0x1000000 +
                         (data_sizes[fd][1] & 0xFF) * 0x10000 +
                         (data_sizes[fd][2] & 0xFF) * 0x100 +
                         (data_sizes[fd][3] & 0xFF);
        incoming_datas[fd] = "";
      }
    }
#else
    while(sizeof(data)) {
      if (!data_sizes[fd] || !intp(data_sizes[fd])) {  // Still incomplete
        data_sizes[fd] = data_sizes[fd] || ({ });
        tmp = sizeof(data);
        if (tmp > 4)
          tmp = 4;
        tmp -= sizeof(data_sizes[fd]);
        data_sizes[fd] += data[0..(tmp-1)];
        data = data[tmp..];
        if (sizeof(data_sizes[fd]) == 4) {
          data_sizes[fd] = (data_sizes[fd][0] & 0xFF) * 0x1000000 +
                           (data_sizes[fd][1] & 0xFF) * 0x10000 +
                           (data_sizes[fd][2] & 0xFF) * 0x100 +
                           (data_sizes[fd][3] & 0xFF);
        }
      } else {
        tmp = sizeof(data);
        if (tmp > data_sizes[fd])
          tmp = data_sizes[fd];
        if (!incoming_datas[fd])
          incoming_datas[fd] = "";
        incoming_datas[fd] += to_string(data[0..(tmp-1)]);
        data = data[tmp..];
        data_sizes[fd] -= tmp;
        if (!data_sizes[fd]) {
          if (error = catch(lpc_data = from_mudmode(incoming_datas[fd])))
            log_file("INTERMUD3_PACKET", __LINE__ + " " + error + incoming_datas[fd] + "\n");
          else {
#ifdef OOB_DEBUG
            debug_oob(originator_muds[fd],"Local",lpc_data);
#endif
            if (error = catch(handle_oob_data(fd, lpc_data)))
              log_file("INTERMUD3_PACKET", __LINE__ + " " + error + incoming_datas[fd] + "\n");
          }
          incoming_datas[fd] = 0;
          data_sizes[fd] = 0;
        }
      }
    }
#endif
    return;
  case ERQ_EXITED:
    m_delete(oob_unanswered, originator_muds[fd] || target_muds[fd]);
    tickets[fd] = 0;
    originator_muds[fd] = 0;
    target_muds[fd] = 0;
    direction[fd] = 0;
    last_used[fd] = 0;
    return;
  case ERQ_E_UNKNOWN:
#ifdef OOB_DEBUG
    debug(OOB_DEBUG, "Failed to connect");
#endif
    if (!pointerp(tickets[fd])) {
      tickets[fd] = 0;
      originator_muds[fd] = 0;
      if (target_muds[fd]) {
        m_delete(auth_tokens, target_muds[fd]);
        target_muds[fd] = 0;
      }
    }
    return;
  }
}

void oob_connect(string where) {
  mapping tmp;
  int a, b, c, d, new_fd;
  if ((new_fd = member(tickets, 0)) == -1)
    return;
  tmp = muds[where];
  sscanf(tmp[1], "%d.%d.%d.%d", a, b, c, d);
  tickets[new_fd] = 1;
  direction[new_fd] = 1; // outgoing
  target_muds[new_fd] = where;
#ifdef OOB_DEBUG
  debug(OOB_DEBUG,"Connecting to "+tmp[1]+" "+tmp[3]+"...");
#endif
  send_erq(ERQ_OPEN_TCP, ({ a, b, c, d, tmp[3] / 0x100, tmp[3] & 0xFF }),
           lambda(({ 'x, 'y }), ({ #'oob_read_callback, new_fd, 'x, 'y })));
}

void listen_callback(mixed *data, int size) {
  int fd;
  if (!pointerp(data) || !sizeof(data))  // Coogan, 15-Jan-1999, emergency fix
    return;
  switch (data[0]) {
  case ERQ_OK:
    socket_ticket   = data[1..];
    tickets         = allocate(MAX_CONNECTIONS);
    incoming_datas  = allocate(MAX_CONNECTIONS);
    buffers         = allocate(MAX_CONNECTIONS);
    data_poss       = allocate(MAX_CONNECTIONS);
    data_sizes      = allocate(MAX_CONNECTIONS);
    sendings        = allocate(MAX_CONNECTIONS);
    originator_muds = allocate(MAX_CONNECTIONS);
    target_muds     = allocate(MAX_CONNECTIONS);
    direction       = allocate(MAX_CONNECTIONS);
    last_used       = allocate(MAX_CONNECTIONS);
    call_out("timeout_loop",60);
    connect();
    return;
  case ERQ_STDOUT:
    fd = member(tickets, 0);
    if (fd == -1)
      return; /* none left */
    tickets[fd] = 1;
    direction[fd] = -1; // incoming
    send_erq(ERQ_ACCEPT, socket_ticket, lambda(({ 'x, 'y }),
             ({ #'oob_read_callback, fd, 'x, 'y })));
    return;
  case ERQ_E_UNKNOWN: // Can't allocate listener socket
    oob_port++;
    call_out("listen", 2);
  }
}

void listen() {
  send_erq(ERQ_LISTEN, ({ oob_port / 0x100, oob_port & 0xFF }),
           #'listen_callback);
}

void oob_flush(int fd) {
  if (sendings[fd] || !tickets[fd])
    return;
  if (sizeof(buffers[fd])) {
    string tmp;
    int *tmp_arr;
    int size, num;
    tmp = buffers[fd][0];
    size = strlen(tmp) + 1;
    if (data_poss[fd])
      tmp_arr = to_array(tmp[data_poss[fd]..data_poss[fd] +
                             (num = MAX_SEND - sizeof(tickets[fd]) - 1)]);
    else
      tmp_arr = ({ 0, (size & 0xFFFFFF) / 0x10000,
                   (size & 0xFFFF) / 0x100, size & 0xFF }) +
                   to_array(tmp[data_poss[fd]..data_poss[fd] +
                                (num = MAX_SEND - sizeof(tickets[fd]) - 5)]);
    if (num + data_poss[fd] < strlen(tmp))
      tmp_arr = tmp_arr[0..<2];
    last_used[fd] = time();
    send_erq(ERQ_SEND, tickets[fd] + tmp_arr, lambda(({ 'x, 'y }),
             ({ #'oob_write_callback, fd, 'x, 'y })));
    sendings[fd] = 1;
  }
}

void oob_write_callback(int fd, mixed *data, int size) {
  sendings[fd] = 0;
  switch(data[0]) {
  case ERQ_OK:
    if (!data_poss[fd])
      data_poss[fd] = -4;
    data_poss[fd] += MAX_SEND - sizeof(tickets[fd]);
    if (data_poss[fd] > strlen(buffers[fd][0])) {
      data_poss[fd] = 0;
      buffers[fd] = buffers[fd][1..];
    }
    oob_flush(fd);
    return;
  case ERQ_E_WOULDBLOCK:
    call_out("oob_flush", 0, fd);
    return;
  }
}

void send_oob_tcp(string where, mixed arg) {
#ifdef OOB_DEBUG
  debug_oob("Local",where,arg);
#endif
  if (arg) {
    if (oob_queue[where])
      oob_queue[where] += ({ to_mudmode(arg) });
    else
      oob_queue[where] = ({ to_mudmode(arg) });
    if (oob_unanswered[where])
      oob_unanswered[where] += ({ arg[0] });
    else
      oob_unanswered[where] = ({ arg[0] });
  }
  if (member(originator_muds, where) == -1 &&
      member(target_muds, where) == -1) {
    if (muds[where][11]["auth"])
      send_tcp(({ "auth-mud-req", 5, MUDNAME, 0, where, 0 }));
    else {
      send_tcp(({ "oob-req", 5, MUDNAME, 0, where, 0 }));
      call_out("oob_connect", 2, where);
    }
  }
#ifdef OOB_DEBUG
  else
    debug(OOB_DEBUG,"Using already opened connection");
#endif
}

void send_oob_ack_tcp(string where, mixed arg) {
  int fd;

#ifdef OOB_DEBUG
  debug(OOB_DEBUG,"Expedited acknowledge");
  debug_oob("Local",where,arg);
#endif

  for (fd = sizeof(direction); fd--;) {
    if (((direction[fd] > 0) && (target_muds[fd] == where) ||
         (direction[fd] < 0) && originator_muds[fd] == where)) {
      buffers[fd] += ({ to_mudmode(arg) });
      oob_flush(fd);
      break;
    }
  }
}
   
void close_oob_connection(int fd) {
  m_delete(oob_unanswered,originator_muds[fd] || target_muds[fd]);
  send_erq(ERQ_KILL, tickets[fd], 0);
  tickets[fd] = 0;
  originator_muds[fd] = 0;
  target_muds[fd] = 0;
  direction[fd] = 0;
  last_used[fd] = 0;
}

void handle_oob_answered(string mud) {
  oob_unanswered[mud] = oob_unanswered[mud][1..];
}

void handle_oob_data(int fd, mixed *lpc_data) {
  string queued_pkt;
  string mud;
  mixed tmp; // Perle 26-Jul-1999
    
  switch(lpc_data[0]) {
  case "oob-begin":
    if (direction[fd] > 0) {
#ifdef OOB_DEBUG
      debug(OOB_DEBUG,oob_queue);
      debug(OOB_DEBUG,target_muds[fd]);
#endif
      if (tmp = oob_queue[target_muds[fd]]) {
        buffers[fd] += tmp;
        efun::m_delete(oob_queue, target_muds[fd]);
      }
      buffers[fd] += ({ to_mudmode(({ "oob-end", MUDNAME })) });
      oob_flush(fd);
    }
    else {
#ifdef SERVICE_AUTH
      string originator;
      if (originator = our_auth_tokens[lpc_data[3]])
        originator_muds[fd] = originator;
      else
        close_oob_connection(fd);
#else
      originator_muds[fd] = lpc_data[1];
#endif
      buffers[fd] += ({ to_mudmode(({ "oob-begin", MUDNAME, 0, 0 })) });
      oob_flush(fd);
    }
    return;
  case "oob-end":
    if (direction[fd] > 0) {
      if (tmp = oob_queue[target_muds[fd]]) {
        buffers[fd] += tmp + ({ to_mudmode(({ "oob-end", MUDNAME })) });
        efun::m_delete(oob_queue, target_muds[fd]);
        oob_flush(fd);
      }
      else
        close_oob_connection(fd);
    }
    else if (direction[fd] < 0) {
      if (tmp = oob_queue[originator_muds[fd]]) {
        buffers[fd] += tmp;
        efun::m_delete(oob_queue, originator_muds[fd]);
      }
      buffers[fd] += ({ to_mudmode(({ "oob-end", MUDNAME })) });
      oob_flush(fd);
    }
    return;
  default:
    if (!direction[fd])
      return;
  }

  /*
   * Handle incoming requests
   */

  switch(lpc_data[0]) {
  case "mail":
    IMUD3"/mail"->receive_mail(lpc_data,
                               originator_muds[fd] || target_muds[fd]);
    return;
  case "file-list-req":
    receive_file_list_request(lpc_data);
    return;
  case "file-put":
    receive_file_put_request(lpc_data);
    return;
  case "file-get-req":
    receive_file_get_request(lpc_data);
    return;
  }

  /*
   * It wasn't a request. Check for a valid reply code.
   */
  
  mud = originator_muds[fd] || target_muds[fd];
  queued_pkt = oob_unanswered[mud][0];
  
  switch(lpc_data[0]) {
  case "mail-ack":
    if (queued_pkt == "mail")
      handle_oob_answered(mud);
    IMUD3"/mail"->receive_mail_acknowledge(lpc_data, mud);
    return;
  case "file-list-reply":
    if (queued_pkt == "file-list-req")
      handle_oob_answered(mud);
    receive_file_list_reply(lpc_data);
    return;
  case "file-put-ack":
    if (queued_pkt == "file-put")
      handle_oob_answered(mud);
    receive_file_put_acknowledge(lpc_data,
                                 originator_muds[fd] || target_muds[fd]);
    return;
  case "file-get-reply":
    if (queued_pkt == "file_get")
      handle_oob_answered(mud);
    receive_file_get_reply(lpc_data,
                           originator_muds[fd] || target_muds[fd]);
    return;
  default:
#ifdef OOB_DEBUG
    debug(OOB_DEBUG, lpc_data);
#endif
  }
}

void timeout_loop() {
  int fd, dir;
  string where;
  for (fd=sizeof(last_used); fd--;) {
    if (tickets[fd] && last_used[fd] && last_used[fd]+TIME_OUT < time()) {
      where = ((dir = direction[fd]) < 0)
               ?  originator_muds[fd] : target_muds[fd];
      close_oob_connection(fd);
      if (oob_queue[where]) {
#ifdef OOB_DEBUG
        debug(OOB_DEBUG,"Trying to reopen connection...");
#endif
        call_out("send_oob_tcp", 20, where);
      }
    }
  }
  call_out("timeout_loop", TIME_OUT/2);
}

#if 1  // this is intended - coogan, 22-May-2002
void create() {
  int i;
  string *names;

  "pf-colours"::create();
  restore_object(SAVE_INTERMUD);
  i = sizeof(names = m_indices(muds));
  while (i--)
    mud_names[implode(explode(lower_case(names[i]), " "), ".")] = names[i];
  listen();
  oob_port = PORT_OOB;
}
#endif

// help functions called by the modules
void remove_channel(string channel) {
  m_delete(channels, channel);
  save_me();
}

#endif

