id(str) {return "area";}
query_auto_load() { return "/players/mythos/closed/play/tell.c:"; }

init() {
  add_action("all","all");
}

all(str) {
  if(!str) {
   write("try again...\n");
  return 1;}
  else {
  say(str+"\n");
  write(str+"\n");
  return 1;}
return 1;}
