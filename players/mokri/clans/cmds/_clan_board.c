#include "../defs.h"
#define MAX_NOTES 25

main()
{
    if(!C_OBJ)
      {
      write("Error! Missing clan object.\n");
      return 1;
   }
   
  move_object(clone_object(TOP_DIR + "obj/clan_board_obj"),TP);
  return 1;
}
