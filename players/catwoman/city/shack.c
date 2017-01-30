inherit "room/room";
int bar_here;


reset(arg)
{
  if (arg) return;

  set_light(1);
bar_here = 1;
short_desc = "A rotting old shack";
  no_castle_flag = 0;
                                                         
long_desc =
  "This old shack has seen better days.  It has rotted\n"+
  "from the weather and lack of upkeep and fallen down.\n"+
  "It's actually nothing more than a pile of rubble now.\n";

}

init ()
   {
    add_action ("south","south");
	add_action("search","search");
	add_action("unpile","unpile");
    return;
  }

south(){
  this_player()->move_player("south#players/catwoman/dock3.c");
return 1;
}

search(str) {
if(!str) { write("You search the ground and find nothing.\n");
  return 1; }
if(str == "shack") {
  write("You search through what is left standing and find nothing.\n");
  return 1; }
if(str == "rubble") {
  write("You search through the shack rubble and think you spot\n"+
	"something.  It looks like you'll have to unpile it.\n");
  return 1; }
}

unpile(str) {
object ob;
  ob = present("rangerluck",this_player());
if(!str) { write("Unpile what?\n"); return 1; }
if(str != "rubble") {
  write("I really don't understand what you're doing.\n"); return 1; }

if(!ob && str == "rubble") {
  write("You've missed something along the way, you find nothing.\n");
  return 1; }
if(str == "rubble" && bar_here == 1) {
  write("You carefully unpile the rubble and find a metal bar.\n");
  move_object(clone_object("players/catwoman/closed/bar.c"),
	this_player());
  bar_here = 0;
  destruct(ob);
  return 1; }
else {
  write("You carefully unpile the rubble only to find a broken shell.\n");
  return 1; }
}
query_light()
{
  return 1;
}
