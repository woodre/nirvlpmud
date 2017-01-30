/*
 * A cantrip that adds 'jump' messages to the normal movement messages.
 * Bard v3.0
 */

inherit "obj/treasure";

#define tp this_player()->query_name()

reset(arg)  {
  if(arg) return;
    set_id("jump_obj");
    call_out("go_away",400+random(300));
        }

drop()   { return 1;   }
can_put_and_get()  { return 0; }

go_away() {
  tell_object(environment(this_object()),
    "\nYour jump cantrip expires.\n\n");
  remove_call_out("go_away");
  destruct(this_object());
  return 1;
        }


init()  {
  ::init();
  add_action("jump","jump");
         }
         
jump(str) {
int MES;
object target;
  
  if(!str)  {
    write("You jump high into the air.\nWeeeeeeeeee!\n");
    say(tp+" jumps twenty feet into the air.\n");
    return 1;
        }
  
  if(target = present(str, environment(this_player())))  {
    write("You jump high into the air and land on "+capitalize(str)+".\n");
    say(tp+" jumps high into the air and lands on "+capitalize(str)+".\n",target);
    tell_object(target, tp+" jumps high into the air and lands on you.\nOuch!\n");
    return 1;
        } 
  
  if(str == "n")  str = "north";
  if(str == "e")  str = "east";
  if(str == "w")  str = "west";
  if(str == "s")  str = "south";
  if(str == "u")  str = "up";
  if(str == "d")  str = "down";
  if(str == "nw") str = "northwest";
  if(str == "ne") str = "northeast";
  if(str == "sw") str = "southwest";
  if(str == "se") str = "southeast"; 
 
 
  if(str == "north"     ||   str == "east"      || 
     str == "west"      ||   str == "south"     ||
     str == "northwest" ||   str == "northeast" ||
     str == "southeast" ||   str == "southwest" || 
     str == "up"        ||   str == "down"      ||
     str == "out"       ||   str == "in"         )  {
       
     MES = random(4);
     
     if(MES == 0)  {
       write("\nYou leap _high_ into the air, heading "+str+".\n");
       say(tp+" leaps _high_ into the air, heading "+str+".\n");
             }
     if(MES == 1)  {
       write("\nTaking a running leap, you fly "+str+".\n");
       say(tp+" takes a running leap and sails "+str+".\n");
             }
     if(MES == 2)  {
       write("\nYou jump _high_ into the air, going "+str+".\n");
       say(tp+" jumps _high_ into the air, going "+str+".\n");
             }
     if(MES == 3)  {
       write("\nYou gather your strength and leap _high_ to the "+str+".\n");
       say(tp+" gathers "+this_player()->query_possessive()+" strength and"+
           "leaps _high_ into the air.\n");
             }
             
      command(str, this_player());
      
      if(MES == 0)  {
        say(tp+" sails through the air and lands gracefully.\n");
             }
      if(MES == 1)  {
        say(tp+" drops from the sky, rolls, and springs to "+
        this_player()->query_possessive()+" feet.\n");
             }
       if(MES == 2)  {
         say(tp+" sails down out of the sky ands land softly on "+
         this_player()->query_possessive()+" feet.\n");
             }
       if(MES == 3)  {
         say(tp+" drops out of the sky, bounces on "+
         this_player()->query_possessive()+" feet a few times and then grins.\n");
             }
     
      return 1;  
       }
     
     write("You can not jump to the "+str+".\n");
     return 1;
       }
         
