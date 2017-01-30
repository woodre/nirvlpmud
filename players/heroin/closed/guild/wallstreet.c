#define TOOL "/players/heroin/closed/guild/guild_ob.c"
#define ENVTO environment(this_object())
id(str) {return str == "news" || str == "wallstreet"; }
long() {
write("This is the latest news..nothing new yet.\n");
}

wallstreet() {
write("No news is good news...blah blah blah\n");
tell_room(ENVTO, (this_player()->query_name()) + " considers the present state of the market.\n");
return 1;
}

