#define FILENAME "/log/ENTER"

/*-------------------------------------------------------------------*/
short() {
    return "A list of the top players since reboot" ;
}

long() {
    write("blah\n");
}

/*-------------------------------------------------------------------*/
init() {
    add_action("read"); add_verb("read");
}

/*-------------------------------------------------------------------*/
id(str) {
    return str == "list" || str == "top" || str == "top players" ||
        str == "list of top players" || str == "top list";
}

/*-------------------------------------------------------------------*/
read(str) {
    if (!id(str))
        return 0;
    say(call_other(this_player(), "query_name") + " reads the top list.\n");
    check_scores();
    return 1;
}

/*-------------------------------------------------------------------*/
query_weight() { return 1; }

get() { return 1; }

query_value() { return 5; }

/*-------------------------------------------------------------------*/
check_scores () {
string *keepers; /* Array of strings from FILENAME to be kept */
string str, entry_time, pname, direction, junk;
int n, starttime, num, x, pexp, plevel, numeric_time;
object who;

  n = 1;
  restore_object("/log/upsince.o");

  do {
     /* Get the current line from the file */
     str = read_file(FILENAME, n, 1);

     /* Parse the string into the appropriate variables.  If
        all of the variables aren't there, we don't want it */
    num=sscanf(str, "%s(%s) %s %d %s", entry_time, pname, direction, pexp, junk);

     if (num == 5) {

        /* Convert the time string back to a number */
        numeric_time = convert_time(entry_time);

        /* Convert the player's name to an object and get the level */
        /* THIS WON'T WORK, SINCE pname DOES NOT HAVE AN ENVIRONMENT */
        /* who = present(pname, this_player()); */
        /* plevel = who->query_level(); */

        /* If the entry is for the current reboot period, and the player
           is not the guest , then add the string to the array */
        if ((numeric_time > starttime) && (pname != "guest")) 
          keepers += ({ str });   /* add the string to the array */

     }
     n++;
  } while (read_file(FILENAME, n, 1)!=0);

  /* Output an array of the valid entries from FILENAME */
  for (x=0; x < sizeof(keepers); x++) {
     write (keepers[x]);
  }
  return 1;
}

/*-------------------------------------------------------------------*/
convert_time(string time_stamp) {
string Smonth;
int year, leap, Nmonth, date, hour, min;
int num_time;
  year=1998;  /* the current year */
  leap=7;     /* the number of leap years since 1970 */
  sscanf(time_stamp,"%s %d %d:%d", Smonth, date, hour, min);
  switch(Smonth) {
    case "Jan": Nmonth=0; break;
    case "Feb": Nmonth=31*86400; break;
    case "Mar": Nmonth=59*86400; break;
    case "Apr": Nmonth=90*86400; break;
    case "May": Nmonth=120*86400; break;
    case "Jun": Nmonth=151*86400; break;
    case "Jul": Nmonth=181*86400; break;
    case "Aug": Nmonth=212*86400; break;
    case "Sep": Nmonth=243*86400; break;
    case "Oct": Nmonth=273*86400; break;
    case "Nov": Nmonth=304*86400; break;
    case "Dec": Nmonth=334*86400; break;
    default: write("Invalid month abbreviation.\n");
  }
  /* (Years+leap years+minutes+hours+days-timezone correction) in seconds */
  num_time=(86400*365*(year-1970))+(86400*leap)+(60*min)+(3600*hour)+
           (86400*date)+Nmonth-(19*3600);
  return num_time;
}

/*-------------------------------------------------------------------*/
