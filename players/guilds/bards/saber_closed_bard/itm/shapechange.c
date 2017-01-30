/*
 * The object a Bard enters when she shapechanges.
 * Bard v3.0 by Saber / Geoffrey Z.
 *
 */


inherit "/obj/monster";

string LONG, SHORT;

reset(arg) {
   ::reset(arg);
if (!arg){
     set_name("jacket");
     set_level(1);
     set_ac(10);
     set_wc(0);
     set_hp(5);
     set_al(0);
     set_aggressive(0);

     set_dead_ob(this_object());

     set_object(this_object());
     set_function("inform_player");
     set_type("");
     set_match("");
   }
   }


long()  {  write(LONG+".\n");  }

short()  {
  if(environment(this_player()) != environment(this_object())) {
  return environment(this_object())->short();
  }  else {
  return SHORT; 
        
        }
        }

inform_player(str) {  tell_room(this_object(), str); }  


init()  {
  ::init();

if(environment(this_player()) == this_object())  {
  add_action("end_it","shapechange");
  add_action("new_look","l");
  add_action("new_look","look");
  }
  }
  


end_it()  {

  write("You shapechange back into "+this_player()->query_name()+".\n");
  say(SHORT+" shapechanges into "+this_player()->query_name()+".\n");

  destruct(this_object());
  return 1;
        }


monster_died()  {
object ob, bard;
 
  ob = first_inventory(this_object());
  
  while(ob)  {
    if(ob->is_player())  { bard = ob; }
    ob = next_inventory(ob);
        }
 
 move_object(bard, environment(this_object()));
 
 tell_room(environment(bard), this_object()->short()+" suddenly changes shape into "+
 bard->query_name()+"!\n");
 
        }


new_look(str)  {
string there, short_str;
object MUSIC_ENV, THERE;


   THERE = call_other(environment(this_object()),"long");
   MUSIC_ENV = first_inventory(environment(this_object()));
  
    while(MUSIC_ENV)  {
     short_str = call_other(MUSIC_ENV, "short");
     if(short_str)  {  write(short_str+".\n");  }
     MUSIC_ENV = next_inventory(MUSIC_ENV);
        }


  return 1;

        }
        
        
set_new_long(str)   { LONG = str;   }
query_new_long()    { return LONG;  }
set_new_short(str)  { SHORT = str;  }
query_new_short()   { return SHORT; }
