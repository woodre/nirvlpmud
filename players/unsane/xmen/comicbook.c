#define tp this_player()->query_name()
inherit "obj/treasure";
reset(arg){
  if(arg) return;
set_id("comic");
set_alias("comic book");
set_short("A Comic Book");
set_long("This is a copy of an X-men comic book.  It is an annual that came out\n"+
"in the early 80's.  This issue is titled 'Nightcrawler's Inferno'.  Hmm...\n"+
"that is quite a coincidence wouldn't you say?  The comic is about Kurt's trip\n"+
"to Hell.\nMaybe you could enter this comic?\n");
set_weight(1);
}
init(){
add_action("read","read");
add_action("read","enter");
}
get()
{write("The judge glances over and you and you think better of stealing his comic.\n");
return 0;}
read(str){
string a,b;
if(!str) return 0;
if (sscanf(str,"%scomic%s",a,b) == 2) {
write("The Judge smiles as the comic book sucks you in!\n"+
"You have entered the world of the X-men!\n");
say(tp+" gets sucked into the comic book.\n");
move_object(this_player(),"/players/unsane/xmen/field.c");
say(tp+" suddenly appears.\n");
return 1;}
}
