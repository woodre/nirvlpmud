/*
    basic/open.c - generic open/close logic
    Feb 1992 by marion@cs.tu-berlin.de
*/

private int open_state;

int query_open() {
  return open_state;
}

int toggle_open() { // Ugh Apr-07-1999 -- changed from toggle() (overload)
  open_state = !open_state;
  return open_state;
}

int toggle() {
  return toggle_open();
}

// next one added for better persistence handling, Coogan, 05-Sep-1997
void set_open_state(status o) {
  open_state = o;
}

status query_open_state() {  // Alfe 1997-Sep-10
  return query_open();
    // Ugh Apr-07-1999 -- changed from open_state (for overload)
}

int open() {
#if 0 // Ugh Apr-09-1999
  if (open_state)  // Coogan, 09-Apr-1999 - changed from query_open()
#else
  if (query_open())
#endif
    return 0;
  toggle_open(); // Ugh Apr-07-1999 -- changed from open_state = 1
  return 1;
}

int close() {
#if 0 // Ugh Apr-09-1999
  if (!open_state)  // Coogan, 09-Apr-1999 - changed from !query_open()
#else
  if (!query_open())
#endif
    return 0;
  toggle_open(); // Ugh Apr-07-1999 -- changed from open_state = 0
  return 1;
}
