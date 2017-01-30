inherit "/players/feldegast/std/room.c";

int x,y;

int *query_coords() {
  return ({ 30+x, 20+y });
}
