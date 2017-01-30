#include "/players/reflex/lib/lib.h"
#include "/players/reflex/lib/include/ansi.h"
inherit ROOM;

void
reset(int arg)
{
    ::reset(arg);
    if (arg)
        return;
    set_short("Outside the Church");
    set_long(
        "You are on the path to the church.  Off to the right and left\n"+
        "is a well manicured lawn, and directly to the south lies a large\n"+
        "church.  To the north is Lance road, and the town beyond that.\n"+
        "There are bushes on either side of the path, up to about hip\n"+
        "level.  It is quiet and serene here...\n\n"+
        "There is a sign off to the side of the path...\n",);    
    set_items(([
        "path" :
        "This is a white paved walkway leading to the church.\n",  
        "lawn" :
        "A very well manicured lawn, it looks like it is kept up on a daily\n"+
        "basis.\n",
        "church" :
        "A very large and ornate church.  You see stained glass windows and\n"+
        "double doors on the front.\n",
        "bushes" :
        "Well manicured bushes, coming up to your waist, they are covered\n"+
        "in flowers...\n",
        "sign" :
        "<>===============================<>\n"+
        "||    "+BOLD+"First Church of Nirvana"+NORM+"    ||\n"+
        "||                               ||\n"+
        "||  This church is dedicated to  ||\n"+
        "||      performing wedding       ||\n"+
        "||     ceremonies.  For more     ||\n"+
        "||     information, contact      ||\n"+
        "||            Reflex             ||\n"+
        "<>===============================<>\n",
        ]));
    set_smells(([
	"default" : 
	"You smell freshly cut grass, and the aroma of flowers.\n",
	"lawn" :
	"You smell grass and dirt.\n",
	]));
    set_sounds(([
	"default" :
	"The only sound is that of the birds flying by overhead.\n",
	"birds" :
	"Chirp!  Whistle!  Tweet!  Here putty tat!\n",
	]));
    set_chat_frequency(45);
	load_chats(({
	"The breeze rustles your hair...\n",
	"You hear a bird chirping\n",
	"Clouds float by in the blue sky...\n",
	"The wind blows lazily about you...\n",
	"The breeze whistles slightly as it blows through the bushes.\n",
	"A butterfly floats by...\n",
	}));
    set_exits(([
        "enter" : "/players/reflex/realms/weddings/church/church",
        "north" : "/room/lanceroad3",
        ]));
    set_light(1);
    replace_program(ROOM);
}

init(){
 ::init();
 add_action("move_south", "south", 1);
 }

move_south(){
  if(this_player())
  if(this_player()->is_player()) 
  this_player()->move_player("south#players/reflex/realms/weddings/church/church.c");
  return 1;
  }