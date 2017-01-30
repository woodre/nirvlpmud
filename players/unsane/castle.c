#define NAME "Unsane"
#define tp this_player()->query_name()
#define DEST "room/big_tree"
/*
 * This is just the facade to a castle. If you want to enable the
 * "enter" command, move the player to a hall or something (which
 * you have to design yourself).
 * The predefined string DEST is where a player should come when he
 * leaves the castle.
 *
 * This file is loaded automatically from "init_file". We have to move
 * ourself to where we are supposed to be.
 */
object dispenser, ob, lucky;

id(str) { return str == "man"; }

short() {
    return "A Hooded Man";
}

long() {
write(
"  This man scowls when he sees that you are staring at him.  He looks\n"+
"at you, and then at a length of rope nearby.  A devilish grin appears on\n"+
"his face.  It is at this time that you notice the large tree here.  This\n"+
"sure would be a perfect place for a hanging, don't you think.  Apparently\n"+
"the hooded man thinks so as well.  You have always wondered what lies beyond\n"+
"this life.  Perhaps you should ask him to hang you?  You can experience\n"+
"the afterlife first hand.\n");
}

init() {
#ifndef __LDMUD__ /* Rumplemintz */
    add_action("my_say"); add_verb("say");
    add_action("my_say"); add_xverb("'");
#else
  add_action("my_say", "say");
  add_action("my_say", "'", 3);
#endif
}

my_say(str) {
string a,b;
lucky = this_player();
write ("You say: " + str + "\n");
say (tp + " says: " +str + "\n");
if (!str) {
return 0;
}
if (sscanf (str, "%shang%s", a,b) == 2) {
write("The man walks takes the length of rope and fashions a noose with it.\n");
write("\n");
write("He tosses the end of the rope over the tree branch.\n");
write("\n");
write("Then he places the noose around your head and you know no more.\n");
call_out("ddie",3);
say("The hooded man has hung "+tp+".\n");
}
return 1;
}

ddie(){
if(!lucky) return 1;
tell_object(lucky,"You suddenly find you have woken up in a strange place.\n");
move_object(lucky,"/players/unsane/closed/hell/circle1.c");
command("look",lucky);
return 1; }
reset(arg) {
if (!find_living("roach")){move_object(clone_object("/players/unsane/chaos/roach"),"/room/plane4");}
    if (arg)
	return;
    move_object(this_object(), DEST);
}
is_castle(){return 1;}
