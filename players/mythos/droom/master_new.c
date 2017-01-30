#define PARAM 0
#define AMOUNT 31

object grid_obxy,grid_obxny,grid_obnxny,grid_obnxy;
object temp_gxy,temp_gxny,temp_gnxny,temp_gnxy;
static int grid;

id(str) { return str == "master room"; }

reset(arg) { 
  if(arg) return;
  grid = 31;
  
  grid_obxy = allocate(grid * grid);
  grid_obxny = allocate(grid * grid);
  grid_obnxny = allocate(grid * grid);
  grid_obnxy = allocate(grid * grid); 
}

add_grid(object ob,int x,int y) {
if(!ob) ob = 0;
if((x > grid - PARAM) || (y > grid - PARAM) || (y < -grid + PARAM) || (x < -grid + PARAM)) {
  increase_grid(AMOUNT);
}
  if(x > -PARAM && y > -PARAM) grid_obxy[translate_grid(x,y)] = ob;
  if(x > -PARAM && y < PARAM) grid_obxny[translate_grid(x,-y)] = ob;
  if(x < PARAM && y < PARAM) grid_obnxny[translate_grid(-x,-y)] = ob;
  if(x < PARAM && y > -PARAM) grid_obnxy[translate_grid(-x,y)] = ob;
return 1; }

translate_grid(int x,int y) {
  return (y*(grid-1) + x);
}

increase_grid(int amount) {
int h,z;

  h = 0;
  z = 0;
  temp_gxy = grid_obxy;
  temp_gxny = grid_obxny;
  temp_gnxny = grid_obnxny;
  temp_gnxy = grid_obnxy;
  
  while(z<amount) {
    grid_obxy += ({});
	grid_obxny += ({});
	grid_obnxny += ({});
	grid_obnxy += ({});
	z++;
   }
  
  while(h <grid*grid) {
    grid_obxy[h] = temp_gxy[h];
    grid_obxny[h] = temp_gxny[h];
    grid_obnxny[h] = temp_gnxny[h];
    grid_obnxy[h] = temp_gnxy[h];
	h++;
  }
  grid = grid + amount;
}

query_exist(int x,int y) { 
object exst;
string exi;
string null,nyl;
 x = x -1;
 y = y -1;
  if(x > -1 && y > -1) exst = grid_obxy[translate_grid(x,y)];
  if(x > -1 && y < 1) exst = grid_obxny[translate_grid(x,-y)];
  if(x < 1 && y < 1) exst = grid_obnxny[translate_grid(-x,-y)];
  if(x < 1 && y > -1) exst = grid_obnxy[translate_grid(-x,y)];
  if(exst) { 
    exi = "/"+object_name(exst);
    if(find_object(exi)) return exst;
    else add_grid(0,x,y); }
return 0; }

showall() {
int h;
h = 0;
  while(h<sizeof(grid_obxy)) {
    if(grid_obxy[h]) write(h+"  "+object_name(grid_obxy[h])+"\n");
   h++; 
   }
return 1; }