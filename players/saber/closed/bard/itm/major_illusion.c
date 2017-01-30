/*
 * An object used for majors illusions.
 * Bard v3.0 by Saber / Geoffrey Z.
 *
 */


inherit "obj/clean";

string short_string, name, alias_name;

reset(arg)  {
  if(arg) return;

  call_out("bye_bye", 350+random(300));  
         }

id(str)  {
  return str == name || str == alias_name || str == "illusion";  }

short()  {  return short_string;  
            if(this_player()->query_level() > 59)  {
              write("-This is a bardic illusion-\n");    } }

long()   {  write("You notice that "+lower_case(short_string)+
                  " is nothing but an illusion\n");
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
  add_action("ill_get","get");
  add_action("ill_get","take");
         }

bye_bye()  {
  remove_call_out("bye_bye");
  say("\nThe image of "+lower_case(short_string)+" shimmers and fades away.\n\n");
  destruct(this_object());
  return 1;
         }


ill_get(str)  {

  if(str == name || str == alias_name || str == "illusion")  {
  
  write("Your hand passes through the "+lower_case(short_string)+".\n");
  say(this_player()->query_name()+" tries to take a "+lower_case(short_string)+".\n");
  return 1;
         }
         }
         
