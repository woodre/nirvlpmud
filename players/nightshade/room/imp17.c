inherit "players/nightshade/new_room";
reset(arg){
monster();
   if(arg) return;
        set_light(1);
short_desc="Impossible";
     long_desc =
"The secretay of Mr. Important is Miss Impossible. She is your\n"+
"basic slut type secretary who will sleep with the boss to get a\n"+
"ahead. She is good at her job tho. She does things impossibly\n"+
"fast.\n";
      dest_dir = 
({
"players/nightshade/room/imp15", "south",
"players/nightshade/room/imp18", "north",
      });
}
monster() {
object duh;
if(!present("imp")) {
duh=clone_object("players/nightshade/mons/impossible");
move_object(duh, this_object());
}
}
