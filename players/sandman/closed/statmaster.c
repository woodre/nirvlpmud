
id(str) { return str == "statmaster" || str == "stat"; }

short() { return "A statmaster -- Version 1.01"; }

long() {
   write("The Original Statmaster:\n"+
         "\nTO USE:  raise <stat> <num>\n"+
         "stats available:  str, sta, pie, mag, wil, luc, ste\n");
}

get() {
   if(this_player()->query_level() > 20) { return 1; }
   return 0;
}

init() {
   if(this_player()->query_level() < 20) { return 1; }
   add_action("raise","raise");
}

raise(str) {
   string attrib, raise, who, what;
   int num;

    if(!str || sscanf(str, "%s %s %d", who, what, num) != 3){
     write("Useage:  raise <who> <stat> <num>\n");
     return 1;
   }
   if(what == "wil") { attrib = "will_power"; }
   if(what == "mag") { attrib = "magic_aptitude"; }
   if(what == "pie") { attrib = "piety"; }
   if(what == "ste") { attrib = "stealth"; }
   if(what == "luc") { attrib = "luck"; }
   if(what == "str") { attrib = "strength"; }
   if(what == "sta") { attrib = "stamina"; }
   if(what == "int") { attrib = "intelligence"; }
   raise = "raise_"+attrib;
   call_other(find_player(who), raise, num);
   return 1;
}

