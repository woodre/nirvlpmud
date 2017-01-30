/* Created by Cosmo, 12/4/98
 * Revised by Cosmo, 4/14/99
 * Approved by Snow, 4/??/99
 * 3-14-01 Verte added Exp Contest stuff
 * 5-23-01 Verte rm'd 100k cap, changed logging to 100k + 
 * 10/16/2013 - Added exclusion list - Rumplemintz
 * 06/27/2014 - Added topkill - Gnar
 */

#define TOP_KILL_SIZE 20
#define MYFUN "/obj/user/vdsfuns.c"
#define TP this_player()

mapping delta_map; /* Mapping of current names and exp */
mixed *top_kills;  /* Array of Top Kills */
status toggle;     /* On/off switch in case of high load */
mapping contest;   /* Mapping for Experience Contest */
status Contest_On; /* On/off switch for Contest */

string *exclusion;  /* New array for excluded characters - Wizzies - add
                        your test/not-test to this list! - Rumplemintz */

/*-------------------------------------------------------------------*/
reset(arg) {
  if(arg) return;
  delta_map = ([]);
  contest = ([ ]);
  top_kills = ({ });
  toggle = 1;

/* Add names here to exclude from showing up on exp lists */
  exclusion = ({
    "guest",
    "nosferatu",
  });
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
collector(string pname, int amt) 
{
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
   /* and players on the exclusion list - Rumplemintz */
  if(TP && (TP->query_real_name() == "guest" ||  TP->is_testchar() ||
            member(exclusion, TP->query_real_name()) != -1))
    return 1; /* Added this return - Rumplemintz */
  if(pname && find_player(lower_case(pname)))
    if(find_player(lower_case(pname))->query_level() > 19)
      return 1;
  if(amt < 0) return 1;
   /* Log any really big experience gains */
  if(amt > 100000)
    log_file("BIGEXP", pname+" gained "+amt+" exp, at "+ctime(time())+"\n");
   /* If the experience contest has been activated and the player
      has registered, accumulate the am't to a map */
  if(Contest_On)
    if(MYFUN->member(contest, pname))
      contest[pname] += amt;
   /* Create a new record for the player, if there isn't one already */
  if(!MYFUN->member(delta_map, pname)) delta_map += ([pname:amt]);
   /* The player's record already exists; add the experience to it */
  else delta_map[pname] += amt;
  return 1;
}

int is_member( mixed *myarr, string str ) {
  int i, idx;

  idx = -1;

  if(!myarr)
    return idx;

  for( i=0; i < sizeof(myarr); i++ ) {
    idx = member( myarr[i], str );
    if(idx >= 0 )
      return i;
  }
  return idx;
}

int kill_sort(mixed *a, mixed *b) {
  /****************************************
   * Sort by date if exp amt is the same
   ****************************************/
  if( a[1] == b[1] )
    return a[3] > b[3];
  else
    return  a[1] < b[1];
}

/*
 * Function: kill_collector
 * Purpose: This function is called from  player.c.  The
 * player's name, the amount kill, mob name, and time is passed from
 * add_exp().  This function places those variables in an array.
 */
kill_collector(string pname, int amt, int npc_name, int time )
{
   int s, sort_flag;

   /* Safety switch */
  if(!toggle) return 1;

   /* Avoid bogus data */
  if (!stringp(pname) || !intp(amt) || !stringp(npc_name)) return 1;
   /* Avoid kills that comes from wizards or monsters */
  if(TP) {
     if(TP->query_interactive() && TP->query_level() > 19)
     return 1;
  } 
   /* Avoid kills gained by wizards */
   /* and players on the exclusion list - Rumplemintz */
  if(TP && (TP->query_real_name() == "guest" ||  TP->is_testchar() ||
            member(exclusion, TP->query_real_name()) != -1))
    return 1; /* Added this return - Rumplemintz */
  if(pname && find_player(lower_case(pname)))
    if(find_player(lower_case(pname))->query_level() > 19)
      return 1;
  if(amt < 0) return 1;
   
  s = sizeof( top_kills );
  if( s < TOP_KILL_SIZE ) { 
    top_kills += ({ ({ pname, amt, npc_name, time}) });
    sort_flag = 1;
  }
  else if( amt > top_kills[s-1][1] ) {
    top_kills[s-1][0] = pname;
    top_kills[s-1][1] = amt;
    top_kills[s-1][2] = npc_name;
    top_kills[s-1][3] = time;
    sort_flag = 1;
  }

  if( sort_flag )
    top_kills = sort_array( top_kills, "kill_sort", this_object() );

  return 1;
}

/*
 * Function: query_map()
 * Purpose: Returns the mapping defined above.  This function is called
 * by /players/cosmo/hslist/vds.c
 */
mapping query_map() { return delta_map; }

/*
 * Function: query_kills_map()
 * Purpose: Returns the array of topkills.
 */
mixed * query_kills() { return top_kills; }

/*
 * Function: query_player_exp()
 * Purpose: Returns the exp value for the player
 */
int query_player_exp( string pname ) {
  int ret;
  ret = delta_map[ pname ];
  return ret ? ret : 0;
}

/* following stuff is for the xp contest */

void
add_contestant(string Name)
{
    if(MYFUN->member(contest, Name))
      return;

    else contest[Name] = 0;
}

void
activate_contest(int x)
{
    Contest_On = x;
}

mapping
query_contest()
{
    return contest;
}
