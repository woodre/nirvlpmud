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
     set_name("rose");
     set_short("A crystal rose");
     set_level(1);
     set_ac(3);
     set_wc(0);
     set_hp(3);
     set_al(0);
     set_aggressive(0);

     set_dead_ob(this_object());

     set_object(this_object());
     set_function("inform_player");
     set_type("");
     set_match("");
   }
   }


long()  {  write("This small crystal rose is very pleasing to the eye.\n");  }


get()  { return 1; }


inform_player(str) {  tell_room("/players/saber/closed/bard/r/garden.c", 
                                "The roses whisper.\n* "+str); } 


init() {  add_action("smell_rose", "smell");   }


smell_rose(str)  {
 
 if (str == "rose")  {
 
   write("You smell the sweet fragrance of the crystal rose.\n");
   return 1;   
        }
        }
