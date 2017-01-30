inherit "/room/room";
#include "/players/autumn/defs.h"

reset(arg) {

    if(arg) return;
    set_light(1);

short_desc=(HIB+"ESC Cinemas: "+NORM+YEL+"Movie Theater #5"+NORM);

long_desc=
 
RED+" ________________________________________________________________________\n"+NORM+BRED+CYN+
"|                                                                        |\n"+ 
"|\\__/\\__/\\__/\\__/\\__/\\__/\\__/\\__/\\__/\\__/\\__/\\__/\\__/\\__/\\"+
"__/\\__/\\__/\\__/|\n"+
"|!!!!!!!!!!!!}"+NORM+"                                              "+BRED+CYN+"{!!!!!!!!!!!!|\n"+
"|!!!!!!!!!!!}"+NORM+"        "+NORM+HIW+" _____________________________ "+
"         "+NORM+BRED+CYN+"{!!!!!!!!!!!|\n"+
"|!!!!!!!!!!}"+NORM+"         "+NORM+HIW+"|                             |"+
"          "+NORM+BRED+CYN+"{!!!!!!!!!!|\n"+
"|!!!!!!!!!}"+NORM+"          "+NORM+HIW+"|   "+NORM+FLASH+YEL+"COMING SOON:"+NORM+HIK+
"              | "+NORM+"          "+BRED+CYN+"{!!!!!!!!!|\n"+
"|!!!!!!!!}"+NORM+"           "+NORM+HIW+"|                             |"+
"            "+NORM+BRED+CYN+"{!!!!!!!!|\n"+
"|!!!!!!!}"+NORM+"            "+NORM+HIW+"|            "+HIB+"T"+NORM+HIW+"H"+NORM+RED+
"E"+NORM+HIK+" C"+NORM+HIG+"U"+NORM+HIY+"B"+NORM+HIB+"E         "+NORM+HIW+"|             "+NORM+BRED+CYN+"{!!!!!!!|\n"+
"|!!!!!!}"+NORM+"            "+NORM+HIW+" |                             |"+
"              "+NORM+BRED+CYN+"{!!!!!!|\n"+
"|!!!!!!}"+NORM+"            "+NORM+HIW+" |                             | "+
"             "+NORM+BRED+CYN+"{!!!!!!|\n"+
"|!!!!!!}"+NORM+"            "+NORM+HIW+" `-----------------------------'"+
"              "+NORM+BRED+CYN+"{!!!!!!|\n"+
"|!!!!!!}"+NORM+"                                                          "+NORM+BRED+CYN+"{!!!!!!|\n"+
"|!!!!!!}"+NORM+"                 "+NORM+HIK+" (~~) (~~) (~~) (~~)     "+
"                "+NORM+BRED+CYN+"{!!!!!!|\n"+
"|!!!!!!}"+NORM+"                 "+NORM+HIK+" _)(___)(___)(___)(_     "+
"                "+NORM+BRED+CYN+"{!!!!!!|\n"+
"|!!!!!!}"+NORM+"               "+NORM+HIK+"(~~) (~~) (~~) (~~) (~~)  "+
"                 "+NORM+BRED+CYN+"{!!!!!!|\n"+
"|!!!!!!}"+NORM+"               "+NORM+HIK+"_)(___)(___)(___)(___)(_  "+
"                 "+NORM+BRED+CYN+"{!!!!!!|\n"+
"|!!!!!!}"+NORM+"             "+NORM+HIK+"(~~) (~~) (~~) (~~) (~~) (~~)"+
"                "+NORM+BRED+CYN+"{!!!!!!|\n"+
"|!!!!!!}"+NORM+"             "+NORM+HIK+"_)(___)(___)(___)(___)(___)(_   "+
"             "+NORM+BRED+CYN+"{!!!!!!|\n"+
"|!!!!!!}"+NORM+"            "+NORM+HIK+"|    |    |    |    |    |    | "+
"              "+NORM+BRED+CYN+"{!!!!!!|\n"+
"|!!!!!!}"+NORM+"            "+NORM+HIK+"|    |    |    |    |    |    |  "+
"             "+NORM+BRED+CYN+"{!!!!!!|\n"+
"|!!!!!!}"+NORM+"            "+NORM+HIK+"||~~~~~||~~~~~||~~~~~||~~~~~~|| - L       "+
"    "+NORM+BRED+CYN+"{!!!!!!|\n"+
"|lc!!!!}"+NORM+"            "+NORM+HIK+"`'     `'     `'     `'      `'      "+
"         "+NORM+BRED+CYN+"{!!!!!!|\n\n"+


NORM+HIK+"Movie theater #5:\n"+NORM+YEL+
"A large, white screen surrounded by beautiful, red, velvety curtains sits\n"+
"on the far wall.  Round lights line the ceiling, giving off just enough light\n"+
"to see clearly.  The room has a perimeter of lighted walkways and the center\n"+
"is lined with high-back seats.  A projector hides behind a window on the back\n"+
"wall.  The theater is equipped with Dolby Atmos surround sound, high-definition,\n"+
"3-D digital projector, I-MAX screen, and reclining seats.  Most of the seats\n"+
"are filled with eager patrons... it might be hard to find an empty seat.\n"+HIK;



items = ({
  
  "theater","A very clean theater with a gigantic movie screen and comfortable-looking seats.",
  "dolby","Speakers strategically placed around the room.",
  "atmos","Speakers strategically placed around the room.",
  "projector","A high-definition, 3-D digital projector.",
  "seat","An empty seat.",
  "seats","Seats, filled with eager patrons.",
  "screen","A gigantic I-MAX screen.",
  "curtains","Red, velvety curtains.",
  "lights","Small, round lights on the ceiling.",
  "walkway","A narrow, lighted walkway.",
  "window","A small window.",

});

dest_dir = ({
  "/players/autumn/cinemas/rooms/hall5.c","exit",
  
});

}

init()
{
  ::init();
  add_action("search","search");
  add_action("sit","sit");
  add_action("watch","watch");
  add_action("smell","smell");
  add_action("listen","listen");
}

search()
{
  write("This theater is immaculate. You won't find anything, not even a crumb!\n"); 
  say(TPN+" looks around the theater.\n");
  return 1;
}

sit()
{
	write("You sit in a comfy chair. AHHHHHH... NICE!\n");
	say(TPN+" sits down to relax. Is that lazy or what?!?!\n");
	return 1;
}

watch()
{
	write("We're sorry, but this theater is currently closed.\n");
	say(TPN+" checks, but there is no movie playing.\n");
	return 1;
}

smell()
{
	write("Yummy smells of buttered popcorn and candy are everywhere.\n");
	return 1;
}

listen()
{
	write("You hear many people talking in the room. Man that's LOUD!\n");
	return 1;
}























