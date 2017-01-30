init() {
add_action("bb","bb");
}
bb(){ 
this_player()->heal_self(20);
return 1;
}
id(str) {
    return str == "top" || str == "wooden top";
}
