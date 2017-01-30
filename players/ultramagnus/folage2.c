reset(arg)
{
if(!arg)
set_light(1);
extra_reset();
}
extra_reset()
{
       object cloak,staff,wizard;
if(!present("wizard")){
       wizard = clone_object("players/ultramagnus/wizard.c");
       call_other(wizard, "set_a_chat_chance", 35);
       call_other(wizard, "load_a_chat", "Wizard says: What manner of follie is this...??!!!\n");
       call_other(wizard, "load_a_chat", "Wizard says: I'll show YOU a sense of Justice!!!\n");
       call_other(wizard, "load_a_chat", "Wizard throws a Fireball at You...!!!\n");
       move_object(wizard, this_object());
       staff = clone_object("players/ultramagnus/staff.c");
       move_object(staff, wizard);
       cloak = clone_object("players/ultramagnus/wiz_cloak.c");
       move_object(cloak, wizard);
}
}
init()
{
add_action("north","north");
}
long()
{
write("You are near the River's edge.\n");
write("There is an old bridge high above you.\n");
write("There is a small trail leading North\n");
write("into the folage.\n");
}
short()
{
return "River's edge";
}
north()
{
call_other(this_player(), "move_player","north#players/ultramagnus/folage.c");
return 1;
}
