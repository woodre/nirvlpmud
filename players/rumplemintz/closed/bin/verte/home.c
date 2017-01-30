status
main()
{
    write("You go home.\n");
   say("Vertebraker goes home.\n");
    move_object(this_player(), "/players/vertebraker/workroom");
    tell_room(environment(this_player()), "Vertebraker comes back home.\n", ({ this_player() }));
    return 1;
}
