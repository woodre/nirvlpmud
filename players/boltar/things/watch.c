#include "/obj/clean.c"
object cl;
string nam;
int ti, th, days, hr, tmin, min, se;
int test_flag,dong_flag,clock_start;
int tx, hx, corr,corr2, i;


short()
{
    return "A gold pocket watch";
}

query_value()
{
        return 45;
}

  query_weight() {   return 0; }
long()
{

 nam = call_other(this_player(), "query_name", 0);
write("A heavy gold pocket watch. A very ornate and beautiful time piece.\n");
write("The watch shows the time to be: ");
  write(hr + ":");
  if (min < 10) {
   write("0");
  }
write(min);
 if (hx > 11) write("pm" + "\n");
 if (hx < 12) write("am" + "\n");
write("Change time with 'set hour #ofHour' and 'set min #of min'\n");
write("To change am/pm add 12 hours to the #ofHour\n");
write("'reset' watch before setting, else the time may not be what you want.\n");
say(nam + " takes out a gold pocket watch and checks the time.\n");
}


id(str) {
    return str == "clock" || str == "watch";
}

get() {
    write("The gold watch feels good in your hand.\n");
    return 1;
}
zone(arg) {
 int temp;
/*
  sscanf(arg, "%d", temp);
*/
temp = arg;
  corr = temp - hx;
  return 1;
}
find_time() {
  tx = time();
  tx = tx + corr*3600;
  tx = tx + corr2*60;
  ti = tx + 19*3600;
  th = ti/3600;
   days = (th)/24;
   hx = th - days*24;
   if (hx > 12) {
      hr = hx - 12;
    }
   if (hx < 12) {
       hr = hx;
}
   if (hx == 0 || hr == 0) {
       hr = 12;
 }
   tmin = ti/60;
   min = tmin - days*24*60 - hx*60;
   se = ti - days*24*3600 - hx*3600 - min*60;
   if(test_flag) {
   min=0;
  se = 0;
   test_flag = 0;
  }
  if (min == 0 && se< 2 && dong_flag == 0) {
 say("\n");
   say("You hear the watch chime.\n");
   say("\n");
   i = 1;
   dong_flag = 1;
   dong();
}
call_out("find_time", 1);
}


dong() {
    say("ding.  \n");
    say("\n");
    if (i < hr) {
      i += 1;
    call_out("dong", 4);
   }
  if (i >= hr) 
     dong_flag = 0;
}
init(){
    add_action("settest","test");
    add_action("set","set");
   add_action("res","reset");
   if (!clock_start) {
     clock_start = 1;
     call_out("find_time", 1);
    }
}
settest(){
   if (call_other(this_player(), "query_level", 0) < 21)
     return 0;
  test_flag=1;
  return 1;
  }
zonemin(arg) {
  int temp;
/*
  sscanf(arg, "%d", temp);
*/
temp = arg;
  corr2 = temp - min;
  return 1;
}
set(str) {
 int arg,temp;
  string tmp;
   if (sscanf(str, "%s %d", tmp,temp) ==2) {
   if (tmp !="min" && tmp !="hour")
     return 0;
   if (tmp == "min")
     zonemin(temp);
   if (tmp == "hour")
     zone(temp);
}
  return 1;
}
res(){
 corr = 0;
 corr2 =0;
write("watch reset.\n");
return 1;
}
