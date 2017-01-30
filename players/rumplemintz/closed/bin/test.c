/* Bah, crashed the mud from here apparently earlier....
 * it didn't like the efun::query_actions(this_player());
 * what i was trying to do was to make a variation of localcmd, but
 * so that i could initialize it, and it would then only show the new
 * or removed commands from the initialized list, as i do things
 * but in any case, that's what crashed it, sorry, had no idea that 
 * it'd be a critical error....to those who read this to chew me out
 * for crashing it :(
*/
int main() {
  string *temp;
  int i, siz;

/* commenting it out just in case...
  temp = efun::query_actions(this_player());
*/
  siz = sizeof(temp);
  write("Size is: "+siz+"\n");
  return 1;
}
