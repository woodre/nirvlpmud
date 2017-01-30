reset(arg){ if(arg) return;  change_shape(); }




heart_beat(){  ::heart_beat();}
if(!random(10)) change_shape();


change_shape() {

switch(random(5)) {

       case 4: set_short(" ");
               set_long(" ");
               set_alt_name(" ");
               break;


       case 3:

               break;
       case 2:

               break;
       case 1:
    
               break;
       case 0:

               break;
             }
            if(environment())
            tell_room(environment(),"Psiren changes into "+alt_name+".\n");
             }



