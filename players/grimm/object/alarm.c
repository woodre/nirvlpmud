inherit "obj/treasure";
int alarm, alarm_on;
reset(arg) {
   if (arg) return;
   alarm_on = 0;
   alarm = time();
   set_short("An alarm clock");
   set_alias("clock");
   set_weight(2);
   set_value(100);
   set_long("An alarm clock. You can \"set_alarm <X>\" where X is the number of minutes\nbefore you want the clock to go off, \"turn on\" and \"turn off\" the alarm,\nand \"check\" the times.\n");
  set_heart_beat(1);
}
init() {
  add_action("set","set_alarm");
  add_action("turn","turn");
  add_action("check","check");
}
heart_beat() {
  if(alarm_on) {
    if(alarm==time()) {
      tell_object(environment(this_object()),"\n\n\nYOUR ALARM CLOCK GOES OFF!\n\n\n");
      alarm_on = 0;
     }
  }
}
set(x) {
  int z;
  if(!x) {
    write("Usage is:\nset_alarm <X>\nWhere X is the number of minutes from now that you want the alarm to go off.\n");
    return 1;
  }
  sscanf(x,"%d",z);
  alarm = time()+(z*60);
  write("The alarm will go off at "+ctime(alarm)+".\n");
  write("(Don't forget to \"turn on\" the alarm.)\n");
  return 1;
}
check() {
  write("The current time is:      "+ctime(time())+"\n");
  write("The alarm will go off at: "+ctime(alarm)+"\n");
  write("The alarm is currently ");
  if(alarm_on) write("on.\n");
  else write("off.\n");
  return 1;
}
turn(str) {
  if(str=="on" || str=="On" || str=="ON") {
    alarm_on = 1;
  } else {
    if(str=="off" || str=="Off" || str=="OFF") {
      alarm_on = 0;
    } else {
      write("You can either turn the alarm on or off.\n");
    }}
  return 1;
}
