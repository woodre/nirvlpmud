/* since nobody feels like fixing moe, i decided to do something
 * about it :)
 */

 short() { return "Moe's Pacemaker"; }

 long()
 {
	write("This is an object daemon that simply kicks Moe of Springfield's\n"+
	"heartbeat every so often. This is a L24 monster that loses its heartbeat\n"+
	"and is a known exploit to players on the mud.\n");
 }

 reset(arg)
 {
	move_object(this_object(), "/players/mizan/core/02h/room04.c");
	if(arg) return;

	remove_call_out("fake_beat");
	call_out("fake_beat", 3);

 }

 fake_beat()
 {
	object ob;
	ob = find_living("Moe");

	if(ob && ob->query_attack())
	{
            ob->set_heart_beat(1);
	}
	remove_call_out("fake_beat");
	call_out("fake_beat", 3);
 }
