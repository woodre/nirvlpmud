inherit "players/nightshade/new_room";
reset(arg){
   if(arg) return;
        set_light(1);
        short_desc = "Forest Trail";
     long_desc =
"You are walking caustiously along a trail going south through the forest.\n";
      dest_dir = 
      ({ "/players/nightshade/room/trail3", "south",
      "players/nightshade/room/trail", "north",
      });
items = ({
"penis", "This is Gorgan's  penis. What a joke!",
});
}
