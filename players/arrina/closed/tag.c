id(str){return str == "tagger";}
init() {
add_action("copy","copy");
}
copy(str){
string reader;
int ender,n;
if(!str) return 0;
ender = file_size(str);
n=0;
while(n<sizeof(ender)){
reader = read_bytes(str,n,5);
write_file("/players/arrina/closed/file",reader+"\n");
n = n+6;}
write("done\n");
return 1;}
