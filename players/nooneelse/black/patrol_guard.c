/*
 patrol_guard.c
*/

inherit "obj/monster";

string  moves_str, destination_str;

int which_destination, how_long_here;

reset(arg) {
  if (sizeof(explode(file_name(this_object()),"#"))==1) return;
  ::reset(arg);
  if (arg) return;

  set_name("guard");
  set_level(10); /*18*/
  set_hp(300);   /*220*/
  set_wc(15);    /*17*/
  set_ac(7);     /*13*/
  set_al(-395);
  set_short("Nooneelse's patrolling guard");
  set_long("Nooneelse's guard on sentry duty.\n"+
           "He says: I'm patrolling between the shop and the bridge.\n");
  msgout = "marches out";
  msgin = "marches in";
  set_whimpy(0);
  set_aggressive(0);
  if (!moves_str) load_moves_str();
  sscanf(moves_str[0], "%s %d", destination_str, how_long_here);
  call_out("make_a_move", how_long_here);
}

make_a_move() {
  sscanf(moves_str[which_destination], "%s %d", destination_str, how_long_here);
  command(destination_str, this_object());
  which_destination=which_destination+1;
  if (which_destination >= 9) {
    which_destination=0;
    sscanf(moves_str[0], "%s %d", destination_str, how_long_here);
  }
  call_out("make_a_move", how_long_here);
  return 1;
}

load_moves_str() {
  moves_str=allocate(10);

  moves_str[0] = "south 5";
  moves_str[1] = "west 3";
  moves_str[2] = "west 3";
  moves_str[3] = "west 3";
  moves_str[4] = "west 10";
  moves_str[5] = "east 3";
  moves_str[6] = "east 3";
  moves_str[7] = "east 3";
  moves_str[8] = "east 3";
  moves_str[9] = "north 5";
}
