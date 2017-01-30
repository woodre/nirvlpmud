/*
 * Note - drop a note into a file for perusal later
 */

status main(string str) {

  if (!str) {
    write("What do you want to put in the suggestion box?\n");
    return 1;
  }
  write_file("/players/guilds/dopplegangers/log/ideas",
             "On " + ctime() + ": " + this_player()->query_name() +
           " wrote you: \n" + str +
           "\n----------------------------------------------------------\n");
  write("The note has been dropped in the box.\nYou Rock!!\n");
  return 1;
}
