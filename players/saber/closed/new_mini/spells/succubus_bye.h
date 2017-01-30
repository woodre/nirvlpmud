/*
 *  How to get out of a mini guilds (v2.0)
 *
 */


static object OBJ;
succubus_bye()  {
  OBJ = present("jeweled choker",this_player());
  OBJ->set_is_succubus(0);
   write("You drop your choker and vow never to tempt men again.\n");
  call_out("gone",1);
  return 1;
        }

gone()  {
  if(OBJ)
  if(environment(OBJ)) {
     if(environment(OBJ)->query_attrib("ste") > 20)
      environment(OBJ)->set_attrib("ste",20);
     }
   write("A feeling of sorrow passes over you.\n");
   destruct(OBJ);
   OBJ = 0;
   return 1;
        }
