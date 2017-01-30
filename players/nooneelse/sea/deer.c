/*
 deer.c
*/

inherit "obj/monster";

string route_str;
int route_num;

reset(arg){
  if (arg) return;
  ::reset(arg);

  route_str = allocate(16);
  route_str[0] = "south";
  route_str[1] = "east";
  route_str[2] = "south";
  route_str[3] = "south";
  route_str[4] = "west";
  route_str[5] = "north";
  route_str[6] = "north";
  route_str[7] = "east";
  route_str[8] = "east";
  route_str[9] = "south";
  route_str[10] = "west";
  route_str[11] = "west";
  route_str[12] = "north";
  route_str[13] = "east";
  route_str[14] = "north";
  route_str[15] = "west";
  set_name("deer");
  set_short("A shy deer");
  set_long("This is a shy deer.  It is quite slender and graceful.\n" +
           "It is harmless and practically defenseless.\n");
  set_level(random(3) + 6);
  set_aggressive(0);
  set_hp(random(100) + 300);
  set_al(100);
  set_ac(random(4) + 6);
  set_wc(random(4) + 14);
  msgout = "walks out";
  msgin = "walks in";
  call_out("move_deer", 25);
  route_num = 0;
}

move_deer(){
  route_num++;
  if(route_num == 16) route_num = 0;
  init_command(route_str[route_num]);
  call_out("move_deer", 25);
}
