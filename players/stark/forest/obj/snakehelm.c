/*
   This is based highly off of 
     /open/examples/OBJ/bartering.c
    written by Feldegast
  I added in the ability to chk how many times you've bartered.
*/
inherit "obj/armor";

reset(arg) {
  if(arg) return;
  set_id("snake helm");
  set_alias("helm");
  set_short("Snake Helm");
  set_long(
"A large dark helm shaped like a snakes head.  A set of eyes gleams \n"+
"from atop the head.  There is a pair of small and sharp fangs just \n"+
"at the tip of the helms opening.\n"
  );
  set_ac(1);
  set_type("helmet");  /* armor,helmet,boots,ring,amulet,shield,misc  */
  set_weight(1);
  set_value(1000+random(900));
}

init() {
  ::init();
  add_action("barter","barter");
}

barter(str) {

if(id(str)) {
 if(present("drand claclah",environment(this_player()))) {
  if(present("drand claclah",environment(this_player()))->helmcheck() < 1){
   present("drand claclah",environment(this_player()))->helmbarter();
   write(
    "   Drand takes the helm and stuff it deep inside his backpack.  He \n"+
    "smiles at you and gives you a wink.  He hands you some coins for your \n"+
    "trouble."
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
