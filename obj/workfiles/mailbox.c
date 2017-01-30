/*
 * This is the mailbox
 * Rumplemintz
 */

#include <wizlevels.h>
#include <prop/player.h>
#include <mail.h>
#include <regexps.h>
#include <is_wizard.h>
#include <limits.h>
#include <udp.h>
#include <time_units.h>

#define NEW       MAIL_NEW
#undef SENDER  // already devined in udp.h, but we want something else
#define SENDER    MAIL_SENDER
#define DATE      MAIL_DATE
#define SUBJECT   MAIL_SUBJECT
#define CC        MAIL_CC
#define INFO      MAIL_INFO
#define RECEIVERS MAIL_RECEIVERS

#define DEFRAGMENTATE_RATE 20

#define FORWARD_ALIAS ".forward"
#define FORWARD_DELAY (10 * ONE_SECOND)
#define AUTO_FORWARD_MAIL_COOKIE "IGNORE FOLLOWING LINES! \b\n"

inherit "basic/database";
static variables inherit "basic/name";
static variables inherit "basic/editor";
static variables inherit "basic/path";

