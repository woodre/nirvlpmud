/*
 * Check if alignment is good or evil...
 */

status main(string str) {
  if (str ) return 0;
  if (this_player()->query_alignment() < 0)
    write("You are of an Evil alignment.\n");
  else
    write("You are of a Good alignment.\n");
  return 1;
}
