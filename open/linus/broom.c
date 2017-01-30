#include "/players/linus/def.h"
#define NAME HBWHT+RED+"S"+BLU+"oldier"+BLU+" F"+RED+"ield"+NORM+" (Bears "+bscore+" vs. "+opponent+" "+oscore+")"
#define SCHEDULE "/open/linus/schedule.txt"
inherit "/players/vertebraker/closed/std/room.c";

/* Global Variables */
string MyShort;

string opponent;
int oscore,bscore;

reset(arg) {
  string filetext, *lines, tdate, now, twho;
  int i, siz;

  if (!arg) {
    ::reset(arg);
    return;
  }

 set_light(1);
 set_long(
"To change scores: 'bscore' sets the bears score and 'oscore' sets the opponent's\n"+
"You can set the opposing teams name by 'name' the opposing team name.\n");
add_item("blah","blah blah blah");

  filetext = read_file(SCHEDULE);
  lines = explode(filetext, "\n");
  siz = sizeof(lines = explode(filetext, "\n"));
  now = ctime()[4..9];
  ::reset(arg);

  for (i = 0; i < siz; i++)
  {
    if (sscanf(lines[i], "%s: %s", tdate, twho) == 2)
    {
      if (now < tdate)
      {
        MyShort = twho;
        return;
      }
    }
  }

  MyShort = "Linus's Workroom";
}

short() { return MyShort; }

init() {
::init();
 add_action("name_opp","name");
 add_action("set_bscore","bscore");
 add_action("set_oscore","oscore");
}
name_opp(string str) {
if(!str) { notify_fail("Usage: name <team>\n");
return 0; }
return opponent = capitalize(str);
return 1;
}
set_bscore(int x) {
 return bscore = x;
return 1;
}
set_oscore(int x) {
 return oscore = x;
return 1;
}
