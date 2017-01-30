#include "/players/fred/ansi.h"
inherit "/obj/treasure.c";

reset (arg) {
  set_id("stand");
  set_short("An Exchange Stand");
  set_long(
    "  A small stand where you could exchange elemental armors.\n"+
    "All one would have to do is 'exchange <what> for <what>'\n"+
    "This is for a limited time of 1 week and will also cost you\n"+
    "15,000 coins. To see the armors available type 'list'.\n");
}

get(){ return 0; }

init(){
 ::init();
   add_action("exchange","exchange");
   add_action("list_all","list");
 }

list_all(){
  write("\n\t    The new armors available are:\n"+
        RED+"\t\t~ "+NORM+BLU+"Ele"+NORM+GRN+"ment"+NORM+BOLD+"al B"+NORM+GRN+"oo"+NORM+BLU+"ts"+NORM+RED+" ~"+NORM+"\n"+
        RED+"\t\t~ "+NORM+BLU+"Ele"+NORM+GRN+"ment"+NORM+BOLD+"al H"+NORM+GRN+"el"+NORM+BLU+"m"+NORM+RED+" ~"+NORM+"\n"+
        RED+"\t\t~ "+NORM+BLU+"Ele"+NORM+GRN+"ment"+NORM+BOLD+"al Gau"+NORM+GRN+"ntl"+NORM+BLU+"ets"+NORM+RED+" ~"+NORM+"\n"+
        RED+"\t\t~ "+NORM+BLU+"Ele"+NORM+GRN+"ment"+NORM+BOLD+"al C"+NORM+GRN+"lo"+NORM+BLU+"ak"+NORM+RED+" ~"+NORM+"\n"+
        RED+"\t\t~ "+NORM+BLU+"Ele"+NORM+GRN+"ment"+NORM+BOLD+"al Sh"+NORM+GRN+"ie"+NORM+BLU+"ld"+NORM+RED+" ~"+NORM+"\n"+
        RED+"\t\t~ "+NORM+BLU+"Ele"+NORM+GRN+"ment"+NORM+BOLD+"al Neck"+NORM+GRN+"gua"+NORM+BLU+"rd"+NORM+RED+" ~"+NORM+"\n\n");
  return 1;
}

exchange(str){
  string item1, item2;
  object ob;
  if(!str){ write("Exchange <what> for <what>?\n"); return 1; }  
  if(sscanf(str, "%s for %s", item1, item2)){
  ob = present(item1, this_player());
  if(!ob){
    write("You don't have a "+item1+".\n");
    return 1; }
  if(!ob->is_elem_armor()){
    write("You can't exchange that here!\n");
    return 1; }
  if(ob->query_worn()){
    write("You must remove the "+item1+" first.\n");
    return 1; }
  if(item2 != "boots" && item2 != "ring" && item2 != "cloak" &&
     item2 != "neckguard" && item2 != "helm" && item2 != "shield"){
    write("You can't exchange your "+item1+" for a "+item2+".\n");
    return 1; }
  if(this_player()->query_money() < 15000){
    write("You don't have enough money to make an exchange.\n");
    return 1; }
  write_file("/players/snow/closed/test/traded",
    this_player()->query_name()+" exchanged a "+item1+" for an "+item2+" "+ctime() [4..15]+ "\n");
  if(item2 == "shield"){
    move_object(clone_object("/players/snow/closed/test/shield.c"),
    this_player());
    this_player()->add_money(-15000);
    destruct(ob);
    write("You watch as a large gust of wind blows away the money you put on the stand.\n");
    write("As you turn back towards the stand you notice you're "+item1+" is gone\n"+
          "and you now hold a new "+item2+"!\n");
    return 1; }
  if(item2 == "gauntlets"){  
    move_object(clone_object("/players/snow/closed/test/gauntlets.c"),
    this_player());
    this_player()->add_money(-15000);
    destruct(ob); 
    write("You watch as a large gust of wind blows away the money you put on the stand.\n");
    write("As you turn back towards the stand you notice you're "+item1+" is gone\n"+
          "and you now hold a new pair of "+item2+"!\n");
    return 1; }
  if(item2 == "boots"){
    move_object(clone_object("/players/snow/closed/test/boots.c"),
    this_player());
    this_player()->add_money(-15000);
    destruct(ob); 
    write("You watch as a large gust of wind blows away the money you put on the stand.\n");
    write("As you turn back towards the stand you notice you're "+item1+" is gone\n"+
          "and you now hold a new pair of "+item2+"!\n");
    return 1; }
  if(item2 == "cloak"){
    move_object(clone_object("/players/snow/closed/test/cloak.c"),
    this_player());
    this_player()->add_money(-15000);
    destruct(ob); 
    write("You watch as a large gust of wind blows away the money you put on the stand.\n");
    write("As you turn back towards the stand you notice you're "+item1+" is gone\n"+
          "and you now hold a new "+item2+"!\n");
    return 1; }
  if(item2 == "neckguard" || item2 == "guard"){
    move_object(clone_object("/players/snow/closed/test/neckguard.c"),
    this_player());
    this_player()->add_money(-15000);
    destruct(ob); 
    write("You watch as a large gust of wind blows away the money you put on the stand.\n");
    write("As you turn back towards the stand you notice you're "+item1+" is gone\n"+
          "and you now hold a new "+item2+"!\n");
    return 1; }
  if(item2 == "helm"){
    move_object(clone_object("/players/snow/closed/test/helm.c"),
    this_player());
    this_player()->add_money(-15000);
    destruct(ob); 
    write("You watch as a large gust of wind blows away the money you put on the stand.\n");
    write("As you turn back towards the stand you notice you're "+item1+" is gone\n"+
          "and you now hold a new "+item2+"!\n");
    return 1; }
   }
  return 1;
}
