#include "attribs.h"
short() { return "A test object"; }
long() {
write("This object will help you out in testing.\n"+"Type list_cmds\n");
}
id(str) { return str == "test" || str == "object" || str == "test object"; }
get() { return 1; }
drop() { destruct(this_object()); }
init() {
move_object(this_player(),"/open/new/test_room");
add_action("list_cmds","list_cmds");
add_action("dcalm","dcalm");
add_action("teport","teport");
add_action("trans","trans_stuff");
}
list_cmds() {
write("trans_stuff hp xx Mock trans hps\n");
write("trans_stuff sp xx Mock trans sps\n");
write("dcalm         Mock calm monsters\n");
write("teport         Mock teleport\n");
return 1;
}
trans(str) {
if(!str) return 0;
if(strlen(str) > 2) str = str[0..1];
if(str == "hp") {
if(environment(this_player())->query_attribute(NO_TRANSFER_HP)) {
  write("You room prevents you.\n");
  return 1;
}
else write("You just mock transfered some hp.\n");
} else {
if(environment(this_player())->query_attribute(NO_TRANSFER_SP)) {
  write("Your room prevents you.\n");
  return 1;
} else write("You just mock transfered some sp.\n");
return 1;
}
}
dcalm() {
if(present("monster",environment(this_player()))->query_attribute(NO_CALM)) {
/* ONLY CHECKS ABOVE IN ***MONSTER*** */
  write("The monster avoids your attempts\n");
  return 1;
} else write("He seems calm...doh.\n");
return 1;
}
teport() {
if(environment(this_player())->query_attribute(NO_TELEPORT)) {
  write("You fail to leave.\n");
  return 1;
} else write("There you went.\n");
return 1;
}
