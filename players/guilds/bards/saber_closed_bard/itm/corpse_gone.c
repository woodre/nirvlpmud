/*
 * Get rid of corpse.
 * Bard v3.0
 */


reset(arg) {
   if(arg) return;

  call_out("corpse_gone",1);

        }


get()    { return 1;   }
drop()   { return 1;   }
can_put_and_get()  { return 0; }


id(str) { return str == "corpse_gone"; }
      
        
corpse_gone()  {
object corpse;

  if(corpse = present("corpse", environment(this_object())))  {  
     destruct(corpse);  }
  
  destruct(this_object());
  return 1;
        }
