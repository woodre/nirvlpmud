inherit "room/room";

#define tp this_player()->query_name()

reset (arg){
if (!arg){
set_light(1);
}
if (!present("Bouncer")) move_object(clone_object("/players/heroin/hunting_grounds/bouncer.c"), this_object());
short_desc="Wild, Wild, Backstage area";
items=({
"change", "change"});
dest_dir=({
"/players/heroin/hunting_grounds/concert.c","west",
"players/heroin/hunting_grounds/limo.c","limo"});
long_desc=
"As the concert ended, you found it easier to move about. You \n"+
"still aren't really sure who just played but you being a party\n"+
"kind of guy decide to check outthe backstage area anyway. \n"+
"Over to the right of you, you see a huge deli tray filled with\n"+
"tons of scrumptous finger foods. AND better yet beside the trays\n"+
"are buckets filled with expensive imported beer.  Boy, that sure\n"+
"would hit the spot.  As you approach the beer, you notice one guy\n"+
"eyeing you.  EEEK, its a Once-I-Played-Football-I-Beat-People-Up-\n"+
"At-Concerts-For-No-Good-Reason Bouncer. Run for coat check.\n";
}
init(){
::init();
add_action("listen","listen");
add_action("kill","kill");
add_action("search","search");
}
kill(str){
object test;
test = (present("counter", this_player()));
if (test) { test->inc_count();}
}
search(){
write("You find nothing\n");
say(tp + "finds a dime and tells you: Losers weepers\n");
return 1;
}
listen(){
write("You overhear some guitar prodigy say: MAN his licks ROCKED ME\n");
say(tp + "giggles\n");
return 1;
}
