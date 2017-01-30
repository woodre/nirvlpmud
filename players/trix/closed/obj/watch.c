string str,month,weekday;
object who;
int day,hour,minute,second,year;
reset(arg) {
        if(arg) return;
}

id( str ) {
        if(str=="watch") return 1;
        return 0;
}

long() {
        write( "This is an alarm watch.\n");
}

short()
  { return "A clock alarm"; }
init()
{
  add_action( "ora","time");
  add_action( "alarm","alarm");
}

alarm(str)
{ int ora,tra,minuto;
  if(sscanf(str,"%d:%d",ora,minuto)!=2) {
    write("Wrong syntax, type 'alarm hh:mm' (hh=hour,mm=minute).\n"); return 1;}
  str=ctime(time());
  sscanf(str,"%s %s %d %d:%d:%d %d",weekday,month,day,hour,minute,second,year);
  ora=ora-hour;
  if(ora<0) ora+=12;
  minuto=minuto-minute;
  tra=(ora*60+minuto)*60-second;
  call_out("sveglia",tra);
  who=this_player();
  write(tra+"\n");
  return 1;
}
sveglia()
{ tell_object(who,"ALARM CLOCK!\n");
}

    
ora()
{ 
  str=ctime(time());
  sscanf(str,"%s %s %d %d:%d:%d %d",weekday,month,day,hour,minute,second,year);
  write("Anno: "+year+"\n");
  write("Mese: "+month+"\n");
  write("Giorno: "+weekday+" "+day+"\n");
  write("Ora: "+hour+"\n");
  write("Minuto: "+minute+"\n");
  write("Secondo: "+second+"\n");
  return 1;
}
get() {
        return 1;
}
drop() {
        return 0;
}
