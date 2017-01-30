int sand_points;

void reset(int arg) {
  int i, siz;
  string *files;
  string temp;

  if (arg) destruct(this_object());

  siz = sizeof(files = get_dir("/players/snow/dervish/member/*.o"));

  for (i = 0; i < siz; i++) {
#ifndef __LDMUD__ /* Rumplemintz */
    temp = "players/snow/dervish/member/"+files[i][0..-3];
#else
    temp = "players/snow/dervish/member/"+files[i][0..<3];
#endif
    restore_object(temp);
if (sand_points > 10000)
#ifndef __LDMUD__ /* Rumplemintz */
    write(pad(files[i][0..-3], 12)+sand_points+"\n");
#else
    write(pad(files[i][0..<4], 12)+sand_points+"\n");
#endif
  }
}
