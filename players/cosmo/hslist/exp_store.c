/* Created by Cosmo, 12/4/98
 * Revised by Cosmo, 4/14/99
 * Approved by Snow, 4/??/99
 */

#define MYFUN "/players/cosmo/hslist/vdsfuns.c"
#define TP this_player()

mapping delta_map; /* Mapping of current names and exp */
status toggle;     /* On/off switch in case of high load */

/*-------------------------------------------------------------------*/
reset(arg) {
  if(arg) return;
  delta_map = ([]);
  toggle = 1;
}

set_on() {
   /* Allow senior wizards to turn this thing off, if necessary */
  if (!TP) return;
  if(TP->query_level() > 99 && query_ip_number(TP)) {
    toggle = !toggle;
    if(!toggle) tell_object(TP,"Experience collector turned off.\n");
    else tell_object(TP,"Experience collector turned on.\n");
  }
}

/*
 * Function: collector
 * Purpose: This function is called from add_exp() in player.c.  The
 * player's name and the amount of gained experience is passed from
 * add_exp().  This function places those variables in a mapping.
 */
collector(string pname, int amt) {
   /* Safety switch */
  if(!toggle) return 1;
   /* Avoid bogus data */
  if (!stringp(pname) || !intp(amt)) return 1;
   /* Avoid experience that comes from wizards or monsters */
  if(TP) {
     if(TP->query_interactive() && TP->query_level() > 19)
     return 1;
  }
   /* Avoid experience gained by wizards */
  if(find_player(lower_case(pname))->query_level() > 19) return 1;
   /* Avoid negative experience and guild transfers */
  if(amt < 0) return 1;
   /* Log any really big experience gains */
  if(amt > 10000)
    log_file("BIGEXP", pname+" gained "+amt+" exp, at "+ctime(time())+"\n");
   /* Create a new record for the player, if there isn't one already */
  if(!MYFUN->member(delta_map, pname)) delta_map += ([pname:amt]);
   /* The player's record already exists; add the experience to it */
  else delta_map[pname] += amt;
  return 1;
}

/*
 * Function: query_map()
 * Purpose: Returns the mapping defined above.  This function is called
 * by /players/cosmo/hslist/vds.c
 */
mapping query_map() { return delta_map; }
