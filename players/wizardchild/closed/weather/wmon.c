/* File: wmon.c (monitor of weather.c object)
   Creator: Wizardchild (04/12/95)
*/
#define WEATHERC "/players/wizardchild/closed/weather/weather.c"
#define ERRORFIL "/players/wizardchild/closed/weather/ERROR"
string nowtime;
short() {
  return "A weather display";
}
long()  {
  write("A weather display for monitoring the current weather.\n");
  write("Type \"check weather\" to see the current status.\n");
  return 1;
}
id(str) { 
  return str == "display" || str == "weather display"; 
}
reset(arg) {
  if(arg) 
    return 0;
  nowtime = ({"nighttime", "sunrise", "daytime", "sunset"});
}
init() {
  string str, jnk, nm;
  int i;
  str = file_name(environment(this_object()));
  if(living(environment(this_object())))
    move_object(this_object(), environment(environment(this_object())));
  if(!sscanf(str, "/players/%s/workroom", jnk) &&
     !sscanf(str, "/players/%s/%swork", nm, jnk)) {
    write("Object not supposed to be here.\n");
    destruct(this_object());
  } else 
    add_action("check", "check");
}
pat_str(ob) {
  int i;
  string weather;
  string blah;
  blah = ob->query_weather();
  if(!blah) return 0;
  weather = ({"b","clear","c","cloudy","h","hot","o","overcast",
              "r","rainy","s","snowy","u","humid","w","windy"});
  for(i = 0; i < sizeof(weather); i++) 
    if(weather[i] == blah) 
      return weather[i+1];
  return -1;
}
sea_str(ob) {
  int i; 
  string season;
  i = ob->query_season();
  season = ({"winter", "spring", "summer", "autumn"});
  return season[i];
}
string *s;
object mememe;
check_disp_err() {
  input_to("check_err");  
  write("Do you wish to view the most recent errors (y/N)? ");
  return 1;
}
check_err(str) {
  int i, cnt, tim;
  string jnk1, jnk2;
  if(!str || !(str == "y" || str == "Y")) 
    write("Ok.\n");
  else {
    if(!sscanf(extract(ctime(time()), 8, 9), "%d", tim))
      sscanf(extract(ctime(time()), 8, 9), " %d", tim);
    tim -= 3;  /* view logs for past 3 days */
    for(i = 0; i < sizeof(s); i++) {
      sscanf(extract(s[i], 8, 9), "%d", cnt);
      if(cnt >= tim)
        write((i+1)+") "+s[i]+"\n");
    }
  }
  return 1;
}
check(str) {
  object ob;
  int i, cnt;
  string *s;
  mememe = 0;
  mememe = this_player();
  if(str != "weather") 
    return 0;
  write("Weather status:\n");
  ob = find_object(WEATHERC);
  write("The weather object is currently "+(ob?"cloned":"idle")+
        " and "+(ob->query_working() ? "working" : "down")+".\n");
  if(ob) {
    write("The season has been recognized as "+sea_str(ob)+".\n");
    write("The current pattern is "+pat_str(ob)+" ("+
           nowtime[ob->query_daytime()]+").\n");
    write("The object is using "+ob->query_fname()+" for its data.\n");
    write("The current weather has been running for "+
           (ob->query_count()*10)+" minutes.\n");
    if(file_size(ERRORFIL) < 1)
      write("No errors have been recorded.\n");
    else {
      s = explode(read_file(ERRORFIL), "\n");
      write(" There are "+sizeof(s)+" errors logged.\n");
      check_disp_err();
    }
    ob = users();
    for(cnt = i = 0; i < sizeof(ob); i++)
      if(ob[i]->on_channel("weather")) 
        cnt++;
    write(cnt+" people are currently on the weather channel.\n");
  }
  return 1;
}
