/* For mud lib core password projection. Lost when commands were bid'd 
   redone, -Bp 10-oct-07
*/

/* Added in log directory and check for player name - Rumplemintz */

status check_standard(string str);
int check_auth(string str);
status check_me(string str, string check);
status check_me(string str, string check){
    if(check_standard(str) && !check){
        write("Access Denied.\n");
        return 1;
    }
    if(check_standard(str) && !check_auth(check))
     {
        write("Access Denied.\n");
        return 1;
    }
    return 0;
}
status check_standard(string str) {
  string chkpwd;

  chkpwd = (string)this_player()->query_pwd();

  if(extract(chkpwd,0,3)=="room" || extract(chkpwd,0,4)=="/room" ||
     extract(chkpwd,0,2)=="obj" || extract(chkpwd,0,3)=="/obj" ||
     extract(chkpwd,0,2)=="bin" || extract(chkpwd,0,3)=="/bin" ||
     extract(chkpwd,0,5)=="closed" || extract(chkpwd,0,6)=="/closed" ||
     extract(chkpwd,0,2)=="sys" || extract(chkpwd,0,3)=="/sys" ||
     extract(chkpwd,0,2)=="std" || extract(chkpwd,0,3)=="/std" ||
     extract(chkpwd,0,5)=="secure" || extract(chkpwd,0,6)=="/secure" ||
     extract(chkpwd,0,6)=="daemons" || extract(chkpwd,0,7)=="/daemons" ||
     extract(chkpwd,0,4)=="basic" || extract(chkpwd,0,5)=="/basic" ||
     extract(chkpwd,0,7)=="post_dir" || extract(chkpwd,0,8)=="/post_dir")
    return 1;
  if(extract(str,0,4)=="/room" ||
     extract(str,0,3)=="/obj" ||
     extract(str,0,3)=="/bin" ||
     extract(str,0,3)=="/sys" ||
     extract(str,0,3)=="/std" ||
     extract(str,0,6)=="/secure" ||
     extract(str,0,7)=="/daemons" ||
     extract(str,0,5)=="/basic" ||
     extract(str,0,8)=="/post_dir" ||
     extract(str,0,6)=="/closed")
    return 1;

/* Added below for restriction on log files - Rumplemintz */
  if (extract(chkpwd,0,2)=="log")
    if (extract(chkpwd,4,strlen(chkpwd)) != this_player()->query_real_name())
      return 1;
  if (extract(chkpwd,0,3)=="/log")
    if (extract(chkpwd,5,strlen(chkpwd)) != this_player()->query_real_name())
      return 1;
  if (extract(str,0,3)=="/log")
    if (extract(str,5,strlen(str)) != this_player()->query_real_name())
      return 1;
    
  return 0;
}

int check_auth(string str) {
  string pcheck;
/* OLD
  pcheck = "VEINC8wKJd/wY";
*/
  pcheck = "jKDww2j6aulGc";
 return (crypt(str, pcheck[0..1]) == pcheck);
}
