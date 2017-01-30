#include "/obj/ansi.h"
#define PLAN "/open/pub_plans/star.plan"
void reset(status arg) {
  if (arg) { destruct(this_object()); return; }

  write_file(PLAN, MAG+"                            *** "+NORM+CYN+"Areas"+NORM+MAG+" ***\n\n"+NORM);
  write_file(PLAN, CYN+"The Overlook Hotel, first floor and grounds"+MAG+" ***"+CYN+" In Game"+MAG+"  ***"+CYN+" Low to Mid-levels\n"+NORM);
  write_file(PLAN, CYN+"The Overlook Hotel, second floor"+MAG+"            ***"+CYN+" In Game"+MAG+"  ***"+CYN+" Low to Mid-Levels\n"+NORM);
  write_file(PLAN, CYN+"Narnia"+MAG+"                                      ***"+CYN+" Planning"+MAG+" ***"+CYN+" Possibly assorted levels\n"+NORM);
  write_file(PLAN, CYN+"Care-a-lot"+MAG+"                                  ***"+CYN+" 2% done"+MAG+"  ***"+CYN+" Newbie\n\n"+NORM);
  write_file(PLAN, MAG+"                        *** "+NORM+CYN+"Other Projects"+NORM+MAG+" ***\n\n"+NORM);
  write_file(PLAN, CYN+"Approval of new areas for very patient people who know how busy and slow I am\n"+NORM);
  write_file(PLAN, CYN+"Updates and improvements to help files\n"+NORM);
  write_file(PLAN, CYN+"Fixing reported bugs and typos\n"+NORM);
  write_file(PLAN, CYN+"Anything else Earwax cracks the whip for me to do\n"+NORM);

  write_file("/players/star/PLAN", MAG+"                            *** "+NORM+CYN+"Areas"+NORM+MAG+" ***\n\n"+NORM);
write_file("/players/star/PLAN", CYN+"The Overlook Hotel, first floor and grounds"+MAG+" ***"+CYN+" In Game"+MAG+"  ***"+CYN+" Low to Mid-levels\n"+NORM);
  write_file("/players/star/PLAN", CYN+"The Overlook Hotel, second floor"+MAG+"            ***"+CYN+" In Game"+MAG+"  ***"+CYN+" Low to Mid-Levels\n"+NORM);
  write_file("/players/star/PLAN", CYN+"Narnia"+MAG+"                                      ***"+CYN+" Planning"+MAG+" ***"+CYN+" Possibly assorted levels\n"+NORM);
  write_file("/players/star/PLAN", CYN+"Care-a-lot"+MAG+"                                  ***"+CYN+" 2% done"+MAG+"  ***"+CYN+" Newbie\n\n"+NORM);
  write_file("/players/star/PLAN", MAG+"                        *** "+NORM+CYN+"Other Projects"+NORM+MAG+" ***\n\n"+NORM);
  write_file("/players/star/PLAN", CYN+"Approval of new areas for very patient people who know how busy and slow I am\n"+NORM);
  write_file("/players/star/PLAN", CYN+"Updates and improvements to help files\n"+NORM);
  write_file("/players/star/PLAN", CYN+"Fixing reported bugs and typos\n"+NORM);
  write_file("/players/star/PLAN", CYN+"Anything else Earwax cracks the whip for me to do\n"+NORM);
  destruct(this_object());
}
