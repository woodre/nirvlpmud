/* A Disease Control object, based on the Mini Guild Master Ring.
 * From the object base.c
 * Version 1.0 by Saber
 * This is a master object for all the diseases.
*/

#define CAP capitalize(str)
#define TO this_object()
#define tp this_player()->query_name()
object flu;


id(str)  {
  return str == "disease_control" ||
    str == "control";
          }

  drop()  { return 1; }
  get()   { return 1; }
  can_put_and_get()  { return 0; }

  short()  { return "A Disease Control Object"; }

  long()  {
   write("A Disease Control Object.\n");
   write("\n");
   write("It reads:\n"+
         "Type <control> <disease name> to see who has what.\n");
         }


init()  {
  if(this_player()->query_level() > 20)  {
    add_action("check_disease","control");

  }   else   {
   write("This object was not ment for you!\n");
   write("You feel your brain melting...\n");
   say(tp+" touches the Disease Object and is fried by a blue bolt.\n");
   flu = clone_object("/players/saber/closed/virus/flu.c");
   move_object(flu,this_player());
   return 1;
        }
        }


check_disease(str)  {
int a, b;
string NO, YES;
object ob, ob2;
ob = users();

NO = " *       ";
YES = "Yes      ";

if(!str)  {
  write("What do you want to scan for?\n");
  return 1;
          }

write("\n\n");
write("Player Name    Do they have (the) "+str+"?\n");
write("\n");

for(b=0;b<sizeof(ob);b+=1)  {
write("* ");
write(pad(ob[b]->query_name(),13));
if(present(str, ob[b])) { write(YES); }
 else { write(NO);  }

/*
if(present("blade_obj", ob[b])) { write(YES); }
 else { write(NO);  }
if(present("meow_obj", ob[b])) { write(YES); }
 else { write(NO);  }
*/

write("\n");
        }
write("\n");
return 1;
        }
