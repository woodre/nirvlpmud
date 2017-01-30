inherit "obj/treasure";

reset(arg) {
   if(arg) return;
set_short("A doppleganger watch");
set_long("This is a rare doppleganger watch.  It tells if it is night or day.\n"+
         "                  type CHECK TIME to use\n");
set_alias("watch");
set_id("vampire watch");
set_value(25432);
}
init() {
   add_action("check","check");
   ::init();
}
check(str) {
   if(!str) return;
   if(str!="time") return;
   write("The watch reports: ");
   if("players/grimm/closed/vampcastl/castle20"->night()==1) {
      write("It is now nighttime.\n");
      return 1;
   }
   write("It is daytime.\n");
return 1;
}
