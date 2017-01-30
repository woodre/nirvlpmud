/*
 snooper_bat.c - listening device (nooneelse's new improved model :)
                 it allows a vampire to listen to what's said in a room
                 for 20 clock ticks.
*/

object obj, master_obj;

string master_name;

int bat_age, bat_lifespan;
 
set_owner(str) {
  master_name = str;
  master_obj = find_player(str);
  set_heart_beat(1);
  return 1;
}
 
reset(arg) {
  if (arg) return;

  bat_lifespan=20;
  enable_commands();
  set_heart_beat(1);
  destruct(this_object());
  /* the above aded by wizardchild
     this *really* is illegal, ok ? hello ? */
}

heart_beat() {
  bat_age=bat_age+1;
  if (bat_age >= bat_lifespan) {
    tell_object(master_obj, "You cannot concentrate any longer.  "+
                            "The snooper bat is released and flys away.\n");
    destruct(this_object());
    return 1;
  }
}  

catch_tell(str) {
  if(!master_obj) { destruct(this_object()); return 1;}   /*addied in a check so that if player is  no longer on then it is dested - mythos <11/3/95>  */
  tell_object(master_obj, "==>>> From the environment of\n"+
              "      "+environment(this_object())->short()+":\n"+
              "==>"+str);
  return;
}

query_weight() { return 666; }
 
query_value() { return 0; }

id(str) { return (str=="snooperbat" ||
                  str==master_name+"snooperbat" ||
                  str=="bat"); }
