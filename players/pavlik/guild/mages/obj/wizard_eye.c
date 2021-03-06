#include "/players/pavlik/guild/mages/macs"

long() {
  write("A mysterious floating eye.\n");
  return;
}


reset(arg) {
 if(arg)
  return;
}

short() { "A floating eyeball"; }


id(str) {
  return str == "wizard_eye" || str == "eyeball" || str == "eye";
}

query_value() {
    return 0;
}

get() {
    return 0;
}

do_report(dir, num) {
  int i;
  object ob, obj;

  if(!num) write("To the "+HIC+dir+NORM+":\n");
  obj = all_inventory(environment(this_object()));

  if(!obj) {
    write("  nothing.\n");
  }
  else {
    for(i=0; i<sizeof(obj); i++) {
      if(obj[i]->short()) write("  "+obj[i]->short()+"\n");
    }
  }

  return 1;
}

exit_report(str) {
  int good_exit, i;
  int count;
  string exits, fname;

  good_exit = 1;
  count = 0;

  while(good_exit == 1 && count < 4) {
    good_exit = 0;
    fname = 0;
    exits = environment(this_object())->query_dest_dir();
    for(i=0; i<sizeof(exits); i+=2) {
      if(exits[i+1] == str) {
        fname = exits[i];
        good_exit = 1;
      }
    }
    if(fname) {
      move_object(this_object(), fname);
      if(count == 0) write("Nearby to the "+HIC+str+NORM+":\n");
      if(count == 1) write("To the "+HIC+str+NORM+":\n");
      if(count == 2) write("Far away to the "+HIC+str+NORM+":\n");
      if(count == 3) write("Very far away to the "+HIC+str+NORM+":\n");
      do_report(str, 1);
      count++;
    }
  }
  return 1;
}




