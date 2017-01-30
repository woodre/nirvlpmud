/*
   This is based highly off of 
     /open/examples/OBJ/bartering.c
    written by Feldegast
  I added in the ability to chk how many times you've bartered.
*/
inherit "obj/treasure";

reset(arg) {
  if(arg) return;
  set_id("fang of sithos");
  set_alias("fang");
  set_short("Fang of Sithos");
  set_long(
"A strong and solid fang.  It slides down to a pin sharp point.  \n"+
"It looks like it was once a powerful weapon.  Now it is broken \n"+
"at the top and to awkward to hold.  You could barter it for \n"+
"quite a profit if you found the right person.\n"
  );
  set_weight(1);
  set_value(4500+random(600));
}

init() {
  add_action("barter","barter");
}

barter(str) {

if(id(str)) {
 if(present("drand claclah",environment(this_player()))) {
   write(
    "   Drands eyes light up with joy.  'Oh, you got him!  You killed \n"+
    "that horrible Sithos!'  He digs through all of his pockets and \n"+ 
    "finds some coins.  He shakes your hand and leaves you with the \n"+
    "gold.\n"
            );
   this_player()->add_money(value);
   this_player()->add_weight(-1);
   destruct(this_object());
   return 1; }
 write("You need to find the right person to barter with.\n");
 return 1;
 }
write("Barter what?\n");
return 1;
}
