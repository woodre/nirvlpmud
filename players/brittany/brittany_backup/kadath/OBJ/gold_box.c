inherit "/obj/treasure";
reset(arg){
set_short("A gold box");
set_long("     A gold box with symbols engraved on it.  The box is closed with a\n"+
         "combination dial set to 0.  If you had the secret code, maybe you could 'open' it..\n");
set_id("box");
set_weight(2);
}

init(){
::init();
add_action("turn","turn");
}

turn(str){
  if(!str || str != "clasp"){
  notify_fail("Turn what?\n");
  return 0; }
write("The clasp turns, the box disappears and turns into a key.\n");
move_object(clone_object("/players/brittany/kadath/OBJ/gold_key.c"),this_player());
  destruct(this_object());
set_weight(1);
  return 1; }
