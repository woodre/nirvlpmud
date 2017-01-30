inherit "room/room.c";
object snake;
object truck;
reset(arg) {
    if (arg) return;
    set_light(1);
    short_desc = "The end of the countryside";
    long_desc = 
        "This is the end of the countryside. In what appears to be a\n" 
        + "funny comic, you see three snakes on the road, and an oncoming\n"
        + "pickup truck. Too bad you don't know the punchline, eh?\n";
    dest_dir = 
        ({
        "/players/wizardchild/rooms/side1.c", "north",
        });
    snake = clone_object("/players/wizardchild/monsters/snake.c");
    move_object(snake, this_object());
    snake = clone_object("/players/wizardchild/monsters/snake.c");
    move_object(snake, this_object());
    snake = clone_object("/players/wizardchild/monsters/snake.c");
    move_object(snake, this_object());
    truck = clone_object("/players/wizardchild/objects/truck.c");
    move_object(truck, this_object());
}
