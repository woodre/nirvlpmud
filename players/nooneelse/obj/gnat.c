/*
 gnat.c - listening device from smiley (nooneelse's new improved model :)
*/

object master;
int gnat_on, gnat_log_on;
 
init() {
  add_action("capture",    "capture");
  add_action("capture",    "catch");
  add_action("on_off",     "gnat");
  add_action("buzz",       "buzz");
  add_action("squash",     "squash");
}
 
capture(str) {
  if (!str || str != "gnat") return;
  if (!master) master = this_player();
  if (this_player() != master) {
    write("It buzzes.\n");
    tell_object(master,"\nYou hear a familiar, high-pitched buzz.\n");
    tell_object(master,"   It's the alarm!\n"+this_player()->query_name()+
                " is trying to capture your gnat!\n");
    return 1;
  }
  write("............................................................\n"+
        ":    The gnat emits a high pitched buzz....                :\n"+
        ":                                                          :\n"+
        ": The gnat is now YOURS.  It will tell you what is said in :\n"+
        ": any room you drop it in.                                 :\n"+
        ":                                                          :\n"+
        ": It will, sound an alarm which only you can hear to tell  :\n"+
        ": you that someone has captured it, or is trying to.       :\n"+
        ":                                                          :\n"+
        ": You can turn it on or off                                :\n"+
        ":    Use: gnat on/off                                      :\n"+
        ":                                                          :\n"+
        ": You can turn the log on or off (writes to a file)        :\n"+
        ":    Use: gnat log on/off                                  :\n"+
        ":                                                          :\n"+
        ": Since it is invisible, you can find out if it's in the   :\n"+
        ": same room as you by typing 'buzz'.                       :\n"+
        "............................................................\n");
  return 1;
}
 
on_off(str) {
  if (str=="off") {
    if(gnat_on) {
      write("You turn the gnat off.  (I guess you're not it's type :)\n");
      gnat_on=0;
      return 1;
    }
    else {
      write("The gnat is not turned on.  (I guess you're not it's type :)\n");
      return 1;
    }
  }
  if (str=="on") {
    if(gnat_on) {
      write("The gnat is already turned on (pervert! :)\n");
      return 1;  
    }
    else {
      write("You turn the gnat on (pervert! :)\n");
      gnat_on=1;
      return 1;
    }
  }
  if (str=="log off") {
    if(gnat_log_on) {
      write("You turn the gnat log off.\n");
      gnat_log_on=0;
      return 1;
    }
    else {
      write("The gnat log is not turned on.\n");
      return 1;
    }
  }
  if (str=="log on") {
    if(gnat_log_on) {
      write("The gnat log is already turned on.\n");
      return 1;
    }
    else {
      write("You turn the gnat log on.\n");
      gnat_log_on=1;
      return 1;
    }
  }
}

buzz() {
  write("You hear a soft buzzing.\n");
  return 1;
}

squash() {
  write("You hear a sharp quick buzz which stops abruptly.\n");
  destruct(this_object());
  return 1;
}

reset(arg) {
  if (arg) return;

  gnat_on=0;
  enable_commands();
}

am_i_a_servant() { return 1; }

catch_tell(str) {
  if (gnat_on)
    tell_object(master,">>> From gnat in: " +
                environment(this_object())->short()+".\n=====>"+str);
  if (gnat_log_on)
    write_file("/players/nooneelse/closed/gnat_log", str);
  return;
}

get() {
  if (!master || this_player() == master) return 1;
  tell_object(master,"\nYou hear a familiar, high-pitched buzz.\n");
  tell_object(master,"   It's the alarm!\n"+this_player()->query_name()+
              " has captured your gnat!\n");
  return 1;
}

drop(str) {
  if (str=="gnat") {
    tell_object(this_player(), "You drop the gnat.\n");
    move_object(this_object(), environment(this_player()));
    return 1;
  }
}

query_weight() { return 1; }
 
query_value() { return 50; }

id(str) { return str=="gnat" || str=="bug"; }
