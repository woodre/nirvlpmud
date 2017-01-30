inherit "basic/create";

#include <time_units.h>
#include <server.h>  // Coogan, 12-Feb-2001

void create() {
  int now, offset;
  if (clonep())
    return;
  now = (time() + ONE_HOUR) % ONE_DAY;
  // added ONE_MINUTE below, Coogan, 16-Aug-2004
  offset = (ONE_DAY + 6 * ONE_HOUR + ONE_MINUTE - now) % ONE_DAY;
  call_out("start_gc", offset);
}

static void start_gc() {
  if (find_call_out("start_gc") < 0)
    call_out("start_gc", ONE_DAY);
  enable_commands(); // Ensure shout() goes to the player who started this.
#ifdef TUBMUD  // changed ifndef SERENDIPITY to TUBMUD, Coogan, 18-Jan-2001
#  if 0  // Coogan, 03-Nov-2001
#  define REBOOT_ON_MONDAY_MORNING
#  else
//   return;  // we don't want to GC due to a driver bug
#  endif
#endif

#ifdef REBOOT_ON_MONDAY_MORNING  // Alfe 97-Nov-9
  if (ctime()[0..2] == "Sun") {  // we want to reboot on Monday morning, so we
                                 // start the Armageddon on Sunday morning.
    "etc/shut"->start_armageddon(ONE_DAY / ONE_MINUTE,  // it is measured in
                                                        // minutes. *shrug*
                                 "automatic reboot on Monday morning (GMT)");
  }
#endif
  call_out("do_gc", ONE_MINUTE);
  shout("Gamedriver shouts: Starting garbage collection in 60 seconds...\n");
}

static void do_gc() {
  log_file("GCOLLECT", ctime() + ": Garbage collection started.");
  shout("Gamedriver shouts: Starting garbage collection now!\n"
        "  Please hold on, this can take several minutes.\n");
  call_out(#'garbage_collection, 0);
}

