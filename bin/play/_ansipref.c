status
cmd_ansipref()
{
    object ob;
    ob=clone_object("/obj/ansi_man");
    move_object(ob, this_player());
    ob->cmd_ansipref();
    return 1;
}
