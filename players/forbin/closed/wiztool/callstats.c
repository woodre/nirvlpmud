/*
//  Copied from Feldegast
*/

inherit "obj/treasure";

reset(arg) {
  set_id("wand");
  set_alias("calltest");
  set_short("Wand of Calltesting");
  set_long("Blah blah blah...'calltest' to dump callouts.\n");
  set_weight(1);
  set_value(0);
}
init() {
  add_action("calltest","calltest");
  add_action("callcount","callcount");
}
callcount() {
  write("There are "+sizeof(call_out_info())+" call_outs going right now.\n");
  return 1;
}
calltest() {
  mixed it;
  int i;
  rm("/players/forbin/logs/call_outs.log");
  it=call_out_info();
  for(i=0; i<sizeof(it); i++) {
    write_file("/players/forbin/logs/call_outs.log",i+". ");
    if(sizeof(it[i]) > 0)
    write_file("/players/forbin/logs/call_outs.log",file_name(it[i][0]));
    if(sizeof(it[i]) > 1)
    write_file("/players/forbin/logs/call_outs.log","\t"+it[i][1]);
    write_file("/players/forbin/logs/call_outs.log","\n");
  }
  write("It is done.\n");
  return 1;
}
