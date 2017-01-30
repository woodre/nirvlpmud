main(str){
if(this_player()->query_level() < 21){
write("This command has been blocked.\n");
return 1;
}
return 0;
}
