inherit "players/nightshade/new_room";
reset(arg){
monster();
   if(arg) return;
        set_light(1);
short_desc="Impolite";
     long_desc =
"A very rude person is sitting here. All he is doing is insulting\n"+
"anything and everything that walks by. He was kicked off of Genocide\n"+"because of his rudeness and now he has made his home here.\n";
      dest_dir = 
({
"players/nightshade/room/imp2", "west",
"players/nightshade/room/imp7", "north",
      });
}
monster() {
object duh;
if(!present("imp")) {
duh=clone_object("players/nightshade/mons/impolite");
move_object(duh, this_object());
}
}
