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
#define ALLTIME_99 "players/cosmo/hslist/1999"
#define ALLTIME_00 "players/cosmo/hslist/2000"
#define ALLTIME_01 "players/cosmo/hslist/2001"
#define ALLTIME_02 "players/cosmo/hslist/2002"
#define ALLTIME_03 "players/cosmo/hslist/2003"
#define ALLTIME_04 "players/cosmo/hslist/2004"
#define ALLTIME_05 "players/cosmo/hslist/2005"
#define ALLTIME_06 "players/cosmo/hslist/2006"
#define ALLTIME_07 "players/cosmo/hslist/2007"
#define ALLTIME_08 "players/cosmo/hslist/2008"
#define ALLTIME_09 "players/cosmo/hslist/2009"
#define ALLTIME_10 "players/cosmo/hslist/2010"
#define ALLTIME_11 "players/cosmo/hslist/2011"
#define ALLTIME "players/cosmo/hslist/2011"
#define SYM "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"

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
if(hour == 18)
    x=42300; /* Evening reboot period, 11.75 hours */
  else
    x=43200; /* Day reboot period, 12 hours */

  /* Setup a callout to update the all-time scores right before reboot */
  if(sscanf(file_name(this_object()), "%s#%s", junk1, junk2) != 2) {
    /*
    call_out("update_alltime", x);
    */
  /*setup a callout to save every 3 hours, bug for multirunning solved
   -Bp */
    /*  Now just updated in Army's shut down phase
    call_out("update_alltime", 10800);
    */
  }
}

/*-------------------------------------------------------------------*/
short() { return "MASTER VDS ["+HIR+"Do not destruct!!"+NORM+"]"; }

long() {
  write("\n"+short()+"\nThe master VDS.  Keep this in Cosmo's workroom.\n");
  if(this_player()->query_real_name() == "cosmo")
    write("You can also use the "+BOLD+"alltime"+NORM+" function.\n");
}

id(str) { return str == "VDS" || str == "screen" ||
     str == "display" || str == "vds" || str == "display screen"; }

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
  log_file("COSMO","XXXX");
  at_names = ({ }); /* zero out */
  at_scores = ({ }); /* zero out */
  restore_object(ALLTIME);

  /* Get the current names and scores */
  current_map = ([ ]); /* zero out */
  current_map = CURRENT->query_map();
  current_array = ({ });
  current_array = deconstruct_mapping(current_map);

  log_file("COSMO","YYYY\n");
  /* Step through the current scores and update the alltime
     scores, as necessary */
  for (x=1; x<sizeof(current_array); x=x+2) {
    pos = check_scores(current_array[x], at_scores);
    if (pos>-1 && pos<15) {
      write("POS >-1 && POS < 15\n");
      if(at_names[pos]!=current_array[x-1]&&at_scores[pos]!=current_array[x]) {
      write("updating "+pos+"\n");
      at_names = update_array(pos, current_array[x-1], at_names);
      at_scores = update_array(pos, current_array[x], at_scores);
      log_file("COSMO", ctime()+" GOT TO SAVE\n");
      save_object(ALLTIME);
      }
    }
  }
  log_file("COSMO","call-ouit");
  call_out("update_alltime", 10800);
  return 1;
}

/*-------------------------------------------------------------------*/
init() {
  add_action("view","view");
  if(this_player()->query_real_name() == "boltar" || "angel")
    add_action("alltime","alltime");
}

view(str) {
int x;
mapping current_map;

  /* Print some headers to make it look nice */
  if (str == "current" || str == "2011" || str == "2010" || str == "2009" ||
         str == "2008" || str == "2007" || str == "2006" || str == "2005" ||
         str == "2004" || str == "2003" || str == "2002" || str == "2001" ||
         str == "2000" || str == "1999"){
     
    say(this_player()->query_name() + " looks at the virtual display.\n");
    write("\n"+HIR+SYM+NORM+"\n");
    if (str=="current")
      write("  "+YEL+"Top Scores for Current Reboot Period"+NORM+"\n");
    else if (str=="1999")
      write("\t  "+YEL+"Top Scores for 1999"+NORM+"\n");
    else if (str=="2000")
      write("\t  "+YEL+"Top Scores for 2000"+NORM+"\n");
    else if(str=="2001")
     write("\t  "+YEL+"Top Scores for 2001"+NORM+"\n");
    else if(str=="2002")
     write("\t  "+YEL+"Top Scores for 2002"+NORM+"\n");
    else if(str=="2003")
     write("\t "+YEL+"Top Scores for 2003"+NORM+"\n");
    else if(str=="2004")
     write("\t "+YEL+"Top Scores for 2004"+NORM+"\n");
    else if(str=="2005")
     write("\t "+YEL+"Top Scores for 2005"+NORM+"\n");
    else if(str=="2006")
     write("\t "+YEL+"Top Scores for 2006"+NORM+"\n");
    else if(str=="2007")
     write("\t "+YEL+"Top Scores for 2007"+NORM+"\n");
    else if(str=="2008")
     write("\t "+YEL+"Top Scores for 2008"+NORM+"\n");
    else if(str=="2009")
     write("\t "+YEL+"Top Scores for 2009"+NORM+"\n");
    else if(str=="2010")
     write("\t "+YEL+"Top Scores for 2010"+NORM+"\n");
    else if(str=="2011")
     write("\t "+YEL+"Top Scores for 2011"+NORM+"\n");
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
      if (str=="1999") restore_object(ALLTIME_99);
      else if(str=="2000") restore_object(ALLTIME_00);
      else if(str=="2001") restore_object(ALLTIME_01);
      else if(str=="2002") restore_object(ALLTIME_02);
      else if(str=="2003") restore_object(ALLTIME_03);
      else if(str=="2004") restore_object(ALLTIME_04);
      else if(str=="2005") restore_object(ALLTIME_05);
      else if(str=="2006") restore_object(ALLTIME_06);
      else if(str=="2007") restore_object(ALLTIME_07);
      else if(str=="2008") restore_object(ALLTIME_08);
      else if(str=="2009") restore_object(ALLTIME_09);
      else if(str=="2010") restore_object(ALLTIME_10);
      else if(str=="2011") restore_object(ALLTIME_11);
      else restore_object(ALLTIME);
      for (x=0; x<sizeof(at_names); x++)
          write("\t"+pad(at_names[x],16)+at_scores[x]+"\n");
    }

    /* Print a footer */
    write(HIR+SYM+NORM+"\n");
  }

  /* Print a friendly error message */
  else write("Usage: <view current> or <view 'year'> ie: <view 2010>\n");
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
  if(str=="backup") {
    command("cp /players/cosmo/hslist/alltime.o /players/cosmo/hslist/alltime.bak");
    write("Backup complete.\n");
    return 1;
  }
  else { write("<alltime update/reset/backup>\n"); return 1; }
}

/*added by wocket */
remove_object(prev){
  update_alltime();
}
