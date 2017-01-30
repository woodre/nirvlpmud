/*
 * View libreports (Verte, Illarion currently have them, I will...)
 */

#include "/obj/user/dt_stamp.h"

int main(string arg) {
  if (!arg || arg == "earwax") {
    command("tail /log/WR/LIB_REPORT", this_player());
    return 1;
  }

  if (arg == "verte") arg = "vertebraker";
  if (arg == "ill") arg = "illarion";

  if (arg == "vertebraker" || arg == "illarion") {
    command("tail /log/WR/"+arg+"_libreport", this_player());
    return 1;
  }

  write_file("/log/WR/"+(string)this_player()->query_real_name()+"_libreport",
    "["+DT+"]: "+arg+"\n");
  write("Noted in libreport.\n");
  return 1;
}
