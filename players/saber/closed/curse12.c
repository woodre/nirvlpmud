#define tp this_player()->query_name()
inherit "obj/treasure";

id(str) {return str == "curse";}
long() {
    write("A curse designed by Saber.\n");
}
short() {write("A curse.\n");
}
 query_weight() {return 0;}
query_value() {return 0;}
drop() {return 1;}

init() {
   add_action("curse","curse");
}

curse(str) {
object target,curse;
if(!str){
 write("Use: curse 'player'\n");
}
target = find_player(str);
if(!target){
write("This person isn't here.\n");
return 1;
}
curse = clone_object("players/saber/closed/coin2.c");
move_object(curse,target);
tell_object(target,
"A blue aura of magic surrounds you and clamps over your mouth.\n");
write(capitalize(str)+" is gagged by an aura of blue magic.\n");
return 1;
}
