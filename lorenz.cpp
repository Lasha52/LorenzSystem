#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include <string>

using namespace sf;


int main(int argc,char *argv[]){
	float x,y,z,k1,k2,k3;
	float dx,dy,dz,dt;
	dt=0.001;
	
	if (std::string(argv[1])=="-help"){
		std::cout<<"run program with -default tag if you don't want to be asked initial conditions, default initial conditions are 1 2 3 and 10 28 2.5 for constants"<<std::endl;
		return 0;
	}
	if (std::string(argv[1])=="-default"){
		x=1;
		y=2;
		z=3;
		k1=10;
		k2=28;
		k3=2.5;	
	}
	else{
	std::cout<<"please input the initial conditions and constants: x0 y0 z0 k1 k2 k3"<<std::endl;
	std::cin>>x>>y>>z>>k1>>k2>>k3;
}
	RenderWindow window(VideoMode(1000, 800), "Lorenz System");
	RectangleShape pixel;
	pixel.setSize(Vector2f(1,1));
	pixel.setFillColor(Color::Blue);
	while (window.isOpen()){
		Event event;
		
	if (window.pollEvent(event)){
		if (event.type == Event::Closed)
				window.close();	
		}
	dx=(k1*(y-x))*dt;
	dy=(x*(k2-z)-y)*dt;
	dz=(x*y-k3*z)*dt;
	x=x+dx;
	y=y+dy;
	z=z+dz;
	std::cout<<x<<" "<<y<<" "<<z<<std::endl;
	pixel.setPosition(5*x+400,5*y+400);
	window.draw(pixel);
	window.display();
	// window.clear();


	}
}