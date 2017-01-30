/*
 *  A new who for mini guild members.
 *  Version 2.0
 *
 */

mini_guild_who()  {

  string who, levels;
  int number, b, level;
  object ob, ob2;

  ob = users();

  write("\n >< - >< - >< - >< - >< - >< - >< - >< - >< - >< - >< - >< - >< - >< - >< - ><\n");
  write(" ><  Name           Lvl  /  X-Lvl    Gender      Guild         Mini Guild   ><\n");
  write(" >< - >< - >< - >< - >< - >< - >< - >< - >< - >< - >< - >< - >< - >< - >< - ><\n\n");

for(b=0; b<sizeof(ob); b+=1)  {
if(ob[b]->query_level() < 21 && !ob[b]->query_invis()){
    write(" ><  ");

write(pad(ob[b]->query_name(),15));
write(pad(ob[b]->query_level(),8));
write(pad(ob[b]->query_extra_level(),9));
write(pad(ob[b]->query_gender(),12));
if(ob[b]->query_guild_name() == 0)  {
  write("none          ");
  }  else  {
write(pad(ob[b]->query_guild_name(),14));
        }
if(present("base_obj", ob[b]))  {
  ob2 = present("base_obj", ob[b]);
  write(pad(ob2->query_newguild(),12));
        }
if(!present("base_obj", ob[b]))  {
  write("            ");
        }
write(" ><\n");
       }
        }
write("\n >< - >< - >< - >< - >< - >< - >< - >< - >< - >< - >< - >< - >< - >< - >< - ><\n\n");
return 1;
        }
