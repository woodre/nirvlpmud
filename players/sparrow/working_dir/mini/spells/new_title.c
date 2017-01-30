/*
 *  An ability of the version 2.0 of the mini guilds
 *      which allows the player to change their title to one of
 *      the pre set mini guild titles.
 *
 */

new_title()  {

  string titl;
  object ob;

  ob = present("base_obj",this_player());

  if(ob->query_object_name() == "meow_obj")      titl = "the Cat Dancer";
if(ob->query_object_name() == "canine_obj")      titl = "the Canine";
  if(ob->query_object_name() == "succubus_obj")  titl = "the temptress of men";
  if(ob->query_object_name() == "larn_obj")      titl = "the Servant of Larn";
  if(ob->query_object_name() == "kender_obj")    titl = "the Kender";
  if(ob->query_object_name() == "blade_obj")     titl = "the Blade";
  if(ob->query_object_name() == "gothic_obj")      titl = "the Goth";
  if(ob->query_object_name() == "gypsy_obj")     titl = "the Gypsy";


  call_other(this_player(), "set_title", titl);
  write("You are now \""+tp+" "+titl+"\"\n");
  return 1;
        }
