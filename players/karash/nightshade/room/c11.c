inherit "players/nightshade/new_room";
object ob;
reset(arg){
monster();
   if(arg) return;
        set_light(1);
        short_desc = " Dark Cave";
     long_desc =
"A rather large muscular drow female meditates nad mumbles prayers\n"+
"to her evil deity Lolth. It would not be wise to interrupt her.\n";
      dest_dir = 
({
"players/nightshade/room/c10", "east",
      });
}
monster() {
object duh;
if(!present("cleric")) {
duh=clone_object("players/nightshade/mons/drow_cleric");
move_object(duh, this_object());
}
}
