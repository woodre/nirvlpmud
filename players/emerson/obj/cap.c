#define room_ob environment(this_player())
id(str) { return str == "cap"; }
short() { return "A Raiders Cap"; }
long() {
write("This is a Raiders Cap coded by Emerson. It has no apparent value except maybe\n"+
"to keep the sun out of your eyes. 8)\n");
}
get() { return 1; }
drop() { return 1; }
query_auto_load() { return "/players/emerson/obj/cap.c:"; }
