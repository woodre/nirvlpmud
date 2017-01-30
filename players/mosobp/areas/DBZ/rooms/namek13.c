inherit "room/room";
reset(arg){
    if(arg) return;

short_desc = "An entryway";
long_desc = 
..
add_item("mirrors","These mirrors are so the queen can look at herself where eve
r she goes.");
add_item("walls","The walls are decorated with various paintings.");
add_item("paintings","Paintings from famous Saiyan artists hanging on the walls.
");
    add_exit("/players/gohan/namek/namek15.c","east");
    add_door("south",0,0,0,"gate");
}
