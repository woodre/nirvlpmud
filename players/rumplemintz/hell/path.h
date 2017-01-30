#define PATH "players/rumplemintz/hell/"
#define HROOM "players/rumplemintz/hell/hroom"
#define MON (PATH+"mon/")
#define HOBJ_FNAME (PATH+"hobj")

#define LEVHELL 20  /* what level players? */
#define COMPASS ({"north","northeast","east","southeast",\
                  "south","southwest","west","northwest"})
#define NEWDIR ({"forward","forward-right","right","back-right",\
                 "backward","back-left","left","forward-left"})
#define DIR_SZ 8

#define TP this_player()
#define NAME TP->query_name()
#define EXISTS(x,y) if(!present(x,this_object())) \
                      move_object(clone_object(y),this_object())
#define TO this_object()
#define HOBJ present("__hobj",TP)
