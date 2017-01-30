inherit "/obj/treasure.c";
string *BANNED;

reset(arg){
BANNED = ({ "kindred","tallos","newkil","syan","kaya" });
}

init(){
/*
  if(member_array(this_player()->query_real_name(),BANNED) != -1){
    write("Your testing survices are no longer needed.  Thankyou for your time.\n    -wocket\n");
    destruct(this_object());
    return 1;
  }
*/
  write("Updating to the new object.\n");
  move_object(clone_object("/players/wocket/necro/guildob.c"),this_player());
  destruct(this_object());
}
