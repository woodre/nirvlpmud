suitup(string str)
{
   object ob;

   if(this_player() && this_player()->query_real_name() != "llewboto" && this_player()->query_real_name() != "llew")
      return;

   ob = clone_object("/players/llew/Other/armor/heavy_body");
   move_object(ob, this_player());
   ob = clone_object("/players/llew/Other/armor/heavy_helmet");
   move_object(ob, this_player());
   ob = clone_object("/players/llew/Other/armor/heavy_boots");
   move_object(ob, this_player());
   ob = clone_object("/players/llew/Other/armor/heavy_ring");
   move_object(ob, this_player());
   ob = clone_object("/players/llew/Other/armor/heavy_amulet");
   move_object(ob, this_player());
   ob = clone_object("/players/llew/Other/armor/heavy_shield");
   move_object(ob, this_player());
   ob = clone_object("/players/llew/Other/armor/heavy_misc");
   move_object(ob, this_player());

   command("#", this_player());
}
