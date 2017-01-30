/* Daemon to keep track of who has attacked chess pieces  */

string *white,*black;

/*  check array for name and add it if not there  */
black(str) {
  if(!black) black = ({str});
  else black += ({str});
}
white(str) {
  if(!white) white = ({str});
  else white += ({str});
}

/*  Check arrays to see if the player name has attacked  */
check_black(str) {
  if(!black) return 0;
  if(member_array(str, black) < 0) return 0;
  else return 1;
}

check_white(str) {
  if(!white) return 0;
  if(member_array(str,white) < 0) return 0;
  else return 1;
}
