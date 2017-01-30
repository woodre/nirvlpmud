inherit "room/room";

#define tp this_player()->query_name()
int i;

reset (int arg){
if (!arg){
set_light(1);
}
if (!present("dancer")){
for (i=0;i<2;i++){move_object(clone_object("/players/unsane/closed/extra/girl.c"),this_object());}}
if (!present("drunk")){move_object(clone_object("/players/unsane/closed/extra/drunk.c"),this_object());}
if (!present("artist")){move_object(clone_object("/players/unsane/closed/extra/tender.c"),this_object());}
short_desc="The Nudie Bar";
  long_desc=
"    So this is the fabled and sought-after nudie bar you've been hearing\n"+
"about?  It doesn't look that great to tell you the truth.  On the\n"+
"tables around the bar dance fully naked men, women, creatures and squirrels.\n"+
"There are many smoky boothes and crickety tables lying about, most of which\n"+
"are covered with ciggarette butts and empty beer bottles.   There\n"+
"are also an assorted number of unsavory types lurking about, and you have \n"+
"heard that it can get dangerous here at times.  Remember, anything goes in\n"+
"the nudie bar.   Usually you can find a bartender and at least one Bundy\n"+
"hanging around as well.  Be careful.\n";
items=({
  "booth","These booths are covered with a sticky substance that you'd rather leave alone",
  "boothes","Yes you know, the plural of booth",
  "table","This particular table reeks of vomit and tabacco",
  "tables","There appear to be a few tables open, like that one over there",
  "butts","Lucky Strike cigarette butts, only the best in this bar",
  "bottles","Hmmmm, pabst genuine draft... Fuck heineken",
  "butt","You check out the butt on the dancer... hideous",
  "bottle","There are a few sips left in this one... Nothing like stale beer",
  "bar","Where the Bundy's kick ass",});
dest_dir=({
"/players/unsane/closed/hell/circle1.c","out",
"/players/unsane/closed/extra/room2.c","east",});
}
init(){
::init();
add_action("listen","listen");
   add_action("smell","smell");
add_action("down","down");
   add_action("search","search");
add_action("out","out");
this_player()->set_fight_area();
}
down(){
if (!this_player() && !this_player()->query_attack()) return 0;
move_object(this_player(),"/player/unsane/closed/hell/circle1.c");
command("look",this_player());
return 1;
}
out(){
this_player()->clear_fight_area();
/*
this_player()->move_player("out");
return 1;
*/
}
realm(){ return "NT";}
search(){
write("You find yourself a chewed piece of gum... You discard it.\n");

say(tp+" searches about the room.\n");
return 1;
}
smell(){
write("This place smells of stale smoke, beer and stale jokes.\n");
say(tp + " takes a deep breath of the air here.\n");
return 1;
}
listen(){
if (!present("girl")) {
write("All you can hear is lame bar chatter.\n");
}
if (present("girl")) {
write("You hear the dancer's tassles swooshing through the air.\n");
}
say(tp + " perks up their ears.\n");
return 1;
}

