inherit "/room/room";
object mon;
init() {
monster();
}
reset(arg) {
if(arg) return;
set_light(1);
short_desc = "The entrance way";
long_desc = 
"This is the Doppleganger room.\n";
}
monster() {
if(!present("wally")) {
  mon=clone_object("players/grimm/newbie/monsters/wally");
  mon->set_name("Dopple");
  mon->set_ac(1);
  mon->set_alias("dopple");
  mon->set_alias("ganger");
  mon->set_wc(5);
  move_object(mon,this_object());
  }
}
