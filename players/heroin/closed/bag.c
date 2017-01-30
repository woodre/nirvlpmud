get(){return 1;}
query_value(){return 0;}
short(){return "A Marauder's Bag";}
id(str){return str=="bag"||str=="marauder bag";}
init(){
add_action("mine","mine");
}
mine(str){
move_object(clone_object("/players/heroin/mine.c"),environment(this_player()));
return 1;}
query_auto_load(){return "/players/heroin/bag.c";}
