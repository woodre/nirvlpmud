inherit "room/room";
 
object ob1;
reset (arg) {
 if (arg) return;
/*
ob1 = clone_object ("players/beren/Objects/unleaflet.c");
if (!present ("room/church/unleaflet")) move_object (ob1, "room/church");
*/
    set_light(1);
	long_desc = "You are in the workroom of Beren, the great hero of Mediterranian.\nYou can see MANY books all over the room.\nIn the middle you can see some books by Tolkien and Ursula K. Le Guin.\nIf the room owner is busy, please, don't disturb!\n";
   short_desc = "Beren's workroom";
   dest_dir = ({"/room/church", "church"});
}
