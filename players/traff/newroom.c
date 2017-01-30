inherit "room/room";
reset(arg) {
set_light(1);



  short_desc = "Traff's Workroom";

  long_desc = "\tThis is a small but well lit room,\n"+
  "the perfect place for someone to isolate and code\n"+
  "things in.\n";


 dest_dir = ({
  "/room/church","church",
  "/room/post","post",
  "/room/adv_guild","adv",
  "/players/sandman/paladin/adv_guild","pguild",
  "/room/eastroad3","leave",
  "/room/void","void",
});
}
