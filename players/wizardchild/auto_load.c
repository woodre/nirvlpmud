#ifndef __LDMUD__ /* Rumplemintz */
#define root "/players/wizardchild/"
load_objects() {
  object vt,ln,vg;
  call_other(root+"closed/no_channels","??");
  call_other(root+"toys/hickey","??");
  call_other(root+"toys/ering","??");
  call_other("/room/vill_track","??");
  call_other("/room/vill_green","??");
  vt = find_object("/room/vill_track");
  vg = find_object("/room/vill_green");
  if(!present("dispenser",vt))
    move_object(clone_object(root+"toys/dispense"),vt);
  call_other("/players/wizardchild/jerk/no_tell","??");
  call_other("/players/wizardchild/engage/engagering","??");
  call_other("/players/wizardchild/closed/logger/main_obj","??");
/*
  if(!present("statue",vt))
    move_object(clone_object(root+"mud/spock"),vt);
*/
  destruct(this_object());
}
#else
#define root "/players/wizardchild/"

void load_objects() {
  object vt, vg;
  load_object(root+"closed/no_channels");
  load_object(root+"toys/hickey");
  load_object(root+"toys/ering");
  load_object("/room/vill_track");
  load_object("/room/vill_green");
  vt = find_object("/room/vill_track");
  vg = find_object("/room/vill_green");
  if (!present("dispenser", vt))
    move_object(clone_object(root+"toys/dispense"), vt);
  load_object(root+"jerk/no_tell");
  load_object(root+"engage/engagering");
  load_object(root+"closed/logger/main_obj");
}
#endif
