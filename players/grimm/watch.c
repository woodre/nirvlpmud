inherit "obj/treasure";

reset(arg) {
   if(arg) return;
set_short("A vampire watch");
set_long("This is a rare vampire watch.  It tells if it is night or day.\n"+
         "                  type CHECK TIME to use\n");
set_alias("watch");
set_id("vampire watch");
set_value(2432);
}
init() {
   add_action("check","check");
   ::init();
}
check(str) {
  int i,j,h;
   if(!str) return;
   if(str!="time") return;
  i=time();
  j=i/60/60/24;
  i-=j*60*60*24;
  j=i/60/60;
  h=j;
  write("The watch shows: "+j+" hours, ");
  i-=j*60*60;
  j=i/60;
  write(j+" minutes.\n");
/*
   if("players/grimm/closed/vampcastl/castle20"->night()==1) {
      write("It is now nightime.\n");
      return 1;
   }
   write("It is daytime.\n");
*/
  if(i=1)
    write("It is daytime.\n");
  if(i=0)
    write("It is nighttime.\n");
return 1;
}
