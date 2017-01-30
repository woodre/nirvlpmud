/*
   This is based highly off of 
     /open/examples/OBJ/bartering.c
    written by Feldegast
*/
inherit "obj/treasure";

reset(arg) {
  if(arg) return;
  set_id("fang");
  set_alias("fang");
  set_short("Fang of Sithos");
  set_long(
"This is a test object!\n"
  );
  set_weight(2);
  set_value(4500+random(1000));
}

init() {
  add_action("cmd_barter","barter");
}

cmd_barter(str) {

if(id(str)) {
 if(present("drand claclah",environment(this_player()))) {
  if(present("drand claclah",environment(this_player()))->fangcheck() < 2){
   present("drand claclah",environment(this_player()))->fangbarter();
   write("We should be talking about the obj here\n");
   this_player()->add_money(value);
   this_player()->add_weight(-2);
   destruct(this_object());
   return 1; }
  write("Drand doesn't want any more yadda\n");
  return 1;
  }
 write("You need to find the right person to barter with yadda\n");
 return 1;
 }
write("Barter what?\n");
return 1;
}

