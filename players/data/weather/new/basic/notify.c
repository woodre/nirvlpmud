#include <server.h>

status query_no_notify() {
  return 0;  /* default is notifying */
}

void reset(int arg) {
  if (query_no_notify())
    return;
  SE_NOTIFIER->notify_reset(this_object(),arg);
}

mapping query_notifies() {
  mixed *result;
  if (query_no_notify())
    return 0;
  // Ugh Jan-24-1996
  return SE_NOTIFIER->query_notifies(this_object());
}
