reset(arg)
{
if(!arg)
set_light(1);
extra_reset();
}
extra_reset()
{
int i;
       object armor,sword,rider;
if(!present("rider")){
i = 0;
while (i<1){
i +=1;
       rider = clone_object("players/ultramagnus/rider.c");
       call_other(rider, "set_a_chat_chance", 35);
       call_other(rider, "load_a_chat", "Rider pulls at your Soul...!!!\n");
       call_other(rider, "load_a_chat", "Dark Rider says: I'll take your Soul back to Mordor...!!!...\n");
       call_other(rider, "load_a_chat", "Dark Rider says: You cannot Battle the Nazguls...!!!\n");
       move_object(rider, this_object());
}
}
}
init()
{
add_action("west","west");
}
long()
{
write("It is VERY Dark Here...\n");
write("There is an eerie aura about this place...\n");
write("Maybe you shouldn't be Here .... !!!\n");
write("There is light coming from the West.\n");
}
short()
{
return "Dark Cave";
}
west()
{
call_other(this_player(), "move_player","west#players/ultramagnus/pathdown2.c");
return 1;
}
