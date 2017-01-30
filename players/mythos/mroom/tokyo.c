inherit "room/room";
reset(arg) {
  if(!present("messenger")) {
    move_object(clone_object("/players/mythos/mmon/bustle.c"),this_object()); }
  if(!arg) {
  set_light(1);
    short_desc = "<<Tokyo Station>> ";
    long_desc =
    "                       Tokyo Station\n"+
    "Unlike the other stations, this ia rather big one- but still\n"+
    "it is crowded. Center of Tokyo City- this station is always \n"+
    "busy.  You can here the bullet trains rushing off to other parts\n"+
    "of the country, men in busines suits discuss trade/transactions\n"+
    "over the pay phones, and children run around...\n";
  items = ({
    "narita","The airport that leads to many places",
    "ginza","The shoppers dreamplace",
    "akihabara","The place of the cybertech",
    "out","Step out to Tokyo",
    "shinjuku","Walk where the entertainment is",
  });

  dest_dir = ({
     "/players/mythos/mroom/ginza.c","ginza",
    "/players/mythos/mroom/akihabara.c","akihabara",
    "/players/mythos/mroom/shinjuku.c","shinjuku",    
    "/players/mythos/mroom/narita.c","narita",
    "/players/mythos/mroom/masakado.c", "out",
  });
} }
