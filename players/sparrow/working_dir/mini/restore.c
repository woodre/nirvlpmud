/*
 *  The restoration chamber of the new mini guilds.  (v2.0)
 *
 */

#define MAX 120
int count, time, inout;
string name, quote;

short()  { return "The mini guild storage chamber";  }
long()   { write("You are in the storage chamber of the mini guilds.\n"+
                 "You get the feeling you really shouldn't be here...\n");
                 return 1;  }

init()  {
  add_action("leave","leave");
  set_light(1);
        }

reset()  {
  int x;
  name = allocate(MAX);
  time = allocate(MAX);
  quote = allocate(MAX);
  inout = allocate(MAX);
  restore_object("/players/saber/closed/new_mini/store");
  while(x < MAX)  {  inout[x] = 1; x+=1;  }
        }

save_file()  {
  object ob;
  int y;

  ob = present("base_obj", this_player());

  while(y < count)  {
    if(name[y] == this_player()->query_real_name())  { count = y;  }
  y+=1;
        }

  name[count] = environment(ob)->query_real_name();
 /*
  time[count] = time();
 */
  quote[count] = ob->query_QUOTE();
  inout[count] = 1;
  count = 0;
  save_object("players/saber/closed/new_mini/store");
  write("Your mini guild info has been saved.\n");
  return 1;
        }

reset_it()  {
  int z;
  while(z <= MAX)  {
    if(!name[z])  {  count = z - 1;  z = MAX + 1;  }
  z+=1;
        }
  if(name[MAX]) count = MAX + 1;
  return;
        }

leave()  {
 call_other(this_player(), "move_player", "leaves#players/saber/workroom.c");
  return 1;
        }

restore_file()  {
  object ob;
  int y;

  ob = present("base_obj", this_player());

  while(y < MAX)  {
  if(name[y] == this_player()->query_real_name() && inout[y] == 1)  {
    name = name[y];
    time = time[y];
    quote = quote[y];
    inout[y] = 0;
        }
  y+= 1;
        }
  if(!name)  {  write("Your file not saved.  Tell Saber.\n");  return 1;  }

  ob->set_quote(quote);
  ob->set_time(time);

  write("Your mini guild stats have been restored.\n");
  save_object("players/saber/closed/new_mini/store");
  return 1;
        }
