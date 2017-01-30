/*
 * An object used for minor illusions.  The illusion will fade away when looked at.
 * Bard v3.0 by Saber / Geoffrey Z.
 *
 */


inherit "obj/clean";

string short_string, name, alias_name;

reset(arg)  {
  if(arg) return;

  call_out("bye_bye", 300+random(200));  
         }

id(str)  {
  return str == name || str == alias_name || str == "illusion";  }

short()  {  return short_string;  
            if(this_player()->query_level() > 59)  {
              write("-This is a bardic illusion-\n");    } }

long()   {  write("You notice that "+lower_case(short_string)+
                  " is nothing but an illusion\n");
            call_out("bye_bye", 1);
         }

set_name(str)   { name = str;        }
set_alias(str)  { alias_name = str;  }
set_short(str)  { short_string = str;   }

is_illusion()   { return "illusion"; }

get()    { return 1;   }
drop()   { return 1;   }
can_put_and_get()  { return 0; }


init()  {
  ::init();
  add_action("look_at","");
         }

bye_bye()  {
  remove_call_out("bye_bye");
  say("\nThe image of "+lower_case(short_string)+" shimmers and fades away.\n\n");
  destruct(this_object());
  return 1;
         }

look_at(str)  {

string A, B, C, D;

  sscanf(str, "%s %s %s %s", A, B, C, D);
  
  if(A == name || A == alias_name ||
     B == name || B == alias_name ||
     C == name || C == alias_name ||
     D == name || D == alias_name)    {
    
   write("You notice that "+lower_case(short_string)+" is nothing but an illusion.\n");
   
   call_out("bye_bye", 1);
   return 1;
        }
        }
