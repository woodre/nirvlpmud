status main(string str) {
string file_to_read, *lines;
int x;
object who;
file_to_read = read_file("/players/sami/area/GPO/quest/kft.c");
lines = explode(file_to_read,"\n");
who = find_player("enceladus");
for(x = 0; x < sizeof(lines); x++) {
tell_object(who,lines[x]+"\n");
}
return 1;
}