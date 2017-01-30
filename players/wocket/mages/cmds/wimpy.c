cmd(str){
if(str != "off"){
write("This command has been blocked.\n");
return 1;
}
return 0;
}
