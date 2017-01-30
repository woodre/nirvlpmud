int cmd_cemote(string arg)
{
   object ob;
   if((string)this_player()->query_real_name() != "vertebraker" && (string)this_player()->query_real_name() != "forbin") return 0;
   if(ob = present("emote_editor", this_player())) destruct(ob);
   ob = clone_object("/players/vertebraker/emotes/editor");
   move_object(ob, this_player());
   ob->main();
   return 1;
}
