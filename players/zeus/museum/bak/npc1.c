/*  The Museum of Legendary Warriors  */

inherit "room/room";
#include "/players/zeus/closed/all.h"

reset(arg){
	if(arg) return;

	MO(CO("/players/zeus/museum/OBJ/p-tolkor.c"), TO);

 short_desc="The Museum";
 long_desc=
"This is a smaller side room of the museum.  Against the west wall of\n"+
"the room is a life size holographic projection of the warrior Tol'kor.\n"+
"A small electronic chip has been mounted to the floor, directly beneath\n"+
"the projection.  It is displaying some text in the air to the left of\n"+
"the statue.  A soft glow is eminating from the ceiling.\n";
 set_light(1);
 items=({
	 "chip",
"The little electronic chip is mounted to the floor, and is projecting\n"+
"the image of Tol'kor, as well as the text to it's left",
     "text",
"The text is a dark green color, and is scrolling by slowly.  It is\n"+
"giving information about the great warrior Tol'kor.  It is obviously\n"+
"readable",
     "ceiling",
"The ceiling is perfectly clear, through which the blackness of space\n"+
"can be seen.  A soft glow is coming from the ceiling, providing light\n"+
"for the room",
	"stars",
"The stars look beautiful out there in space",
    "space",
"Outer space is black, and very beautiful.  It is scattered with stars",
 });
 dest_dir=({
	 "/players/zeus/museum/hall1.c", "east",
 });
}

void init(){
	::init();
	add_action("read_cmd", "read");
}

status read_cmd(string str){
	if(!str) return 0;
	if(str == "text")
	{
		write("The text reads:\n"+
"Tol'kor was one of the mightiest Ogre Warriors of his time.  Many believed\n"+
"him to be the best.  Best known for being on the offensive even when his\n"+
"death seemed imminent, he was never one to give up a fight.  He was also\n"+
"a master with an axe, and his axe has gone down in history right along\n"+
"with him.\n");
		say(TP->QN+" reads the text.\n");
		return 1;
	}
	else return 0;
	return 1;
}
