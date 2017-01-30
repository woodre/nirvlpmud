/*----------------------------------------------------------------------*/
/* This object creates a list of players along with the experience that */
/* they have earned since the previous reboot.  The names, with their   */
/* earned experience, are sorted and a "Top 15 List" is displayed for   */
/* experience earned during the current reboot period, and most experi- */
/* ence ever gained during one reboot period.  This object includes     */
/* /obj/user/channel.c so that the catch_tell function can collect      */
/* player data via the msg channel.  Data is then stored and sorted     */
/* using a mapping of arrays, with player name as the key field.        */
/*    Thanks to Beck, Sado, and Wizardechild for ideas and              */
/*    implementation help.                                              */
/*              - Cosmo, November 1998                                  */
/*  WARNING: THIS OBJECT IS STILL A WORK-IN-PROGRESS                    */

#include "/players/cosmo/closed/ansi.h"
#include "/obj/user/channel.c"
#include "/players/cosmo/hslist/tempdata.h"
#define MYFUN "/players/cosmo/hslist/mapfuns.c"
#define SAVE "players/cosmo/hslist/scores"

mapping exp_map, delta_map;
string *at_names;  /* Names of highest all-time scores */
int *at_scores;    /* Highest all-time scores */
int starttime;

/*-------------------------------------------------------------------*/
reset(arg) {
int current;
  if(arg) return;

  /* Get the time of reboot and the current time */
  restore_object("log/upsince");
  current=time();

  /* If reboot was less than 100 seconds ago, reset the mappings */
  if ((current-starttime)<22000) {
    exp_map = ([]);
    delta_map = ([]);
  }
}

/*-------------------------------------------------------------------*/
short() { return "A virtual display screen [VDS]"; }

long() {
  write(short()+"\n");
  write("This handy little screen tracks the experience that players\n");
  write("have earned since the last reboot.  A heads-up display\n");
  write("appears whenever you view the VDS.  You may view the\n");
  write("current scores for this reboot period, or the alltime\n");
  write("scores achieved during one reboot period.\n");
}

/*-------------------------------------------------------------------*/
id(str) { return str == "VDS" || str == "screen" || str == "display" ||
          str == "vds" || str == "display screen"; }

/*-------------------------------------------------------------------*/
/* Used in /obj/user/channel.c - must return > 20 */
query_level() { return 22; }

query_weight() { return 1; }
query_value() { return 5; }
get() { return 1; }

/*-------------------------------------------------------------------*/
init() {
  channel_names = ({});
  add_channel("msg");
  add_action("view"); add_verb("view");
}

/*-------------------------------------------------------------------*/
view(str) {
int x;
  if (str=="current") {
    say(this_player()->query_name() + " looks at the virtual display.\n");
    get_data();  /* Temporary for testing */
    write("\nCURRENT REBOOT PERIOD\n");
    write("PLAYER\t\tEXPERIENCE\n");
    MYFUN->display_map(delta_map);
  }
  else if (str=="alltime") {
    get_data();  /* Temporary for testing */
    write("\nALL-TIME SCORES\n");
    write("PLAYER\t\tEXPERIENCE\n");
    for (x=0; x<sizeof(at_names); x++) {
      if (strlen(at_names[x]) < 8)
        write(at_names[x] + "\t\t" + at_scores[x] + "\n");
      else
        write(at_names[x] + "\t" + at_scores[x] + "\n");
    }
  }
  else write("Usage: <view current> or <view alltime>\n");
  return 1;
}

/*----------------------------------------------------------------------*/
/* This function won't work unless this object is added to the people   */
/* array found in /obj/users/channel.c.  In the broadcast() function,   */
/* need to add:  people += "/players/cosmo/hslist/hsscreen.c";  right   */
/* after people = users();                                                    */

catch_tell(str) {
string pname;       /* The player's name   */
string in_out;      /* 'entered' or 'left' */
string junk1, junk2;
int pexp;           /* The player's exp    */
int delta;          /* The change in exp   */
int pos;            /* The position of delta in the all-time score array */
  /* Make sure it is a valid msg str; don't include the guest or dead */
  if ((sscanf(str, "%s (%s) has %s %s", pname, junk1, in_out, junk2) == 4)
     && (pname!="Guest") && (pname!="Some mist")) {
    /* Convert the player's name to an object, get the exp, and store it */
    pexp = present(pname, this_player())->query_exp();
    /* If the player enters and is not already in the mapping, add it. */
    if (in_out=="entered") {
      if (!MYFUN->member(exp_map, pname)) exp_map += ([pname:pexp]);
    }
    else {   /* The player is leaving */
      /* Add the player to the delta mapping, if not already there */
      if (!MYFUN->member(delta_map, pname)) delta_map += ([pname:0]);
      /* Calculate the change in exp and store it in the mapping */
      delta = pexp - exp_map[pname];
      delta_map[pname] = delta;
      /* Check to see if the score qualifies for the all-time list */
      restore_scores();
      pos = check_scores(delta);
      if (pos > -1) {
         /* Add the name and score to the all-time list and save it */
         update_names(pos, pname);
         update_scores(pos, delta);
         save_object(SAVE);
      }
    }
  }
  return 1;
}

/*-------------------------------------------------------------------*/
/* This stuff is temporary for testing purposes until I can get the  */
/* catch_tell() function to work.                                    */

get_data() {
string *stuff;
int *exp_d, x, pexp, pos;
int delta;
string pname, in_out, junk1, junk2;

/* The array data are stored in tempdata.h */
  stuff = ENTRIES;
  exp_d = EXP_DATA;

  for (x=0; x < sizeof(stuff); x++) {
    if ((sscanf(stuff[x], "%s (%s) has %s %s", pname, junk1, in_out, 
     junk2) == 4) && (pname!="Guest") && (pname!="Some mist")) {

      /* Convert the player's name to an object, get the exp, and store it */
      pexp = exp_d[x];

      /* If the player enters and is not already in the mapping, add it. */
      if (in_out=="entered") {
        if (!MYFUN->member(exp_map, pname)) exp_map += ([pname:pexp]);
        /* Else if the player is already in the mapping, do nothing */
      }
      else {   /* The player is leaving */
        /* Add the player to the delta mapping, if not alreahere */
        if (!MYFUN->member(delta_map, pname)) delta_map += ([pname:0]);
        /* Calculate the change in exp and store it in the mapping */
        delta = pexp - exp_map[pname];
        delta_map[pname] = delta;
        /* Check to see if the score qualifies for the all-time list */
        restore_scores();
        pos = check_scores(delta);
        if (pos > -1) {
           update_names(pos, pname);
           update_scores(pos, delta);
           save_object(SAVE);
        }
      }
    }
    else write("Invalid msg string.\n");
  }
  return 1;
}

/*-------------------------------------------------------------------
 Purpose: Get the alltime name and score arrays.
*/
void restore_scores() {
  at_names = ({}); /* zero out */
  at_scores = ({}); /* zero out */
  restore_object(SAVE);
  return;
}

/*-------------------------------------------------------------------
 Purpose: Compare amt to the all-time scores.  Return -1 if amt is 
 less than all of the scores; otherwise, return the position in    
 array where it belongs.
*/
int check_scores(int amt) {
int x;
  for (x=0; x<sizeof(at_scores); x++) {
    if (amt >= at_scores[x]) return x;
  }
return -1;
}

/*-------------------------------------------------------------------
 Purpose: Add a new name in the array and bump the rest down one.
*/
void update_names(int num, string who) {
int x;
  for (x=14; x>num; x--) 
    at_names[x]=at_names[x-1];
  at_names[num]=who;
return;
}

/*-------------------------------------------------------------------
 Purpose: Add a new score in the array and bump the rest down one.
*/
void update_scores(int num, int amt) {
int x;
  for (x=14; x>num; x--)
    at_scores[x]=at_scores[x-1];
  at_scores[num]=amt;
return;
}

