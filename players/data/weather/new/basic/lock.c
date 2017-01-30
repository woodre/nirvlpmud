/*
    basic/lock.c - generic lock/unlock logic
    Feb 1992 by marion@cs.tu-berlin.de
*/

private int lock_state;

int query_lock() {
  return lock_state;
}

int toggle_lock() {
    // Ugh Apr-07-1999 -- changed from toggle() (for overloading)
  lock_state = !lock_state;
  return lock_state;
}

int toggle() {
  return toggle_lock();
}

// next one added for better persistence handling, Coogan, 05-Sep-1997
void set_lock_state(status l) {
  lock_state = l;
}

status query_lock_state() {  // Alfe 1997-Sep-10
  return query_lock();       // Ugh Apr-07-1999 -- changed from lock_state
}

int lock() {
#if 0 // Ugh Apr-09-1999
  if (lock_state)  // Coogan, 09-Apr-1999 - changed from query_lock()
#else
  if (query_lock())
#endif
    return 0;
  toggle_lock(); // Ugh Apr-07-1999 -- changed from lockstate = 1
  return 1;
}

int unlock() {
#if 0 // Ugh Apr-09-1999
  if (!lock_state)  // Coogan, 09-Apr-1999 - changed from !query_look()
#else
  if (!query_lock())
#endif
    return 0;
  toggle_lock(); // Ugh Apr-07-1999 -- changed from lockstate = 0
  return 1;
}

