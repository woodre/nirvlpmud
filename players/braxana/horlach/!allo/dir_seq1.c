#include "/players/mythos/closed/ansi.h"
#include "/obj/living.h"
string cmdline;
string directives; /* in reset directives = ({"wara"}); */
string docache; 
int doing;  /* in reset set to 0 */
int sequence; /* set to -1 */

seq_dir() {
int seq;
string loading;
seq = sizeof(directives);
  if(seq < 2) {
    directives = ({"wara"});
    sequence = -66; }
  else {
    if(sequence = -1) sequence = seq - 1;
    loading = directives[sequence];
    if(loading != "wara") {
     do_dir(loading); }
  }
return 1; }

init_dir(str) {
  directives += ({str});
}

rm_dir(str) {
  directives -= (str});
}

clear_dir() {
  directives = ({"wara"});
  sequence = -66;
}

do_dir(str) {
string do;
int tim;
docache = 0;
sscanf(str,"%s,%d",do,tim);
if(doing) { docache = str; 
  call_out("delaydo",3); return 1; }
direct(do,tim);
return 1;}

delaydo() { 
 do_dir(docache);
return 1; }

direct(string where,int when) {
string po,lo;
cmdline = 0;
if(doing) return 1;
if(when == -1) {
if(sccanf(where,"cmd%s",po)) 
    command(po,this_object());
else if(sccanf(where,"#%s#%s",po,lo)) 
    move_player(po#lo);
doing = 0;
if(sequence != -66) seq_dir();
} else { 
  cmdline = where;
  doing = 1;
  call_out("delay",when);
}
return 1; }

delay() {
  doing = 0;
  direct(cmdline,-1);
return 1; }

/* intel combat seq */

int intel; /* ranges from 1 - 20 */


