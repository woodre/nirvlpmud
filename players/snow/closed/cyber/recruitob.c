#define TOOL "/players/dune/closed/guild/lib/CYBERDAEMON.c"
#define TP this_player()
#define TE tell_object

init() { 
add_action("learn","devote");
  add_action("info_database","cyber");
}


id(str) { return str == "way" || str == "Way"
   || str == "either implants"
   || str == "way of the CyberNinja"
   || str == "Way of the CyberNinja"
   || str == "way of the cyberninja"
   || str == "way of cyberninja"
   || str == "temporary implants"; }
short() { return "Way of the CyberNinja";}
long() {
  TE(TP,"This is your guide to becoming a full-fledged CyberNinja.\n"+
        "To recieve information just type 'devote'.\n");}
get() { return 1; }
drop() { destruct(this_object()); return 1; }

reset(arg) {
 if(!arg) {
 }}

learn() {
  TE(TP,
"_____________________THE CYBERNINJA_____________________\n"+
"You must now go to the CyberNinja guild and register at the\n"+
"chop shop.  Then you must join.  If you do so successfully,\n"+
"you will be a new CyberNinja.\n"+
"  For detailed info, type 'cyber'.\n");
  return 1;
}

info_database(str) { TOOL->info_database(str); return 1; }
