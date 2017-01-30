inherit "obj/treasure";

reset(arg)  {

 if (arg) return;
 
   set_id("rose");
   
   set_short("A crystal rose");
   set_long("This small crystal rose is very pleasing to the eye.\n");
   set_weight(1);
   set_value(10);
        }
        
init() {  add_action("smell_rose", "smell");   }


smell_rose(str)  {
 
 if (str == "rose")  {
 
   write("You smell the sweet fragrance of the crystal rose.\n");
   return 1;   
        }
        }

quest_ob()  { return 1; }
