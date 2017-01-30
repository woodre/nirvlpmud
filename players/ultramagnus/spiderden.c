reset(arg)
{
if(!arg)
set_light(1);
extra_reset();
}
extra_reset()
{
       object shield,heal,apple,chelob;
if(!present("chelob")){
       chelob = clone_object("players/ultramagnus/chelob.c");
       call_other(chelob, "set_a_chat_chance", 35);
       call_other(chelob, "load_a_chat", "Chelob says: Ah!...Fresh Meat....!!!\n");
       call_other(chelob, "load_a_chat", "Chelob says: You will Not Escape Me...!!!\n");
       call_other(chelob, "load_a_chat", "Chelob stings you with Venom...!!!...\n");
       move_object(chelob, this_object());
       heal = clone_object("players/ultramagnus/heal.c");
       move_object(heal, chelob);
	apple= clone_object("players/ultramagnus/apple.c");
	move_object(apple, this_object());
       shield = clone_object("players/ultramagnus/shield_gondor.c");
       move_object(shield, chelob);
}
}
init()
{
add_action("west","west");
}
long()
{
write("This is Chelob's Lair.  There is Sticky Webbing all around.\n");
write("The Smell of Blood is in the Air!!!\n");
write("There is a small exit to the west...\n");
}
short()
{
return "Chelob's Lair";
}
west()
{
int n;
n=random(3);
if(n!=1){
call_other(this_player(), "move_player","west#players/ultramagnus/redweb.c");
}
if(n==1){
write("You are Stuck in Webbing...!!!...You can't seem to Escape...!!!!\n");
}
return 1;
}
