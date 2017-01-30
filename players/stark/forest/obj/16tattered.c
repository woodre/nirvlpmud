/*
   This is based highly off of 
     /open/examples/OBJ/bartering.c
    written by Feldegast
  I added in the ability to chk how many times you've bartered.
*/
inherit "obj/treasure";

reset(arg) {
  if(arg) return;
  set_id("black fabric");
  set_alias("fabric");
  set_short("Black Fabric");
  set_long(
"A tattered piece of of black fabric.  It has many rips and tear in \n"+
"it.  Dust and dirt cover it and color it grey.  You might be able \n"+
"to 'barter' it if you found the right person.\n"
  );
  set_weight(1);
  set_value(800+random(10));
}

init() {
  add_action("barter","barter");
}

barter(str) {

if(id(str)) {
 if(present("drand claclah",environment(this_player()))) {
  if(present("drand claclah",environment(this_player()))->fabriccheck() < 10){
   present("drand claclah",environment(this_player()))->fabricbarter();
   write(
    "   Drand smirks at the fabric.  He nods and stuffs it deep into \n"+
    "his backpack.  He shuffles around the pockets and finds some \n"+
    "coins for you.\n"
            );
   this_player()->add_money(value);
   this_player()->add_weight(-1);
   destruct(this_object());
   return 1; }
  write("Drand says:  Sorry, I just don't have any more room.\n");
  return 1;
  }
 write("You need to find the right person to barter with.\n");
 return 1;
 }
write("Barter what?\n");
return 1;
}
