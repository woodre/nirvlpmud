/*
 *  A special who that only shows Blades.  (v2.0)
 *
 */

blade_kin()  {

  int b;
  object ob, ob2, ob3;
  string IDEN;

  ob = users();
  ob2 = present("blade_obj",this_player());
  IDEN = ob2->query_object_name();

write("\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
  write("\n");
write("  Name           Level    Gender   Quote              \n");
  write("\n");
write("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
  write("\n");


  for(b=0; b<sizeof(ob); b+=1)  {
  if(ob[b]->query_invis() == 0)  {
    if(present("blade_obj", ob[b]))  {

write("  ");
write(pad(ob[b]->query_name(),15));
write(pad(ob[b]->query_level(),9));
write(pad(ob[b]->query_gender(),9));
   ob3 = present("blade_obj", ob[b]);
if(ob3->query_QUOTE() == 0)  {
    write(ob[b]->query_name()+" has no quote.");
  }  else  {
write(pad(ob3->query_QUOTE(),40));
        }

write("\n");
        }
        }
        }

write("\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n");
return 1;
        }
