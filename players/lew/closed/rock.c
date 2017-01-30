inherit "obj/treasure.c";


init(){
if(this_player()->query_real_name() != "lew"){
    add_action("slam"); add_xverb("");}
}

reset(arg){
if(!arg){
set_id("rock");
}

}
slam(){
write(
"you feel your body pelted with rocks as you try to move.\n");
return 1;
}
