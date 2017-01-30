/**********************************************************/
/* A library function to delay action.. fake call_out.    */
/*  ->Catt                                                */
/**********************************************************/

delay_action(arg1, arg2) {
   int t, ti, do_it;
   string func;
   int i;

   if(!arg1) return 1;
   if(!arg2) return 1;

   func = arg1;
   t = arg2;

   ti = time();
   do_it = ti + t;

   write("func string from delay_action: "+func+"\n");
/*
   if(time() >= do_it) do_health();
   write("Got past the if(time() >= do_it) func; ... \n");
   return 1;
}
*/
   while(time() < do_it) {
       for(i=0; i== 100; i++) {}
   }
   write("Got past while() in delay_action()\n");
   return func;
}
