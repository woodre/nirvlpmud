inherit "room/room";
   string WHAT, ME;
realm() {return "NT";}
reset(arg) {
  if(!arg) {
set_light(1);
short_desc="HQ";
long_desc = "You are standing on a dirt road that leads up to a large green\n"+
"building. Directly in front of you there are some doors you can enter \n"+
"or the jeep is waiting to take you back.\n";

dest_dir=({
  "/players/hawkeye/room/rose.c", "jeep",
});

   }
}

init() {
    ::init();
     add_action("doors","doors");
     add_action("doors","enter");
}

doors() {
object pass;
if(present("pass",this_player())) {
write("You hand the pass to the guard and he opens the doors for you.\n");
move_object(this_player(),"players/hawkeye/room/hq1.c");
pass = present("pass",this_player());
destruct(pass);
return 1;}
else {
write("A LARGE sergeant steps in front of you and says:\n" +
"HEY, where is your pass!\n");
write("Get outta here!\n");
move_object(this_player(),"players/hawkeye/room/newent.c");
return 1;}
}
