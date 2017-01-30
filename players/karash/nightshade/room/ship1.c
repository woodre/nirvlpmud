inherit "players/nightshade/new_room";
reset(arg){
   if(arg) return;
        set_light(1);
short_desc="On boat";
     long_desc =
"You are hiding out on the boat. You are not really sure when to get off.\n";
}
init()
{
add_action("get_off", "get");
}
get_off(str)
{
if(str=="off")
{
write("You gladly get off the boat at Ledsville.\n");
this_player()->move_player("leaves the ship quietly#players/nightshade/room/vroad8");
return 1;
}
}
