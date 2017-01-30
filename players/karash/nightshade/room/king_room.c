inherit "players/nightshade/new_room";
object ob;
int found;
reset(arg){
if(!present("elrond"))
{
ob=clone_object("players/nightshade/mons/elrond");
move_object(ob, this_object());
}
found = 0;
   if(arg) return;
        set_light(1);
short_desc = "Kings Room";
     long_desc =
"Well you have made it to King Elronds room. He doesnt look to happy\n"+
"at the interruption. He is a rather old looking dood, but dont let\n"+
"that fool you. Many have died thinking the same thing. There are\n"+
"bookshelves lining the walls containing hundreds of volumes of old\n"+
"dusty tomes. He has a large desk made out of glassteeled black diamond.\n"+
"It has many drawers and a comfortable chair. His bed is small for someone\n"+
"of his stature. A long fluffy pillow lies at the head of the bed.\n";
      dest_dir = 
({
"players/nightshade/room/wait_room", "west",
      });
}
init()
{
::init();
add_action("do_search", "search");
}
do_search(str)
{
object ob;
if(str == "pillow")
{
if(!found) {
write("You find a small piece of paper inside the pillow.\n");
ob=clone_object("players/nightshade/misc/paper");
move_object(ob, this_object());
found = 1;
}
else write("You find nothing.\n");
return 1;
}
if(str == "bed")
{
write("You find nothing of interest.\n");
return 1;
}
if(str == "shelves")
{
write("You find several interesting books about dragons and magic. You sit down for a moment and read a little bit.\n");
return 1;
}
}
