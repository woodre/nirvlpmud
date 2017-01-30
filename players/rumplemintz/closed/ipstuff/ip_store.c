/*
 * IP Address storage
 */

mapping ip_map;     /* Mapping of current names and IP address */


void reset(status arg) {
  if (arg)
    return;
  ip_map = ([ ]);
}

/* IP collector */
int collector(string user, string ipaddr) {
  if (!stringp(user) || !stringp(ipaddr)
    return 1;
  if (!ipaddr)
    return 1;
  if (!"/players/rumplemintz/closed/ipstuff/ipfuns"->member(ip_map, user))
    ip_map += ([user, ipaddr]);
  else
    ip_map[user] += ipaddr;
  return 1;
}

mapping query_map() { return ip_map; }
