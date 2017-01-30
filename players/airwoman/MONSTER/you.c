inherit "obj/monster";
 
reset(arg){
int level, wc, ac;
string short, name, long;
level = this_player()->query_level();
name = this_player()->query_real_name();
        short = this_player()->query_short();
::reset(arg); 
 
if (!arg) {
set_name(name); 
set_alias("you");
set_level(level);
set_ac(level/3);     
set_wc(level);
set_short(short);
set_long("YOUR double!  Now you know how ugly you look!\n");
set_aggressive(1);
}
}

