#include "/players/wocket/closed/ansi.h"
inherit "/players/wocket/mages/obj/bookobj.c";
reset(){
booktitle = "a huge test";
pagenumber = 3;
booktext = ({});
booktext += ({"	this is a test of this\n	book\n	to see about multiple pages"});
booktext += ({"	this is page two of my book\n	again\n	a test of the book"});
booktext += ({"	this is another page in my book\n	funny huh.."});
}