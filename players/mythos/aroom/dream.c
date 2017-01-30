#define tp this_player()->query_name()
inherit "room/room";
reset(arg) {
  if(!present("ruler")) {
    move_object(clone_object("/players/mythos/amon/ruler.c"),this_object()); }
  if(!arg) {
  set_light(0);
    short_desc = "Dream Room";
    long_desc =
      "You enter a black void.  Space and Time have no meaning.\n"+
      "About what seems like 10 meters ahead is an old man.\n"+
      "Behind him you see a wierd tapestry.\n";
  items = ({
      "tapestry","It depicts the hut that you entered long before.  \nIt is the way 'out'",
  });

} }
  init()  {
    ::init();
    add_action("out","out");
}

out() {
  object ob;
    ob = present("ruler");
  if(present("ruler")) {
    write("A great force prevents you from leaving.\n");
    say("A great force prevents "+tp+" from leaving\n");
return 1;
}

  if(!present("ruler")) {
    call_other(this_player(),"move_player","out#players/mythos/aroom/hut.c");
    say(tp+" touches the tapestry and is gone.\n");
return 1;
} }
