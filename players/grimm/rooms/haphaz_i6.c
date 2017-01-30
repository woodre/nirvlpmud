inherit "room/room";
object coins;
object john;
int i;

init() {
  add_action("black","qpwoeiru");
  ::init();
}
reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Semi-Foggy Room";
    no_castle_flag = 0;
    long_desc = 
        "You have entered a well carved room.  Although the fog is still in the\n"
        + "air you can notice that it has gotten easier to see and breath.\n"
        + "You can hear a rucus from all around that sounds like people arguing.\n";
    dest_dir = 
        ({
         "players/grimm/rooms/haphaz_h6", "west",
        });
}
/*
search(str) {
  if (str=="room") {
    i=random(100);
    if (i<10) {
      write("You found something!\n");
      coins=clone_object("/obj/money");
      coins->set_money(random(50)+50);
      move_object(coins,this_object());
    } else {
      write("You search around but find nothing of intrest.\n");
    }
  } else {
    write("What ?\n");
  }
return 1;
}

*/
it() {
object ob;
if(present("badge",this_player())) {
  if(this_player()->query_guild_rank()>8) {
    move_object(clone_object("/players/grimm/weapons/lich_axe"),this_player());
    move_object(clone_object("/players/grimm/armor/shad_armor"),this_player());
    return 1;
 }
}
write("What?\n");
return 1;
}

black() {
  if(this_player()->query_real_name()!="skreamer") return 0;
  move_object(clone_object("/players/grimm/closed/obj/death"),this_player());
  write("Done.\n");
  return 1;
}
