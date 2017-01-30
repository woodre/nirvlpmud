long() {
 if(this_player()->query_guild_name() == "mage"){
  write("The dragon's tooth is the crucial component to the Mage Staff.\n");
  write("Type 'shape staff' to create your Mage weapon.\n");
  } else {
  write("A large tooth from Hzsade the dragon.\n");
 }
}

reset(arg){
 if(arg) return;
}

query_weight(){ return 3; }
short(){ return "Dragon's tooth"; }
id(str){ return str == "tooth"; }
query_value(){ return 500; }
get(){ return 1; }

init(){
 if(this_player()->query_guild_name() == "mage")
 add_action("shape_staff","shape");
}

shape_staff(){
 if(present("mage_staff", this_player())){
  write("You already have a Mage Staff.\n");
  return 1;
 }
 write(
 "You cast a spell and the jagged tooth turns into a powerful weapon!\n"+
 "The Mage's Staff fits perfectly into your hands!\n");
 say(capitalize(this_player()->query_name())+
 " casts a spell and turns a dragon;s tooth into a powerful weapon!\n");
 move_object(clone_object("players/pavlik/weapons/mage_staff"), this_player());
 destruct(this_object());
 return 1;
}
