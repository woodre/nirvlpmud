inherit "room/room";
reset(arg){
   if(arg) return;
        set_light(1);
short_desc="Jungle";
     long_desc =
"You crawl out of the ocean onto a small island. The beach you are\n"+
"is small as well. The jungle to the north comes almost right up to\n"+
"the water. The beach heads northeast and northwest. You can brave\n"+
"the jungle if you want to. Just go north. Out on the ocean you see\n"+
"another ship. Perhaps if you swim to it they can give you a ride back\n"+
"to Ledsville.\n";
      dest_dir = 
({
"players/nightshade/room/i13", "north",
"players/nightshade/room/i8", "northwest",
"players/nightshade/room/i2", "northeast",
      });
}
init()
{
add_action("do_swim", "swim");
::init();
}
do_swim(str)
{
if(!str) return;
if(str == "ship")
{
write("You dive into the ocean and swim towards the ship. They meet you\n"+
"halfway and pick your sorry ass up.\n");
this_player()->move_player("into the ocean#players/nightshade/room/ship1");
return 1;
}
}
