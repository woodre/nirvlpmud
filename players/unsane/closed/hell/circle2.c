inherit "room/room";

#define tp this_player()->query_name()
int i;

object soul, rags;
reset (arg){
if (!arg){
set_light(1);
if (!soul || !living(soul)) {
for (i = 0; i<5; i++) {
soul = clone_object("obj/monster.talk");
call_other(soul, "set_alt_name", "wretch");
if (i==0) {
call_other(soul,"set_short","Semiramis the wretch");
call_other(soul,"set_name","semiramis"); }
if (i == 1) {
call_other(soul,"set_short","Achilles the wretch");
call_other(soul,"set_name","achilles"); }
if (i == 2) {
call_other(soul,"set_short","Paris the wretch");
call_other(soul,"set_name","paris"); }
if (i==3) {
call_other(soul,"set_short","Dido the wretch");
call_other(soul,"set_name","dido"); }
if (i==4) {
call_other(soul,"set_short","Helen the wretch");
call_other(soul,"set_name","helen"); }
call_other(soul, "chat_chance", 5);
call_other(soul, "chat_a_chance",5);
call_other(soul, "load_chat", "You see a soul tighten their grip\n");
call_other(soul, "load_a_chat","The wretch begins to weep.\n");
call_other(soul, "set_long",
"This poor wretch is doing their best to cling to the rocks in this storm.\n"+
"They have a pallid green colour and their fingers are bleeding from years\n"+
"of trying not to get swept up.  This makes you wonder what on earth could\n"+
"could be worse than this?  Why don't they just let go?\n");
call_other(soul,"set_hp",140);
/* No ac, no wc, not lev. 12... changed level from 12 to 3 -Snow */
call_other(soul,"set_level",3);
move_object(soul,this_object());
rags=clone_object("obj/armor");
call_other(rags,"set_name","rags");
call_other(rags,"set_short","A bunch of filthy rags");
call_other(rags,"set_long","These rags are disgusting.\n"+
"They are covered with lice, old flesh, and blood.  Try them on?\n");
call_other(rags,"set_value",random(100));
call_other(rags, "set_ac", 1);
call_other(rags,"set_type","armor");
transfer(rags, soul);
call_other(soul,"init_command","wear rags");
}
}
short_desc="The Second Circle of Hell";
long_desc =
"   You have entered a pit so vast, it seems to go on forever.  This is the\n"+
"Second Circle of Hell.  It is a place of Stygian darkness, where great winds\n"+
"churn the air asm the mightiest storms do the sea.  Caught in this endless\n"+
"are those souls who subjected reason and intellect to carnal desire.  The\n"+
"winds drive all before them, allowing no comfort, no rest.  The best these\n"+
"people can hope for is ot lessen their torment, and the pain it brings them.\n"+
"They will NEVER be free of it.\n";
items=({
   "winds","These winds lash and whip at you",});
dest_dir=({
"/players/unsane/closed/hell/circle1.c","flee",
"/players/unsane/closed/hell/hurricane.c","north",});
} }
init(){
::init();
add_action("listen","listen");
   add_action("smell","smell");
   add_action("search","search");
}
search(){
write("Your search proves to be fruitless.\n");
return 1;
}
smell(){
write("Are you kidding?  You are having a hard enough time breathing.\n");
say(tp + " sniffs the putrid air.\n");
return 1;
}
listen(){
write("You can't hear anything over this wind.\n");
say(tp + " perks up their ears.\n");
return 1;
}

