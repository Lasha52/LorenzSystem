#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>

using namespace sf;


int main(int argc,char *argv[]){
	float x,y,z,k1,k2,k3;
	float dx,dy,dz,dt;
	float resultsX[10000];
	float resultsY[10000];
	float resultsZ[10000];
	int i = 0;
	int j = 0; 
	dt=0.001;
	//just checking arguments from the console
	if (std::string(argv[1])=="-help"){
		std::cout<<"run program with -default tag if you don't want to be asked initial conditions, default initial conditions are 1 2 3 and 10 28 2.5 for constants,run program with ./filenamehere -m to input initial conditions manually"<<std::endl;
		return 0; 	
	}
	else if (std::string(argv[1])=="-default"){
		x=1;
		y=2;
		z=3;
		k1=10;
		k2=28;
		k3=2.5;	
	}
	else{
	std::cout<<"please input the initial conditions and constants: x0 y0 z0 k1 k2 k3"<<std::endl;//asking for initial conditions
	std::cin>>x>>y>>z>>k1>>k2>>k3;
	}
	RenderWindow window(VideoMode(1000, 800), "Lorenz System"); //making a window with 1000x800 resolution
	RectangleShape pixel;//making a rectangle with (1,1) size will serve as a pixel
	pixel.setSize(Vector2f(1,1));
	pixel.setFillColor(Color::Green);
	while (window.isOpen()){
		Event event;
		
	if (window.pollEvent(event)){
		if (event.type == Event::Closed)
				break;	
		}//we write this so we can quit the program when we close the window
	
	dx=(k1*(y-x))*dt;//equations in differential form, initially equations are defined as derivatives we don't want that we want changes in every direction for some fixed dt
	
	dy=(x*(k2-z)-y)*dt;
	
	dz=(x*y-k3*z)*dt;
	x=x+dx;
	y=y+dy;
	z=z+dz;
	j++;
	if (j>100){//saving data in arrays every 100th iteration so we can write them to files
	resultsX[i]=x;
	resultsY[i]=y;
	resultsZ[i]=z;
	i++;
	j=0;
	}
	std::cout<<x<<" "<<y<<" "<<z<<std::endl;
	pixel.setPosition(5*x+400,5*y+400);//multiplying by 5 just scales the image, +400 calibrates it to the center
	window.draw(pixel);//drawing the pixel for current iteration
	window.display();//displaying the still for the current iteration
	// window.clear(); //notice we dont use window.clear()? if we did, we would just see the point moving along the curve as we would redraw the point for every iteration.
	}
	std::ofstream resultx;
    resultx.open ("resultx.txt");
    j=0;
   while(j<10000){
   	resultx<< resultsX[j];
   	resultx<< " ";
  	j++;
  	}
  	resultx.close();
  	std::ofstream resulty;
    resulty.open ("resulty.txt");
    j=0;
   while(j<10000){
   	resulty<< resultsY[j];
   	resulty<< " ";
  	j++;
  	}
  	resulty.close();
  	std::ofstream resultz;
    resultz.open ("resultz.txt");
    j=0;
   while(j<10000){
   	resultz<< resultsZ[j];
   	resultz<< " ";
  	j++;
  	}
  	resultz.close();
  	window.close();
  	return 0;
}