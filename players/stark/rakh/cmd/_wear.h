wear(string arm){
object armor;
if(arm=="shield"){
    write("You're decide not use the shield.\n");
    return 1;
}
armor = present(arm,TP);
if(armor->query_type()=="shield"){
     write("You're decide not use the shield.\n");
     return 1;
}
return 0;}