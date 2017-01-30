inherit "players/nightshade/new_room";
object ob;
reset(arg){
monster();
   if(arg) return;
        set_light(1);
        short_desc = " Dark Cave";
     long_desc =
"A tall, thin drow is here practicing his ambedextrious skills with\n"+
"two longswords. He looks at you and says evily, 'Good, now i have\n"+
"somone to practice on!'\n";
      dest_dir = 
({
"players/nightshade/room/c7", "south",
      });
}
monster() {
object duh;
if(!present("ranger")) {
duh=clone_object("players/nightshade/mons/drow_ranger");
move_object(duh, this_object());
}
}
