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

inherit "/players/cosmo/hslist/vdsfuns.c";

#include "/players/cosmo/closed/ansi.h"
#define CURRENT "/obj/exp_store.c"
#define ALLTIME "players/cosmo/hslist/alltime2"
#define SYM "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
#define TP this_player()

string *at_names;   /* Array of names of highest all-time scores */
int *at_scores;     /* Array of amount of highest all-time scores */

/*-------------------------------------------------------------------*/
reset(arg) {
string day, month, rest, junk1, junk2;
int blah, date, hour, x;
  if(arg) return;

  /* Determine which reboot cycle we are in.
     The a.m. reboot cycle is about 7.5 hours. */
  blah=sscanf(ctime(time()),"%s %s %d %d:%s",day,month,date,hour,rest);
  if(hour<21) x=28800; else x=27000;
  write(x+"\t\t"+hour+"\n");

  /* Setup a callout to update the all-time scores right before reboot */
  if(sscanf(file_name(this_object()), "%s#%s", junk1, junk2) != 2)
    call_out("update_alltime", x);
}

/*-------------------------------------------------------------------*/
short() { return "MASTER VDS2 ["+HIR+"Do not destruct!!"+NORM+"]"; }

long() {
  write("\n"+short()+"\n"+
    "The master VDS2.  Keep this in Cosmo's workroom.\n"+
    BOLD+"Read"+NORM+" the "+BOLD+"sign"+NORM+" for operating instructions.\n"+
    "\n");
}

id(str) { return str == "testvds"; }

query_weight() { return 1000; }
query_value() { return 0; }
get() { return 0; }

/*-------------------------------------------------------------------
 Purpose: Check to see if any of the current scores qualify for the
 alltime list.
*/
update_alltime() {
int x, pos;
mapping current_map;
mixed *current_array;

  /* Get the all-time names and scores */
  at_names = ({ }); /* zero out */
  at_scores = ({ }); /* zero out */
  restore_object(ALLTIME);

  /* Get the current names and scores */
  current_map = ([ ]); /* zero out */
  current_map = CURRENT->query_map();
  current_array = ({ });
  current_array = deconstruct_mapping(current_map);

  /* Step through the current scores and update the alltime
     scores, as necessary */
  for (x=1; x<sizeof(current_array); x=x+2) {
    pos = check_scores(current_array[x], at_scores);
    if (pos>-1 && pos<15) {
      at_names = update_array(pos, current_array[x-1], at_names);
      at_scores = update_array(pos, current_array[x], at_scores);
      save_object(ALLTIME);
    }
  }
  return 1;
}

/*-------------------------------------------------------------------*/
init() {
  add_action("read","read");
  add_action("browse","browse");
  if(this_player()->query_real_name() == "cosmo")
    add_action("alltime","alltime");
}

read(str) {
  if(str=="sign") {
    write("This wall-size screen tracks the players that have earned the\n"+
      "most experience since the last reboot. You may "+BOLD+"view"+NORM+
      " the "+BOLD+"current"+NORM+"\nscores for this reboot period, or the "+
      BOLD+"alltime"+NORM+" scores achieved\nduring one reboot period.\n"+
      "NOTES:\n"+
      "  1. All-time score statistics began on 4/29/99.\n"+
      "  2. The all-time scores are updated right before reboot.  Any\n"+
      "     experience earned after Armageddon appears is not counted.\n"+
      "  3. Mail any comments to Cosmo.\n");
    return 1;
  }
  else {
    write("You may look at the note, or read the sign.\n");
    return 1;
  }
}

browse(str) {
int x;
mapping current_map;

  /* Print some headers to make it look nice */
  if (str=="current" || str=="alltime") {
    say(TP->query_name() + " looks at the virtual display.\n");
    write("\n"+HIR+SYM+NORM+"\n");
    if (str=="current")
      write("     "+YEL+"Scores for Current Reboot Period"+NORM+"\n");
    else write("\t     "+YEL+"All-Time Scores"+NORM+"\n");
    write(HIR+SYM+NORM+"\n");
    write(BOLD+"\tPLAYER\t\tEXPERIENCE"+NORM+"\n");

    /* Get the current scores, stick them in a mapping, and 
       call a function which will sort and display them */
    if (str=="current") {
      current_map = ([ ]); /* zero out */
      current_map = CURRENT->query_map();
      display_map(current_map);
    }

    /* Get the all-time names and scores, and display them */
    else {
      at_names = ({ }); /* zero out */
      at_scores = ({ }); /* zero out */
      restore_object(ALLTIME);
      for (x=0; x<sizeof(at_names); x++)
          write("\t"+pad(at_names[x],16)+at_scores[x]+"\n");
    }

    /* Print a footer */
    write(HIR+SYM+NORM+"\n");
  }

  /* Print a friendly error message */
  else write("Usage: <view current> or <view alltime>\n");
  return 1;
}

/*
 * Function: display_map
 * Purpose: Write the sorted keys and values of a mapping in tabular form.
 */
void display_map(mapping m) {
int x, y, asize, *values;
string *indices, *s_names;
  indices = keys(m);
  values = m_values(m);
  values = sort_array(values);
  s_names = allocate(sizeof(indices));
  for (x=0; x<sizeof(indices); x++) {
    y=0;
    while((y<sizeof(values)) && (m[indices[x]]!=values[y])) y++;
    s_names[y]=indices[x];
    values[y]=-1;
  }
  values = m_values(m);
  values = sort_array(values);
  if (sizeof(s_names) < 15)  asize = sizeof(s_names);
  else asize = 15;
  for (x=0; x<asize; x++)
      write("\t"+pad(s_names[x],16)+values[x]+"\n");
}

alltime(str) {
  if(str=="update") {
    update_alltime();
    write("Update complete... alltime scores saved.\n");
    return 1;
  }
  if(str=="reset") {
    at_names=({"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o"});
    at_scores=({15,14,13,12,11,10,9,8,7,6,5,4,3,2,1});
    save_object(ALLTIME);
    write("Alltime scores reset.\n");
    return 1;
  }
  else { write("<alltime update/reset>\n"); return 1; }
}
