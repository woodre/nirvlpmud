#define STARTING 900
/*
 *  Mud-Time by Grimm (11/92)
 */
inherit "/obj/treasure";
int myr, mmo, mdy, mhr, mmin;
reset(arg) {
  if(arg) return;
  set_short("Mud-Watch");
  set_long("This is the mud's official mud-watch. It will tell you\n"+
           "the mud time and the actual time. Just type \"time\" to see it.\n");
  set_value(100);
  set_weight(0);
  set_alias("watch");
}

init() {
  add_action("query_full_time","time");
}

query_mud_year() {
  return myr = (time() / 2592000)+STARTING;
}

query_mud_month() {
  return mmo = ((time() - ((query_mud_year()-STARTING)*2592000))/259200);
}

query_mud_day() {
  return mdy = ((time() - ((query_mud_year()-STARTING)*2592000) -
                          (query_mud_month()*259200))/7200)+1;
}

query_mud_hour() {
   return mhr = ((time() - ((query_mud_year()-STARTING)*2592000) -
                           (query_mud_month()*259200) -
                           ((query_mud_day()-1)*7200))/300);
}

query_mud_hour_12() {
  if(query_mud_hour()<13) return query_mud_hour();
  return query_mud_hour()-12;
}

query_mud_minutes() {
  return mmin = ((time() - ((query_mud_year()-STARTING)*2592000) -
                           (query_mud_month()*259200) -
                           ((query_mud_day()-1)*7200) -
                           (query_mud_hour()*300))/5);
}

query_full_time() {
  write("The time is now: "+ctime(time())+".\n");
  write("Mud time is: "+day_name()+" the "+(query_mud_day())+day_fix()+
        " of "+month_name()+", "+(query_mud_year())+" at "+
        query_mud_hour_12()+":");
  if(query_mud_minutes()<10) 
    write("0"+query_mud_minutes());
  else
    write(query_mud_minutes());
  write(" "+minutes_apm()+".\n");
  write("The season is "+query_mud_season()+".\n");
  write("It is "+query_ddnd()+".\n");
  return 1;
}

month_name() {
  int x;
  x = query_mud_month();
  if(x==0) { return "Ktah"; }
  if(x==1) { return "Saychen"; }
  if(x==2) { return "Swerdna"; }
  if(x==3) { return "Nivlac"; }
  if(x==4) { return "Sebboh"; }
  if(x==5) { return "Melog"; }
  if(x==6) { return "Drazil"; }
  if(x==7) { return "Clocna"; }
  if(x==8) { return "Julnia"; }
  return "Deochen";
}

day_name() {
  int x;
  x = query_mud_day()-1;
  if(x==0 || x==9 || x==18 || x==27) { return "Moshta"; }
  if(x==1 || x==10 || x==19 || x==28) { return "Tievnar"; }
  if(x==2 || x==11 || x==20 || x==29) { return "Veshnek"; }
  if(x==3 || x==12 || x==21 || x==30) { return "Shootok"; }
  if(x==4 || x==13 || x==22 || x==31) { return "Freignosh"; }
  if(x==5 || x==14 || x==23 || x==32) { return "Marlouk"; }
  if(x==6 || x==15 || x==24 || x==33) { return "Jalnier"; }
  if(x==7 || x==16 || x==25 || x==34) { return "Calshen"; }
  return "Metjun";
}

query_day() {
  if(query_mud_hour()>6 && query_mud_hour()<19) return 1;
  return 0;
}

query_night() {
  return !query_day();
}

query_ddnd() {
  if(query_mud_hour()>6 && query_mud_hour()<18) return "daytime";
  if(query_mud_hour()>5 && query_mud_hour()<7) return "dawn";
  if(query_mud_hour()<19) return "dusk";
  return "nighttime";
}

day_fix() {
  int x;
  x = query_mud_day()-1;
  if(x==0 || x==20 || x==30) { return "st"; }
  if(x==1 || x==21 || x==31) { return "nd"; }
  if(x==2 || x==22 || x==32) { return "rd"; }
  return "th";
}

minutes_apm() {
  int x;
  x = query_mud_hour();
  if(x<12) { return "am"; }
  return "pm";
}

query_mud_season() {
  int x;
  x = query_mud_month();
  if(x==0 || x==8 || x==9) { return "Winter"; }
  if(x==3 || x==4 || x==5) { return "Summer"; }
  if(x==1 || x==2) { return "Spring"; }
  return "Fall";
}
