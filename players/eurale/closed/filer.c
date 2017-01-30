/* This workreport filer is for your protection.  All wizzes use
   some form of filer to keep track of what they do and why in case
   they ever need to refer back to it.  All you need to do is change
   all the NAME locations to your name.
*/

#define TP this_player()
id(str) { return str == "filer"; }

drop() {
  write("Your filer disappears in a FLASH!\n");
  destruct(this_object());
  return 1; }

short() { return "Workreport 'filer'"; }
long() { write(
  "This is a workreport filer.  It is fast and easy to use but is\n"+
  "limited to 255 char strings.  Just type 'file <string>'.\n"); }

init() {
  if(TP->query_real_name() != "NAME") {
    write("The filer disappears as it touches a non-owner...\n");
    destruct(this_object()); }
  add_action("filer","file");
}

filer(str) {
  if(!str) return 0;
  write_file("/players/NAME/WORK_REPORT",ctime(time())+" "+str+"\n");
  write_file("/log/WR/NAME_workreport",ctime(time())+"  "+str+".\n");
  write("Report done.\n");
return 1;}
