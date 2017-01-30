/*
   This is based highly off of 
     /open/examples/OBJ/bartering.c
    written by Feldegast
  I added in the ability to chk how many times you've bartered.
*/
inherit "obj/armor";

reset(arg) {
  if(arg) return;
  set_id("dress");
  set_alias("dress");
  set_short("Black Dress");
  set_long(
"A long sleek black dress.  It is made out of a soft and silky material \n"+
"that seems to fend off light.  You might be able to 'barter' this if \n"+
"you found the right person.  But many would be inclined to just wear it.\n"
  );
  set_ac(1);
  set_type("misc");  /* armor,helmet,boots,ring,amulet,shield,misc  */
  set_weight(1);
  set_value(800+random(70));
}

init() {
  ::init();
  add_action("barter","barter");
}

barter(str) {

if(id(str)) {
 if(present("drand claclah",environment(this_player()))) {
  if(present("drand claclah",environment(this_player()))->platecheck() < 3){
   present("drand claclah",environment(this_player()))->platebarter();
   write(
    "   Drand picks up the dress and blushes a bit.  He then sets it \n"+
    "neatly in his backpack.  He pushes the contents of his backpack \n"+
    "around trying to make room.  He then returns with some coins for you.\n"
            );
   this_player()->add_money(value);
   this_player()->add_weight(-1);
   destruct(this_object());
   return 1; }
  write("Drand says:  I have too many dresses as is.\n");
  return 1;
  }
 write("You need to find the right person to barter with.\n");
 return 1;
 }
write("Barter what?\n");
return 1;
}
