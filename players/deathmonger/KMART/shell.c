
id(str){ return str == "shell" || str == "artshell"; }
short(){ return "An artillery shell"; }
long(){
write("A note on the shell reads: 'For use with the dreadndnought cannon.'\n");
}
get(){ return 1; }
query_weight(){ return 1; }
query_value(){ return 400; }
