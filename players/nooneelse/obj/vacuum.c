/*
  vacuum.c - get rid of merlyn's clouds :)
*/

inherit "obj/treasure";

init() {
  ::init();

  add_action("vacuum", "vacuum");
}

vacuum(str) {
  object cloud_obj;
  string str1, str2, str3;
  if (!str || str != "cloud") return 0;
  cloud_obj=present("cloud", environment(this_player()));
  if (!cloud_obj) {
    write("There is no cloud here!\n");
    return 1;
  }
  str1=file_name(cloud_obj);
  if (sscanf(str1, "%s/merlyn/closed/guild/cloud#%s", str2, str3) != 2) {
    write("Sorry, this vacuum only works on mage's clouds.\n");
    return 1;
  }
  destruct(cloud_obj);
  write("You point the vacuum at the cloud and it is sucked away.\n");
  say(this_player()->query_name()+
      " points a vacuum at the cloud and it is sucked away.\n", this_player());
  return 1;
}

reset(arg) {
  set_id("vacuum");
  set_short("A vacuum");
  set_long(
    "It is a small vacuum cleaner with the picture of a cloud on the side.\n");
  set_value(500);
  set_weight(2);
}
