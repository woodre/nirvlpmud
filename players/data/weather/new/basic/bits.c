/*
 * /basic/bits.c by Alfe for Tubmud 1997-Sep-16
 *
 * This is a basic class for storing more bits than the efuns
 * {test,set,clear}_bit() can handle.
 */

#define LIMIT 1024

//
// possible values for the data:
// int 0: no bit set
// string: bits 0 up to LIMIT-1 in use
// array:
//   element is int 0: no bit of this range is set
//   element is string: bits of this range in use
//

private mixed prepare_current(mixed current,int number,status for_query) {
  mixed h;
  if (!current)
    if (for_query)
      return 0;
    else  // not for query
      if (number < LIMIT)
        return "";
      else {  // number >= LIMIT
        h = allocate(number/LIMIT + 1);
        h[number/LIMIT] = "";
        return h;
      }
  else if (stringp(current))
    if (number < LIMIT)
      return current;
    else  // number >= LIMIT
      if (for_query)
        return 0;
      else {  // not for query
        h = allocate(number/LIMIT + 1);
        h[0] = current;
        h[number/LIMIT] = "";
        return h;
      }
  else if (pointerp(current))
    if (sizeof(current) > number/LIMIT) {  // array long enough?
      if (!current[number/LIMIT])  // element is 0?
        if (for_query)
          return 0;
        else  // not for query
          current[number/LIMIT] = "";
      return current;
    }
    else  // array too short
      if (for_query)
        return 0;
      else {  // not for query
        current += allocate(number/LIMIT + 1 - sizeof(current));
        current[number/LIMIT] = "";
        return current;
      }
  else  // strange value
    throw(1);  // bad arg 1
}

mixed set_bit(mixed current,int number) {
  mixed h;
  if (h=catch(current=prepare_current(current,number,0)))
    raise_error("Bad argument " + h + " to set_bit()\n");
  if (stringp(current))
    return efun::set_bit(current,number);
  else {  // must be pointer
    current[number/LIMIT] = efun::set_bit(current[number/LIMIT],
                                          number % LIMIT);
    return current;
  }
}

mixed clear_bit(mixed current,int number) {
  mixed h;
  if (h=catch(current=prepare_current(current,number,0)))
    raise_error("Bad argument " + h + " to clear_bit()\n");
  if (stringp(current))
    return efun::clear_bit(current,number);
  else {  // must be pointer
    current[number/LIMIT] = efun::clear_bit(current[number/LIMIT],
                                            number % LIMIT);
    return current;
  }
}

status test_bit(mixed current,int number) {
  mixed h;
  if (h=catch(current=prepare_current(current,number,1)))
    raise_error("Bad argument " + h + " to test_bit()\n");
  if (!current)
    return 0;
  if (stringp(current))
    return efun::test_bit(current,number);
  else  // must be pointer
    return efun::test_bit(current[number/LIMIT], number % LIMIT);
}
