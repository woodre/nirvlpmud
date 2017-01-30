#define NAME "Hurtbrain"
#define DEST "room/plane6"
/*
 * This is just the facade to a castle. If you want to enable the
 * "enter" command, move the player to a hall or something (which
 * you have to design yourself).
 * The predefined string DEST is where a player should come when he
 * leaves the castle.
 *
 * This file is loaded automatically from "init_file". We have to move
 * ourself to where we are supposed to be.
 */

id(str) { return str == "machine"; }

short() {
    return "A Time Machine <enter machine>";
}

long() {
    write("This is The Time Machine.\n");
    write("You can enter it typyng 'enter machine'.\n");
}

init() {
  add_action("enter", "enter");
}

enter(str) {
    if (!id(str))
        return 0;
    write(this_player()->query_name() + " enters the Machine.\n");
    move_object(this_player(), "/players/hurtbrain/castello/entrance");    
    command("look",this_player());
    command("read sign",this_player());
    return 1;
}

reset(arg) {
    if (arg)
        return;
move_object(this_object(), DEST);
/*
   call_other("/players/hurtbrain/ball.c","??");
   call_other("/players/hurtbrain/advancer.c","??");
   call_other("/players/hurtbrain/quick.c","??");
   call_other("/players/hurtbrain/obj/myspeed.c","??");
 */

/* Autoloading wiztools waste alot of memory   -miz */
   call_other("/players/hurtbrain/life.c","??");
/*
   call_other("/players/hurtbrain/obj/newspeed.c","??");
*/
}

is_castle(){return 1;}
