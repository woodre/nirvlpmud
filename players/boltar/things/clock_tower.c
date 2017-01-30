object cl;
/*int YK;*/
string nam;
int ti, th, days, hr, tmin, min, se;
int test_flag, dong_flag;
int clock_start;
int tx, hx, i;


short()
{
     return "A large and very tall clock tower stands here";
}

query_value()
{
        return 3;
}

  query_weight() {   return 30000; }
long()
{
 nam = call_other(this_player(), "query_name", 0);
  write("A large brick clock tower,"+
    "\n" +
"the clock is reporting the time to be: ");
  write(hr + ":");
  if (min < 10) {
   write("0");
  }
 write(min + "  Central time.\n");
 say(nam + " takes a look at the clock and finds out the time.\n");
}

find_time() {
  tx = time();
  ti = tx + 21*3600;
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
  if (min == 0 && se < 2 && dong_flag == 0) {
   shout_two("\nYou hear the clock tower chime.\n\n");
   i = 1;
   dong_flag = 1;
   dong();
}
call_out("find_time", 1);
}

id(str) {
    return str == "tower" || str == "clock" || str == "clock tower";
}

get() {
    return 0;
}
dong() {
string a,b;
 /* Y2K loading..... */
/*
 if(!YK) {
 if(sscanf(ctime(time()),"%sJan  1 01:0%s",a,b) == 2)
  call_other("players/boltar/closed/Y2K","blah",0);
 YK = 7;
 }
*/
/*
    shout_two("dong!  \n");
*/
    shout_two("dong!\n\n");
    if (i < hr) {
      i += 1;
    call_out("dong", 4);
   }
  if (i >= hr) 
     dong_flag = 0;
}
init(){
  add_action("settest", "test");
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
shout_two(str) {
    object list;
    object envob;
    string envfil,envst;
     int i, z, x;
/*
     log_file("CLOCKTEST", str);
*/
   list=users();
    while(i < sizeof(list)) {
      string sn, ip, sd, sh;
      object obply, plob;
  if(list[i])
  if(list[i]->query_level() > 0) {
      sn = list[i]->query_real_name();
      if(call_other(list[i], "query_ghost", 0) == 1) {
           sn = "ghost of " + sn;
}
       plob = find_player(sn);
       envob=environment(list[i]);
       if (envob) {
       envfil = file_name(envob);
       envst = extract(envfil, 0, 8);
      if(call_other(list[i], "query_level", 0) < 20) {
		  if (envst == "room/vill"){
       tell_object(list[i], str);
	   look_for_symb(list[i]);
		  }
		  if(envst=="room/stor" || envst=="room/shop" || envst=="room/pub2" ||envst=="room/yard" || envst=="room/narr" || envst == "room/alle" || envst=="room/bank"){
     tell_object(list[i], str);
	 look_for_symb(list[i]);
		  }
	  if(envst=="room/inn" || envst=="room/east" || envst=="room/suna" ||envst=="room/jetty" || envst=="room/well" || envst == "room/pub3" || envst=="room/back"){
     tell_object(list[i], str);
	 look_for_symb(list[i]);
		  }
	   if(envst=="room/nort" || extract(envfil,0,10) == "room/southr"){
      tell_object(list[i], str);
	look_for_symb(list[i]);
		  }
    }
        }
}
     i = i +1;
 }
 }


look_for_symb(object ob){
if(ob->query_guild_name() == "symbiote" || ob->query_guild_name() == "neo symbiote"){
           tell_object(ob,
			   "Your symbiote cries out in pain as the clock tower's bells chime!\n");
		   ob->heal_self(-(30 + random(21)));
		   if(ob->query_hp() <= 0){
			   ob->hit_player(1000);
		   }
   }
}
