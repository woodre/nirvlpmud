
inherit "room/room";

object xynobyte, dagger, tooth;
int i;
   
reset(arg) {
  if(arg) return;
i = 0;
if (!xynobyte || !living(xynobyte)) {
  while (i < 5)  {
    i += 1;
    xynobyte = clone_object("obj/monster");
    call_other(xynobyte, "set_name", "xynobyte");
    call_other(xynobyte, "set_level", 5);
    call_other(xynobyte, "set_al", -200);
    call_other(xynobyte, "set_aggressive", 1);
    call_other(xynobyte, "set_short", "A Xynobyte");
    call_other(xynobyte, "set_long", "Evolved during the ice age, this\n"
              +"little creature is extremely vicious.  It lives off the \n"
              +"blood of animals.  Sometimes the xynobyte will attack\n"
              +"if provoked.  During the Medeval period, these hapless\n"
          +"creatures were blamed for stealing babies...\n");
    call_other(xynobyte, "set_ac", 6);
    call_other(xynobyte, "set_wc", 6);
    dagger = clone_object("obj/weapon");
    call_other(dagger, "set_name", "dagger");
    call_other(dagger, "set_short", "A dagger");
    call_other(dagger, "set_long", "A very sharp dagger used by the \n"
              +"Xynobytes to extract the teeth from babies.\n"
              +"They later use the teeth in a hunting ritual for\n"
              +"good luck...\n");
    call_other(dagger, "set_class", 8);
    call_other(dagger, "set_weight", 2);
    call_other(dagger, "set_value", 200);
    move_object(dagger, xynobyte);
    tooth = clone_object("obj/treasure");
    call_other(tooth, "set_id", "tooth");
    call_other(tooth, "set_value", 50);
    call_other(tooth, "set_weight", 1);
    call_other(tooth, "set_short", "A babies tooth");
    call_other(tooth, "set_long", "A babies tooth carried by\n"
              +"a Xynobyte for good luck during the hunt.\n");
    move_object(tooth, xynobyte);
    move_object(xynobyte, this_object());
   }
 }

short_desc = "Strawberry Fields forever...";
long_desc =
  "A small group of Xynobytes on the hunt!\n";

dest_dir = ({
  "players/morgoth/CASTLE/field13.c","north",
  "players/morgoth/CASTLE/field15.c","south",
  "players/morgoth/CASTLE/field7.c","west"
});

 }


init() {
  ::init();
  add_action("west","west");
}

west() {
if(present("xynobyte")) {
  write("The xynobyte stops you from going that way.\n"); return 1; }
if(!present("magic ruby",this_player())) {
  write("A voice whispers, 'You cannot enter without the magic ruby.'\n");
  return 1; }
else {
  this_player()->move_player("lair#players/morgoth/CASTLE/field7.c");
  return 1; }
}
query_temp() { return 1; }
