fangs(str) {
object fangs, who;

who=present(str,environment(this_player()));
if(!who) {
	write("That person is not here.\n");
	return 1;
}
fangs=move_object(clone_object("/players/nooneelse/black/vampire_fangs"),who);
return 1;
}