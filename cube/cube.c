#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <string.h>

float z_pos_buffer[40][20];
char xy_pos_buffer[40][20];
float cube_width = 8.0;
int xx,yy;
float xi, yi, zi;
float A = 0.0, B = 0.0, C = 0.0;

float xpos(float x, float y, float z){
	//return x*cos(A)*cos(B) + y*(cos(A)*sin(B)*sin(C) - sin(A)*cos(C)) + z*(cos(A)*sin(B)*cos(C)+sin(A)*sin(C));
	return x*cos(B)*cos(C) + y*(sin(A)*sin(B)*cos(C) - cos(A)*sin(C)) + z*(cos(A)*sin(B)*cos(C) + sin(A)*sin(C));
}

float ypos(float x, float y, float z){
	//return x*sin(A)*cos(B) + y*(sin(A)*sin(B)*sin(C) + cos(A)*cos(C)) + z*(sin(A)*sin(B)*cos(C)-cos(A)*sin(C));
	return x*cos(B)*sin(C) + y*(sin(A)*sin(B)*sin(C) + cos(A)*cos(C)) + z*(cos(A)*sin(B)*sin(C) - sin(A)*cos(C));
}

float zpos(float x, float y, float z){
	//return -x*sin(B) + y*cos(B)*sin(C) + z*cos(B)*cos(C);
	return -x*sin(B) + y*sin(A)*cos(B) + z*cos(A)*cos(B);
}

void reset(){
	for (int i=0;i<40;i++){
		for (int j=0;j<20;j++){
			z_pos_buffer[i][j] = -100.0;
			xy_pos_buffer[i][j] = ' ';
		}
	}
}

void set(int x, int y, int z, char c){
	xx = (int) (xpos(x,y,z) + 20);
	yy = (int) (ypos(x,y,z)/2 + 10);
	zi = zpos(x,y,z);
	if (zi>z_pos_buffer[xx][yy]){
		z_pos_buffer[xx][yy] = zi;
		xy_pos_buffer[xx][yy] = c;
	}

}

void render2D(){
	zi = cube_width;
	for(yi=-cube_width;yi<cube_width;yi+=.5){
		for(xi=-cube_width;xi<cube_width;xi+=.5){
			set(xi,yi,zi,'.');
		}
	}

	zi = -cube_width;
	for(yi=-cube_width;yi<cube_width;yi+=.5){
		for(xi=-cube_width;xi<cube_width;xi+=.5){
			set(-xi,-yi,zi,'.');
		}
	}
	
	for (yy=0;yy<20;yy++){
		for (xx=0;xx<40;xx++){
			putc(xy_pos_buffer[xx][yy],stdout);
		}
		putc('\n', stdout);
	}
}

int main(){
	for(;;){
		system("clear");
		reset();
		render2D();
		usleep(20000);
		A+=.03;
		B+=.02;
		C+=.01;
	}
	return 0;
}
