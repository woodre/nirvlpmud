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
if((x > grid - 1) || (y > grid - 1) || (y < -grid + 1) || (x < -grid + 1)) {
  return 1;
}
  if(x > -1 && y > -1) grid_obxy[translate_grid(x,y)] = ob;
  if(x > -1 && y < 1) grid_obxny[translate_grid(x,-y)] = ob;
  if(x < 1 && y < 1) grid_obnxny[translate_grid(-x,-y)] = ob;
  if(x < 1 && y > -1) grid_obnxy[translate_grid(-x,y)] = ob;
return 1; }

translate_grid(int x,int y) {
  return (y*grid + x);
}

increase_grid() {
int h;
  grid = grid + grid;
  h = 0;
  temp_gxy = grid_obxy;
  temp_gxny = grid_obxny;
  temp_gnxny = grid_obnxny;
  temp_gnxy = grid_obnxy;
  grid_obxy = allocate(grid * grid);
  grid_obxny = allocate(grid * grid);
  grid_obnxny = allocate(grid * grid);
  grid_obnxy = allocate(grid * grid);
  while(h <grid*grid) {
    grid_obxy[h] = temp_gxy[h];
    grid_obxny[h] = temp_gxny[h];
    grid_obnxny[h] = temp_gnxny[h];
    grid_obnxy[h] = temp_gnxy[h];
  }
}

query_exist(int x,int y) { 
object exst;
string exi;
string null,nyl;
  if(x > -1 && y > -1) exst = grid_obxy[translate_grid(x,y)];
  if(x > -1 && y < 1) exst = grid_obxny[translate_grid(x,-y)];
  if(x < 1 && y < 1) exst = grid_obnxny[translate_grid(-x,-y)];
  if(x < 1 && y > -1) exst = grid_obnxy[translate_grid(-x,y)];
  if(exst) { 
    exi = "/"+object_name(exst);
    if(find_object(exi)) return exst;
    else add_grid(0,x,y); }
return 0; }
