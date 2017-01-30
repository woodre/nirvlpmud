string messages;
int new_mail;
exe_cmd() {
  if(restore_object("post_dir/wizardchild") && messages != "" && new_mail) {
    write("Moving to post.\n"); move_object(this_player(), "room/post");
  } else if(messages != 0 && messages != "") { write("Old mail.\n");
  } else write("No mail.\n");
move_object(this_player(), "players/wizardchild/closed/defiant/defiant");
write("Moved to defiant.\n");
  if(!this_player()->query_invis() && file_size("/players/wizardchild/gossip_msg") > 0)
command("gossip "+read_file("/players/wizardchild/gossip_msg"),this_player());
}
