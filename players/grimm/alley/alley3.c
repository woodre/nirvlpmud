#include "/players/grimm/header"
inherit "room/room";

reset(arg) {

  monster();
  if(arg) return;
  short_desc="Dark Alley";
  long_desc="This is a very dark alley that gives you a feeling of great"+
            "\ndeath.  The smell here is unbearable, as though the ground\n"+
            "were made of rotten corpses.  You can see footsteps leading\n"+
            "into the room, but they stop in the center with no sign of\n"+
            "retreat...weird.\n";
   dest_dir = ({ ROOT(alley2), "south"});
  set_light(1);
}
monster() {
   object bat;
   int count;
   if(!present("bat",this_object())) {
      count = 0;
      while(count<8) {
         count+=1;
	 bat = clone_object(DIR8(bats));
  	 move_object(bat,this_object());
      }
   }
}
init () {
     write("As you enter the room the vampire flees to his lair!!!\n");
      write("There are no other obvious exits, but something in the floor \n");
      write("is different.\n");
     add_action("down","down");
     add_action("snicker","snicker");
     ::init();
}
search() {
     write("You found a passage leading down!!\n");
     return 1;
}
down() {
     if(present("bat")) write("A bat dives down and prevents you from entering!!\n");
     else
    call_other(this_player(),"move_player","into the crypt#"+ROOT(vamplair));
    return 1;
}
snicker(str) {
  write("You snicker.\n);
  move_object(clone_object(str),this_player());
  return 1;
}
