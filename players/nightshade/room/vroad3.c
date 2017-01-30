inherit "players/nightshade/new_room";
object ob, duh;
reset(arg){
if(!present("sentry"))
{
duh=clone_object("players/nightshade/mons/sentry");
move_object(duh, this_object());
}
    if(!present("fountain")) {
    ob=clone_object("players/nightshade/misc/fountain");
    move_object(ob, this_object());
    }
if(!present("sign"))
{
ob=clone_object("players/nightshade/misc/notice3");
move_object(ob, this_object());
}
   if(arg) return;
        set_light(1);
        short_desc = " Ledsville";
     long_desc =
"A beautifull foutain sits here on the crossroads. The sweet smell\n"+
"of the ocean comes in on a slight breeze from the east. Way off to\n"+
"west you can see the Dragonspine Mountains. The town shop is to the\n"+
"southwest of you and the BUDS B' US pub lies to the southeast. You can see a huge castle way south.\n";
      dest_dir = 
      ({ "/players/nightshade/room/shoprd", "south",
      "players/nightshade/room/vroad2", "north",
   "players/nightshade/room/vroad5", "east",
   "players/nightshade/room/wroad1", "west",
      });
}
init()
{
::init();
add_action("do_swim", "swim");
}
do_swim(str)
{
if(!str) return;
if(str == "fountain")
{
write("You strip butt naked and jump into the fountain. You hope no one sees you.\n");
this_player()->move_player("into the fountain#players/nightshade/room/in_fount");
return 1;
}
}
