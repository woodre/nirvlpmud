/*
*      Function:
*      Change History:
*/
#include <ansi.h>
inherit "/room/room";

reset(arg)
{
::reset(arg);

if(arg) return;

set_light(1);

short_desc = "Guidance Office";

long_desc =
"This is one of two guidance offices branched off of the main office. This is where \n"+
"the troubled kids go for guidance in certain areas of their lives, as well as kids \n"+
"with mental disabilities, or learning problems in general. There are pamphlets and \n"+
"many books lining the shelves on the walls, as well as a simple desk in the center \n"+
"of the room, on which there is a computer and some random post-its and folders.\n";

items =
({
"pamphlets",
"Informational pamphlets with titles like 'Dealing with ADHD' and 'Child Abuse Support' ",
"desk",
"This is just a simple desk, with a few papers scattered about on it",
"computer",
"An old desktop computer which probably contains students' confidential files",
"post-its",
"Most of them have phone numbers, or times and dates jotted on them",
"books",
"Mostly your basic psychology and mental health guides",
"shelves",
"There are many pamphlets and cooks lining these shelves",
"papers",
"Just some random papers strewn about the desktop",
});


dest_dir =
({
"/players/chip/room/hdgmd/schools/elem/officehall.c",     "out",
});

}
