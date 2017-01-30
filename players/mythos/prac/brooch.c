#include "/players/mythos/closed/ansi.h"
#define tp this_player()
#define ep environment(this_object())
#define etp environment(tp)
#define eep environment(ep)
#define epn ep->query_real_name()
#define tpn tp->query_real_name()
#define SOURCE "/players/mythos/prac/source.c"

string wor, mmsg;
int wcr;

id(str) { return str == "brooch"; }

query_auto_load() { return "/players/mythos/prac/brooch.c:"; }

reset(arg) {
  if(arg) return;
  mmsg = "";
  wor = "";
  wcr = 0;
}
drop() { return 1;}

short() { return "Crystal Brooch"+wor; }

long() { write("A "+RED+"CR"+NORM+YEL+"YS"+NORM+GRN+"TA"+NORM+BLU+"L"+NORM+
               " Brooch of great beauty.  \nOnce worn by a female, the beauty of"+
               " a goddess is inherited.\n  Type <brooch_help>\n"); }

extra_look() { 
  if(wcr) { mmsg = "Dazzling "+CYN+"light"+NORM+" eminates from "+capitalize(epn); }
return mmsg; }

get() { return 0;}
query_save_flag() { return 0;}

init() {
  if(living(ep) && ep->query_gender() != "female") {
     tell_object(ep,"This is something you may not use!\n");
  return 1;}
  add_action("brooch_help","brooch_help");
  add_action("bdazzle","bdazzle");
  add_action("bsmile","bsmile");
  add_action("blaugh","blaugh");
  add_action("blight","blight");
  add_action("blove","blove");
  add_action("bsigh","bsigh");
  add_action("bangry","bangry");
  add_action("bweep","bweep");
  add_action("badore","badore");
  add_action("bgiggle","bgiggle");
  add_action("brkiss","brkiss");
  add_action("brhug","brhug");
  add_action("bembrace","bembrace");
  add_action("bwear","wear");
  add_action("bremove","remove");
}

brooch_help() {
  write("Following actions allowed when worn:\n"+
        "   bdazzle  bsmile  blaugh  blight  blove\n"+
        "   bsigh  bangry  bweep  badore  bgiggle\n"+
        "   brkiss  brhug  bembrace\n");
return 1;}

bdazzle(str) { SOURCE->bdazzle(str); return 1;}
bsmile(str) { SOURCE->bsmile(str); return 1;}
blaugh(str) { SOURCE->blaugh(str); return 1;}
blight(str) { SOURCE->blight(str); return 1;}
blove(str) { SOURCE->blove(str); return 1;}
bsigh(str) { SOURCE->bsigh(str); return 1;}
bangry(str) { SOURCE->bangry(str); return 1;}
bweep(str) { SOURCE->bweep(str); return 1;}
badore(str) { SOURCE->badore(str); return 1;}
bgiggle(str) { SOURCE->bgiggle(str); return 1;}
bembrace(str) { SOURCE->bembrace(str); return 1;}
brkiss(str) { SOURCE->brkiss(str); return 1;}
brhug(str) { SOURCE->brhug(str); return 1;}

bwear(str) {
  if(!str) return 0;
  if(str == "brooch") {
    if(wcr) { write("You already wear the Crystal Brooch!\n"); return 1;}
    write("You wear the Crystal Brooch.\n\n");
    write("*  *           The beauty within you emerges!             *  *\n\n"+
          "*  *   No longer are you just beautiful, but ravishing-   *  *\n"+
          "*  *   a Goddess in full rights!  All bow before you!     *  *\n\n");
    say("\n"+capitalize(tpn)+" is suddenly surrounded by light!\n\n");
    say("You are filled with great awe and reverence at "+
        capitalize(tpn)+"'s goddesslike beauty!\n");
    say("You bow before "+capitalize(tpn));
    say("\n");
    wor = " <worn>";
    wcr = 1;
  return 1;}
}

bremove(str) {
  if(!str) return 0;
  if(str == "brooch") {
    if(!wcr) { write("You are not wearing the brooch!\n"); return 1;}
    write("You remove the brooch.\n");
    wor = "";
    wcr = 0;
    return 1;}
}

