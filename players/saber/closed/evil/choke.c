
 /* A spell to freeze a player solid */

int count;

id(str)  {  return str == "hands";  }

long()  { return "A pair of spectral hands around your neck.\n";  }

short()  { return "A pair of spectral hands (worn)";  }

choke()  {
  count = time();
        }

init()  { 
   add_action("not","shout");
   add_action("not","gossip");
   add_action("not","risque");
   add_action("not","equip");
   add_action("not","junk");
   add_action("not","emergency");
   add_action("not","farsing");
   add_action("not","farsinge");
        }

init_arg(str)  {  sscanf(str, "%d", count);  }

not()  {
  if(time() < count + 300)  {
   say(this_player()->query_name()+" tries to say something, but chokes on "+this_player()->query_possessive()+" words.\n");
  write("You can't!  You're being strangled.\n");
    return 1;  }
  else  {
    destruct(this_object());
    return 0;
        }
        }

drop()  { return 1; }
get()   { return 1;  }
