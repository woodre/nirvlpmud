main(str){
string who,what;
if(!str || sscanf(str,"%s %s",who,what) != 2) {
write("Incorrect # of args.\n");
return 1;
}
if(!find_player(who)){
write("Player not found.\n");
return 1;
}
write("Querying...\n");
write("Returns: ");
write(call_other(find_player(who), "query_"+what));
write("\n");
return 1;
}
