init(){
 add_action("bl","bl");
}
bl() {
say("blleeeech "+this_player()->query_name()+" NNNNNNN\n");
return 1;
}
id(str) {
    return str == "cookie" || str == "yummy cookie";
}
