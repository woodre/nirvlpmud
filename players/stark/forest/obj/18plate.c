/*
   This is based highly off of 
     /open/examples/OBJ/bartering.c
    written by Feldegast
  I added in the ability to chk how many times you've bartered.
*/
inherit "obj/armor";

reset(arg) {
  if(arg) return;
  set_id("sithos armor");
  set_alias("armor");
  set_short("Sithos Armor");
  set_long(
"A cheap piece of leather armor.  It has been cleaned and buffed \n"+
"recently.  There is a design of a large snake cut into the leather.\n"
  );
  set_ac(1);
  set_type("armor");  /* armor,helmet,boots,ring,amulet,shield,misc  */
  set_weight(3);
  set_value(800+random(100));
}

init() {
  ::init();
  add_action("barter","barter");
}

barter(str) {

if(id(str)) {
 if(present("drand claclah",environment(this_player()))) {
  if(present("drand claclah",environment(this_player()))->platecheck() < 1){
   present("drand claclah",environment(this_player()))->platebarter();
   write(
    "   Drand takes the piece of armor and attaches it to his backpack.  \n"+
    "He groans a bit under the new stress then smirks again.  He hands \n"+
    "you some coins from his backpack.\n"
            );
   this_player()->add_money(value);
   this_player()->add_weight(-1);
   destruct(this_object());
   return 1; }
  write("Drand says:  I can only carry one of those!\n");
  return 1;
  }
 write("You need to find the right person to barter with.\n");
 return 1;
 }
write("Barter what?\n");
return 1;
}
