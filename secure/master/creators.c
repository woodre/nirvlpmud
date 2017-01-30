string master_create_wizard(string owner, object caller) {
  string txt, tmp1, tmp2;
  object access;
  int tmp;

  if (!owner) return 0;

  if (!valid_player_call(caller)) return 0;
  write_file("/log/WIZ",
        "Name: " + owner + ", By: " + (string)this_player()->query_real_name()
      + " Time: " + ctime(time()) + "\n");

  /* promote wizard */

  if (file_size(WIZARD_DIR + owner) != -2) {
    tell_object(caller, "Adding Wizard Directory...\n");
    mkdir(WIZARD_DIR + owner);
  }
  if (file_size(WIZARD_DIR + owner + "/open") != -2) {
    tell_object(caller, "Adding Open directory, ~/open\n");
    mkdir(WIZARD_DIR + owner + "/open");
  }
  if (file_size(WIZARD_DIR + owner + "/private") != -2) {
    tell_object(caller, "Adding Private directory, ~/private\n");
    mkdir(WIZARD_DIR + owner + "/private");
  }
  if (file_size(WIZARD_DIR + owner + "/" + DEAD_ED) != -2) {
    tell_object(caller, "Adding dead edit directory, ~/" + DEAD_ED + "\n");
    mkdir(WIZARD_DIR + owner + "/" + DEAD_ED);
  }
  if (file_size(INIT_ACCESS) > 0
   && file_size(WIZARD_DIR + owner + "/access.c") < 0) {
    tell_object(caller, "Adding Configurable Access Object...\n");
    txt = "#define NAME \"" + owner + "\"\n";
    write_file(WIZARD_DIR + owner + "/access.c", txt);
    txt = read_file(INIT_ACCESS);
    write_file(WIZARD_DIR + owner + "/access.c", txt);
  }
  if (file_size(INIT_WORKROOM) > 0
   && file_size(WIZARD_DIR + owner + "/workroom.c") < 0) {
    tell_object(caller, "Adding Workroom...\n");
    txt = "#include <mudlib.h>\ninherit ROOM;\n\n";
    write_file(WIZARD_DIR + owner + "/workroom.c", txt);
    txt = read_file(INIT_WORKROOM);
    write_file(WIZARD_DIR + owner + "/workroom.c", txt);
  }
}

