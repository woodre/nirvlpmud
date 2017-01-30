#pragma strong_types

#include <erq.h>
#include <time_units.h>
#include <libs.h>
#include <udp.h>

#define DNEWSFILE       "/open/tmp/dnews.txt"

inherit "basic/encoding";
inherit "basic/create";

string *news;

mapping line_cache = ([]);

mapping query_line_cache() { return line_cache; }

private void send_news_line(int index) {
  string line;
  if (!member(line_cache, news[index])) {
    line = "*** Neu! ***   " + news[index];
    // throw out all cached lines which are older than three hours:
    line_cache = filter(line_cache, (: $2 > time() - 3 * ONE_HOUR :));
  }
  else {
    line = news[index];
  }
  line_cache[news[index]] = time();  // add line to cache
#if 0  // for local only
  LIB_CHANNELS->channel_shout("d-news", line, "d-news@Tubmud");
#else
  INETD->do_send_udp(0, ([ REQUEST  : "channel",
                           SENDER   : "d-news",
                           "CHANNEL": "d-news",
                           "CMD"    : 0,
#if 0  // this takes too much time
                           DATA     : mud2ascii(line),
#else
                           DATA     : line,
#endif
                        ]));
#endif 
}

static void send_news(int index) {
  int sn;
  sn = sizeof(news);
  if (!news || index < 0 || index >= sn)
    return;
  send_news_line(index);
  if (index == sn - 1)  // this was the last line
    return;
  if (index == 0)
    index += 1;
  else {
    send_news_line(index+1);
    index += 2;
  }
  call_out("send_news", 10, index);
}

// read the file /open/tmp/dnews.txt and prepare the text for sending
private int evaluate_news() {
  if (file_size(DNEWSFILE) <= 0)  // no news ..
    return 0;
  news = explode(LIB_FILE->read_file_in_string(DNEWSFILE), "\n") - ({ "" });
  return 1;
}

private void erq_execute_callback(mixed *data, mixed size) {
  if (!pointerp(data) || !sizeof(data)) {
    log_file("D-NEWS", ctime() + ": "
             "Something went wrong with the erq while executing the dnews.\n");
    return;
  }
  switch (data[0]) {
  case ERQ_OK:
    log_file("D-NEWS", ctime() + ": "
             "Erq command executed and returned an exit value of " +
             data[1] + ".\n");
    break;
  case ERQ_E_ILLEGAL:
    log_file("D-NEWS", ctime() + ": "
             "Command from outside ERQ_DIR requested.\n");
    break;
  case ERQ_E_FORKFAIL:
    log_file("D-NEWS", ctime() + ": "
             "Command could not be forked, errno " + data[1] + ".\n");
    break;
  case ERQ_SIGNALED:
    log_file("D-NEWS", ctime() + ": "
             "Command terminated the signal " + data[1] + ".\n");
    break;
  case ERQ_E_NOTFOUND:
    log_file("D-NEWS", ctime() + ": "
             "No process found to wait() for.\n");
    break;
  case ERQ_E_UNKNOWN:
    log_file("D-NEWS", ctime() + ": "
             "Unknown exit condition from wait().\n");
    break;
  }
  if (evaluate_news())  // try it anyway
    send_news(0);
}

void do_get_dnews() {
  log_file("D-NEWS", ctime() + ": do_get_dnews() started\n");
  send_erq(ERQ_EXECUTE,
           "dnews",
           #'erq_execute_callback);
  return;
}

static void get_news() {
  if (find_call_out("get_news") < 0)
    call_out("get_news", ONE_HOUR - (time() % ONE_HOUR) + 5 * ONE_MINUTE);

  call_out("do_get_dnews", ONE_MINUTE);
}

void create() {
  if (clonep())
    return;
  call_out("get_news", ONE_HOUR - (time() % ONE_HOUR) + 5 * ONE_MINUTE);
}

void notify_destruct() {
  while (remove_call_out("do_get_news") != -1)
    ;
  while (remove_call_out("get_news") != -1)
    ;
}

