inherit "obj/treasure";
reset(arg) {
  if(arg) return;
    set_id("pearl");
    set_alias("gem");
    set_short("A beautiful white pearl");
    set_long("Hidden within is the ability to read into\n"+
             "the help files of the Order.  Type dhelp\n");
    set_weight(1);
    set_value(1);
}


init() {
  ::init();
  add_action("dhelp","dhelp");}
  
  dhelp(str) {
int n;
  if(!str) { cat("/players/mythos/closed/guild/help/help1"); return 1;}
  if(!cat("/players/mythos/closed/guild/help/"+str)) {
  write("Subject not found....\n"); }
return 1;}
