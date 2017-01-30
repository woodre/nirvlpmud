#include "/players/balowski/lib.h"
inherit ROOM;

void create()
{
    ::create();
    set_short("alien fields");
    set_long("\
The plants around you look fully grown. Their strong stems and buxom-\n\
ness make it impossible for you to move freely around. You have to\n\
elbow your way through the dense crop.\n\
");
    set_items(([
	({ "plants", "crop", }) : "\
The fully grown plants are about a meter and a half tall and have big\n\
green leaves. Something seems to be hidden behind the petals at the top\n\
of the stem.\n",
	"petals" : "\
You peel back the petals and look into a minute human face. Its tiny\n\
little mouth smiles at you and asks, \"Are you going to eat me now? I\n\
am just about ripe.\". In surprise you let go of the petals and they\n\
flip back to cover the plant's fruit.\n",
    ]));
    set_chat_chance(5);
    load_chats(({
	"You hear a tiny voice begging: Eat me. Eat me.\n",
	"A tiny voice squeaks: I wonder who will pluck me.\n",
    }));
    add_sound("default", "You could have sworn you heard something.\n");
    set_exits(([
	"north": 0,
	"south": "/players/balowski/tiny/b1",
	"east" : "/players/balowski/tiny/a2",
	"west" : 0,
    ]));
    set_light(1);
}
