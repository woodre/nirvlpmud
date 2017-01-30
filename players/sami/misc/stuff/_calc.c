#include "/players/mokri/define.h"

main(string str) {

   int total, tmp, tmp2, firstTime, x;
   string operation,*calculation;

   if(!str) {
      write("No calculation entered.\n");
      return 1;
   }

   total = 0;
   firstTime = 0;
   operation = "";

   calculation = explode(str," ");

   for(x = 0; x < sizeof(calculation); x++) {

      if(sscanf(calculation[x],"%d",tmp) == 1) {

         if(firstTime == 0) {
            firstTime = 1;
            total = tmp;
         }
         else {
            switch(operation) {
               case "+":
                  total = total + tmp;
               break;
               case "-":
                  total = total - tmp;
               break;
               case "*":
               case "x":
               case "X":
                  total = total * tmp;
               break;
               case "/":
                  if(tmp == 0) {
                     write("Error: Divide by 0.\n");
                     return 1;
                  }
                  total = total / tmp;
               break;
               case "^":
                  if(tmp < 0) {
                     write("Error: Negative exponents not yet implemented.\n");
                     return 1; }
                  if(tmp == 0)
                     total = 1;
                  tmp2 = total;
                  while(tmp > 1) {
                     total = total * tmp2;
                     tmp -= 1;
                  }

               break;
               case "%":
                  total = total % tmp;
               break;
            }
            operation = "";

         }
       } else {
         operation = calculation[x];
       }

   }

   operation = "/players/mokri/cmds/funcs/numbers"->numberAddCommas(total);
   write(str + " = " + HIY + operation + NORM + "\n");
   return 1;
}
