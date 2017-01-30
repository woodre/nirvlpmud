#define FINAL 741070800
inherit "/obj/treasure";
int marker;
 
reset(arg) {
  if(arg) return;
  set_weight(10000000);
  set_short("Dopple Tymer");
  set_id("tymer");
  marker=999;
  set_heart_beat(1);
}
 
long() {
write(
"This is just a little tymer to count down how long until the new additions\n"+
"are to be put into the game.\nCurrently its clock reads "+
query_hours()+" hours "+query_minutes()+" minutes and "+query_seconds()+
" seconds left.\n");
return 1;
}
 
query_hours() {
  return ((FINAL-time())/3600); }
 
query_minutes() {
  return ((FINAL-time()-(query_hours()*3600))/60); }
 
query_seconds() {
  return ((FINAL-time()-(query_hours()*3600)-(query_minutes()*60))); }
 
heart_beat() {
  if(marker!=query_hours()) {
    marker=query_hours();
    tellem(marker+" hours left!");
  }
  if(marker<0) {
    tellem(" OPEN OPEN OPEN OPEN!");
    destruct(this_object());
    return 1;
  }
}
 
tellem(str) {
  object people;
  int i;
  people=users();
  for(i=0;i<(sizeof(people)+1);i++)
    if(present("badge",people[i]))
      tell_object(people[i],"[Grimm's Assistant]: "+str+"\n");
}
