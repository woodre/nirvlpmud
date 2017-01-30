/* candy.c the scandy store */
inherit "room/room";
reset(arg) {
if(arg) return ;
set_light(1);
short_desc = "The Candy Store";
long_desc  = "You are astanding in a huge shop, with walls lined with\n"
+"candy dispensers. It looks like candy here is sold by the pound.\n"
+"Commands are: list candy, buy <type>\n";
dest_dir = ({"/players/wizardchild/mall/entry", "west"});
move_object(clone_object("players/wizardchild/mall/cseller"),this_object());
}
