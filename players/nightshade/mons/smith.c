inherit "obj/monster";
int x,y,max_return,avg_wc;
object ob;
reset(arg){
   ::reset(arg);
   if(arg) return;
set_name("smith");
set_short("Cool Weaponsmith");
set_long("Give a weapon to this dude to see how badly you are\n"
+ "breaking the rules.\n");
   set_level(20);
set_hp(10000);
   set_al(100);
   set_wc(50);
   set_ac(50);
x = allocate(50);
}
init() {
::init();
add_action("give","give");
}
give(str) {
int bs;
string str1, str2;
if (!str) return 0;
if (sscanf(str,"%s to %s",str1,str2) != 2) return 0;
if (str2 != "smith") return 0;
if (!present(str1,this_player())) {
write ("You don't have that.\n");
return 1;
}
if (this_player()->query_level() < 21) {
write ("Smith says: I don't do favors for low life scum like you.\n");
return 1;
}
ob = present(str1,this_player());
if (!ob->weapon_class()) {
write ("That is not a weapon.\n");
return 1;
}
max_return = 0;
avg_wc = 0;
for(y=0;y<50;y++) {
bs = ob->weapon_hit(this_object());
x[y] = ob->weapon_class() + bs;
avg_wc = avg_wc + x[y];
if (bs > max_return) max_return = bs;

}
avg_wc = (avg_wc/50);
tell_room(environment(this_object()),this_player()->query_name()+" gives "+ob->short()+" to smith.\n");
tell_room(environment(this_player()),"The average weapon class of "+ob->short()+" is "+avg_wc+".\n");
tell_room(environment(this_player()),"The base weapon class was "+ob->weapon_class()+".\n");
tell_room(environment(this_player()),"The max return was "+max_return+".\n");
if (avg_wc > 25) tell_room(environment(this_player()),"Smith says: Damn! I want this weapon!\n");
return 1;
}
