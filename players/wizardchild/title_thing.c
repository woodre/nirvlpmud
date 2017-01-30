/* we update this every 5 minutes let's say */
#define UPDATE 300
#define SAVE(s) rm("/players/wizardchild/Current");\
                write_file("/players/wizardchild/Current",s)
                
#define ARRIVE_DAY 15
#define ARRIVE_HR  18
#define ARRIVE_MIN 36
 
get_time() { return extract(ctime(time()),11,15); }
get_day()  { return extract(ctime(time()),8,9);   }
reset(arg) {
  if(arg) return ;
  do_thing();
}
do_thing() {
  int day,hr,min,tot1,tot2;
  int diff;
  string days,hours,minutes,out;
  remove_call_out("do_thing");
  sscanf(get_day(),"%d",day);
  sscanf(get_time(),"%d:%d",hr,min);
  hr -= 2; /* CST */
  tot1 = (ARRIVE_DAY*24*60)+(ARRIVE_HR*60)+ARRIVE_MIN;
  tot2 = (day*24*60)+(hr*60)+min;
  diff = tot1-tot2;
  if(diff == 0) 
    out = "Seductress just arrived!!!";
  else if(diff < 0)
    out = "Seductress is here!!!";
  else {
    day = diff/(24*60);
    if(day != 0) days = day+" da"+(day==1?"y":"ys");
    diff -= (day*24*60);
    hr = diff/60;
    if(hr != 0) hours = hr+" hou"+(hr==1?"r":"rs");
    diff -= (hr*60);
    if(diff != 0) minutes = diff+" minut"+(diff==1?"e":"es");
    out = "";
    if(days) {
      out += days; 
      if(hours && minutes) out += ", "+hours+" and "+minutes;
      else if(hours) out += " and "+hours;
      else out += " and "+minutes;
    } else if(hours) {
      out += hours;
      if(minutes) out += " and "+minutes;
    } else
      out += minutes;
    out = "Seductress arrives in "+out+"!!!";
  }
  if(find_player("wizardchild"))
    command("setal "+out,find_player("wizardchild"));
  SAVE(out);
  call_out("do_thing",UPDATE);
}
