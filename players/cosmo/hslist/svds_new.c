/*
   This object uses the data collected by exp_store.c, to track players
   who have earned the most experience during the current reboot.  A
   list of the all-time greatest scores is also maintained. The view()
   function allows players to see the top scores for the current reboot
   period and the all-time top scores.
      Thanks to Snow, Mythos, Beck, Sado, Pavlik and Wizardchild
      for various implementation help.  Thanks to Bastion
      for leaving his mapping functions in /open.
              - Cosmo, December 1998
*/

/* Modified by Rumplemintz - 2014 - cleaned up - original file backed up */

inherit "/players/cosmo/hslist/vdsfuns.c";

#include <ansi.h>

#define CURRENT "/obj/exp_store.c"
#define BASE    "players/cosmo/hslist/"
#define SYM     "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"

string *at_names;   /* Array of names of highest all-time scores */
int    *at_scores;  /* Array of amount of highest all-time scores */

string current_year;   /* Holds the current year as a string */

void display_map(mapping m);

/*-------------------------------------------------------------------*/
void reset(status arg) {
  string day, month, year;
  int date, hour, minute, second;
  int blah, x;

  if(arg) return;

  /* Determine which reboot cycle we are in. The a.m. reboot cycle
     is about 7.5 hours. */
#if 0
  blah = sscanf(ctime(time()),
                "%s %s %d %d:%d:%d %s",
                day, month, date, hour, minute, second, year);
  if (hour == 18) x = 42300; /* Evening reboot period, 11.75 hours */
  else x = 43200; /* Day reboot period, 12 hours */
  current_year = year;
#else
  if (sscanf(ctime(), "%s %s %d %d:%d:%d %s",
                       day, month, date, hour, minute, second, year) != 7) {
    if (find_player("rumplemintz"))
      tell_object(find_player("rumplemintz"), 
                  "Something went wrong with the sscanf call, aborting.\n");
  }
  if (hour == 18) x = 42300;  /* Evening reboot preiod, 11.75 hours */
  else            x = 43200;  /* Day reboot period, 12 hours */
  current_year = year;
  if (find_player("rumplemintz"))
    tell_object(find_player("rumplemintz"),
                "HSLIST: current_year set to " + current_year + ".\n");

#endif
}

/*-------------------------------------------------------------------*/
string short() {
  return "MASTER VDS [" + HIR + "Do not destruct!!" + NORM + "]";
}

void long() {
  write("\n" +
        short() +
        "\nThe master VDS.  Keep this in Cosmo's workroom.\n");
  switch(this_player()->query_real_name()) {
    case "cosmo":
    case "boltar":
    case "rumplemintz":
    case "sparrow":
      write("You can also use the " + BOLD + "alltime" + NORM +
            " function.\n");
      break;
  }
}

int id(string str) {
  return str == "VDS" ||
         str == "screen" ||
         str == "display" ||
         str == "vds" ||
         str == "display screen";
}

int query_weight() { return 1000; }
int query_value() { return 0; }
status get() { return 0; }

/*-------------------------------------------------------------------
 Purpose: Check to see if any of the current scores qualify for the
 alltime list.
 ********************************************************************
 05-27-2016 Gnar - This is confusing as hell. This looks like it
                   should update the alltime list, but it only
                   updates the list for the current year. This is 
                   called by obj/shut just before reboot. I have 
                   compiled all of the exp from all the years and 
                   updated the alltime list. Now I will update this 
                   to actually update the alltime save file when 
                   somone is updated to the current year.
**********************************************************************
*/
int update_alltime( string file ) {
  int x, pos, update_flag, max;
  mapping current_map;
  mixed *current_array;

  if( !file ) {
    file = current_year;
  }
  
  /** Max exp gets a few more slots **/
  if( file == "alltime" ) {
    max = 25;
  }
  else {
    max = 15;
  }

  /* Get the all-time names and scores */
  log_file("COSMO","XXXX");
  at_names =  ({ });  /* zero out */
  at_scores = ({ });  /* zero out */

  if (!restore_object(BASE + file)) {
    log_file("COSMO", "Failure to restore "+file+".\n");
    at_names=({"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o"});
    at_scores=({15,14,13,12,11,10,9,8,7,6,5,4,3,2,1});
  }
  else
    log_file("COSMO", "Restored "+file+" OK.\n");
  /* Get the current names and scores */
  current_map =   ([ ]); /* zero out */
  current_map = (mapping)CURRENT->query_map();
  current_array = ({ });
  current_array = deconstruct_mapping(current_map);
  log_file("COSMO","YYYY\n");
  /* Step through the current scores and update the alltime
     scores, as necessary */
  for (x=1; x<sizeof(current_array); x=x+2) {
    pos = check_scores(current_array[x], at_scores);
    if (pos>-1 && pos<max) {
      if(current_array[x] > at_scores[pos]) {
        /* Set the flag if someone is inserted into the current year */
        update_flag = 1;
        at_names = update_array(pos, current_array[x-1], at_names);
        at_scores = update_array(pos, current_array[x], at_scores);
        log_file("COSMO", ctime() + " GOT TO SAVE\n");
        save_object(BASE+file);
      }
    }
  }
  /** Recursively call function to update the real alltime list **/
  log_file("COSMO","update alltime check: "+update_flag+":"+file+"\n");
  if( update_flag && file != "alltime" ) {
    log_file("COSMO","calling update ALLTIME\n");
    update_alltime( "alltime" );
  }
  log_file("COSMO","call-ouit\n");
  call_out("update_alltime", 10800);
  return 1;
}

/*-------------------------------------------------------------------*/
void init() {
  add_action("view", "view");
  switch(this_player()->query_real_name()) {
    case "boltar":
    case "angel":
    case "rumplemintz":
    case "sparrow":
    case "dragnar":
      add_action("alltime","alltime");
  }
}

int view(string str) {
  int x;
  mapping current_map;
  string header;

  if (!str || (str != "current" && !restore_object(BASE + str)) ) {
    write("Usage: 'view current' or 'view alltime' or 'view <year>'\n" +
          "       Where year = 1999 or later.\n");
    return 1;
  }

  say(this_player()->query_name() + " looks at the virtual display.\n");
  write("\n" + HIR + SYM + NORM + "\n");
  write("  " + YEL + "Top Score for " );
  switch( str ) {
    case "current":
      write( "Current Reboot Period" );
      break;
    case "alltime":
      write( "All Time" );
      break;
    default:
      write( str );
      break;
  }
  write( NORM + "\n" );
  write(HIR + SYM + NORM + "\n");
  write(BOLD + "\tPLAYER\t\tEXPERIENCE" + NORM + "\n");
  if (str == "current") {
    current_map = ([ ]);
    current_map = (mapping)CURRENT->query_map();
    display_map(current_map);
  } else {
    at_names  = ({ }); /* zero out */
    at_scores = ({ }); /* zero out */
    restore_object(BASE + str);
    for (x=0; x<sizeof(at_names); x++)
      write("\t" + pad(at_names[x],16) + ralign(comma_number(at_scores[x]),10) + "\n");
  }
  /* Print a footer */
  write(HIR + SYM + NORM + "\n");
  return 1;
}

/*
 * Function: display_map
 * Purpose: Write the sorted keys and values of a mapping in tabular form.
 */
void display_map(mapping m) {
  int x, y, asize, *values;
  string *indices, *s_names;

  indices = m_indices(m);
  values =  m_values(m);
  values =  sort_array(values);
  s_names = allocate(sizeof(indices));
  for (x=0; x<sizeof(indices); x++) {
    y = 0;
    while((y<sizeof(values)) && (m[indices[x]]!=values[y])) y++;
    s_names[y] = indices[x];
    values[y] = -1;
  }
  values = m_values(m);
  values = sort_array(values);
  if (sizeof(s_names) < 15)  asize = sizeof(s_names);
  else asize = 15;
  for (x=0; x<asize; x++)
      write("\t" + pad(s_names[x],16) + ralign(comma_number(values[x]),10)+"\n");
}

int alltime(string str) {
  if (str == "update") {
    update_alltime( current_year );
    write("Update complete... alltime scores saved.\n");
    return 1;
  }

  else  if (str == "reset") {
    at_names=({"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o"});
    at_scores=({15,14,13,12,11,10,9,8,7,6,5,4,3,2,1});
    save_object(BASE+current_year);
    write("Alltime scores reset.\n");
    return 1;
  }
  else if (str == "backup") {
    command("cp /players/cosmo/hslist/alltime.o /players/cosmo/hslist/alltime.bak");
    write("Backup complete.\n");
    return 1;
  }
  else {
    write("<alltime update/reset/backup>\n");
    return 1;
  }
}

/*added by wocket */
void remove_object(object prev) {
  update_alltime( current_year );
}
