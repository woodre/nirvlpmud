/*
   This is based highly off of 
     /open/examples/OBJ/bartering.c
    written by Feldegast
  I added in the ability to chk how many times you've bartered.
*/
inherit "obj/treasure";

reset(arg) {
  if(arg) return;
  set_id("snake skin");
  set_alias("skin");
  set_short("Snake Skin");
  set_long(
"The skin off of a snake.  It looks like it wasn't taken off \n"+
"cleanly.  You could 'barter' it if you found the right person.\n"
  );
  set_weight(1);
  set_value(800+random(75));
}

init() {
  add_action("barter","barter");
}

barter(str) {

if(id(str)) {
 if(present("drand claclah",environment(this_player()))) {
  if(present("drand claclah",environment(this_player()))->skincheck() < 8){
   present("drand claclah",environment(this_player()))->skinbarter();
   write(
    "  Drand smiles as you give him the skin.  He folds it neatly \n"+
    "and stuffs it into his backpack.  He takes some coins out of \n"+
    "his pockets and hands them over to you.\n"
            );
   this_player()->add_money(value);
   this_player()->add_weight(-1);
   destruct(this_object());
   return 1; }
  write("Drand says: No thanks, I've got too many snake skins allready!\n");
  return 1;
  }
 write("You need to find the right person to barter with.\n");
 return 1;
 }
write("Barter what?\n");
return 1;
}
