#define tp this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Shade Lane";
long_desc =
	"  Shade Lane was so named because of the sightings by many people\n"+
	"of actual shades or apparitions along it's length.  It's path\n"+
	"will take you through the forests and plains to a small town \n"+
	"located in a glen in the valley of Sleepy Hollow.  The fields\n"+
	"here seem to stretch for as far as the eye can see.\n";

items = ({
	"fields","Golden waves of wheat, swaying in the breeze",
});

dest_dir = ({
	"players/eurale/Dis/Slpy/sl2.c","northeast",
	"players/eurale/Dis/rooms/hub.c","southwest",
});

}
