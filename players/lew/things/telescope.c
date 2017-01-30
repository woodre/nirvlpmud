inherit "obj/treasure";

reset(arg) {
   if(!arg) {

    set_id("telescope");
    set_short("A telescope");
    set_long("This is a telescope. (no kidding).\n"+
             "With it you can 'spy player' and see where they are.\n");
    set_weight(5);
    set_value(1000);
}
}
init() {
  ::init();

    add_action("look", "spy");
}
look(str) {
    object player;
    player=find_player(str);
    if(!player) { write("You can't see who isn't here.\n"); return 1; }
    if(player->query_level() >21) { write("You don't need to know where a wiz is.\n"); return 1; }
    call_other(player, "look");
    tell_object(player, "You feel as if you are being watched.\n");
    return 1;
}
